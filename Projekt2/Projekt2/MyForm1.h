#pragma once
namespace Projekt2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
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


	private: System::Windows::Forms::CheckedListBox^  checkedListBox1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::CheckedListBox^  checkedListBox2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button5;




	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Timer^  parter;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Timer^  pietro1;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Timer^  pietro2;
	private: System::Windows::Forms::Timer^  pietro3;







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
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->checkedListBox2 = (gcnew System::Windows::Forms::CheckedListBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->parter = (gcnew System::Windows::Forms::Timer(this->components));
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->pietro1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->pietro2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pietro3 = (gcnew System::Windows::Forms::Timer(this->components));
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
			// button3
			// 
			this->button3->Location = System::Drawing::Point(575, 543);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(19, 22);
			this->button3->TabIndex = 17;
			this->button3->Text = L"P";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm1::button3_Click);
			// 
			// parter
			// 
			this->parter->Interval = 1;
			this->parter->Tick += gcnew System::EventHandler(this, &MyForm1::parter_Tick);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(575, 387);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(19, 22);
			this->button4->TabIndex = 18;
			this->button4->Text = L"1";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm1::button4_Click);
			// 
			// pietro1
			// 
			this->pietro1->Interval = 1;
			this->pietro1->Tick += gcnew System::EventHandler(this, &MyForm1::pietro1_Tick);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(575, 270);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(19, 25);
			this->button6->TabIndex = 19;
			this->button6->Text = L"2";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm1::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(575, 164);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(19, 22);
			this->button7->TabIndex = 20;
			this->button7->Text = L"3";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm1::button7_Click);
			// 
			// pietro2
			// 
			this->pietro2->Interval = 1;
			this->pietro2->Tick += gcnew System::EventHandler(this, &MyForm1::pietro2_Tick);
			// 
			// pietro3
			// 
			this->pietro3->Interval = 1;
			this->pietro3->Tick += gcnew System::EventHandler(this, &MyForm1::pietro3_Tick);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1062, 645);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
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
private: System::Void parter_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (pictureBox2->Top < 470)
		this->pictureBox2->Top += 1;
	else if (pictureBox2->Top > 470)
		this->pictureBox2->Top -= 1;
	else if (pictureBox2->Top == 470)
		parter->Stop();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	parter->Start();
}
private: System::Void pietro1_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (pictureBox2->Top < 330)
		this->pictureBox2->Top += 1;
	else if (pictureBox2->Top > 330)
		this->pictureBox2->Top -= 1;
	else if (pictureBox2->Top == 330)
		pietro1->Stop();
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	pietro1->Start();
}
private: System::Void pietro2_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (pictureBox2->Top < 205)
		this->pictureBox2->Top += 1;
	else if (pictureBox2->Top > 205)
		this->pictureBox2->Top -= 1;
	else if (pictureBox2->Top == 205)
		pietro2->Stop();
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	pietro2->Start();
}
private: System::Void pietro3_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (pictureBox2->Top < 100)
		this->pictureBox2->Top += 1;
	else if (pictureBox2->Top > 100)
		this->pictureBox2->Top -= 1;
	else if (pictureBox2->Top == 100)
		pietro3->Stop();
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	pietro3->Start();
}
};
}
