#include "Chromosom.h"

struct Populacja
{
	vector<Chromosom> chromosomy;
	Chromosom najlepszyChromosom;
	int rozmiarPopulacji;
	double najlepszaOcena;
	double sredniaOcena;
	double minX;
	double maxX;
	
	Populacja()
	{

	}

	

	// tworzy nowa populacje
	Populacja(int rozmiarPopulacji, double min, double max, int rozmiarChromosomu)
	{
		this->rozmiarPopulacji = rozmiarPopulacji;
		this->minX = min;
		this->maxX = max;

		for (int i = 0; i < rozmiarPopulacji; i++)
		{
			chromosomy.push_back(Chromosom(min, max, rozmiarChromosomu, true));
		}

	}

	int losujChromosom()
	{
		return rand() % rozmiarPopulacji;
	}

	int wyborTurniejowy(int liczbaKrokow)
	{
		int indeksNajlepszego = losujChromosom();
		double najlepszaOcena = chromosomy[indeksNajlepszego].wartoscFunkcji;

		// przez okreslona liczbe krokow dany chromosom bedzie sie "mierzyl" z nowym
		// wylosowanym
		// jesli wygra to "przechodzi dalej", jesli przegra to ten nowy zajmuje jego miejsce
		// z funkcji zwracany jest ten ktory zostanie na koniec
		for (int i = 0; i < liczbaKrokow; i++)
		{
			int indeksKolejnego = losujChromosom();

			double ocenaKolejnego = chromosomy[indeksKolejnego].wartoscFunkcji;

			if (ocenaKolejnego < najlepszaOcena)
			{
				indeksNajlepszego = indeksKolejnego;
				najlepszaOcena = ocenaKolejnego;
			}
		}

		return indeksNajlepszego;
	}

	void obliczStatystyki()
	{
		double suma = 0;
		
		int indeksNajlepszego = -1;

		for (int i = 0; i < rozmiarPopulacji; i++)
		{
			double ocena = chromosomy[i].wartoscFunkcji;

			if (suma == 0 || ocena < najlepszaOcena)
			{
				najlepszaOcena = ocena;
				indeksNajlepszego =  i;
			}

			suma += ocena;
		}

		sredniaOcena = suma / rozmiarPopulacji;
		najlepszyChromosom = chromosomy[indeksNajlepszego];
	}


	static Chromosom znajdzNajlepszyChromosom(vector<Chromosom> chr)
	{
		int indeks = -1;
		double najlepsza = 0;

		for (unsigned i = 0; i < chr.size(); i++)
		{
			double ocena = chr[i].wartoscFunkcji;

			if (indeks == -1 || ocena < najlepsza)
			{
				najlepsza = ocena;
				indeks =  i;
			}
		}

		return chr[indeks];
	}

	

	vector<Chromosom> generujNowePokolenie(double prawdopodobienstwoKrzyzowania,
		double prawdopodobienstwoMutacji, int liczbaKrokowWyboruTurniejowego)
	{
		double min = chromosomy[0].min;
		double max = chromosomy[0].max;
		int rozmiarChromosomu = chromosomy[0].n;

		vector<Chromosom> nowePokolenie;
		for (int i = 0; i < rozmiarPopulacji; i++)
		{
			// wybiera dwa indeksy osobnikow
			int indeks1 = wyborTurniejowy(liczbaKrokowWyboruTurniejowego);
			int indeks2 = wyborTurniejowy(liczbaKrokowWyboruTurniejowego);
			
			// jesli spelniony jest warunek krzyzowania to osobniki sie krzyzuja
			if (prawdopodobienstwoKrzyzowania > fRand(0.0, 1.0))
			{
				Chromosom dziecko1(min, max, rozmiarChromosomu, false);

				Chromosom::krzyzowanie(chromosomy[indeks1], chromosomy[indeks2], dziecko1);

				nowePokolenie.push_back(dziecko1);
			}
			else
			{
				nowePokolenie.push_back(chromosomy[indeks1]);
			}

			// sprawdzenie mutacji dla pierwszego z dodanych osobnikow
			if (prawdopodobienstwoMutacji > fRand(0.0, 1.0))
			{
				nowePokolenie[nowePokolenie.size() - 1].mutuj();
			}

			
		}
		// kopiuje chromosomy z nowego pokolenia do zmiennej chromosomy
		chromosomy = vector<Chromosom>(nowePokolenie.begin(), nowePokolenie.end());

		return nowePokolenie;
	}
};