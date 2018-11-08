
#include <iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>

#include "expression_parser.h"

using namespace std;

double PI = 3.1415927;
double RMAX = RAND_MAX;
double* arg;
int ileZmiennych = 1;
const char* expr = "";

char* zmienne[] = {"x", "y", "z", "a", "b", "c", "d", "e", "f", "g"};

double generatorRozkladuNormalnego(const double &srednia, const double &odchylenieStandardowe)
{
	return odchylenieStandardowe * sqrt(-2*log((rand()+1)/RMAX))*sin(2*PI*rand()/RMAX)+srednia;
}

double randomFloat(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}


int ustawZmienna( void *user_data, const char *name, double *value)
{
	for (int i = 0; i < ileZmiennych; i++)
	{
		if(strcmp(name, zmienne[i] ) == 0)
        {
            *value = arg[i];
            return PARSER_TRUE;
        }
	}
	return PARSER_FALSE;
}

double funkcja(vector<double> x)
{
	int n = x.size();
	arg = (double*)malloc(n * sizeof(double));
	for (int i = 0; i < n; i++) arg[i] = x[i];
	return parse_expression_with_callbacks(expr, ustawZmienna, NULL, NULL);
}

struct Osobnik
{
	vector<double> genotyp;
	
	double wartoscFunkcji;

	double minX;
	double maxX;
	double minY;
	double maxY;

	Osobnik()
	{
		minX = 0;
		maxX = 0;
	}

	Osobnik(double minX, double maxX, double minY, double maxY)
	{
		this->minX = minX;
		this->maxX = maxX;

		this->minY = minY;
		this->maxY = maxY;

		for (int i = 0; i < ileZmiennych; i++)
		{
			if (ileZmiennych == 2 && i == 1)
			{
				genotyp.push_back(randomFloat(minY, maxY));
			}
			else
			{
				genotyp.push_back(randomFloat(minX, maxX));
			}
		}
		
		ustawWartoscFunkcji();
	}

	void ustawWartoscFunkcji()
	{
		wartoscFunkcji = funkcja(genotyp);
	}

	double wyrownajDoZakresu(double v, double min, double max)
	{
		if (v < min) return min;
		if (v > max) return max;
		return v;
	}

	void mutuj()
	{
		int losowyIndeks = rand() % ileZmiennych;

		if (ileZmiennych == 2 && losowyIndeks == 1)
		{
			genotyp[losowyIndeks] = wyrownajDoZakresu(generatorRozkladuNormalnego(genotyp[losowyIndeks], (maxY-minY)/5), minY, maxY);
		}
		else
		{
			genotyp[losowyIndeks] = wyrownajDoZakresu(generatorRozkladuNormalnego(genotyp[losowyIndeks], (maxX-minX)/5), minX, maxX);
		}

		ustawWartoscFunkcji();
	}

	static void krzyzuj(Osobnik& rodzic1, Osobnik& rodzic2, Osobnik& dziecko1, Osobnik& dziecko2)
	{
		int punktPrzeciecia = rand() % ileZmiennych;
		dziecko1.genotyp.clear();
		dziecko2.genotyp.clear();
		for (int i = 0; i < punktPrzeciecia; i++)
		{
			dziecko1.genotyp.push_back(rodzic1.genotyp[i]);
			dziecko2.genotyp.push_back(rodzic2.genotyp[i]);
		}
		for (int i = punktPrzeciecia; i < ileZmiennych; i++)
		{
			dziecko1.genotyp.push_back(rodzic2.genotyp[i]);
			dziecko2.genotyp.push_back(rodzic1.genotyp[i]);
		}
		dziecko1.ustawWartoscFunkcji();
		dziecko2.ustawWartoscFunkcji();
	}
};

vector<vector<Osobnik> > listaGeneracjiPoczatkowych;
vector<vector<Osobnik> > listaGeneracjiPoSelekcji;
vector<vector<Osobnik> > listaGeneracjiPoKrzyzowaniu;
vector<vector<Osobnik> > listaGeneracjiPoMutacji;

struct Populacja
{
	vector<Osobnik> chromosomy;
	Osobnik najlepszyOsobnik;
	int rozmiarPopulacji;
	double najlepszaOcena;
	double sredniaOcena;
	double minX;
	double maxX;
	double minY;
	double maxY;

	Populacja()
	{

	}

	Populacja(int rozmiarPopulacji, double minX, double maxX, double minY, double maxY)
	{
		this->rozmiarPopulacji = rozmiarPopulacji;

		this->minX = minX;
		this->maxX = maxX;

		this->minY = minY;
		this->maxY = maxY;

		for (int i = 0; i < rozmiarPopulacji; i++)
		{
			chromosomy.push_back(Osobnik(minX, maxX, minY, maxY));
		}
	}

	int losowyOsobnik()
	{
		return rand() % rozmiarPopulacji;
	}

