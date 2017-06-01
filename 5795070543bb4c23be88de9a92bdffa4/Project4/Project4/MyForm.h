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

		static int licznik_odleglosci = 0;
		static int pozycja_windy = 510;
		static int cel_windy = 510;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::Button^  button17;
	private: System::Windows::Forms::Button^  button18;
	private: System::Windows::Forms::Button^  button19;
	private: System::Windows::Forms::Button^  button20;
	private: System::Windows::Forms::Button^  button21;
	private: System::Windows::Forms::Button^  button22;

			 static int kierunek = 1;

		

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		void Pietro_1(void)
		{
			if (pozycja_windy != 510)
			{
				if (pozycja_windy > 510)
					kierunek = 1;
				if (pozycja_windy < 510)
					kierunek = -1;

				this->timer1->Start();

				cel_windy = 510;
			}
		};


		void Pietro_2(void)
		{
			if (pozycja_windy != 410)
			{
				if(pozycja_windy > 410)
					kierunek = 1;
				if (pozycja_windy < 410)
					kierunek = -1;

				this->timer1->Start();

				cel_windy = 410;
			}
		};

		void Pietro_3(void)
		{
			if (pozycja_windy != 310)
			{
				if (pozycja_windy > 310)
					kierunek = 1;
				if (pozycja_windy < 310)
					kierunek = -1;

				this->timer1->Start();

				cel_windy = 310;
			}
		};

		void Pietro_4(void)
		{
			if (pozycja_windy != 210)
			{
				if (pozycja_windy > 210)
					kierunek = 1;
				if (pozycja_windy < 210)
					kierunek = -1;

				this->timer1->Start();

				cel_windy = 210;
			}
		};

		void Pietro_5(void)
		{
			if (pozycja_windy != 110)
			{
				if (pozycja_windy > 110)
					kierunek = 1;
				if (pozycja_windy < 110)
					kierunek = -1;

				this->timer1->Start();

				cel_windy = 110;
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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
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
			// button1
			// 
			this->button1->Location = System::Drawing::Point(933, 389);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(153, 61);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Wjedz ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(932, 476);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(153, 57);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Zjedz na dol";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// timer1
			// 
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
			this->label1->Text = L"Piêtro 1";
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
			this->label2->Text = L"Piêtro 2";
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
			this->label3->Text = L"Piêtro 3";
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
			this->label4->Text = L"Piêtro 4";
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
			this->label5->Text = L"Piêtro 5";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(36, 444);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(21, 26);
			this->button3->TabIndex = 10;
			this->button3->Text = L"2";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(786, 363);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(21, 26);
			this->button4->TabIndex = 11;
			this->button4->Text = L"3";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(35, 244);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(21, 26);
			this->button5->TabIndex = 12;
			this->button5->Text = L"2";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(785, 120);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(21, 26);
			this->button6->TabIndex = 13;
			this->button6->Text = L"2";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(35, 47);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(21, 26);
			this->button7->TabIndex = 14;
			this->button7->Text = L"2";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(36, 467);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(21, 26);
			this->button8->TabIndex = 15;
			this->button8->Text = L"3";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(785, 140);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(21, 26);
			this->button9->TabIndex = 16;
			this->button9->Text = L"3";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(34, 66);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(21, 26);
			this->button10->TabIndex = 17;
			this->button10->Text = L"3";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(787, 345);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(20, 23);
			this->button11->TabIndex = 18;
			this->button11->Text = L"1";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(36, 225);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(20, 23);
			this->button12->TabIndex = 19;
			this->button12->Text = L"1";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(787, 100);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(20, 23);
			this->button13->TabIndex = 20;
			this->button13->Text = L"1";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(36, 24);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(20, 23);
			this->button14->TabIndex = 21;
			this->button14->Text = L"1";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(36, 89);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(20, 23);
			this->button15->TabIndex = 22;
			this->button15->Text = L"4";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(35, 266);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(20, 23);
			this->button16->TabIndex = 23;
			this->button16->Text = L"4";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(786, 389);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(20, 23);
			this->button17->TabIndex = 24;
			this->button17->Text = L"4";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
			// 
			// button18
			// 
			this->button18->Location = System::Drawing::Point(36, 493);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(20, 23);
			this->button18->TabIndex = 25;
			this->button18->Text = L"4";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &MyForm::button18_Click);
			// 
			// button19
			// 
			this->button19->Location = System::Drawing::Point(785, 162);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(21, 26);
			this->button19->TabIndex = 26;
			this->button19->Text = L"5";
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &MyForm::button19_Click);
			// 
			// button20
			// 
			this->button20->Location = System::Drawing::Point(34, 286);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(21, 26);
			this->button20->TabIndex = 27;
			this->button20->Text = L"5";
			this->button20->UseVisualStyleBackColor = true;
			this->button20->Click += gcnew System::EventHandler(this, &MyForm::button20_Click);
			// 
			// button21
			// 
			this->button21->Location = System::Drawing::Point(787, 418);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(21, 26);
			this->button21->TabIndex = 28;
			this->button21->Text = L"5";
			this->button21->UseVisualStyleBackColor = true;
			this->button21->Click += gcnew System::EventHandler(this, &MyForm::button21_Click);
			// 
			// button22
			// 
			this->button22->Location = System::Drawing::Point(34, 522);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(21, 26);
			this->button22->TabIndex = 29;
			this->button22->Text = L"5";
			this->button22->UseVisualStyleBackColor = true;
			this->button22->Click += gcnew System::EventHandler(this, &MyForm::button22_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1308, 620);
			this->Controls->Add(this->button22);
			this->Controls->Add(this->button21);
			this->Controls->Add(this->button20);
			this->Controls->Add(this->button19);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		kierunek = 1;
		this->timer1->Start();

	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		pozycja_windy -= 2*kierunek;
		this->pictureBox2->Location = System::Drawing::Point(288, pozycja_windy);

		if (pozycja_windy == cel_windy)
			this->timer1->Stop();

	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		kierunek = -1;
		this->timer1->Start();

	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Pietro_2();
	}

	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Pietro_3();
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Pietro_2();
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Pietro_2();
	}
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Pietro_2();
	}

	private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Pietro_3();
	}
	private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Pietro_3();
	}
	private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Pietro_3();
	}

	private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Pietro_1();
	}
	private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Pietro_1();
	}
	private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Pietro_1();
	}
	private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Pietro_1();
	}

	private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Pietro_4();
	}
	private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Pietro_4();
	}
	private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Pietro_4();
	}
	private: System::Void button18_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Pietro_4();
	}

	private: System::Void button19_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Pietro_5();
	}
	private: System::Void button20_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Pietro_5();
	}
	private: System::Void button21_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Pietro_5();
	}
	private: System::Void button22_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Pietro_5();
	}

};
}
