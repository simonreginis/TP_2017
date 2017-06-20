#pragma once
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <windows.h>

namespace CppWinForm2 {
	
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
	public: int iterator;
	public: int s;
	public: int k;
	public: int n;
	public: int l;
	public: int p;
	public: int f;
	public: int przywolanie1;
	public: int przywolanie2;
	public: int przywolanie3=1;
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;




	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::PictureBox^  pictureBox5;


	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::Timer^  timer3;
	private: System::Windows::Forms::Timer^  timer4;
	private: System::Windows::Forms::Timer^  timer5;
	private: System::Windows::Forms::Timer^  timer6;
	private: System::Windows::Forms::PictureBox^  pictureBox6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Timer^  timer7;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::Timer^  timer8;
	private: System::Windows::Forms::Timer^  timer9;
	private: System::Windows::Forms::Timer^  timer10;
	private: System::Windows::Forms::Timer^  timer11;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Timer^  timer12;
	private: System::Windows::Forms::Timer^  timer13;
	private: System::Windows::Forms::Timer^  timer14;
	private: System::Windows::Forms::Timer^  timer15;
	private: System::Windows::Forms::Timer^  timer16;
	private: System::Windows::Forms::Timer^  timer17;
	private: System::Windows::Forms::Timer^  timer18;
	private: System::Windows::Forms::TextBox^  textBox1;


	private: System::ComponentModel::IContainer^  components;

	protected:

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer4 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer5 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer6 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->timer7 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->timer8 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer9 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer10 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer11 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->timer12 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer13 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer14 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer15 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer16 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer17 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer18 = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 23);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"0";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 52);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"1";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(591, 123);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"0";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(591, 183);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"2";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(14, 235);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 4;
			this->button5->Text = L"1";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(14, 264);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 5;
			this->button6->Text = L"2";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(261, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(171, 317);
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(94, 183);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(183, 114);
			this->pictureBox2->TabIndex = 10;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MyForm::pictureBox2_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(415, 97);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(170, 115);
			this->pictureBox3->TabIndex = 11;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(94, 0);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(183, 132);
			this->pictureBox4->TabIndex = 12;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(280, 20);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(133, 91);
			this->pictureBox5->TabIndex = 13;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->Click += gcnew System::EventHandler(this, &MyForm::pictureBox5_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// timer3
			// 
			this->timer3->Tick += gcnew System::EventHandler(this, &MyForm::timer3_Tick);
			// 
			// timer4
			// 
			this->timer4->Tick += gcnew System::EventHandler(this, &MyForm::timer4_Tick);
			// 
			// timer5
			// 
			this->timer5->Tick += gcnew System::EventHandler(this, &MyForm::timer5_Tick);
			// 
			// timer6
			// 
			this->timer6->Tick += gcnew System::EventHandler(this, &MyForm::timer6_Tick);
			// 
			// pictureBox6
			// 
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(100, 25);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(37, 79);
			this->pictureBox6->TabIndex = 14;
			this->pictureBox6->TabStop = false;
			this->pictureBox6->Click += gcnew System::EventHandler(this, &MyForm::pictureBox6_Click);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button7->Location = System::Drawing::Point(12, 81);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 23);
			this->button7->TabIndex = 15;
			this->button7->Text = L"2";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// timer7
			// 
			this->timer7->Interval = 30;
			this->timer7->Tick += gcnew System::EventHandler(this, &MyForm::timer7_Tick);
			// 
			// pictureBox7
			// 
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(534, 132);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(40, 69);
			this->pictureBox7->TabIndex = 16;
			this->pictureBox7->TabStop = false;
			this->pictureBox7->Click += gcnew System::EventHandler(this, &MyForm::pictureBox7_Click);
			// 
			// timer8
			// 
			this->timer8->Tick += gcnew System::EventHandler(this, &MyForm::timer8_Tick);
			// 
			// timer10
			// 
			this->timer10->Tick += gcnew System::EventHandler(this, &MyForm::timer10_Tick);
			// 
			// timer11
			// 
			this->timer11->Tick += gcnew System::EventHandler(this, &MyForm::timer11_Tick);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button8->Location = System::Drawing::Point(591, 154);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 23);
			this->button8->TabIndex = 17;
			this->button8->Text = L"1";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button9->Location = System::Drawing::Point(14, 206);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(75, 23);
			this->button9->TabIndex = 18;
			this->button9->Text = L"0";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// timer12
			// 
			this->timer12->Tick += gcnew System::EventHandler(this, &MyForm::timer12_Tick);
			// 
			// timer13
			// 
			this->timer13->Tick += gcnew System::EventHandler(this, &MyForm::timer13_Tick);
			// 
			// timer14
			// 
			this->timer14->Tick += gcnew System::EventHandler(this, &MyForm::timer14_Tick);
			// 
			// timer15
			// 
			this->timer15->Tick += gcnew System::EventHandler(this, &MyForm::timer15_Tick);
			// 
			// timer16
			// 
			this->timer16->Tick += gcnew System::EventHandler(this, &MyForm::timer16_Tick);
			// 
			// timer17
			// 
			this->timer17->Tick += gcnew System::EventHandler(this, &MyForm::timer17_Tick);
			// 
			// timer18
			// 
			this->timer18->Tick += gcnew System::EventHandler(this, &MyForm::timer18_Tick);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(464, 49);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(59, 20);
			this->textBox1->TabIndex = 20;
			this->textBox1->Text = L"0 kg";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(669, 302);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->pictureBox7);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox6);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}


	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void pictureBox2_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void pictureBox5_Click(System::Object^  sender, System::EventArgs^  e) {
}