	int selekcjaTurniejowa(int liczbaKrokow)
	{
		int indeksNajlepszego = losowyOsobnik();
		double najlepszaOcena = chromosomy[indeksNajlepszego].wartoscFunkcji;

		for (int i = 0; i < liczbaKrokow; i++)
		{
			int indeks = losowyOsobnik();

			double ocena = chromosomy[indeks].wartoscFunkcji;

			if (ocena < najlepszaOcena)
			{
				indeksNajlepszego = indeks;
				najlepszaOcena = ocena;
			}
		}

		return indeksNajlepszego;
	}

	static Osobnik znajdzNajlepszegoOsobnika(vector<Osobnik> ch)
	{
		int indeks = -1;
		double najlepsza = 0;

		for (unsigned i = 0; i < ch.size(); i++)
		{
			double ocena = ch[i].wartoscFunkcji;

			if (indeks == -1 || ocena < najlepsza)
			{
				najlepsza = ocena;
				indeks =  i;
			}
		}

		return ch[indeks];
	}

	vector<Osobnik> wykonajSelekcje(int liczbaKrokowTurnieju)
	{
		vector<Osobnik> generacja;
		for (int i = 0; i < rozmiarPopulacji / 2; i++)
		{
			int indeks1 = selekcjaTurniejowa(liczbaKrokowTurnieju);
			int indeks2 = selekcjaTurniejowa(liczbaKrokowTurnieju);
			generacja.push_back(chromosomy[indeks1]);
			generacja.push_back(chromosomy[indeks2]);
		}
		return generacja;
	}

	vector<Osobnik> nowaGeneracja(double prawdopodobienstwoKrzyzowania,
		double prawdopodobienstwoMutacji, int liczbaKrokowTurnieju)
	{
		double minX = chromosomy[0].minX;
		double maxX = chromosomy[0].maxX;

		double minY = chromosomy[0].minY;
		double maxY = chromosomy[0].maxY;

		listaGeneracjiPoczatkowych.push_back(chromosomy);

		vector<Osobnik> generacjaPoSelekcji = wykonajSelekcje(liczbaKrokowTurnieju);
		vector<Osobnik> generacjaPoKrzyzowaniu;
		vector<Osobnik> generacjaPoMutacji;

		listaGeneracjiPoSelekcji.push_back(generacjaPoSelekcji);

		for (int i = 0; i < rozmiarPopulacji / 2; i++)
		{	
			Osobnik rodzic1 = generacjaPoSelekcji[i];
			Osobnik rodzic2 = generacjaPoSelekcji[i + 1];

			if (prawdopodobienstwoKrzyzowania > randomFloat(0.0, 1.0))
			{
				Osobnik dziecko1(minX, maxX, minY, maxY);
				Osobnik dziecko2(minX, maxX, minY, maxY);

				Osobnik::krzyzuj(rodzic1, rodzic2, dziecko1, dziecko2);
				generacjaPoKrzyzowaniu.push_back(dziecko1);
				generacjaPoKrzyzowaniu.push_back(dziecko2);
			}
			else
			{
				generacjaPoKrzyzowaniu.push_back(rodzic1);
				generacjaPoKrzyzowaniu.push_back(rodzic2);
			}
		}

		listaGeneracjiPoKrzyzowaniu.push_back(generacjaPoKrzyzowaniu);


		for (int i = 0; i < rozmiarPopulacji; i++)
		{
			if (prawdopodobienstwoMutacji > randomFloat(0.0, 1.0))
			{
				generacjaPoKrzyzowaniu[i].mutuj();
			}
			generacjaPoMutacji.push_back(generacjaPoKrzyzowaniu[i]);
		}

		listaGeneracjiPoMutacji.push_back(generacjaPoMutacji);


		chromosomy = vector<Osobnik>(generacjaPoMutacji.begin(), generacjaPoMutacji.end());
		return chromosomy;
	}
};

vector<vector<Osobnik> > symuluj(
	int rozmiarPopulacji,
	int liczbaGeneracji,
	double wartoscMinimalnaX,
	double wartoscMaksymalnaX,
	double wartoscMinimalnaY,
	double wartoscMaksymalnaY,
	double prawdopodobienstwoKrzyzowania,
	double prawdopodobienstwoMutacji,
	const char* e)
{
	expr = e;
	int liczbaKrokowTurnieju = 5;

	Populacja populacja(rozmiarPopulacji, wartoscMinimalnaX, wartoscMaksymalnaX, wartoscMinimalnaY, wartoscMaksymalnaY);
		
	vector<vector<Osobnik> > pokolenia;

	listaGeneracjiPoczatkowych.clear();
	listaGeneracjiPoSelekcji.clear();
	listaGeneracjiPoKrzyzowaniu.clear();
	listaGeneracjiPoMutacji.clear();

	for (int j = 0; j < liczbaGeneracji; j++)
	{
		pokolenia.push_back(populacja.nowaGeneracja(
			prawdopodobienstwoKrzyzowania,
			prawdopodobienstwoMutacji,
			liczbaKrokowTurnieju));	
	}
	return pokolenia;
}
