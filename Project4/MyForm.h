#pragma once

namespace Project4 {

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

		static int timer = 0;
		int pozycja=330;
		int roznica;
		int czas = 0;
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
	private: System::Windows::Forms::PictureBox^  pictureBox3;
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
	private: System::Windows::Forms::Button^  button10;
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
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
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
			this->button10 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
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
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(289, 350);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(68, 94);
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
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
			this->groupBox1->Location = System::Drawing::Point(27, 51);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(174, 204);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Na ktore pietro chcesz jechac\?";
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(21, 153);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(50, 23);
			this->button9->TabIndex = 4;
			this->button9->Text = L"4";
			this->button9->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(21, 124);
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
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(21, 66);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(50, 23);
			this->button6->TabIndex = 1;
			this->button6->Text = L"1";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(21, 37);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(50, 23);
			this->button5->TabIndex = 0;
			this->button5->Text = L"0";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(72, 12);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(87, 23);
			this->button10->TabIndex = 9;
			this->button10->Text = L"Zaczynamy!!!";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(967, 526);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->Pietro4);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (czas < 130)
			this->pictureBox3->Left += 2;

		else {
		if (pictureBox2->Top > pozycja)
		{
			this->pictureBox2->Top -= 1;
			this->pictureBox3->Top -= 1;
			//roznica = pictureBox2->Top - pozycja;
			//this->pictureBox2->Top -= roznica;
		}
		else if(pictureBox2->Top < pozycja)
		{
			//this->timer1->Stop();
			this->pictureBox2->Top += 1;
			this->pictureBox3->Top += 1;
			//roznica = pictureBox2->Top - pozycja;
			//this->pictureBox2->Top -= roznica;
		}
		}
			
		czas++;
	}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Pietro4_Click(System::Object^  sender, System::EventArgs^  e) {
	pozycja = 81;
	
	
	//this->pictureBox2->Top -= 250;
	//this->pictureBox3->Top -= 250;

	//int r;

	
		//r = pictureBox2->Top - 88;
		//this->pictureBox2->Top -= r;
	
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	pozycja = 159;
	
	//int r;

	
		//r = (pictureBox2->Top) - 166;
		//this->pictureBox2->Top -= r;
	

}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	pozycja = 209;
	
	//int r;

	
		//r = pictureBox2->Top - 216;
		//this->pictureBox2->Top -= r;
	
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	pozycja = 283;
	

	//int r;

	
		//r = pictureBox2->Top - 290;
		//this->pictureBox2->Top -= r;
	
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	pozycja = 323;
	
	
		//this->pictureBox2->Top= 330;
	
}
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
	//this->timer1->Start();
}
};
}