private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	this->iterator = 117; 
	this->n = 430;
	this->f = 534;
	this->timer1->Enabled = true;
	this->timer1->Interval = 30;
	this->timer1->Start();
	this->timer15->Enabled = true;
	this->timer15->Interval = 5;
	this->timer15->Start();
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	n--;
	if (n < 200)
	{
		textBox1->Text = "50 kg";
		this->pictureBox5->Location = System::Drawing::Point(280, iterator);
		this->pictureBox7->Location = System::Drawing::Point(280, iterator + 15);
		iterator--;
		if (iterator < 21)
		{
			this->timer1->Stop();
			przywolanie1 = 0;
			przywolanie2 = 0;
			przywolanie3 = 1;
			this->timer16->Enabled = true;
			this->timer16->Interval = 5;
			this->timer16->Start();
			textBox1->Text = "0 kg";
		}
	}
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	this->iterator = 117;
	this->f = 534;
	this->n = 430;
	this->timer2->Enabled = true;
	this->timer2->Interval = 30;
	this->timer2->Start();
	this->timer15->Enabled = true;
	this->timer15->Interval = 5;
	this->timer15->Start();
}
private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
	n--;
	if (n < 200)
	{
		textBox1->Text = "50 kg";
		this->pictureBox5->Location = System::Drawing::Point(280, iterator);
		this->pictureBox7->Location = System::Drawing::Point(280, iterator+15);
		iterator++;
		if (iterator > 201)
		{
			this->timer2->Stop();
			przywolanie1 = 1;
			przywolanie2 = 0;
			przywolanie3 = 0;
			this->timer16->Enabled = true;
			this->timer16->Interval = 5;
			this->timer16->Start();
			textBox1->Text = "0 kg";
		}
	}
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	this->iterator = 21;
	this->s = 94;
	this->n = 350;
	this->l = 280;
	this->timer3->Enabled = true;
	this->timer3->Interval = 30;
	this->timer3->Start();
	this->timer17->Enabled = true;
	this->timer17->Interval = 5;
	this->timer17->Start();
}
private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e) {
	n--;
	if (n < 200)
	{
		textBox1->Text = "50 kg";
		this->pictureBox7->Location = System::Drawing::Point(280, iterator + 15);
		this->pictureBox5->Location = System::Drawing::Point(280, iterator);
		iterator++;
		if (iterator > 117)
		{
			this->timer3->Stop();
			przywolanie2 = 1;
			przywolanie1 = 0;
			przywolanie3 = 0;
			this->timer18->Enabled = true;
			this->timer18->Interval =5 ;
			this->timer18->Start();
			textBox1->Text = "0 kg";
		}
	}
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	this->iterator = 20;
	this->n = 350;
	this->s = 94;
	this->f = 280;
	this->timer4->Enabled = true;
	this->timer4->Interval = 30;
	this->timer4->Start();
	this->timer17->Enabled = true;
	this->timer17->Interval = 5;
	this->timer17->Start();

	textBox1->Text = "0 kg";

}
private: System::Void timer4_Tick(System::Object^  sender, System::EventArgs^  e) {
	n--;
	if (n < 200)
	{
		textBox1->Text = "50 kg";
		this->pictureBox5->Location = System::Drawing::Point(280, iterator);
		this->pictureBox7->Location = System::Drawing::Point(280, iterator + 15);
		iterator++;
		if (iterator > 201)
		{
			this->timer4->Stop();
			iterator = 20;
			przywolanie1 = 1;
			przywolanie2 = 0;
			przywolanie3 = 0;
			this->timer16->Enabled = true;
			this->timer16->Interval = 5;
			this->timer16->Start();
			textBox1->Text = "0 kg";
		}
	}
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	
	this->timer7->Enabled = true;
	this->timer7->Interval = 5;
	this->timer7->Start();
	this->n = 350;
	this->iterator = 200;
	this->l = 280;
	this->s = 94;
	this->timer5->Enabled = true;
	this->timer5->Interval = 30;
	this->timer5->Start();
}
private: System::Void timer5_Tick(System::Object^  sender, System::EventArgs^  e) {
	n--;
	if (n < 200)
	{
		textBox1->Text = "50 kg";
		this->pictureBox5->Location = System::Drawing::Point(280, iterator);
		this->pictureBox7->Location = System::Drawing::Point(280, iterator + 18);
		iterator--;
		if (iterator < 20)
		{
			this->timer5->Stop();
			n = 400;
			przywolanie3 = 1;
			przywolanie2 = 0;
			przywolanie1 = 0;
			this->timer14->Enabled = true;
			this->timer14->Interval = 5;
			this->timer14->Start();
			textBox1->Text = "0 kg";
		}
	}
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	
	this->timer7->Enabled = true;
	this->timer7->Interval = 30;
	this->timer7->Start();
	this->s = 94;
	this->k = 350;
	this->l = 280;
	this->p = 1;
	this->iterator = 200;
	this->timer6->Enabled = true;
	this->timer6->Interval = 30;
	this->timer6->Start();

}
private: System::Void timer7_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->pictureBox7->Location = System::Drawing::Point(s, 218);
	s++;
	if (s>280)
	{
		this->timer7->Stop();
		s = 94;
		przywolanie2 = 1;
		przywolanie3 = 0;
		przywolanie1 = 0;
	}
}
private: System::Void timer6_Tick(System::Object^  sender, System::EventArgs^  e) {
	k--;
	if (k < 200)
	{
		textBox1->Text = "50 kg";
		this->pictureBox5->Location = System::Drawing::Point(280, iterator);
		this->pictureBox7->Location = System::Drawing::Point(280, iterator+15);
		iterator--;
		if (iterator < 117)
		{
			this->timer6->Stop();
			k = 400;
			przywolanie2 = 1;
			przywolanie1 = 0;
			przywolanie3 = 0;
			this->timer13->Enabled = true;
			this->timer13->Interval = 5;
			this->timer13->Start();
			textBox1->Text = "0 kg";
		}
	}
}
private: System::Void pictureBox6_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	this->n = 117;
	this->iterator = 200;
	this->timer10->Enabled = true;
	this->timer10->Interval = 30;
	this->timer10->Start();
	
	this->pictureBox7->Location = System::Drawing::Point(100, 30);
}
private: System::Void pictureBox7_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void timer8_Tick(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void timer10_Tick(System::Object^  sender, System::EventArgs^  e) {
	
	if (przywolanie1 == 1)
	{
		this->pictureBox5->Location = System::Drawing::Point(280, iterator);
		iterator--;
		if (iterator < 20)
		{
			this->timer10->Stop();
			przywolanie1 = 0;
			iterator = 200;
			przywolanie3 = 1;
			przywolanie1 = 0;
			przywolanie2 = 0;
			textBox1->Text = "0 kg";
		}
	}
	if (przywolanie2 == 1)
	{
		this->pictureBox5->Location = System::Drawing::Point(280, n);
		n--;
		if (n < 20)
		{
			this->timer10->Stop();
			przywolanie2 = 0;
			n = 117;
			przywolanie3 = 1;
			przywolanie1 = 0;
			textBox1->Text = "0 kg";
		}
	}

}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
	this->iterator = 20;
	this->n = 200;
	this->timer11->Enabled = true;
	this->timer11->Interval = 30;
	this->timer11->Start();

	this->pictureBox7->Location = System::Drawing::Point(534, 132);
}
private: System::Void timer11_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (przywolanie3 == 1)
	{
		this->pictureBox5->Location = System::Drawing::Point(280, iterator);
		iterator++;
		if (iterator > 117)
		{
			this->timer11->Stop();
			przywolanie3 = 0;
			iterator = 20;
			przywolanie2 = 1;
			przywolanie3 = 0;
			textBox1->Text = "0 kg";
		}
	}
	if (przywolanie1 == 1)
	{
		this->pictureBox5->Location = System::Drawing::Point(280, n);
		n--;
		if (n < 117)
		{
			this->timer11->Stop();
			przywolanie1 = 0;
			n = 200;
			przywolanie2 = 1;
			przywolanie3 = 0;
			textBox1->Text = "0 kg";
		}
	}
}
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
	this->iterator = 117;
	this->n = 20;
	this->timer12->Enabled = true;
	this->timer12->Interval = 30;
	this->timer12->Start();

	this->pictureBox7->Location = System::Drawing::Point(95, 218);
}
private: System::Void timer12_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (przywolanie2 == 1)
	{
		this->pictureBox5->Location = System::Drawing::Point(280, iterator);
		iterator++;
		if (iterator > 201)
		{
			this->timer12->Stop();
			przywolanie2 = 0;
			iterator = 117;
			przywolanie1 = 1;
			przywolanie2 = 0;
			textBox1->Text = "0 kg";
		}
	}
	if (przywolanie3 == 1)
	{
		this->pictureBox5->Location = System::Drawing::Point(280, n);
		n++;
		if (n > 201)
		{
			this->timer12->Stop();
			n = 20;
			przywolanie3 = 0;
			przywolanie1 = 1;
			przywolanie2 = 0;
			textBox1->Text = "0 kg";
		}
	}
}
private: System::Void timer13_Tick(System::Object^  sender, System::EventArgs^  e) {
	
		this->pictureBox7->Location = System::Drawing::Point(l, 132);
		if (l > 534)
		{
			this->timer13->Stop();
			l = 280;
			przywolanie2 = 1;
			przywolanie1 = 0;
			przywolanie3 = 0;
			textBox1->Text = "0 kg";
		}
		l++;
	
}
private: System::Void timer14_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->pictureBox7->Location = System::Drawing::Point(l, 32);
	l--;
	if (l<94)
	{
		this->timer14->Stop();
		l=280;
		przywolanie3 = 1;
		przywolanie1 = 0;
		przywolanie2 = 0;
		textBox1->Text = "0 kg";
	}
}
private: System::Void timer15_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->pictureBox7->Location = System::Drawing::Point(f, 132);
	f--;
	if (f < 279)
	{
		this->timer15->Stop();
		f = 280;
		textBox1->Text = "0 kg";
	}
}
private: System::Void timer16_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (przywolanie1 == 1)
	{
		this->pictureBox7->Location = System::Drawing::Point(f, 220);
		f--;
		if (f < 94)
		{
			this->timer16->Stop();
			f = 534;
			textBox1->Text = "0 kg";
		}
	}
	if (przywolanie3 == 1)
	{
		this->pictureBox7->Location = System::Drawing::Point(f, 30);
		f--;
		if (f < 94)
		{
			this->timer16->Stop();
			f = 534;
			textBox1->Text = "0 kg";
		}
	}
}
private: System::Void timer17_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->pictureBox7->Location = System::Drawing::Point(s, 30);
	s++;
	if (s>280)
	{
		this->timer17->Stop();
		s = 94;
		przywolanie2 = 1;
		textBox1->Text = "0 kg";
	}
}
private: System::Void timer18_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->pictureBox7->Location = System::Drawing::Point(l, 132);
	if (l > 534)
	{
		this->timer18->Stop();
		l = 280;
		przywolanie2 = 1;
		textBox1->Text = "0 kg";
	}
	l++;
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
