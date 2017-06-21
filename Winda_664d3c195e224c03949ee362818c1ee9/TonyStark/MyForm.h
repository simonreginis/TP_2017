#pragma once
#include <cstdlib>;
#include <windows.h>;
 
//HELLO WOOOORRRLLLDDDD
namespace TonyStark {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

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
	protected:
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Timer^  timer1;





	private: System::Windows::Forms::Button^  pietro1;

	private: System::Windows::Forms::Button^  PRZYCISK4;
	private: System::Windows::Forms::Button^  PIETRO3;
	private: System::Windows::Forms::Button^  BUTTON2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::PictureBox^  pictureBox3;



	private: System::ComponentModel::IContainer^  components;

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
			this->pietro1 = (gcnew System::Windows::Forms::Button());
			this->PRZYCISK4 = (gcnew System::Windows::Forms::Button());
			this->PIETRO3 = (gcnew System::Windows::Forms::Button());
			this->BUTTON2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(323, 398);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(160, 140);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(707, 300);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(80, 100);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Visible = false;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 15;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// pietro1
			// 
			this->pietro1->Location = System::Drawing::Point(12, 430);
			this->pietro1->Name = L"pietro1";
			this->pietro1->Size = System::Drawing::Size(57, 32);
			this->pietro1->TabIndex = 5;
			this->pietro1->Text = L"1 -> 2";
			this->pietro1->UseVisualStyleBackColor = true;
			this->pietro1->Click += gcnew System::EventHandler(this, &MyForm::pietro1_Click);
			// 
			// PRZYCISK4
			// 
			this->PRZYCISK4->Location = System::Drawing::Point(725, 31);
			this->PRZYCISK4->Name = L"PRZYCISK4";
			this->PRZYCISK4->Size = System::Drawing::Size(62, 36);
			this->PRZYCISK4->TabIndex = 7;
			this->PRZYCISK4->Text = L"4 -> 1";
			this->PRZYCISK4->UseVisualStyleBackColor = true;
			this->PRZYCISK4->Click += gcnew System::EventHandler(this, &MyForm::PRZYCISK4_Click);
			// 
			// PIETRO3
			// 
			this->PIETRO3->Location = System::Drawing::Point(12, 156);
			this->PIETRO3->Name = L"PIETRO3";
			this->PIETRO3->Size = System::Drawing::Size(57, 35);
			this->PIETRO3->TabIndex = 8;
			this->PIETRO3->Text = L"3 -> 1";
			this->PIETRO3->UseVisualStyleBackColor = true;
			this->PIETRO3->Click += gcnew System::EventHandler(this, &MyForm::PIETRO3_Click_1);
			// 
			// BUTTON2
			// 
			this->BUTTON2->Location = System::Drawing::Point(727, 276);
			this->BUTTON2->Name = L"BUTTON2";
			this->BUTTON2->Size = System::Drawing::Size(60, 33);
			this->BUTTON2->TabIndex = 9;
			this->BUTTON2->Text = L"2 -> 1";
			this->BUTTON2->UseVisualStyleBackColor = true;
			this->BUTTON2->Click += gcnew System::EventHandler(this, &MyForm::BUTTON2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 468);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(57, 32);
			this->button1->TabIndex = 10;
			this->button1->Text = L"1 -> 3";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(12, 506);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(57, 32);
			this->button3->TabIndex = 11;
			this->button3->Text = L"1 -> 4";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(727, 315);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(60, 33);
			this->button4->TabIndex = 12;
			this->button4->Text = L"2 -> 3";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(727, 354);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(60, 33);
			this->button5->TabIndex = 13;
			this->button5->Text = L"2 -> 4";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(12, 238);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(57, 35);
			this->button6->TabIndex = 14;
			this->button6->Text = L"3 -> 4";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(12, 197);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(57, 35);
			this->button7->TabIndex = 15;
			this->button7->Text = L"3 -> 2";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(725, 73);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(62, 36);
			this->button8->TabIndex = 16;
			this->button8->Text = L"4 -> 2";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(725, 115);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(62, 36);
			this->button9->TabIndex = 17;
			this->button9->Text = L"4 -> 3";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(12, 438);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(80, 100);
			this->pictureBox3->TabIndex = 18;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(799, 550);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->BUTTON2);
			this->Controls->Add(this->PIETRO3);
			this->Controls->Add(this->PRZYCISK4);
			this->Controls->Add(this->pietro1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox3);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	//public: int gotowy = 0;
	public:	int idzie = 0;
	public: int ruszaj = 0;
	public: int jest_w_windzie = 0;
	public: int wsiada = 0;
	public: int dokad = 0;
	public: int wysiada = 0;
	public: int do_wsiadania = 0;
	public: int do_wysiadania = 0;
	public: int wysokosc = 0;
	public: int positionx = 0;
	public: int positiony = 0;
	public: int *array = new int[15];
	public: int *posx = new int[15];
	public: int *posy = new int[15];


	private: System::Void gogogo() {

		

		if (array[0] == 270) {
			if (idzie <= 52) {
				this->pictureBox2->Left -= 4;
				if (idzie == 0) {
					this->pictureBox2->Top = 300;
					this->pictureBox2->Left = 706;
				}	
				idzie += 1;
			}
		}
		if (array[0] == 10) {
			if (idzie <= 52) {
				this->pictureBox2->Left -= 4;
				if (idzie == 0) {
					this->pictureBox2->Top = 40;
					this->pictureBox2->Left = 706;
				}	
				idzie += 1;
			}
		}
		if (array[0] == 140) {
			if (idzie <= 52) {
				this->pictureBox2->Left += 4;
				
				if (idzie == 1) {
					this->pictureBox2->Top = 170;
					this->pictureBox2->Left = 20;
				}	
				idzie += 1;
			}
			
		}
		if (array[0] == 400) {
			if (idzie <= 52) {
				this->pictureBox2->Left += 4;
				
				if (idzie == 1) {
					this->pictureBox2->Top = 430;
					this->pictureBox2->Left = 20;
				}	
				idzie += 1;
			}
		}
		if (idzie == 1) {
			this->pictureBox2->Visible = true;
		}
	}
	
	private: System::Void kolejkuj() {
		
		for (int i = 0; i < 14; i++) {
			if (array[i]==402) {
				array[i] = wysokosc;
				array[i + 1] = dokad;
				posx[i] = positionx;
				posy[i] = positiony;
				i = 20;
			}
		}
	}


	private: System::Void entrans() {
		//ENTRANS

		if (ruszaj == 2) {
			if (do_wsiadania < 60) {
				if (array[0] == 270 || array[0] == 10) {
					this->pictureBox2->Left -= 2;
				}
				if (array[0] == 400 || array[0] == 140) {
					this->pictureBox2->Left += 2;
				}
				do_wsiadania += 1;
				wsiada = 1;
			}
			else {
				wsiada = 0;
				jest_w_windzie = 1;
			}
		}
	}

	private: System::Void exitrans() {
		//EXITRANS
		
		if (ruszaj == 2) {
			if (do_wysiadania < 80) {
				if (array[0]==140||array[0]==400) {
					this->pictureBox2->Left -= 2;
				}
				if (array[0]==10||array[0]==270) {
					this->pictureBox2->Left += 2;
				}
				do_wysiadania += 1;
				wysiada = 1;
			}
			else {
				
				if (posx[2] != 0) {
					posx[0] = posx[2];
					posy[0] = posy[2];
				}	
				//else {
				//	Sleep(5000);
				//}
				wysiada = 0;
				this->pictureBox2->Visible = false;
				jest_w_windzie = 0;
				dokad = 0;
				ruszaj = 0;
				idzie = 0;
				wsiada = 0;
				do_wsiadania = 0;
				do_wysiadania = 0;
				wysokosc = 0;
			}
		}
	}

	private: System::Void errrrreeeeyyy() {
			for (int i = 0; i < 14; i++) {
				array[i] = array[i + 1];
			}
			array[14] = 402;
	}

	private: System::Void pietro1_Click(System::Object^  sender, System::EventArgs^  e) {
		//1-2
		//this->pictureBox2->Visible = true;
		positionx = 20;
		positiony = 430;
		ruszaj = 2;
		wysokosc = 400;
		dokad = 270;
		kolejkuj();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//1-3
		//this->pictureBox2->Visible = true;
		positionx = 20;
		ruszaj = 2;
		positiony = 430;
		wysokosc = 400;
		dokad = 140;
		kolejkuj();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		//1-4
		//this->pictureBox2->Visible = true;
		positionx = 20;
		positiony = 430;
		ruszaj = 2;
		wysokosc = 400;
		dokad = 10;
		kolejkuj();
	}
	private: System::Void BUTTON2_Click(System::Object^  sender, System::EventArgs^  e) {
		//2-1
		positionx = 706;
		positiony = 300;
		//this->pictureBox2->Visible = true;
		ruszaj = 2;
		wysokosc = 270;
		dokad = 400;
		kolejkuj();
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		//2-3
		positionx = 706;
		positiony = 300;
		//this->pictureBox2->Visible = true;
		ruszaj = 2;
		wysokosc = 270;
		dokad = 140;
		kolejkuj();
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		//2-4
		positionx = 706;
		positiony = 300;
		//this->pictureBox2->Visible = true;
		ruszaj = 2;
		wysokosc = 270;
		dokad = 10;
		kolejkuj();
	}
	private: System::Void PIETRO3_Click_1(System::Object^  sender, System::EventArgs^  e) {
		//3-1
		positionx = 20;
		positiony = 140;
		//this->pictureBox2->Visible = true;
		ruszaj = 2;
		wysokosc = 140;
		dokad = 400;
		kolejkuj();
	}
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
		//3-2
		positionx = 20;
		positiony = 140;
		ruszaj = 2;
		//this->pictureBox2->Visible = true;
		wysokosc = 140;
		dokad = 270;
		kolejkuj();
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
		//3-4
		positionx = 20;
		positiony = 140;
		ruszaj = 2;
		//this->pictureBox2->Visible = true;
		wysokosc = 140;
		dokad = 10;
		kolejkuj();
	}
	private: System::Void PRZYCISK4_Click(System::Object^  sender, System::EventArgs^  e) {
		//4-1
		//this->pictureBox2->Visible = true;
		positionx = 706;
		positiony = 10;
		wysokosc = 10;
		dokad = 400;
		ruszaj = 2;
		kolejkuj();
	}
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
		//4-2
		//this->pictureBox2->Visible = true;
		positionx = 706;
		positiony = 10;
		wysokosc = 10;
		ruszaj = 2;
		dokad = 270;
		kolejkuj();
	}
	private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
		//4-3
		//this->pictureBox2->Visible = true;
		positionx = 706;
		positiony = 10;
		ruszaj = 2;
		wysokosc = 10;
		dokad = 140;
		kolejkuj();
	}

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		for (int i = 0; i < 15; i++) {
			array[i] = 402;
			posx[i] = 0;
			posy[i] = 0;
		}
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

			if (ruszaj!=0) {
				gogogo();
			}
				if (pictureBox1->Top > array[0]) {
					this->pictureBox1->Top -= 2;
					if (jest_w_windzie == 1) {
						this->pictureBox2->Top -= 2;
					}
				}
				if (pictureBox1->Top < array[0]) {
					this->pictureBox1->Top += 2;
					if (jest_w_windzie == 1) {
						this->pictureBox2->Top += 2;
					}
				}
			if (pictureBox1->Top == array[0]) {
				if (jest_w_windzie == 0) {
					entrans();
					if (array[1] != 402) {
						ruszaj = 2;
					}
				}
				if (wsiada == 0 && wysiada == 0) {
					errrrreeeeyyy();
					//gotowy = 0;
				}
				if (jest_w_windzie == 1) {
					exitrans();
				}
			}
	}
};
}
