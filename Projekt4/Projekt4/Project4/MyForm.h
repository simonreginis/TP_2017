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
		static int kierunek = 1;
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















	private: System::Windows::Forms::Label^  l1na5;

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
				if (pozycja_windy > 410)
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
			// b1na2
			// 
			this->b1na2->Location = System::Drawing::Point(36, 415);
			this->b1na2->Name = L"b1na2";
			this->b1na2->Size = System::Drawing::Size(21, 26);
			this->b1na2->TabIndex = 10;
			this->b1na2->Text = L"2";
			this->b1na2->UseVisualStyleBackColor = true;
			this->b1na2->Click += gcnew System::EventHandler(this, &MyForm::b1na2_Click);
			// 
			// b2na3
			// 
			this->b2na3->Location = System::Drawing::Point(786, 338);
			this->b2na3->Name = L"b2na3";
			this->b2na3->Size = System::Drawing::Size(21, 26);
			this->b2na3->TabIndex = 11;
			this->b2na3->Text = L"3";
			this->b2na3->UseVisualStyleBackColor = true;
			this->b2na3->Click += gcnew System::EventHandler(this, &MyForm::b2na3_Click);
			// 
			// b3na2
			// 
			this->b3na2->Location = System::Drawing::Point(36, 234);
			this->b3na2->Name = L"b3na2";
			this->b3na2->Size = System::Drawing::Size(21, 26);
			this->b3na2->TabIndex = 12;
			this->b3na2->Text = L"2";
			this->b3na2->UseVisualStyleBackColor = true;
			this->b3na2->Click += gcnew System::EventHandler(this, &MyForm::b3na2_Click);
			// 
			// b4na2
			// 
			this->b4na2->Location = System::Drawing::Point(786, 109);
			this->b4na2->Name = L"b4na2";
			this->b4na2->Size = System::Drawing::Size(21, 26);
			this->b4na2->TabIndex = 13;
			this->b4na2->Text = L"2";
			this->b4na2->UseVisualStyleBackColor = true;
			this->b4na2->Click += gcnew System::EventHandler(this, &MyForm::b4na2_Click);
			// 
			// b5na2
			// 
			this->b5na2->Location = System::Drawing::Point(34, 45);
			this->b5na2->Name = L"b5na2";
			this->b5na2->Size = System::Drawing::Size(21, 26);
			this->b5na2->TabIndex = 14;
			this->b5na2->Text = L"2";
			this->b5na2->UseVisualStyleBackColor = true;
			this->b5na2->Click += gcnew System::EventHandler(this, &MyForm::b5na2_Click);
			// 
			// b1na3
			// 
			this->b1na3->Location = System::Drawing::Point(36, 447);
			this->b1na3->Name = L"b1na3";
			this->b1na3->Size = System::Drawing::Size(21, 26);
			this->b1na3->TabIndex = 15;
			this->b1na3->Text = L"3";
			this->b1na3->UseVisualStyleBackColor = true;
			this->b1na3->Click += gcnew System::EventHandler(this, &MyForm::b1na3_Click);
			// 
			// b4na3
			// 
			this->b4na3->Location = System::Drawing::Point(786, 141);
			this->b4na3->Name = L"b4na3";
			this->b4na3->Size = System::Drawing::Size(21, 26);
			this->b4na3->TabIndex = 16;
			this->b4na3->Text = L"3";
			this->b4na3->UseVisualStyleBackColor = true;
			this->b4na3->Click += gcnew System::EventHandler(this, &MyForm::b4na3_Click);
			// 
			// b5na3
			// 
			this->b5na3->Location = System::Drawing::Point(34, 77);
			this->b5na3->Name = L"b5na3";
			this->b5na3->Size = System::Drawing::Size(21, 26);
			this->b5na3->TabIndex = 17;
			this->b5na3->Text = L"3";
			this->b5na3->UseVisualStyleBackColor = true;
			this->b5na3->Click += gcnew System::EventHandler(this, &MyForm::b5na3_Click);
			// 
			// b2na1
			// 
			this->b2na1->Location = System::Drawing::Point(786, 309);
			this->b2na1->Name = L"b2na1";
			this->b2na1->Size = System::Drawing::Size(20, 23);
			this->b2na1->TabIndex = 18;
			this->b2na1->Text = L"1";
			this->b2na1->UseVisualStyleBackColor = true;
			this->b2na1->Click += gcnew System::EventHandler(this, &MyForm::b2na1_Click);
			// 
			// b3na1
			// 
			this->b3na1->Location = System::Drawing::Point(37, 206);
			this->b3na1->Name = L"b3na1";
			this->b3na1->Size = System::Drawing::Size(20, 23);
			this->b3na1->TabIndex = 19;
			this->b3na1->Text = L"1";
			this->b3na1->UseVisualStyleBackColor = true;
			this->b3na1->Click += gcnew System::EventHandler(this, &MyForm::b3na1_Click);
			// 
			// b4na1
			// 
			this->b4na1->Location = System::Drawing::Point(785, 80);
			this->b4na1->Name = L"b4na1";
			this->b4na1->Size = System::Drawing::Size(20, 23);
			this->b4na1->TabIndex = 20;
			this->b4na1->Text = L"1";
			this->b4na1->UseVisualStyleBackColor = true;
			this->b4na1->Click += gcnew System::EventHandler(this, &MyForm::b4na1_Click);
			// 
			// b5na1
			// 
			this->b5na1->Location = System::Drawing::Point(35, 16);
			this->b5na1->Name = L"b5na1";
			this->b5na1->Size = System::Drawing::Size(20, 23);
			this->b5na1->TabIndex = 21;
			this->b5na1->Text = L"1";
			this->b5na1->UseVisualStyleBackColor = true;
			this->b5na1->Click += gcnew System::EventHandler(this, &MyForm::b5na1_Click);
			// 
			// b5na4
			// 
			this->b5na4->Location = System::Drawing::Point(35, 109);
			this->b5na4->Name = L"b5na4";
			this->b5na4->Size = System::Drawing::Size(20, 23);
			this->b5na4->TabIndex = 22;
			this->b5na4->Text = L"4";
			this->b5na4->UseVisualStyleBackColor = true;
			this->b5na4->Click += gcnew System::EventHandler(this, &MyForm::b5na4_Click);
			// 
			// b3na4
			// 
			this->b3na4->Location = System::Drawing::Point(37, 266);
			this->b3na4->Name = L"b3na4";
			this->b3na4->Size = System::Drawing::Size(20, 23);
			this->b3na4->TabIndex = 23;
			this->b3na4->Text = L"4";
			this->b3na4->UseVisualStyleBackColor = true;
			this->b3na4->Click += gcnew System::EventHandler(this, &MyForm::b3na4_Click);
			// 
			// b2na4
			// 
			this->b2na4->Location = System::Drawing::Point(786, 370);
			this->b2na4->Name = L"b2na4";
			this->b2na4->Size = System::Drawing::Size(20, 23);
			this->b2na4->TabIndex = 24;
			this->b2na4->Text = L"4";
			this->b2na4->UseVisualStyleBackColor = true;
			this->b2na4->Click += gcnew System::EventHandler(this, &MyForm::b2na4_Click);
			// 
			// b1na4
			// 
			this->b1na4->Location = System::Drawing::Point(37, 479);
			this->b1na4->Name = L"b1na4";
			this->b1na4->Size = System::Drawing::Size(20, 23);
			this->b1na4->TabIndex = 25;
			this->b1na4->Text = L"4";
			this->b1na4->UseVisualStyleBackColor = true;
			this->b1na4->Click += gcnew System::EventHandler(this, &MyForm::b1na4_Click);
			// 
			// b4na5
			// 
			this->b4na5->Location = System::Drawing::Point(786, 173);
			this->b4na5->Name = L"b4na5";
			this->b4na5->Size = System::Drawing::Size(21, 26);
			this->b4na5->TabIndex = 26;
			this->b4na5->Text = L"5";
			this->b4na5->UseVisualStyleBackColor = true;
			this->b4na5->Click += gcnew System::EventHandler(this, &MyForm::b4na5_Click);
			// 
			// b3na5
			// 
			this->b3na5->Location = System::Drawing::Point(36, 295);
			this->b3na5->Name = L"b3na5";
			this->b3na5->Size = System::Drawing::Size(21, 26);
			this->b3na5->TabIndex = 27;
			this->b3na5->Text = L"5";
			this->b3na5->UseVisualStyleBackColor = true;
			this->b3na5->Click += gcnew System::EventHandler(this, &MyForm::b3na5_Click);
			// 
			// b2na5
			// 
			this->b2na5->Location = System::Drawing::Point(786, 399);
			this->b2na5->Name = L"b2na5";
			this->b2na5->Size = System::Drawing::Size(21, 26);
			this->b2na5->TabIndex = 28;
			this->b2na5->Text = L"5";
			this->b2na5->UseVisualStyleBackColor = true;
			this->b2na5->Click += gcnew System::EventHandler(this, &MyForm::b2na5_Click);
			// 
			// b1na5
			// 
			this->b1na5->Location = System::Drawing::Point(36, 507);
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
			this->l1na2->Location = System::Drawing::Point(202, 462);
			this->l1na2->Name = L"l1na2";
			this->l1na2->Size = System::Drawing::Size(43, 13);
			this->l1na2->TabIndex = 30;
			this->l1na2->Text = L"1->2 : 0";
			// 
			// l1na3
			// 
			this->l1na3->AutoSize = true;
			this->l1na3->Location = System::Drawing::Point(202, 484);
			this->l1na3->Name = L"l1na3";
			this->l1na3->Size = System::Drawing::Size(43, 13);
			this->l1na3->TabIndex = 31;
			this->l1na3->Text = L"1->3 : 0";
			// 
			// l1na4
			// 
			this->l1na4->AutoSize = true;
			this->l1na4->Location = System::Drawing::Point(202, 507);
			this->l1na4->Name = L"l1na4";
			this->l1na4->Size = System::Drawing::Size(43, 13);
			this->l1na4->TabIndex = 32;
			this->l1na4->Text = L"1->4 : 0";
			// 
			// l1na5
			// 
			this->l1na5->AutoSize = true;
			this->l1na5->Location = System::Drawing::Point(202, 529);
			this->l1na5->Name = L"l1na5";
			this->l1na5->Size = System::Drawing::Size(43, 13);
			this->l1na5->TabIndex = 33;
			this->l1na5->Text = L"1->5 : 0";
			// 
			// l2na1
			// 
			this->l2na1->AutoSize = true;
			this->l2na1->Location = System::Drawing::Point(569, 370);
			this->l2na1->Name = L"l2na1";
			this->l2na1->Size = System::Drawing::Size(43, 13);
			this->l2na1->TabIndex = 34;
			this->l2na1->Text = L"2->1 : 0";
			// 
			// l2na3
			// 
			this->l2na3->AutoSize = true;
			this->l2na3->Location = System::Drawing::Point(569, 390);
			this->l2na3->Name = L"l2na3";
			this->l2na3->Size = System::Drawing::Size(43, 13);
			this->l2na3->TabIndex = 35;
			this->l2na3->Text = L"2->3 : 0";
			// 
			// l2na4
			// 
			this->l2na4->AutoSize = true;
			this->l2na4->Location = System::Drawing::Point(569, 412);
			this->l2na4->Name = L"l2na4";
			this->l2na4->Size = System::Drawing::Size(43, 13);
			this->l2na4->TabIndex = 36;
			this->l2na4->Text = L"2->4 : 0";
			// 
			// l2na5
			// 
			this->l2na5->AutoSize = true;
			this->l2na5->Location = System::Drawing::Point(569, 428);
			this->l2na5->Name = L"l2na5";
			this->l2na5->Size = System::Drawing::Size(43, 13);
			this->l2na5->TabIndex = 37;
			this->l2na5->Text = L"2->5 : 0";
			// 
			// l3na1
			// 
			this->l3na1->AutoSize = true;
			this->l3na1->Location = System::Drawing::Point(204, 251);
			this->l3na1->Name = L"l3na1";
			this->l3na1->Size = System::Drawing::Size(43, 13);
			this->l3na1->TabIndex = 38;
			this->l3na1->Text = L"3->1 : 0";
			// 
			// l3na2
			// 
			this->l3na2->AutoSize = true;
			this->l3na2->Location = System::Drawing::Point(204, 271);
			this->l3na2->Name = L"l3na2";
			this->l3na2->Size = System::Drawing::Size(43, 13);
			this->l3na2->TabIndex = 39;
			this->l3na2->Text = L"3->2 : 0";
			// 
			// l3na4
			// 
			this->l3na4->AutoSize = true;
			this->l3na4->Location = System::Drawing::Point(204, 295);
			this->l3na4->Name = L"l3na4";
			this->l3na4->Size = System::Drawing::Size(43, 13);
			this->l3na4->TabIndex = 40;
			this->l3na4->Text = L"3->4 : 0";
			// 
			// l3na5
			// 
			this->l3na5->AutoSize = true;
			this->l3na5->Location = System::Drawing::Point(204, 314);
			this->l3na5->Name = L"l3na5";
			this->l3na5->Size = System::Drawing::Size(43, 13);
			this->l3na5->TabIndex = 41;
			this->l3na5->Text = L"3->5 : 0";
			// 
			// l4na1
			// 
			this->l4na1->AutoSize = true;
			this->l4na1->Location = System::Drawing::Point(563, 136);
			this->l4na1->Name = L"l4na1";
			this->l4na1->Size = System::Drawing::Size(43, 13);
			this->l4na1->TabIndex = 42;
			this->l4na1->Text = L"4->1 : 0";
			// 
			// l4na2
			// 
			this->l4na2->AutoSize = true;
			this->l4na2->Location = System::Drawing::Point(563, 154);
			this->l4na2->Name = L"l4na2";
			this->l4na2->Size = System::Drawing::Size(43, 13);
			this->l4na2->TabIndex = 43;
			this->l4na2->Text = L"4->2 : 0";
			// 
			// l4na3
			// 
			this->l4na3->AutoSize = true;
			this->l4na3->Location = System::Drawing::Point(563, 173);
			this->l4na3->Name = L"l4na3";
			this->l4na3->Size = System::Drawing::Size(43, 13);
			this->l4na3->TabIndex = 44;
			this->l4na3->Text = L"4->3 : 0";
			// 
			// l4na5
			// 
			this->l4na5->AutoSize = true;
			this->l4na5->Location = System::Drawing::Point(563, 195);
			this->l4na5->Name = L"l4na5";
			this->l4na5->Size = System::Drawing::Size(43, 13);
			this->l4na5->TabIndex = 45;
			this->l4na5->Text = L"4->5 : 0";
			// 
			// l5na1
			// 
			this->l5na1->AutoSize = true;
			this->l5na1->Location = System::Drawing::Point(202, 77);
			this->l5na1->Name = L"l5na1";
			this->l5na1->Size = System::Drawing::Size(43, 13);
			this->l5na1->TabIndex = 46;
			this->l5na1->Text = L"5->1 : 0";
			// 
			// l5na2
			// 
			this->l5na2->AutoSize = true;
			this->l5na2->Location = System::Drawing::Point(202, 99);
			this->l5na2->Name = L"l5na2";
			this->l5na2->Size = System::Drawing::Size(43, 13);
			this->l5na2->TabIndex = 47;
			this->l5na2->Text = L"5->2 : 0";
			// 
			// l5na3
			// 
			this->l5na3->AutoSize = true;
			this->l5na3->Location = System::Drawing::Point(202, 122);
			this->l5na3->Name = L"l5na3";
			this->l5na3->Size = System::Drawing::Size(43, 13);
			this->l5na3->TabIndex = 48;
			this->l5na3->Text = L"5->3 : 0";
			// 
			// l5na4
			// 
			this->l5na4->AutoSize = true;
			this->l5na4->Location = System::Drawing::Point(202, 141);
			this->l5na4->Name = L"l5na4";
			this->l5na4->Size = System::Drawing::Size(43, 13);
			this->l5na4->TabIndex = 49;
			this->l5na4->Text = L"5->4 : 0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1308, 620);
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

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		pozycja_windy -= 2 * kierunek;
		this->pictureBox2->Location = System::Drawing::Point(288, pozycja_windy);

		if (pozycja_windy == cel_windy)
			this->timer1->Stop();

	}

	private: System::Void b1na2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i1na2++;
		s1na2 = Convert::ToString(i1na2);
		l1na2->Text = "1->2 : " + s1na2;
		//Pietro_2();
	}

	private: System::Void b2na3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i2na3++;
		s2na3 = Convert::ToString(i2na3);
		l2na3->Text = "2->3 : " + s2na3;
		//Pietro_3();
	}
	private: System::Void b3na2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i3na2++;
		s3na2 = Convert::ToString(i3na2);
		l3na2->Text = "3->2 : " + s3na2;
		//Pietro_2();
	}
	private: System::Void b4na2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i4na2++;
		s4na2 = Convert::ToString(i4na2);
		l4na2->Text = "4->2 : " + s4na2;
		//Pietro_2();
	}
	private: System::Void b5na2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i5na2++;
		s5na2 = Convert::ToString(i5na2);
		l5na2->Text = "5->2 : " + s5na2;
		//Pietro_2();
	}

	private: System::Void b1na3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i1na3++;
		s1na3 = Convert::ToString(i1na3);
		l1na3->Text = "1->3 : " + s1na3;
		//Pietro_3();
	}
	private: System::Void b4na3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i4na3++;
		s4na3 = Convert::ToString(i4na3);
		l4na3->Text = "4->3 : " + s4na3;
		//Pietro_3();
	}
	private: System::Void b5na3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i5na3++;
		s5na3 = Convert::ToString(i5na3);
		l5na3->Text = "5->3 : " + s5na3;
		//Pietro_3();
	}

	private: System::Void b2na1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i2na1++;
		s2na1 = Convert::ToString(i2na1);
		l2na1->Text = "2->1 : " + s2na1;
		//Pietro_1();
	}
	private: System::Void b3na1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i3na1++;
		s3na1 = Convert::ToString(i3na1);
		l3na1->Text = "3->1 : " + s3na1;
		//Pietro_1();
	}
	private: System::Void b4na1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i4na1++;
		s4na1 = Convert::ToString(i4na1);
		l4na1->Text = "4->1 : " + s4na1;
		//Pietro_1();
	}
	private: System::Void b5na1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i5na1++;
		s5na1 = Convert::ToString(i5na1);
		l5na1->Text = "5->1 : " + s5na1;
		//Pietro_1();
	}

	private: System::Void b5na4_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i5na4++;
		s5na4 = Convert::ToString(i5na4);
		l5na4->Text = "5->4 : " + s5na4;
		//Pietro_4();
	}
	private: System::Void b3na4_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i3na4++;
		s3na4 = Convert::ToString(i3na4);
		l3na4->Text = "3->4 : " + s3na4;
		//Pietro_4();
	}
	private: System::Void b2na4_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i2na4++;
		s2na4 = Convert::ToString(i2na4);
		l2na4->Text = "2->4 : " + s2na4;
		//Pietro_4();
	}
	private: System::Void b1na4_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i1na4++;
		s1na4 = Convert::ToString(i1na4);
		l1na4->Text = "1->4 : " + s1na4;
		//Pietro_4();
	}

	private: System::Void b4na5_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i4na5++;
		s4na5 = Convert::ToString(i4na5);
		l4na5->Text = "4->5 : " + s4na5;
		//Pietro_5();
	}
	private: System::Void b3na5_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i3na5++;
		s3na5 = Convert::ToString(i3na5);
		l3na5->Text = "3->5 : " + s3na5;
		//Pietro_5();
	}
	private: System::Void b2na5_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i2na5++;
		s2na5 = Convert::ToString(i2na5);
		l2na5->Text = "2->5 : " + s2na5;
		//Pietro_5();
	}
	private: System::Void b1na5_Click(System::Object^  sender, System::EventArgs^  e)
	{
		i1na5++;
		s1na5 = Convert::ToString(i1na5);
		l1na5->Text = "1->5 : " + s1na5;
		//Pietro_5();
	}
	
};
}
