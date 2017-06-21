#pragma once
#include <vector>
#include <queue>

namespace Project4 {

	std::vector <int> kolejnosc;
	std::queue <int> P1;
	std::queue <int> P2;
	std::queue <int> P3;
	std::queue <int> P4;
	std::queue <int> P5;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>

	public ref class MyForm : public System::Windows::Forms::Form
	{
		static int pozycja_windy = 510;
		static int cel_windy = 510;
		static int kierunek = 1;
		static int postoj = 0;
		static int bezczynnosc = 0;
		static int a, b, c;
		static int licznik_osob = 0;
		bool zakonczony = false;
		bool spr;
		static int i_obciazenie = 0;
		String^ s_obciazenie;

		//i1na2 - int, znaczy ilość ludzi czekająch na piętrze 1 i chcących jechać na piętro 2
		//s1na2 - string, odwzorowanie i1na2
		//w_na1 - int, pokazuje ile osób w windzie chce jechać na 1 piętro
		//sw_na1 = string, odworowanie w_na1
		static int i1na2 = 0, i1na3 = 0, i1na4 = 0, i1na5 = 0;
		String^ s1na2; String^ s1na3; String^ s1na4; String^ s1na5;
		static int i2na3 = 0, i2na4 = 0, i2na5 = 0, i2na1 = 0;
		String^ s2na3; String^ s2na4; String^ s2na5; String^ s2na1;
		static int i3na4 = 0, i3na5 = 0, i3na1 = 0, i3na2 = 0;
		String^ s3na4; String^ s3na5; String^ s3na1; String^ s3na2;
		static int i4na5 = 0, i4na1 = 0, i4na2 = 0, i4na3 = 0;
		String^ s4na5; String^ s4na1; String^ s4na2; String^ s4na3;
		static int i5na1 = 0, i5na2 = 0, i5na3 = 0, i5na4 = 0;
		String^ s5na1; String^ s5na2; String^ s5na3; String^ s5na4;
		static int w_na1 = 0, w_na2 = 0, w_na3 = 0, w_na4 = 0, w_na5 = 0;
		String^ sw_na1; String^ sw_na2; String^ sw_na3; String^ sw_na4; String^ sw_na5;

		//b1na2 - guzik który po wciśnięciu tworzy na 1 piętrze osobę która chce jechać na 2 piętro
		//l1na2 - label pokazujacy ile razy dany guzik został wciśnięty, w tym przypadku guzik b1na2
		//l_w_na1 - label pokazujący wartość inta w_na1 (w_na1 opisany wyżej)
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  b1na2;
	private: System::Windows::Forms::Button^  b2na3;
	private: System::Windows::Forms::Button^  b3na2;
	private: System::Windows::Forms::Button^  b4na2;
	private: System::Windows::Forms::Button^  b5na2;
	private: System::Windows::Forms::Button^  b1na3;
	private: System::Windows::Forms::Button^  b4na3;
	private: System::Windows::Forms::Button^  b5na3;
	private: System::Windows::Forms::Button^  b2na1;
	private: System::Windows::Forms::Button^  b3na1;
	private: System::Windows::Forms::Button^  b4na1;
	private: System::Windows::Forms::Button^  b5na1;
	private: System::Windows::Forms::Button^  b5na4;
	private: System::Windows::Forms::Button^  b3na4;
	private: System::Windows::Forms::Button^  b2na4;
	private: System::Windows::Forms::Button^  b1na4;
	private: System::Windows::Forms::Button^  b4na5;
	private: System::Windows::Forms::Button^  b3na5;
	private: System::Windows::Forms::Button^  b2na5;
	private: System::Windows::Forms::Button^  b1na5;
	private: System::Windows::Forms::Label^  l1na2;
	private: System::Windows::Forms::Label^  l1na3;
	private: System::Windows::Forms::Label^  l1na4;
	private: System::Windows::Forms::Label^  l1na5;
	private: System::Windows::Forms::Label^  l2na1;
	private: System::Windows::Forms::Label^  l2na3;
	private: System::Windows::Forms::Label^  l2na4;
	private: System::Windows::Forms::Label^  l2na5;
	private: System::Windows::Forms::Label^  l3na1;
	private: System::Windows::Forms::Label^  l3na2;
	private: System::Windows::Forms::Label^  l3na4;
	private: System::Windows::Forms::Label^  l3na5;
	private: System::Windows::Forms::Label^  l4na1;
	private: System::Windows::Forms::Label^  l4na2;
	private: System::Windows::Forms::Label^  l4na3;
	private: System::Windows::Forms::Label^  l4na5;
	private: System::Windows::Forms::Label^  l5na1;
	private: System::Windows::Forms::Label^  l5na2;
	private: System::Windows::Forms::Label^  l5na3;
	private: System::Windows::Forms::Label^  l5na4;
	private: System::Windows::Forms::Label^  l_w_na1;
	private: System::Windows::Forms::Label^  l_w_na2;
	private: System::Windows::Forms::Label^  l_w_na3;
	private: System::Windows::Forms::Label^  l_w_na4;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Timer^  timer3;
	private: System::Windows::Forms::Label^  l_obciazenie;

	private: System::Windows::Forms::Label^  l_w_na5;



	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void Przesiadka(static int)		//Funkcja obsługująca wywołanie funkcji w której ludzie na danym piętrze wysiadają z windy, a także do niej wsiadają dodając do wektora "kolejnosc" kolejne piętra
		{
			switch (cel_windy)
			{
			case 510:
				Pietro_1();
				break;

			case 410:
				Pietro_2();
				break;

			case 310:
				Pietro_3();
				break;

			case 210:
				Pietro_4();
				break;

			case 110:
				Pietro_5();
				break;

			default:
				break;
			}

			//Obsługa interfejsu pokazującego aktualną masę pasażerów w windzie
			i_obciazenie = 70 * (w_na1 + w_na2 + w_na3 + w_na4 + w_na5);
			s_obciazenie = Convert::ToString(i_obciazenie);
			l_obciazenie->Text = "Obciążenie : " + s_obciazenie;

		};



		//Funkcje Piętro_x obsługują wsiadanie i wysiadanie osób: zmianę labelów, zmiennych int, dodawanie do kolejności kolejne piętra, funkcja zostaje wywołana na każde tiknięcie timera2 pod warunkiem spełnienia odpowienich warunków.
		//Na każde ticknięcie timera2 swoje położenie względem windy może zmienić tylko 1 osoba (wsiadanie lub wysiadanie), to ograniczenie obsługuje zmienna boolowska "spr"
		//W funkcji odbywa się także aktualizowanie stanów labeli pokazujących ilość osób na danym piętrze i w windzie
		void Pietro_1(void)
		{
			spr = false;

			if (w_na1 != 0)
			{
				w_na1--;
				sw_na1 = Convert::ToString(w_na1);
				l_w_na1->Text = "w->1 : " + sw_na1;
				licznik_osob--;
			}

			if (w_na1 == 0 && P1.empty() == false && P1.front() == 2 && licznik_osob < 8 && spr == false)
			{
				w_na2++;
				sw_na2 = Convert::ToString(w_na2);
				l_w_na2->Text = "w->2 : " + sw_na2;
				kolejnosc.push_back(2);
				i1na2--;
				s1na2 = Convert::ToString(i1na2);
				l1na2->Text = "1->2 : " + s1na2;
				P1.pop();
				licznik_osob++;
				spr = true;
			}

			if (w_na1 == 0 && P1.empty() == false && P1.front() == 3 && licznik_osob < 8 && spr == false)
			{
				w_na3++;
				sw_na3 = Convert::ToString(w_na3);
				l_w_na3->Text = "w->3 : " + sw_na3;
				kolejnosc.push_back(3);
				i1na3--;
				s1na3 = Convert::ToString(i1na3);
				l1na3->Text = "1->3 : " + s1na3;
				P1.pop();
				licznik_osob++;
				spr = true;
			}

			if (w_na1 == 0 && P1.empty() == false && P1.front() == 4 && licznik_osob < 8 && spr == false)
			{
				w_na4++;
				sw_na4 = Convert::ToString(w_na4);
				l_w_na4->Text = "w->4 : " + sw_na4;
				kolejnosc.push_back(4);
				i1na4--;
				s1na4 = Convert::ToString(i1na4);
				l1na4->Text = "1->4 : " + s1na4;
				P1.pop();
				licznik_osob++;
				spr = true;
			}

			if (w_na1 == 0 && P1.empty() == false && P1.front() == 5 && licznik_osob < 8 && spr == false)
			{
				w_na5++;
				sw_na5 = Convert::ToString(w_na5);
				l_w_na5->Text = "w->5 : " + sw_na5;
				kolejnosc.push_back(5);
				i1na5--;
				s1na5 = Convert::ToString(i1na5);
				l1na5->Text = "1->5 : " + s1na5;
				P1.pop();
				licznik_osob++;
				spr = true;
			}

			if (P1.empty() == true && w_na1 == 0)		//jesli na pietrze juz nikt nie czeka
				zakonczony = true;

			if (licznik_osob == 8 && w_na1 == 0 && P1.empty() == false)	//jesli ktos nie wsiadl to winda bo jest ona pełna to winda znowu przyjedzie na dane pietro
			{
				zakonczony = true;
				kolejnosc.push_back(1);
			}
		};



		void Pietro_2(void)
		{
			spr = false;

			if (w_na2 != 0)
			{
				w_na2--;
				sw_na2 = Convert::ToString(w_na2);
				l_w_na2->Text = "w->2 : " + sw_na2;
				licznik_osob--;
			}

			if (w_na2 == 0 && P2.empty() == false && P2.front() == 1 && licznik_osob < 8 && spr == false)
			{
				w_na1++;
				sw_na1 = Convert::ToString(w_na1);
				l_w_na1->Text = "w->1 : " + sw_na1;
				kolejnosc.push_back(1);
				i2na1--;
				s2na1 = Convert::ToString(i2na1);
				l2na1->Text = "2->1 : " + s2na1;
				P2.pop();
				licznik_osob++;
				spr = true;
			}

			if (w_na2 == 0 && P2.empty() == false && P2.front() == 3 && licznik_osob < 8 && spr == false)
			{
				w_na3++;
				sw_na3 = Convert::ToString(w_na3);
				l_w_na3->Text = "w->3 : " + sw_na3;
				kolejnosc.push_back(3);
				i2na3--;
				s2na3 = Convert::ToString(i2na3);
				l2na3->Text = "2->3 : " + s2na3;
				P2.pop();
				licznik_osob++;
				spr = true;
			}

			if (w_na2 == 0 && P2.empty() == false && P2.front() == 4 && licznik_osob < 8 && spr == false)
			{
				w_na4++;
				sw_na4 = Convert::ToString(w_na4);
				l_w_na4->Text = "w->4 : " + sw_na4;
				kolejnosc.push_back(4);
				i2na4--;
				s2na4 = Convert::ToString(i2na4);
				l2na4->Text = "2->4 : " + s2na4;
				P2.pop();
				licznik_osob++;
				spr = true;
			}

			if (w_na2 == 0 && P2.empty() == false && P2.front() == 5 && licznik_osob < 8 && spr == false)
			{
				w_na5++;
				sw_na5 = Convert::ToString(w_na5);
				l_w_na5->Text = "w->5 : " + sw_na5;
				kolejnosc.push_back(5);
				i2na5--;
				s2na5 = Convert::ToString(i2na5);
				l2na5->Text = "2->5 : " + s2na5;
				P2.pop();
				licznik_osob++;
				spr = true;
			}

			if (P2.empty() == true && w_na2 == 0)
				zakonczony = true;

			if (licznik_osob == 8 && w_na2 == 0 && P2.empty() == false)
			{
				zakonczony = true;
				kolejnosc.push_back(2);
			}
		};



		void Pietro_3(void)
		{
			spr = false;

			if (w_na3 != 0)
			{
				w_na3--;
				sw_na3 = Convert::ToString(w_na3);
				l_w_na3->Text = "w->3 : " + sw_na3;
				licznik_osob--;
			}

			if (w_na3 == 0 && P3.empty() == false && P3.front() == 1 && licznik_osob < 8 && spr == false)
			{
				w_na1++;
				sw_na1 = Convert::ToString(w_na1);
				l_w_na1->Text = "w->1 : " + sw_na1;
				kolejnosc.push_back(1);
				i3na1--;
				s3na1 = Convert::ToString(i3na1);
				l3na1->Text = "3->1 : " + s3na1;
				P3.pop();
				licznik_osob++;
				spr = true;
			}

			if (w_na3 == 0 && P3.empty() == false && P3.front() == 2 && licznik_osob < 8 && spr == false)
			{
				w_na2++;
				sw_na2 = Convert::ToString(w_na2);
				l_w_na2->Text = "w->2 : " + sw_na2;
				kolejnosc.push_back(2);
				i3na2--;
				s3na2 = Convert::ToString(i3na2);
				l3na2->Text = "3->2 : " + s3na2;
				P3.pop();
				licznik_osob++;
				spr = true;
			}

			if (w_na3 == 0 && P3.empty() == false && P3.front() == 4 && licznik_osob < 8 && spr == false)
			{
				w_na4++;
				sw_na4 = Convert::ToString(w_na4);
				l_w_na4->Text = "w->4 : " + sw_na4;
				kolejnosc.push_back(4);
				i3na4--;
				s3na4 = Convert::ToString(i3na4);
				l3na4->Text = "3->4 : " + s3na4;
				P3.pop();
				licznik_osob++;
				spr = true;
			}

			if (w_na3 == 0 && P3.empty() == false && P3.front() == 5 && licznik_osob < 8 && spr == false)
			{
				w_na5++;
				sw_na5 = Convert::ToString(w_na5);
				l_w_na5->Text = "w->5 : " + sw_na5;
				kolejnosc.push_back(5);
				i3na5--;
				s3na5 = Convert::ToString(i3na5);
				l3na5->Text = "3->5 : " + s3na5;
				P3.pop();
				licznik_osob++;
				spr = true;
			}

			if (P3.empty() == true && w_na3 == 0)
				zakonczony = true;

			if (licznik_osob == 8 && w_na3 == 0 && P3.empty() == false)
			{
				zakonczony = true;
				kolejnosc.push_back(3);
			}
		};



		void Pietro_4(void)
		{
			spr = false;

			if (w_na4 != 0)
			{
				w_na4--;
				sw_na4 = Convert::ToString(w_na4);
				l_w_na4->Text = "w->4 : " + sw_na4;
				licznik_osob--;
			}

			if (w_na4 == 0 && P4.empty() == false && P4.front() == 1 && licznik_osob < 8 && spr == false)
			{
				w_na1++;
				sw_na1 = Convert::ToString(w_na1);
				l_w_na1->Text = "w->1 : " + sw_na1;
				kolejnosc.push_back(1);
				i4na1--;
				s4na1 = Convert::ToString(i4na1);
				l4na1->Text = "4->1 : " + s4na1;
				P4.pop();
				licznik_osob++;
				spr = true;
			}

			if (w_na4 == 0 && P4.empty() == false && P4.front() == 2 && licznik_osob < 8 && spr == false)
			{
				w_na2++;
				sw_na2 = Convert::ToString(w_na2);
				l_w_na2->Text = "w->2 : " + sw_na2;
				kolejnosc.push_back(2);
				i4na2--;
				s4na2 = Convert::ToString(i4na2);
				l4na2->Text = "4->2 : " + s4na2;
				P4.pop();
				licznik_osob++;
				spr = true;
			}

			if (w_na4 == 0 && P4.empty() == false && P4.front() == 3 && licznik_osob < 8 && spr == false)
			{
				w_na3++;
				sw_na3 = Convert::ToString(w_na3);
				l_w_na3->Text = "w->3 : " + sw_na3;
				kolejnosc.push_back(3);
				i4na3--;
				s4na3 = Convert::ToString(i4na3);
				l4na3->Text = "4->3 : " + s4na3;
				P4.pop();
				licznik_osob++;
				spr = true;
			}

			if (w_na4 == 0 && P4.empty() == false && P4.front() == 5 && licznik_osob < 8 && spr == false)
			{
				w_na5++;
				sw_na5 = Convert::ToString(w_na5);
				l_w_na5->Text = "w->5 : " + sw_na5;
				kolejnosc.push_back(5);
				i4na5--;
				s4na5 = Convert::ToString(i4na5);
				l4na5->Text = "4->5 : " + s4na5;
				P4.pop();
				licznik_osob++;
				spr = true;
			}

			if (P4.empty() == true && w_na4 == 0)
				zakonczony = true;

			if (licznik_osob == 8 && w_na4 == 0 && P4.empty() == false)
			{
				zakonczony = true;
				kolejnosc.push_back(4);
			}
		};



		void Pietro_5(void)
		{
			spr = false;

			if (w_na5 != 0)
			{
				w_na5--;
				sw_na5 = Convert::ToString(w_na5);
				l_w_na5->Text = "w->5 : " + sw_na5;
				licznik_osob--;
			}

			if (w_na5 == 0 && P5.empty() == false && P5.front() == 1 && licznik_osob < 8 && spr == false)
			{
				w_na1++;
				sw_na1 = Convert::ToString(w_na1);
				l_w_na1->Text = "w->1 : " + sw_na1;
				kolejnosc.push_back(1);
				i5na1--;
				s5na1 = Convert::ToString(i5na1);
				l5na1->Text = "5->1 : " + s5na1;
				P5.pop();
				licznik_osob++;
				spr = true;
			}

			if (w_na5 == 0 && P5.empty() == false && P5.front() == 2 && licznik_osob < 8 && spr == false)
			{
				w_na2++;
				sw_na2 = Convert::ToString(w_na2);
				l_w_na2->Text = "w->2 : " + sw_na2;
				kolejnosc.push_back(2);
				i5na2--;
				s5na2 = Convert::ToString(i5na2);
				l5na2->Text = "5->2 : " + s5na2;
				P5.pop();
				licznik_osob++;
				spr = true;
			}

			if (w_na5 == 0 && P5.empty() == false && P5.front() == 3 && licznik_osob < 8 && spr == false)
			{
				w_na3++;
				sw_na3 = Convert::ToString(w_na3);
				l_w_na3->Text = "w->3 : " + sw_na3;
				kolejnosc.push_back(3);
				i5na3--;
				s5na3 = Convert::ToString(i5na3);
				l5na3->Text = "5->3 : " + s5na3;
				P5.pop();
				licznik_osob++;
				spr = true;
			}

			if (w_na5 == 0 && P5.empty() == false && P5.front() == 4 && licznik_osob < 8 && spr == false)
			{
				w_na4++;
				sw_na4 = Convert::ToString(sw_na4);
				l_w_na4->Text = "w->4 : " + w_na4;
				kolejnosc.push_back(4);
				i5na4--;
				s5na4 = Convert::ToString(i5na4);
				l5na4->Text = "5->4 : " + s5na4;
				P5.pop();
				licznik_osob++;
				spr = true;
			}

			if (P5.empty() == true && w_na5 == 0)
				zakonczony = true;

			if (licznik_osob == 8 && w_na5 == 0 && P5.empty() == false)
			{
				zakonczony = true;
				kolejnosc.push_back(5);
			}
		};

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;


	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->b1na2 = (gcnew System::Windows::Forms::Button());
			this->b2na3 = (gcnew System::Windows::Forms::Button());
			this->b3na2 = (gcnew System::Windows::Forms::Button());
			this->b4na2 = (gcnew System::Windows::Forms::Button());
			this->b5na2 = (gcnew System::Windows::Forms::Button());
			this->b1na3 = (gcnew System::Windows::Forms::Button());
			this->b4na3 = (gcnew System::Windows::Forms::Button());
			this->b5na3 = (gcnew System::Windows::Forms::Button());
			this->b2na1 = (gcnew System::Windows::Forms::Button());
			this->b3na1 = (gcnew System::Windows::Forms::Button());
			this->b4na1 = (gcnew System::Windows::Forms::Button());
			this->b5na1 = (gcnew System::Windows::Forms::Button());
			this->b5na4 = (gcnew System::Windows::Forms::Button());
			this->b3na4 = (gcnew System::Windows::Forms::Button());
			this->b2na4 = (gcnew System::Windows::Forms::Button());
			this->b1na4 = (gcnew System::Windows::Forms::Button());
			this->b4na5 = (gcnew System::Windows::Forms::Button());
			this->b3na5 = (gcnew System::Windows::Forms::Button());
			this->b2na5 = (gcnew System::Windows::Forms::Button());
			this->b1na5 = (gcnew System::Windows::Forms::Button());
			this->l1na2 = (gcnew System::Windows::Forms::Label());
			this->l1na3 = (gcnew System::Windows::Forms::Label());
			this->l1na4 = (gcnew System::Windows::Forms::Label());
			this->l1na5 = (gcnew System::Windows::Forms::Label());
			this->l2na1 = (gcnew System::Windows::Forms::Label());
			this->l2na3 = (gcnew System::Windows::Forms::Label());
			this->l2na4 = (gcnew System::Windows::Forms::Label());
			this->l2na5 = (gcnew System::Windows::Forms::Label());
			this->l3na1 = (gcnew System::Windows::Forms::Label());
			this->l3na2 = (gcnew System::Windows::Forms::Label());
			this->l3na4 = (gcnew System::Windows::Forms::Label());
			this->l3na5 = (gcnew System::Windows::Forms::Label());
			this->l4na1 = (gcnew System::Windows::Forms::Label());
			this->l4na2 = (gcnew System::Windows::Forms::Label());
			this->l4na3 = (gcnew System::Windows::Forms::Label());
			this->l4na5 = (gcnew System::Windows::Forms::Label());
			this->l5na1 = (gcnew System::Windows::Forms::Label());
			this->l5na2 = (gcnew System::Windows::Forms::Label());
			this->l5na3 = (gcnew System::Windows::Forms::Label());
			this->l5na4 = (gcnew System::Windows::Forms::Label());
			this->l_w_na1 = (gcnew System::Windows::Forms::Label());
			this->l_w_na2 = (gcnew System::Windows::Forms::Label());
			this->l_w_na3 = (gcnew System::Windows::Forms::Label());
			this->l_w_na4 = (gcnew System::Windows::Forms::Label());
			this->l_w_na5 = (gcnew System::Windows::Forms::Label());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->l_obciazenie = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(3, 8);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1305, 610);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(288, 510);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(242, 72);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 20;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(92, 455);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(79, 20);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Piętro 1";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(633, 350);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(79, 20);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Piętro 2";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(92, 244);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 20);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Piętro 3";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(633, 129);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(79, 20);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Piętro 4";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(92, 53);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(79, 20);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Piętro 5";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// b1na2
			// 
			this->b1na2->Location = System::Drawing::Point(37, 514);
			this->b1na2->Name = L"b1na2";
			this->b1na2->Size = System::Drawing::Size(21, 26);
			this->b1na2->TabIndex = 10;
			this->b1na2->Text = L"2";
			this->b1na2->UseVisualStyleBackColor = true;
			this->b1na2->Click += gcnew System::EventHandler(this, &MyForm::b1na2_Click);
			// 
			// b2na3
			// 
			this->b2na3->Location = System::Drawing::Point(784, 368);
			this->b2na3->Name = L"b2na3";
			this->b2na3->Size = System::Drawing::Size(21, 26);
			this->b2na3->TabIndex = 11;
			this->b2na3->Text = L"3";
			this->b2na3->UseVisualStyleBackColor = true;
			this->b2na3->Click += gcnew System::EventHandler(this, &MyForm::b2na3_Click);
			// 
			// b3na2
			// 
			this->b3na2->Location = System::Drawing::Point(35, 265);
			this->b3na2->Name = L"b3na2";
			this->b3na2->Size = System::Drawing::Size(21, 26);
			this->b3na2->TabIndex = 12;
			this->b3na2->Text = L"2";
			this->b3na2->UseVisualStyleBackColor = true;
			this->b3na2->Click += gcnew System::EventHandler(this, &MyForm::b3na2_Click);
			// 
			// b4na2
			// 
			this->b4na2->Location = System::Drawing::Point(785, 156);
			this->b4na2->Name = L"b4na2";
			this->b4na2->Size = System::Drawing::Size(21, 26);
			this->b4na2->TabIndex = 13;
			this->b4na2->Text = L"2";
			this->b4na2->UseVisualStyleBackColor = true;
			this->b4na2->Click += gcnew System::EventHandler(this, &MyForm::b4na2_Click);
			// 
			// b5na2
			// 
			this->b5na2->Location = System::Drawing::Point(37, 87);
			this->b5na2->Name = L"b5na2";
			this->b5na2->Size = System::Drawing::Size(21, 26);
			this->b5na2->TabIndex = 14;
			this->b5na2->Text = L"2";
			this->b5na2->UseVisualStyleBackColor = true;
			this->b5na2->Click += gcnew System::EventHandler(this, &MyForm::b5na2_Click);
			// 
			// b1na3
			// 
			this->b1na3->Location = System::Drawing::Point(37, 482);
			this->b1na3->Name = L"b1na3";
			this->b1na3->Size = System::Drawing::Size(21, 26);
			this->b1na3->TabIndex = 15;
			this->b1na3->Text = L"3";
			this->b1na3->UseVisualStyleBackColor = true;
			this->b1na3->Click += gcnew System::EventHandler(this, &MyForm::b1na3_Click);
			// 
			// b4na3
			// 
			this->b4na3->Location = System::Drawing::Point(784, 124);
			this->b4na3->Name = L"b4na3";
			this->b4na3->Size = System::Drawing::Size(21, 26);
			this->b4na3->TabIndex = 16;
			this->b4na3->Text = L"3";
			this->b4na3->UseVisualStyleBackColor = true;
			this->b4na3->Click += gcnew System::EventHandler(this, &MyForm::b4na3_Click);
			// 
			// b5na3
			// 
			this->b5na3->Location = System::Drawing::Point(37, 55);
			this->b5na3->Name = L"b5na3";
			this->b5na3->Size = System::Drawing::Size(21, 26);
			this->b5na3->TabIndex = 17;
			this->b5na3->Text = L"3";
			this->b5na3->UseVisualStyleBackColor = true;
			this->b5na3->Click += gcnew System::EventHandler(this, &MyForm::b5na3_Click);
			// 
			// b2na1
			// 
			this->b2na1->Location = System::Drawing::Point(784, 400);
			this->b2na1->Name = L"b2na1";
			this->b2na1->Size = System::Drawing::Size(20, 23);
			this->b2na1->TabIndex = 18;
			this->b2na1->Text = L"1";
			this->b2na1->UseVisualStyleBackColor = true;
			this->b2na1->Click += gcnew System::EventHandler(this, &MyForm::b2na1_Click);
			// 
			// b3na1
			// 
			this->b3na1->Location = System::Drawing::Point(35, 297);
			this->b3na1->Name = L"b3na1";
			this->b3na1->Size = System::Drawing::Size(20, 23);
			this->b3na1->TabIndex = 19;
			this->b3na1->Text = L"1";
			this->b3na1->UseVisualStyleBackColor = true;
			this->b3na1->Click += gcnew System::EventHandler(this, &MyForm::b3na1_Click);
			// 
			// b4na1
			// 
			this->b4na1->Location = System::Drawing::Point(785, 188);
			this->b4na1->Name = L"b4na1";
			this->b4na1->Size = System::Drawing::Size(20, 23);
			this->b4na1->TabIndex = 20;
			this->b4na1->Text = L"1";
			this->b4na1->UseVisualStyleBackColor = true;
			this->b4na1->Click += gcnew System::EventHandler(this, &MyForm::b4na1_Click);
			// 
			// b5na1
			// 
			this->b5na1->Location = System::Drawing::Point(38, 119);
			this->b5na1->Name = L"b5na1";
			this->b5na1->Size = System::Drawing::Size(20, 23);
			this->b5na1->TabIndex = 21;
			this->b5na1->Text = L"1";
			this->b5na1->UseVisualStyleBackColor = true;
			this->b5na1->Click += gcnew System::EventHandler(this, &MyForm::b5na1_Click);
			// 
			// b5na4
			// 
			this->b5na4->Location = System::Drawing::Point(37, 26);
			this->b5na4->Name = L"b5na4";
			this->b5na4->Size = System::Drawing::Size(20, 23);
			this->b5na4->TabIndex = 22;
			this->b5na4->Text = L"4";
			this->b5na4->UseVisualStyleBackColor = true;
			this->b5na4->Click += gcnew System::EventHandler(this, &MyForm::b5na4_Click);
			// 
			// b3na4
			// 
			this->b3na4->Location = System::Drawing::Point(36, 236);
			this->b3na4->Name = L"b3na4";
			this->b3na4->Size = System::Drawing::Size(20, 23);
			this->b3na4->TabIndex = 23;
			this->b3na4->Text = L"4";
			this->b3na4->UseVisualStyleBackColor = true;
			this->b3na4->Click += gcnew System::EventHandler(this, &MyForm::b3na4_Click);
			// 
			// b2na4
			// 
			this->b2na4->Location = System::Drawing::Point(785, 339);
			this->b2na4->Name = L"b2na4";
			this->b2na4->Size = System::Drawing::Size(20, 23);
			this->b2na4->TabIndex = 24;
			this->b2na4->Text = L"4";
			this->b2na4->UseVisualStyleBackColor = true;
			this->b2na4->Click += gcnew System::EventHandler(this, &MyForm::b2na4_Click);
			// 
			// b1na4
			// 
			this->b1na4->Location = System::Drawing::Point(37, 453);
			this->b1na4->Name = L"b1na4";
			this->b1na4->Size = System::Drawing::Size(20, 23);
			this->b1na4->TabIndex = 25;
			this->b1na4->Text = L"4";
			this->b1na4->UseVisualStyleBackColor = true;
			this->b1na4->Click += gcnew System::EventHandler(this, &MyForm::b1na4_Click);
			// 
			// b4na5
			// 
			this->b4na5->Location = System::Drawing::Point(784, 92);
			this->b4na5->Name = L"b4na5";
			this->b4na5->Size = System::Drawing::Size(21, 26);
			this->b4na5->TabIndex = 26;
			this->b4na5->Text = L"5";
			this->b4na5->UseVisualStyleBackColor = true;
			this->b4na5->Click += gcnew System::EventHandler(this, &MyForm::b4na5_Click);
			// 
			// b3na5
			// 
			this->b3na5->Location = System::Drawing::Point(36, 204);
			this->b3na5->Name = L"b3na5";
			this->b3na5->Size = System::Drawing::Size(21, 26);
			this->b3na5->TabIndex = 27;
			this->b3na5->Text = L"5";
			this->b3na5->UseVisualStyleBackColor = true;
			this->b3na5->Click += gcnew System::EventHandler(this, &MyForm::b3na5_Click);
			// 
			// b2na5
			// 
			this->b2na5->Location = System::Drawing::Point(784, 307);
			this->b2na5->Name = L"b2na5";
			this->b2na5->Size = System::Drawing::Size(21, 26);
			this->b2na5->TabIndex = 28;
			this->b2na5->Text = L"5";
			this->b2na5->UseVisualStyleBackColor = true;
			this->b2na5->Click += gcnew System::EventHandler(this, &MyForm::b2na5_Click);
			// 
			// b1na5
			// 
			this->b1na5->Location = System::Drawing::Point(36, 421);
			this->b1na5->Name = L"b1na5";
			this->b1na5->Size = System::Drawing::Size(21, 26);
			this->b1na5->TabIndex = 29;
			this->b1na5->Text = L"5";
			this->b1na5->UseVisualStyleBackColor = true;
			this->b1na5->Click += gcnew System::EventHandler(this, &MyForm::b1na5_Click);
			// 
			// l1na2
			// 
			this->l1na2->AutoSize = true;
			this->l1na2->Location = System::Drawing::Point(202, 527);
			this->l1na2->Name = L"l1na2";
			this->l1na2->Size = System::Drawing::Size(43, 13);
			this->l1na2->TabIndex = 30;
			this->l1na2->Text = L"1->2 : 0";
			// 
			// l1na3
			// 
			this->l1na3->AutoSize = true;
			this->l1na3->Location = System::Drawing::Point(202, 495);
			this->l1na3->Name = L"l1na3";
			this->l1na3->Size = System::Drawing::Size(43, 13);
			this->l1na3->TabIndex = 31;
			this->l1na3->Text = L"1->3 : 0";
			// 
			// l1na4
			// 
			this->l1na4->AutoSize = true;
			this->l1na4->Location = System::Drawing::Point(202, 463);
			this->l1na4->Name = L"l1na4";
			this->l1na4->Size = System::Drawing::Size(43, 13);
			this->l1na4->TabIndex = 32;
			this->l1na4->Text = L"1->4 : 0";
			// 
			// l1na5
			// 
			this->l1na5->AutoSize = true;
			this->l1na5->Location = System::Drawing::Point(202, 434);
			this->l1na5->Name = L"l1na5";
			this->l1na5->Size = System::Drawing::Size(43, 13);
			this->l1na5->TabIndex = 33;
			this->l1na5->Text = L"1->5 : 0";
			// 
			// l2na1
			// 
			this->l2na1->AutoSize = true;
			this->l2na1->Location = System::Drawing::Point(569, 410);
			this->l2na1->Name = L"l2na1";
			this->l2na1->Size = System::Drawing::Size(43, 13);
			this->l2na1->TabIndex = 34;
			this->l2na1->Text = L"2->1 : 0";
			// 
			// l2na3
			// 
			this->l2na3->AutoSize = true;
			this->l2na3->Location = System::Drawing::Point(569, 381);
			this->l2na3->Name = L"l2na3";
			this->l2na3->Size = System::Drawing::Size(43, 13);
			this->l2na3->TabIndex = 35;
			this->l2na3->Text = L"2->3 : 0";
			// 
			// l2na4
			// 
			this->l2na4->AutoSize = true;
			this->l2na4->Location = System::Drawing::Point(569, 349);
			this->l2na4->Name = L"l2na4";
			this->l2na4->Size = System::Drawing::Size(43, 13);
			this->l2na4->TabIndex = 36;
			this->l2na4->Text = L"2->4 : 0";
			// 
			// l2na5
			// 
			this->l2na5->AutoSize = true;
			this->l2na5->Location = System::Drawing::Point(569, 320);
			this->l2na5->Name = L"l2na5";
			this->l2na5->Size = System::Drawing::Size(43, 13);
			this->l2na5->TabIndex = 37;
			this->l2na5->Text = L"2->5 : 0";
			// 
			// l3na1
			// 
			this->l3na1->AutoSize = true;
			this->l3na1->Location = System::Drawing::Point(202, 307);
			this->l3na1->Name = L"l3na1";
			this->l3na1->Size = System::Drawing::Size(43, 13);
			this->l3na1->TabIndex = 38;
			this->l3na1->Text = L"3->1 : 0";
			// 
			// l3na2
			// 
			this->l3na2->AutoSize = true;
			this->l3na2->Location = System::Drawing::Point(202, 278);
			this->l3na2->Name = L"l3na2";
			this->l3na2->Size = System::Drawing::Size(43, 13);
			this->l3na2->TabIndex = 39;
			this->l3na2->Text = L"3->2 : 0";
			// 
			// l3na4
			// 
			this->l3na4->AutoSize = true;
			this->l3na4->Location = System::Drawing::Point(202, 246);
			this->l3na4->Name = L"l3na4";
			this->l3na4->Size = System::Drawing::Size(43, 13);
			this->l3na4->TabIndex = 40;
			this->l3na4->Text = L"3->4 : 0";
			// 
			// l3na5
			// 
			this->l3na5->AutoSize = true;
			this->l3na5->Location = System::Drawing::Point(202, 217);
			this->l3na5->Name = L"l3na5";
			this->l3na5->Size = System::Drawing::Size(43, 13);
			this->l3na5->TabIndex = 41;
			this->l3na5->Text = L"3->5 : 0";
			// 
			// l4na1
			// 
			this->l4na1->AutoSize = true;
			this->l4na1->Location = System::Drawing::Point(569, 198);
			this->l4na1->Name = L"l4na1";
			this->l4na1->Size = System::Drawing::Size(43, 13);
			this->l4na1->TabIndex = 42;
			this->l4na1->Text = L"4->1 : 0";
			// 
			// l4na2
			// 
			this->l4na2->AutoSize = true;
			this->l4na2->Location = System::Drawing::Point(569, 169);
			this->l4na2->Name = L"l4na2";
			this->l4na2->Size = System::Drawing::Size(43, 13);
			this->l4na2->TabIndex = 43;
			this->l4na2->Text = L"4->2 : 0";
			// 
			// l4na3
			// 
			this->l4na3->AutoSize = true;
			this->l4na3->Location = System::Drawing::Point(569, 137);
			this->l4na3->Name = L"l4na3";
			this->l4na3->Size = System::Drawing::Size(43, 13);
			this->l4na3->TabIndex = 44;
			this->l4na3->Text = L"4->3 : 0";
			// 
			// l4na5
			// 
			this->l4na5->AutoSize = true;
			this->l4na5->Location = System::Drawing::Point(569, 105);
			this->l4na5->Name = L"l4na5";
			this->l4na5->Size = System::Drawing::Size(43, 13);
			this->l4na5->TabIndex = 45;
			this->l4na5->Text = L"4->5 : 0";
			// 
			// l5na1
			// 
			this->l5na1->AutoSize = true;
			this->l5na1->Location = System::Drawing::Point(202, 129);
			this->l5na1->Name = L"l5na1";
			this->l5na1->Size = System::Drawing::Size(43, 13);
			this->l5na1->TabIndex = 46;
			this->l5na1->Text = L"5->1 : 0";
			// 
			// l5na2
			// 
			this->l5na2->AutoSize = true;
			this->l5na2->Location = System::Drawing::Point(202, 100);
			this->l5na2->Name = L"l5na2";
			this->l5na2->Size = System::Drawing::Size(43, 13);
			this->l5na2->TabIndex = 47;
			this->l5na2->Text = L"5->2 : 0";
			// 
			// l5na3
			// 
			this->l5na3->AutoSize = true;
			this->l5na3->Location = System::Drawing::Point(202, 68);
			this->l5na3->Name = L"l5na3";
			this->l5na3->Size = System::Drawing::Size(43, 13);
			this->l5na3->TabIndex = 48;
			this->l5na3->Text = L"5->3 : 0";
			// 
			// l5na4
			// 
			this->l5na4->AutoSize = true;
			this->l5na4->Location = System::Drawing::Point(202, 36);
			this->l5na4->Name = L"l5na4";
			this->l5na4->Size = System::Drawing::Size(43, 13);
			this->l5na4->TabIndex = 49;
			this->l5na4->Text = L"5->4 : 0";
			// 
			// l_w_na1
			// 
			this->l_w_na1->AutoSize = true;
			this->l_w_na1->Location = System::Drawing::Point(285, 26);
			this->l_w_na1->Name = L"l_w_na1";
			this->l_w_na1->Size = System::Drawing::Size(45, 13);
			this->l_w_na1->TabIndex = 50;
			this->l_w_na1->Text = L"w->1 : 0";
			// 
			// l_w_na2
			// 
			this->l_w_na2->AutoSize = true;
			this->l_w_na2->Location = System::Drawing::Point(336, 26);
			this->l_w_na2->Name = L"l_w_na2";
			this->l_w_na2->Size = System::Drawing::Size(45, 13);
			this->l_w_na2->TabIndex = 51;
			this->l_w_na2->Text = L"w->2 : 0";
			// 
			// l_w_na3
			// 
			this->l_w_na3->AutoSize = true;
			this->l_w_na3->Location = System::Drawing::Point(387, 26);
			this->l_w_na3->Name = L"l_w_na3";
			this->l_w_na3->Size = System::Drawing::Size(45, 13);
			this->l_w_na3->TabIndex = 52;
			this->l_w_na3->Text = L"w->3 : 0";
			// 
			// l_w_na4
			// 
			this->l_w_na4->AutoSize = true;
			this->l_w_na4->Location = System::Drawing::Point(438, 26);
			this->l_w_na4->Name = L"l_w_na4";
			this->l_w_na4->Size = System::Drawing::Size(45, 13);
			this->l_w_na4->TabIndex = 53;
			this->l_w_na4->Text = L"w->4 : 0";
			// 
			// l_w_na5
			// 
			this->l_w_na5->AutoSize = true;
			this->l_w_na5->Location = System::Drawing::Point(489, 26);
			this->l_w_na5->Name = L"l_w_na5";
			this->l_w_na5->Size = System::Drawing::Size(45, 13);
			this->l_w_na5->TabIndex = 54;
			this->l_w_na5->Text = L"w->5 : 0";
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 200;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// timer3
			// 
			this->timer3->Enabled = true;
			this->timer3->Interval = 1000;
			this->timer3->Tick += gcnew System::EventHandler(this, &MyForm::timer3_Tick);
			// 
			// l_obciazenie
			// 
			this->l_obciazenie->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->l_obciazenie->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->l_obciazenie->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->l_obciazenie->Location = System::Drawing::Point(588, 26);
			this->l_obciazenie->Name = L"l_obciazenie";
			this->l_obciazenie->Size = System::Drawing::Size(141, 45);
			this->l_obciazenie->TabIndex = 55;
			this->l_obciazenie->Text = L"Obciążenie : 0 ";
			this->l_obciazenie->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1308, 620);
			this->Controls->Add(this->l_obciazenie);
			this->Controls->Add(this->l_w_na5);
			this->Controls->Add(this->l_w_na4);
			this->Controls->Add(this->l_w_na3);
			this->Controls->Add(this->l_w_na2);
			this->Controls->Add(this->l_w_na1);
			this->Controls->Add(this->l5na4);
			this->Controls->Add(this->l5na3);
			this->Controls->Add(this->l5na2);
			this->Controls->Add(this->l5na1);
			this->Controls->Add(this->l4na5);
			this->Controls->Add(this->l4na3);
			this->Controls->Add(this->l4na2);
			this->Controls->Add(this->l4na1);
			this->Controls->Add(this->l3na5);
			this->Controls->Add(this->l3na4);
			this->Controls->Add(this->l3na2);
			this->Controls->Add(this->l3na1);
			this->Controls->Add(this->l2na5);
			this->Controls->Add(this->l2na4);
			this->Controls->Add(this->l2na3);
			this->Controls->Add(this->l2na1);
			this->Controls->Add(this->l1na5);
			this->Controls->Add(this->l1na4);
			this->Controls->Add(this->l1na3);
			this->Controls->Add(this->l1na2);
			this->Controls->Add(this->b1na5);
			this->Controls->Add(this->b2na5);
			this->Controls->Add(this->b3na5);
			this->Controls->Add(this->b4na5);
			this->Controls->Add(this->b1na4);
			this->Controls->Add(this->b2na4);
			this->Controls->Add(this->b3na4);
			this->Controls->Add(this->b5na4);
			this->Controls->Add(this->b5na1);
			this->Controls->Add(this->b4na1);
			this->Controls->Add(this->b3na1);
			this->Controls->Add(this->b2na1);
			this->Controls->Add(this->b5na3);
			this->Controls->Add(this->b4na3);
			this->Controls->Add(this->b1na3);
			this->Controls->Add(this->b5na2);
			this->Controls->Add(this->b4na2);
			this->Controls->Add(this->b3na2);
			this->Controls->Add(this->b2na3);
			this->Controls->Add(this->b1na2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)		//zegar działa cały czas i na każdy tick aktualizuje wekor kolejnosci jazdy dla windy i cel jazdy windy, a także obsługuje samo poruszanie się windy. Zatrzymuje się tylko na symboliczny czas kiedy ludzie "wsiadają" do windy, potem jest ponownie odpalany przez timer2
	{
		timer2->Stop();
		//czyszczenie niepotrzebnych pieter w kolejce 
		if (kolejnosc.size() != 0 && kolejnosc[0] == 1 && P1.empty() == true && w_na1 == 0)
			kolejnosc.erase(kolejnosc.begin());
		else if (kolejnosc.size() != 0 && kolejnosc[0] == 2 && P2.empty() == true && w_na2 == 0)
			kolejnosc.erase(kolejnosc.begin());
		else if (kolejnosc.size() != 0 && kolejnosc[0] == 3 && P3.empty() == true && w_na3 == 0)
			kolejnosc.erase(kolejnosc.begin());
		else if (kolejnosc.size() != 0 && kolejnosc[0] == 4 && P4.empty() == true && w_na4 == 0)
			kolejnosc.erase(kolejnosc.begin());
		else if (kolejnosc.size() != 0 && kolejnosc[0] == 5 && P5.empty() == true && w_na5 == 0)
			kolejnosc.erase(kolejnosc.begin());
		else if (kolejnosc.size() != 0)		//wytyczenie celu windy na podstawie pierwszego elementu kolejnosci
			cel_windy = 610 - 100 * kolejnosc[0];

		if (pozycja_windy != cel_windy)	//wyznaczenie kierunku jazdy windy
		{
			timer3->Stop();
			bezczynnosc = 0;

			if (pozycja_windy > cel_windy)
				kierunek = 1;
			if (pozycja_windy < cel_windy)
				kierunek = -1;
			//poruszanie się windy
			pozycja_windy -= 2 * kierunek;
			this->pictureBox2->Location = System::Drawing::Point(288, pozycja_windy);
		}
		if (pozycja_windy == cel_windy && kolejnosc.size() != 0)		//kiedy winda dojeżdża i w wektorze dalej coś jest
		{
			timer3->Stop();
			bezczynnosc = 0;
			//kolejka tworzy sie tak że na wciśnięcie guzika, dane piętro gdzie został wciśnięty guzik zostaje dodane do kolejki i potem jak winda dojeżdża na dane piętro to w funkcji Przesiadka wsiadajacy ludzie dodaja swoje pietra do kolejki
			a = kolejnosc[0];
			b = 1;
			c = 0;
			while (b <= licznik_osob && kolejnosc.size() != 0 && b <= kolejnosc.size()) //usuwanie powtórzeń tego samego piętra ludzi w windzie  
			{
				if (kolejnosc[c] == a)
				{
					kolejnosc.erase(kolejnosc.begin() + c);
				}
				else
					c++;
				b++;
			}
			timer1->Stop();
			timer2->Start();	//podczas działania timer2 odbywa się wsiadanie i wysiadanie pasażerów
		}

		//timer odmierzający 5 sec bezczynności po których winda ma zjechać na parter
		if (pozycja_windy == cel_windy && kolejnosc.size() == 0)
		{
			timer3->Start();
		}

	}

	private: System::Void b1na2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i1na2++;
		s1na2 = Convert::ToString(i1na2);
		l1na2->Text = "1->2 : " + s1na2;
		kolejnosc.push_back(1);
		P1.push(2);
	}

	private: System::Void b2na3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i2na3++;
		s2na3 = Convert::ToString(i2na3);
		l2na3->Text = "2->3 : " + s2na3;
		kolejnosc.push_back(2);
		P2.push(3);
	}
	private: System::Void b3na2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i3na2++;
		s3na2 = Convert::ToString(i3na2);
		l3na2->Text = "3->2 : " + s3na2;
		kolejnosc.push_back(3);
		P3.push(2);
	}
	private: System::Void b4na2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i4na2++;
		s4na2 = Convert::ToString(i4na2);
		l4na2->Text = "4->2 : " + s4na2;
		kolejnosc.push_back(4);
		P4.push(2);
	}
	private: System::Void b5na2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i5na2++;
		s5na2 = Convert::ToString(i5na2);
		l5na2->Text = "5->2 : " + s5na2;
		kolejnosc.push_back(5);
		P5.push(2);
	}

	private: System::Void b1na3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i1na3++;
		s1na3 = Convert::ToString(i1na3);
		l1na3->Text = "1->3 : " + s1na3;
		kolejnosc.push_back(1);
		P1.push(3);
	}
	private: System::Void b4na3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i4na3++;
		s4na3 = Convert::ToString(i4na3);
		l4na3->Text = "4->3 : " + s4na3;
		kolejnosc.push_back(4);
		P4.push(3);
	}
	private: System::Void b5na3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i5na3++;
		s5na3 = Convert::ToString(i5na3);
		l5na3->Text = "5->3 : " + s5na3;
		kolejnosc.push_back(5);
		P5.push(3);
	}

	private: System::Void b2na1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i2na1++;
		s2na1 = Convert::ToString(i2na1);
		l2na1->Text = "2->1 : " + s2na1;
		kolejnosc.push_back(2);
		P2.push(1);
	}
	private: System::Void b3na1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i3na1++;
		s3na1 = Convert::ToString(i3na1);
		l3na1->Text = "3->1 : " + s3na1;
		kolejnosc.push_back(3);
		P3.push(1);
	}
	private: System::Void b4na1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i4na1++;
		s4na1 = Convert::ToString(i4na1);
		l4na1->Text = "4->1 : " + s4na1;
		kolejnosc.push_back(4);
		P4.push(1);
	}
	private: System::Void b5na1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i5na1++;
		s5na1 = Convert::ToString(i5na1);
		l5na1->Text = "5->1 : " + s5na1;
		kolejnosc.push_back(5);
		P5.push(1);
	}

	private: System::Void b5na4_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i5na4++;
		s5na4 = Convert::ToString(i5na4);
		l5na4->Text = "5->4 : " + s5na4;
		kolejnosc.push_back(5);
		P5.push(4);
	}
	private: System::Void b3na4_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i3na4++;
		s3na4 = Convert::ToString(i3na4);
		l3na4->Text = "3->4 : " + s3na4;
		kolejnosc.push_back(3);
		P3.push(4);
	}
	private: System::Void b2na4_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i2na4++;
		s2na4 = Convert::ToString(i2na4);
		l2na4->Text = "2->4 : " + s2na4;
		kolejnosc.push_back(2);
		P2.push(4);
	}
	private: System::Void b1na4_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i1na4++;
		s1na4 = Convert::ToString(i1na4);
		l1na4->Text = "1->4 : " + s1na4;
		kolejnosc.push_back(1);
		P1.push(4);
	}

	private: System::Void b4na5_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i4na5++;
		s4na5 = Convert::ToString(i4na5);
		l4na5->Text = "4->5 : " + s4na5;
		kolejnosc.push_back(4);
		P4.push(5);
	}
	private: System::Void b3na5_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i3na5++;
		s3na5 = Convert::ToString(i3na5);
		l3na5->Text = "3->5 : " + s3na5;
		kolejnosc.push_back(3);
		P3.push(5);
	}
	private: System::Void b2na5_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i2na5++;
		s2na5 = Convert::ToString(i2na5);
		l2na5->Text = "2->5 : " + s2na5;
		kolejnosc.push_back(2);
		P2.push(5);
	}
	private: System::Void b1na5_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i1na5++;
		s1na5 = Convert::ToString(i1na5);
		l1na5->Text = "1->5 : " + s1na5;
		kolejnosc.push_back(1);
		P1.push(5);
	}

			 //timer sprawiajacy ze pasazerowie wsiadaja pojedynczo i po kolei
	private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		if (zakonczony == true)		//wszyscy wysiedli, wsiedli albo nie ma już miejsca
		{
			zakonczony = false;
			timer1->Start();
			timer2->Stop();
		}
		else Przesiadka(cel_windy);	//Wsiadanie ludzi: zmienianie danych na labelach i dodawanie wybranych przez ludzi pięter do wektora
	}
	private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e)		//naliczanie 5 sec bezczynności po których winda ma zjechać na najniższe piętro
	{
		bezczynnosc++;

		if (bezczynnosc == 5)
		{
			cel_windy = 510;
			timer3->Stop();
			bezczynnosc == 0;
		}
	}
	};
}