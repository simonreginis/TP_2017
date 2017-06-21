#pragma once
#include <iostream>
#include <vector>
#include <cstring>


///using namespace std;



namespace Project4 {

	std::vector < int > kolejnosc;
	int parter = 323;
	int pierwsze_pietro = 283;
	int drugie_pietro = 209;
	int trzecie_pietro = 159;
	int czwarte_piêtro = 81;
	int masa = 70;


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	///using namespace std;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

		String^ wartosc;
		static int timer = 0;
		int pozycja = 330;
		int cel = 330; ///Pietro na ktorym chce wysiasc pasarzer
		int roznica;
		int czas = 0;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
			 int wysiadanie = 130;

			 //int t = parter;

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
	private: System::Windows::Forms::PictureBox^  pictureBox2;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  Pietro4;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button5;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->Pietro4 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(240, -21);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(715, 519);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(521, 324);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(125, 129);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 15;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(442, 333);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Parter";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(651, 282);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Pietro1";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(442, 208);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Pietro2";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(651, 157);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Pietro3";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// Pietro4
			// 
			this->Pietro4->Location = System::Drawing::Point(442, 79);
			this->Pietro4->Name = L"Pietro4";
			this->Pietro4->Size = System::Drawing::Size(75, 23);
			this->Pietro4->TabIndex = 7;
			this->Pietro4->Text = L"Pietro4";
			this->Pietro4->UseVisualStyleBackColor = true;
			this->Pietro4->Click += gcnew System::EventHandler(this, &MyForm::Pietro4_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button9);
			this->groupBox1->Controls->Add(this->button8);
			this->groupBox1->Controls->Add(this->button7);
			this->groupBox1->Controls->Add(this->button6);
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Location = System::Drawing::Point(27, 27);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(174, 204);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Na ktore pietro chcesz jechac\?";
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(21, 37);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(50, 23);
			this->button9->TabIndex = 4;
			this->button9->Text = L"4";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(21, 66);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(50, 23);
			this->button8->TabIndex = 3;
			this->button8->Text = L"3";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(21, 95);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(50, 23);
			this->button7->TabIndex = 2;
			this->button7->Text = L"2";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(21, 124);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(50, 23);
			this->button6->TabIndex = 1;
			this->button6->Text = L"1";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(21, 153);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(50, 23);
			this->button5->TabIndex = 0;
			this->button5->Text = L"0";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(24, 282);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 13);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Masa pasazerow";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(24, 307);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(13, 13);
			this->label2->TabIndex = 12;
			this->label2->Text = L"0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(967, 526);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->Pietro4);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		wartosc = Convert::ToString(masa);
		label2->Text = wartosc;


		if (!kolejnosc.empty()) 
		{
			if (pictureBox2->Top > *(kolejnosc.begin()))
			{
				this->pictureBox2->Top -= 1;
				if (pictureBox2->Top == *(kolejnosc.begin()))
				{
					kolejnosc.erase(kolejnosc.begin());

				}
			}
			else if (pictureBox2->Top < *(kolejnosc.begin()))
			{
				this->pictureBox2->Top += 1;
				if (pictureBox2->Top == *(kolejnosc.begin()))
					kolejnosc.erase(kolejnosc.begin());
			}
		}


	}

	private: System::Void Pietro4_Click(System::Object^  sender, System::EventArgs^  e) {
		kolejnosc.push_back(czwarte_piêtro);
		masa += 70;

	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		kolejnosc.push_back(trzecie_pietro);
		masa += 70;



	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		kolejnosc.push_back(drugie_pietro);
		masa += 70;


	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		kolejnosc.push_back(pierwsze_pietro);
		masa += 70;


	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		kolejnosc.push_back(parter);
		masa += 70;

	}


	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		if (masa > 0)
		{
			kolejnosc.push_back(parter);
			masa -= 70;
		}
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
		if (masa > 0)
		{
			kolejnosc.push_back(pierwsze_pietro);
			masa -= 70;
		}

	}
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
		if (masa > 0)
		{
			kolejnosc.push_back(drugie_pietro);
			masa -= 70;
		}

	}
	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
		if (masa > 0)
		{
			kolejnosc.push_back(trzecie_pietro);
			masa -= 70;
		}
	}
	private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
		if (masa > 0)
		{
			kolejnosc.push_back(czwarte_piêtro);
			masa -= 70;
		}

	}
	};
}
