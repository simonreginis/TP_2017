#pragma once
namespace Projekt2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	int pietro0 = 0;
	int pietro1 = 0;
	int pietro2 = 0;
	int pietro3 = 0;
	int origin = 0;
	int target = 0;

	/// <summary>
	/// Podsumowanie informacji o MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
		static
			int czas = 0;
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Timer^  gora;

	private: System::Windows::Forms::CheckedListBox^  checkedListBox1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::CheckedListBox^  checkedListBox2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Timer^  dol;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;






	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Wymagana metoda obs³ugi projektanta — nie nale¿y modyfikowaæ 
		/// zawartoœæ tej metody z edytorem kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->gora = (gcnew System::Windows::Forms::Timer(this->components));
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->checkedListBox2 = (gcnew System::Windows::Forms::CheckedListBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->dol = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1064, 646);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(282, 482);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(287, 109);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MyForm1::pictureBox2_Click);
			// 
			// gora
			// 
			this->gora->Interval = 1;
			this->gora->Tick += gcnew System::EventHandler(this, &MyForm1::timer1_Tick);
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"3", L"2", L"1", L"0" });
			this->checkedListBox1->Location = System::Drawing::Point(164, 373);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(36, 64);
			this->checkedListBox1->TabIndex = 9;
			this->checkedListBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm1::checkedListBox1_SelectedIndexChanged);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 312);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 10;
			this->textBox1->Text = L"Dodaj pasa¿era";
			// 
			// checkedListBox2
			// 
			this->checkedListBox2->FormattingEnabled = true;
			this->checkedListBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"3", L"2", L"1", L"0" });
			this->checkedListBox2->Location = System::Drawing::Point(51, 373);
			this->checkedListBox2->Name = L"checkedListBox2";
			this->checkedListBox2->Size = System::Drawing::Size(40, 64);
			this->checkedListBox2->TabIndex = 11;
			this->checkedListBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm1::checkedListBox2_SelectedIndexChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 347);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(44, 20);
			this->textBox2->TabIndex = 12;
			this->textBox2->Text = L"Z piêtra:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(117, 347);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(52, 20);
			this->textBox3->TabIndex = 13;
			this->textBox3->Text = L"Na piêtro:";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(125, 458);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 14;
			this->button5->Text = L"Dodaj";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm1::button5_Click);
			// 
			// dol
			// 
			this->dol->Interval = 1;
			this->dol->Tick += gcnew System::EventHandler(this, &MyForm1::timer2_Tick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(26, 107);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 15;
			this->button1->Text = L"up";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click_1);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(26, 136);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 16;
			this->button2->Text = L"down";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1062, 645);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->checkedListBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->checkedListBox1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox2_Click(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		this->pictureBox2->Top -= 3;
		czas++;
		if (czas == 40) {
			this->gora->Stop();
			czas = 0;
		}

	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void checkedListBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	
}

private: System::Void checkedListBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}

 private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	 IEnumerator^ myEnum1 = checkedListBox2->CheckedIndices->GetEnumerator();
	 while (myEnum1->MoveNext())
	 {
		 Int32 indexChecked = *safe_cast<Int32^>(myEnum1->Current);

		 origin = indexChecked;
	 }
	 IEnumerator^ myEnum2 = checkedListBox1->CheckedIndices->GetEnumerator();
	 while (myEnum2->MoveNext())
	 {
		 Int32 indexChecked = *safe_cast<Int32^>(myEnum2->Current);

		 target = indexChecked;
	 }
 }
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
	gora->Start();
}
private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
	this->pictureBox2->Top += 3;
	czas++;
	if (czas == 40) {
		this->dol->Stop();
		czas = 0;
	}
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	dol->Start();
}
};
}
