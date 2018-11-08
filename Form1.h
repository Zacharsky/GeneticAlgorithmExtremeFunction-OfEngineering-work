#pragma once

#include <algorithm>
#include <fstream>
#include "Algorytm.h"

using namespace std;

namespace AlgorytmGenetycznyEkstremumFunkcji {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			ileZmiennychCB->SelectedIndex = 3;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  wykresPB;
	protected: 

	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;

	private: System::Windows::Forms::TextBox^  funkcjaTB;
	private: System::Windows::Forms::TextBox^  rozmiarPopulacjiTB;
	private: System::Windows::Forms::TextBox^  wartoscMinimalnaXTB;
	private: System::Windows::Forms::TextBox^  wartoscMaksymalnaXTB;





	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  prawdopodobienstwoKrzyzowaniaTB;
	private: System::Windows::Forms::TextBox^  prawdopodobienstwoMutacjiTB;


	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Button^  wykonajB;

	private: System::Windows::Forms::Button^  resetB;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::ComboBox^  wybierzGeneracjeCB;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  ekstremumWPunkcieTB;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  wartoscEkstremumTB;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  liczbaGeneracjiTB;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::ComboBox^  ileZmiennychCB;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TextBox^  wartoscMinimalnaYTB;
	private: System::Windows::Forms::TextBox^  wartoscMaksymalnaYTB;





	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->wykresPB = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->funkcjaTB = (gcnew System::Windows::Forms::TextBox());
			this->rozmiarPopulacjiTB = (gcnew System::Windows::Forms::TextBox());
			this->wartoscMinimalnaXTB = (gcnew System::Windows::Forms::TextBox());
			this->wartoscMaksymalnaXTB = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->prawdopodobienstwoKrzyzowaniaTB = (gcnew System::Windows::Forms::TextBox());
			this->prawdopodobienstwoMutacjiTB = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->wybierzGeneracjeCB = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->ekstremumWPunkcieTB = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->wartoscEkstremumTB = (gcnew System::Windows::Forms::TextBox());
			this->wykonajB = (gcnew System::Windows::Forms::Button());
			this->resetB = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->liczbaGeneracjiTB = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->ileZmiennychCB = (gcnew System::Windows::Forms::ComboBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->wartoscMinimalnaYTB = (gcnew System::Windows::Forms::TextBox());
			this->wartoscMaksymalnaYTB = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->wykresPB))->BeginInit();
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// wykresPB
			// 
			this->wykresPB->BackColor = System::Drawing::Color::White;
			this->wykresPB->Location = System::Drawing::Point(513, 12);
			this->wykresPB->Name = L"wykresPB";
			this->wykresPB->Size = System::Drawing::Size(820, 620);
			this->wykresPB->TabIndex = 0;
			this->wykresPB->TabStop = false;
			this->wykresPB->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::wykresPB_Paint);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 38);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(45, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Funkcja";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 76);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(90, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Rozmiar populacji";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 152);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(106, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Wartoœæ minimalna X";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 190);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(118, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Wartoœæ maksymalna X";
			// 
			// funkcjaTB
			// 
			this->funkcjaTB->Location = System::Drawing::Point(245, 41);
			this->funkcjaTB->Name = L"funkcjaTB";
			this->funkcjaTB->Size = System::Drawing::Size(236, 20);
			this->funkcjaTB->TabIndex = 6;
			this->funkcjaTB->Text = L"x^2 + y^2 + z^2 + a^2";
			// 
			// rozmiarPopulacjiTB
			// 
			this->rozmiarPopulacjiTB->Location = System::Drawing::Point(245, 79);
			this->rozmiarPopulacjiTB->Name = L"rozmiarPopulacjiTB";
			this->rozmiarPopulacjiTB->Size = System::Drawing::Size(100, 20);
			this->rozmiarPopulacjiTB->TabIndex = 7;
			this->rozmiarPopulacjiTB->Text = L"80";
			// 
			// wartoscMinimalnaXTB
			// 
			this->wartoscMinimalnaXTB->Location = System::Drawing::Point(245, 155);
			this->wartoscMinimalnaXTB->Name = L"wartoscMinimalnaXTB";
			this->wartoscMinimalnaXTB->Size = System::Drawing::Size(100, 20);
			this->wartoscMinimalnaXTB->TabIndex = 8;
			this->wartoscMinimalnaXTB->Text = L"-10";
			// 
			// wartoscMaksymalnaXTB
			// 
			this->wartoscMaksymalnaXTB->Location = System::Drawing::Point(245, 193);
			this->wartoscMaksymalnaXTB->Name = L"wartoscMaksymalnaXTB";
			this->wartoscMaksymalnaXTB->Size = System::Drawing::Size(100, 20);
			this->wartoscMaksymalnaXTB->TabIndex = 9;
			this->wartoscMaksymalnaXTB->Text = L"10";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(3, 304);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(170, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Prawdopodobieñstwo krzy¿owania";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(3, 342);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(145, 13);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Prawdopodobieñstwo mutacji";
			// 
			// prawdopodobienstwoKrzyzowaniaTB
			// 
			this->prawdopodobienstwoKrzyzowaniaTB->Location = System::Drawing::Point(245, 307);
			this->prawdopodobienstwoKrzyzowaniaTB->Name = L"prawdopodobienstwoKrzyzowaniaTB";
			this->prawdopodobienstwoKrzyzowaniaTB->Size = System::Drawing::Size(100, 20);
			this->prawdopodobienstwoKrzyzowaniaTB->TabIndex = 13;
			this->prawdopodobienstwoKrzyzowaniaTB->Text = L"0,5";
			// 
			// prawdopodobienstwoMutacjiTB
			// 
			this->prawdopodobienstwoMutacjiTB->Location = System::Drawing::Point(245, 345);
			this->prawdopodobienstwoMutacjiTB->Name = L"prawdopodobienstwoMutacjiTB";
			this->prawdopodobienstwoMutacjiTB->Size = System::Drawing::Size(100, 20);
			this->prawdopodobienstwoMutacjiTB->TabIndex = 14;
			this->prawdopodobienstwoMutacjiTB->Text = L"0,1";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel1->Controls->Add(this->label2, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->rozmiarPopulacjiTB, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->label8, 0, 11);
			this->tableLayoutPanel1->Controls->Add(this->wybierzGeneracjeCB, 1, 11);
			this->tableLayoutPanel1->Controls->Add(this->label9, 0, 12);
			this->tableLayoutPanel1->Controls->Add(this->ekstremumWPunkcieTB, 1, 12);
			this->tableLayoutPanel1->Controls->Add(this->label5, 0, 13);
			this->tableLayoutPanel1->Controls->Add(this->wartoscEkstremumTB, 1, 13);
			this->tableLayoutPanel1->Controls->Add(this->wykonajB, 0, 10);
			this->tableLayoutPanel1->Controls->Add(this->resetB, 1, 10);
			this->tableLayoutPanel1->Controls->Add(this->label7, 0, 9);
			this->tableLayoutPanel1->Controls->Add(this->prawdopodobienstwoMutacjiTB, 1, 9);
			this->tableLayoutPanel1->Controls->Add(this->label6, 0, 8);
			this->tableLayoutPanel1->Controls->Add(this->prawdopodobienstwoKrzyzowaniaTB, 1, 8);
			this->tableLayoutPanel1->Controls->Add(this->label4, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->wartoscMaksymalnaXTB, 1, 5);
			this->tableLayoutPanel1->Controls->Add(this->label3, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->wartoscMinimalnaXTB, 1, 4);
			this->tableLayoutPanel1->Controls->Add(this->label10, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->liczbaGeneracjiTB, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->label11, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->ileZmiennychCB, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->funkcjaTB, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->label12, 0, 6);
			this->tableLayoutPanel1->Controls->Add(this->label13, 0, 7);
			this->tableLayoutPanel1->Controls->Add(this->wartoscMinimalnaYTB, 1, 6);
			this->tableLayoutPanel1->Controls->Add(this->wartoscMaksymalnaYTB, 1, 7);
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 27);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 14;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.140673F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.143233F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.143233F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.143233F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.143233F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.143233F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.141168F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.141168F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.143233F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.143233F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.145377F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.142994F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.142994F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 7.142994F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(484, 542);
			this->tableLayoutPanel1->TabIndex = 17;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(3, 418);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(95, 13);
			this->label8->TabIndex = 17;
			this->label8->Text = L"Wybierz generacjê";
			// 
			// wybierzGeneracjeCB
			// 
			this->wybierzGeneracjeCB->FormattingEnabled = true;
			this->wybierzGeneracjeCB->Location = System::Drawing::Point(245, 421);
			this->wybierzGeneracjeCB->Name = L"wybierzGeneracjeCB";
			this->wybierzGeneracjeCB->Size = System::Drawing::Size(112, 21);
			this->wybierzGeneracjeCB->TabIndex = 18;
			this->wybierzGeneracjeCB->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::wybierzGeneracjeCB_SelectedIndexChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(3, 456);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(111, 13);
			this->label9->TabIndex = 19;
			this->label9->Text = L"Ekstremum w punkcie";
			// 
			// ekstremumWPunkcieTB
			// 
			this->ekstremumWPunkcieTB->Location = System::Drawing::Point(245, 459);
			this->ekstremumWPunkcieTB->Name = L"ekstremumWPunkcieTB";
			this->ekstremumWPunkcieTB->Size = System::Drawing::Size(236, 20);
			this->ekstremumWPunkcieTB->TabIndex = 20;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 494);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(101, 13);
			this->label5->TabIndex = 21;
			this->label5->Text = L"Wartoœæ ekstremum";
			// 
			// wartoscEkstremumTB
			// 
			this->wartoscEkstremumTB->Location = System::Drawing::Point(245, 497);
			this->wartoscEkstremumTB->Name = L"wartoscEkstremumTB";
			this->wartoscEkstremumTB->Size = System::Drawing::Size(100, 20);
			this->wartoscEkstremumTB->TabIndex = 22;
			// 
			// wykonajB
			// 
			this->wykonajB->Location = System::Drawing::Point(3, 383);
			this->wykonajB->Name = L"wykonajB";
			this->wykonajB->Size = System::Drawing::Size(75, 23);
			this->wykonajB->TabIndex = 15;
			this->wykonajB->Text = L"Wykonaj Algorytm";
			this->wykonajB->UseVisualStyleBackColor = true;
			this->wykonajB->Click += gcnew System::EventHandler(this, &Form1::wykonajB_Click);
			// 
			// resetB
			// 
			this->resetB->Location = System::Drawing::Point(245, 383);
			this->resetB->Name = L"resetB";
			this->resetB->Size = System::Drawing::Size(75, 23);
			this->resetB->TabIndex = 16;
			this->resetB->Text = L"Reset";
			this->resetB->UseVisualStyleBackColor = true;
			this->resetB->Click += gcnew System::EventHandler(this, &Form1::resetB_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(3, 114);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(84, 13);
			this->label10->TabIndex = 23;
			this->label10->Text = L"Liczba generacji";
			// 
			// liczbaGeneracjiTB
			// 
			this->liczbaGeneracjiTB->Location = System::Drawing::Point(245, 117);
			this->liczbaGeneracjiTB->Name = L"liczbaGeneracjiTB";
			this->liczbaGeneracjiTB->Size = System::Drawing::Size(100, 20);
			this->liczbaGeneracjiTB->TabIndex = 24;
			this->liczbaGeneracjiTB->Text = L"10";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(3, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(71, 13);
			this->label11->TabIndex = 25;
			this->label11->Text = L"Ile zmiennych";
			// 
			// ileZmiennychCB
			// 
			this->ileZmiennychCB->FormattingEnabled = true;
			this->ileZmiennychCB->Items->AddRange(gcnew cli::array< System::Object^  >(10) {L"1", L"2", L"3", L"4", L"5", L"6", L"7", 
				L"8", L"9", L"10"});
			this->ileZmiennychCB->Location = System::Drawing::Point(245, 3);
			this->ileZmiennychCB->Name = L"ileZmiennychCB";
			this->ileZmiennychCB->Size = System::Drawing::Size(82, 21);
			this->ileZmiennychCB->TabIndex = 26;
			this->ileZmiennychCB->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::ileZmiennychCB_SelectedIndexChanged);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(3, 228);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(106, 13);
			this->label12->TabIndex = 27;
			this->label12->Text = L"Wartoœæ minimalna Y";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(3, 266);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(118, 13);
			this->label13->TabIndex = 28;
			this->label13->Text = L"Wartoœæ maksymalna Y";
			// 
			// wartoscMinimalnaYTB
			// 
			this->wartoscMinimalnaYTB->Location = System::Drawing::Point(245, 231);
			this->wartoscMinimalnaYTB->Name = L"wartoscMinimalnaYTB";
			this->wartoscMinimalnaYTB->Size = System::Drawing::Size(100, 20);
			this->wartoscMinimalnaYTB->TabIndex = 29;
			this->wartoscMinimalnaYTB->Text = L"-10";
			// 
			// wartoscMaksymalnaYTB
			// 
			this->wartoscMaksymalnaYTB->Location = System::Drawing::Point(245, 269);
			this->wartoscMaksymalnaYTB->Name = L"wartoscMaksymalnaYTB";
			this->wartoscMaksymalnaYTB->Size = System::Drawing::Size(100, 20);
			this->wartoscMaksymalnaYTB->TabIndex = 30;
			this->wartoscMaksymalnaYTB->Text = L"10";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1336, 631);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->wykresPB);
			this->Name = L"Form1";
			this->Text = L"Algorytm genetyczny - eksremum funkcji";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->wykresPB))->EndInit();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion



	private:

		vector<vector<Osobnik> >* pokolenia;

		int rozmiarPopulacji;
		int liczbaGeneracji;

		float wartoscMinimalnaX;
		float wartoscMaksymalnaX;

		float wartoscMinimalnaY;
		float wartoscMaksymalnaY;

		float prawdopodobienstwoKrzyzowania;
		float prawdopodobienstwoMutacji;

		System::Void resetB_Click(System::Object^  sender, System::EventArgs^  e)
		{
			wybierzGeneracjeCB->Items->Clear();
			wykresPB->Refresh();

			ekstremumWPunkcieTB->Clear();
			wartoscEkstremumTB->Clear();
			wybierzGeneracjeCB->Text = "";
			wybierzGeneracjeCB->SelectedIndex = -1;
		}
		System::Void wykonajB_Click(System::Object^  sender, System::EventArgs^  e)
		{
			String^ funkcjaStr = funkcjaTB->Text;
			String^ rozmiarPopulacjiStr = rozmiarPopulacjiTB->Text;
			String^ liczbaGeneracjiStr = liczbaGeneracjiTB->Text;

			String^ wartoscMinimalnaXStr = wartoscMinimalnaXTB->Text;
			String^ wartoscMaksymalnaXStr = wartoscMaksymalnaXTB->Text;

			String^ wartoscMinimalnaYStr = wartoscMinimalnaYTB->Text;
			String^ wartoscMaksymalnaYStr = wartoscMaksymalnaYTB->Text;

			String^ prawdopodobienstwoKrzyzowaniaStr = prawdopodobienstwoKrzyzowaniaTB->Text;
			String^ prawdopodobienstwoMutacjiStr = prawdopodobienstwoMutacjiTB->Text;

			
			const char* funkcjaCh = (const char*) (Marshal::StringToHGlobalAnsi(funkcjaStr)).ToPointer();

			try {

				rozmiarPopulacji = Int32::Parse(rozmiarPopulacjiStr);
				liczbaGeneracji = Int32::Parse(liczbaGeneracjiStr);

				wartoscMinimalnaX = (float)Convert::ToDouble(wartoscMinimalnaXStr);
				wartoscMaksymalnaX = (float)Convert::ToDouble(wartoscMaksymalnaXStr);

				wartoscMinimalnaY = (float)Convert::ToDouble(wartoscMinimalnaYStr);
				wartoscMaksymalnaY = (float)Convert::ToDouble(wartoscMaksymalnaYStr);

				prawdopodobienstwoKrzyzowania = (float)Convert::ToDouble(prawdopodobienstwoKrzyzowaniaStr);
				prawdopodobienstwoMutacji = (float)Convert::ToDouble(prawdopodobienstwoMutacjiStr);
				ileZmiennych = ileZmiennychCB->SelectedIndex + 1;

			} catch(...)
			{
				return;
			}

			pokolenia = new vector<vector<Osobnik> >[1];

			try
			{

				*pokolenia = symuluj(
					rozmiarPopulacji, liczbaGeneracji,
					wartoscMinimalnaX, wartoscMaksymalnaX,
					wartoscMinimalnaY, wartoscMaksymalnaY,
					prawdopodobienstwoKrzyzowania, prawdopodobienstwoMutacji, funkcjaCh);
			}
			catch(...)
			{
				MessageBox::Show("Niepoprawna funkcja");
				return;
			}


			wybierzGeneracjeCB->Items->Clear();
			int ilePokolen = pokolenia->size();

			for (int i = 0; i < ilePokolen; i++)
			{
				wybierzGeneracjeCB->Items->Add("" + (i + 1));
			}


			wybierzGeneracjeCB->SelectedIndex = ilePokolen - 1;

			

			vector<Osobnik> aktualnePokolenie = (*pokolenia)[ilePokolen - 1];

			
			Osobnik najlepszyOsobnik = Populacja::znajdzNajlepszegoOsobnika(aktualnePokolenie);
			ekstremumWPunkcieTB->Text = "";
			for (int i = 0; i < ileZmiennych; i++)
			{
				ekstremumWPunkcieTB->AppendText(najlepszyOsobnik.genotyp[i].ToString("0.000 "));
			}
			wartoscEkstremumTB->Text = najlepszyOsobnik.wartoscFunkcji.ToString("0.000000");

			ofstream plik ("wyniki.txt");

			if (plik.is_open())
			{
				for (int i = 0; i < liczbaGeneracji; i++)
				{
					plik << "Generacja " << (i + 1) << endl;
					plik << "Osobniki poczatkowe" << endl;
					for (int j = 0; j < rozmiarPopulacji; j++)
					{
						for (int k = 0; k < ileZmiennych; k++)
						{
							plik << setw(13) << listaGeneracjiPoczatkowych[i][j].genotyp[k];
						}
						plik << endl;
					}
					plik << "Osobniki po selekcji" << endl;
					for (int j = 0; j < rozmiarPopulacji; j++)
					{
						for (int k = 0; k < ileZmiennych; k++)
						{
							plik << setw(13) << listaGeneracjiPoSelekcji[i][j].genotyp[k];
						}
						plik << endl;
					}
					plik << "Osobniki po krzyzowaniu" << endl;
					for (int j = 0; j < rozmiarPopulacji; j++)
					{
						for (int k = 0; k < ileZmiennych; k++)
						{
							plik << setw(13) << listaGeneracjiPoKrzyzowaniu[i][j].genotyp[k];
						}
						plik << endl;
					}
					plik << "Osobniki po mutacji" << endl;
					for (int j = 0; j < rozmiarPopulacji; j++)
					{
						for (int k = 0; k < ileZmiennych; k++)
						{
							plik << setw(13) << listaGeneracjiPoMutacji[i][j].genotyp[k];
						}
						plik << endl;
					}

					Osobnik osobnik = Populacja::znajdzNajlepszegoOsobnika((*pokolenia)[i]);
					

					plik << "Najlepszy: ["; 
					for (int k = 0; k < ileZmiennych; k++)
					{
						plik << osobnik.genotyp[k];

						if (k < ileZmiennych - 1) plik << ", ";
					}
					plik << "] = " << osobnik.wartoscFunkcji << endl;

					plik << "--------------------------------------------------------------" << endl;
				}
				plik.close();
			}


			wykresPB->Refresh();


		}
		System::Void wybierzGeneracjeCB_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
		{
			try 
			{
				if (wybierzGeneracjeCB->Items->Count == 0)
				{
					return;
				}

				vector<Osobnik> aktualnePokolenie = (*pokolenia)[wybierzGeneracjeCB->SelectedIndex];
				Osobnik najlepszyOsobnik = Populacja::znajdzNajlepszegoOsobnika(aktualnePokolenie);

				ekstremumWPunkcieTB->Text = "";
				for (int i = 0; i < ileZmiennych; i++)
				{
					ekstremumWPunkcieTB->AppendText(najlepszyOsobnik.genotyp[i].ToString("0.000 "));
				}
				wartoscEkstremumTB->Text = najlepszyOsobnik.wartoscFunkcji.ToString("0.000000");
				


				wykresPB->Refresh();
				}
			catch(...)
			{
				MessageBox::Show("Niepoprawne parametry");
			}
		}


		PointF skaluj(PointF inputPoint, RectangleF inputRectangle, RectangleF outputRectangle)
		{
			float I = inputPoint.X;
			float Min = inputRectangle.Left;
			float Max = inputRectangle.Right;

			float newMin = outputRectangle.Left;
			float newMax = outputRectangle.Right;

			float px = (I - Min) * (newMax - newMin) / (Max - Min) + newMin;

			I = inputPoint.Y;
			Min = inputRectangle.Top;
			Max = inputRectangle.Bottom;

			newMin = outputRectangle.Top;
			newMax = outputRectangle.Bottom;

			float py = (I - Min) * (newMax - newMin) / (Max - Min) + newMin;

			return PointF(px, py);
		}


		System::Void wykresPB_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
		{
			Graphics^ g = e->Graphics;

			if (ileZmiennych != 1)
			{
				return;
			}

			g->DrawLine(gcnew Pen(Color::Blue, 1.0f),
				Point(0, 300),
				Point(820, 300));

			g->DrawLine(gcnew Pen(Color::Blue, 1.0f),
				Point(400, 0),
				Point(400, 620));

			if (wybierzGeneracjeCB->Items->Count == 0)
			{
				return;
			}


			try
			{

				float minY = 0;
				float maxY = 0;

				for (int i = 0; i < 800; i++)
				{
					float x = wartoscMinimalnaX + ((wartoscMaksymalnaX - wartoscMinimalnaX) * i) / 800.0f;

					vector<double> vx;
					vx.push_back(x);
					float y = (float)funkcja(vx);

					if (i == 0 || y < minY)
					{
						minY = y;
					}
					if (i == 0 || y > maxY)
					{
						maxY = y;
					}
				}

				float zakresY = std::max(abs(minY), abs(maxY));

				Pen^ pen = gcnew Pen(Color::Blue, 1.0f);
				Brush^ brush = gcnew SolidBrush( Color::Blue );
				System::Drawing::Font^ font = gcnew System::Drawing::Font("Arial", 10);

				g->DrawLine(pen, Point(2, 295), Point(2, 305));
				g->DrawString( "" + wartoscMinimalnaX, font, brush , PointF(2.0f, 305.0f));

				g->DrawLine(pen, Point(798, 295), Point(798, 305));
				g->DrawString( "" + wartoscMaksymalnaX, font, brush , PointF(785.0f, 305.0f));

				g->DrawLine(pen, Point(395, 2), Point(405, 2));
				g->DrawString(String::Format("{0:f}", -zakresY), font, brush , PointF(405.0f, 2.0f));

				g->DrawLine(pen, Point(395, 598), Point(405, 598));
				g->DrawString(String::Format("{0:f}", zakresY), font, brush , PointF(405.0f, 598.0f));

			

				vector<Osobnik> aktualnePokolenie = (*pokolenia)[wybierzGeneracjeCB->SelectedIndex];


				RectangleF inputRect(wartoscMinimalnaX, -zakresY, wartoscMaksymalnaX - wartoscMinimalnaX, 2 * zakresY);
				RectangleF outputRect(0, 0, 800, 600);


				g->DrawLine(gcnew Pen(Color::Blue, 1.0f),
					Point(0, 300),
					Point(800, 300));

				for (int i = 0; i < 800; i++)
				{
					float x = wartoscMinimalnaX + ((wartoscMaksymalnaX - wartoscMinimalnaX) * i) / 800.0f;

					vector<double> vx;
					vx.push_back(x);
					float y = (float)funkcja(vx);

					PointF p = skaluj(PointF(x, y), inputRect, outputRect);

					g->FillEllipse(
						gcnew SolidBrush(Color::Black), Rectangle((int)p.X, 600 - (int)p.Y, 2, 2));
				}


				for (unsigned i = 0; i < aktualnePokolenie.size(); i++)
				{
					float x =  (float)aktualnePokolenie[i].genotyp[0];

					vector<double> vx;
					vx.push_back(x);
					float y = (float)funkcja(vx);

					PointF p = skaluj(PointF(x, y), inputRect, outputRect);


					g->DrawEllipse(
						gcnew Pen(Color::Green), Rectangle((int)p.X, 600 - (int)p.Y, 8, 8));
				}


				g->DrawEllipse(gcnew Pen(Color::Green), Rectangle(20, 590, 8, 8));
				g->DrawString(" - osobnik", font, brush , PointF(26.0f, 586.0f));

			}
			catch(...)
			{
				MessageBox::Show("Niepoprawne parametry");
			}
		}

		System::Void ileZmiennychCB_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
		{
			if (ileZmiennychCB->SelectedIndex == 1)
			{
				 wartoscMinimalnaYTB->Enabled = true;
				 wartoscMaksymalnaYTB->Enabled = true;
			}
			else
			{
				wartoscMinimalnaYTB->Enabled = false;
				wartoscMaksymalnaYTB->Enabled = false;
			}
		}
};
}

