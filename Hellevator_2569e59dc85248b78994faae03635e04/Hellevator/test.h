#pragma once

namespace Hellevator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o test
	/// </summary>
	public ref class test : public System::Windows::Forms::Form
	{
	public:
		test(void)
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
		~test()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  P1_2;
	private: System::Windows::Forms::Button^  P1_3;
	private: System::Windows::Forms::Button^  P1_4;
	private: System::Windows::Forms::Button^  P1_5;
	private: System::Windows::Forms::Button^  P2_1;
	private: System::Windows::Forms::Button^  P2_3;
	private: System::Windows::Forms::Button^  P2_4;
	private: System::Windows::Forms::Button^  P2_5;
	private: System::Windows::Forms::Button^  P3_1;
	private: System::Windows::Forms::Button^  P3_2;
	private: System::Windows::Forms::Button^  P3_4;
	private: System::Windows::Forms::Button^  P3_5;
	private: System::Windows::Forms::Button^  P4_1;
	private: System::Windows::Forms::Button^  P4_2;
	private: System::Windows::Forms::Button^  P4_3;
	private: System::Windows::Forms::Button^  P4_5;
	private: System::Windows::Forms::Button^  P5_1;
	private: System::Windows::Forms::Button^  P5_2;
	private: System::Windows::Forms::Button^  P5_3;
	private: System::Windows::Forms::Button^  P5_4;
	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Wymagana metoda obs³ugi projektanta — nie nale¿y modyfikowaæ 
		/// zawartoœæ tej metody z edytorem kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->P1_2 = (gcnew System::Windows::Forms::Button());
			this->P1_3 = (gcnew System::Windows::Forms::Button());
			this->P1_4 = (gcnew System::Windows::Forms::Button());
			this->P1_5 = (gcnew System::Windows::Forms::Button());
			this->P2_1 = (gcnew System::Windows::Forms::Button());
			this->P2_3 = (gcnew System::Windows::Forms::Button());
			this->P2_4 = (gcnew System::Windows::Forms::Button());
			this->P2_5 = (gcnew System::Windows::Forms::Button());
			this->P3_1 = (gcnew System::Windows::Forms::Button());
			this->P3_2 = (gcnew System::Windows::Forms::Button());
			this->P3_4 = (gcnew System::Windows::Forms::Button());
			this->P3_5 = (gcnew System::Windows::Forms::Button());
			this->P4_1 = (gcnew System::Windows::Forms::Button());
			this->P4_2 = (gcnew System::Windows::Forms::Button());
			this->P4_3 = (gcnew System::Windows::Forms::Button());
			this->P4_5 = (gcnew System::Windows::Forms::Button());
			this->P5_1 = (gcnew System::Windows::Forms::Button());
			this->P5_2 = (gcnew System::Windows::Forms::Button());
			this->P5_3 = (gcnew System::Windows::Forms::Button());
			this->P5_4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// P1_2
			// 
			this->P1_2->Location = System::Drawing::Point(61, 517);
			this->P1_2->Name = L"P1_2";
			this->P1_2->Size = System::Drawing::Size(25, 25);
			this->P1_2->TabIndex = 0;
			this->P1_2->Text = L"2";
			this->P1_2->UseVisualStyleBackColor = true;
			// 
			// P1_3
			// 
			this->P1_3->Location = System::Drawing::Point(61, 486);
			this->P1_3->Name = L"P1_3";
			this->P1_3->Size = System::Drawing::Size(25, 25);
			this->P1_3->TabIndex = 1;
			this->P1_3->Text = L"3";
			this->P1_3->UseVisualStyleBackColor = true;
			// 
			// P1_4
			// 
			this->P1_4->Location = System::Drawing::Point(61, 455);
			this->P1_4->Name = L"P1_4";
			this->P1_4->Size = System::Drawing::Size(25, 25);
			this->P1_4->TabIndex = 2;
			this->P1_4->Text = L"4";
			this->P1_4->UseVisualStyleBackColor = true;
			// 
			// P1_5
			// 
			this->P1_5->Location = System::Drawing::Point(61, 424);
			this->P1_5->Name = L"P1_5";
			this->P1_5->Size = System::Drawing::Size(25, 25);
			this->P1_5->TabIndex = 3;
			this->P1_5->Text = L"5";
			this->P1_5->UseVisualStyleBackColor = true;
			// 
			// P2_1
			// 
			this->P2_1->Location = System::Drawing::Point(980, 390);
			this->P2_1->Name = L"P2_1";
			this->P2_1->Size = System::Drawing::Size(25, 25);
			this->P2_1->TabIndex = 5;
			this->P2_1->Text = L"1";
			this->P2_1->UseVisualStyleBackColor = true;
			// 
			// P2_3
			// 
			this->P2_3->Location = System::Drawing::Point(980, 359);
			this->P2_3->Name = L"P2_3";
			this->P2_3->Size = System::Drawing::Size(25, 25);
			this->P2_3->TabIndex = 7;
			this->P2_3->Text = L"3";
			this->P2_3->UseVisualStyleBackColor = true;
			// 
			// P2_4
			// 
			this->P2_4->Location = System::Drawing::Point(980, 328);
			this->P2_4->Name = L"P2_4";
			this->P2_4->Size = System::Drawing::Size(25, 25);
			this->P2_4->TabIndex = 9;
			this->P2_4->Text = L"4";
			this->P2_4->UseVisualStyleBackColor = true;
			// 
			// P2_5
			// 
			this->P2_5->Location = System::Drawing::Point(980, 297);
			this->P2_5->Name = L"P2_5";
			this->P2_5->Size = System::Drawing::Size(25, 25);
			this->P2_5->TabIndex = 11;
			this->P2_5->Text = L"5";
			this->P2_5->UseVisualStyleBackColor = true;
			// 
			// P3_1
			// 
			this->P3_1->Location = System::Drawing::Point(61, 309);
			this->P3_1->Name = L"P3_1";
			this->P3_1->Size = System::Drawing::Size(25, 25);
			this->P3_1->TabIndex = 13;
			this->P3_1->Text = L"1";
			this->P3_1->UseVisualStyleBackColor = true;
			// 
			// P3_2
			// 
			this->P3_2->Location = System::Drawing::Point(61, 278);
			this->P3_2->Name = L"P3_2";
			this->P3_2->Size = System::Drawing::Size(25, 25);
			this->P3_2->TabIndex = 15;
			this->P3_2->Text = L"2";
			this->P3_2->UseVisualStyleBackColor = true;
			// 
			// P3_4
			// 
			this->P3_4->Location = System::Drawing::Point(61, 247);
			this->P3_4->Name = L"P3_4";
			this->P3_4->Size = System::Drawing::Size(25, 25);
			this->P3_4->TabIndex = 17;
			this->P3_4->Text = L"4";
			this->P3_4->UseVisualStyleBackColor = true;
			// 
			// P3_5
			// 
			this->P3_5->Location = System::Drawing::Point(61, 216);
			this->P3_5->Name = L"P3_5";
			this->P3_5->Size = System::Drawing::Size(25, 25);
			this->P3_5->TabIndex = 19;
			this->P3_5->Text = L"5";
			this->P3_5->UseVisualStyleBackColor = true;
			// 
			// P4_1
			// 
			this->P4_1->Location = System::Drawing::Point(980, 216);
			this->P4_1->Name = L"P4_1";
			this->P4_1->Size = System::Drawing::Size(25, 25);
			this->P4_1->TabIndex = 21;
			this->P4_1->Text = L"1";
			this->P4_1->UseVisualStyleBackColor = true;
			// 
			// P4_2
			// 
			this->P4_2->Location = System::Drawing::Point(980, 185);
			this->P4_2->Name = L"P4_2";
			this->P4_2->Size = System::Drawing::Size(25, 25);
			this->P4_2->TabIndex = 23;
			this->P4_2->Text = L"2";
			this->P4_2->UseVisualStyleBackColor = true;
			// 
			// P4_3
			// 
			this->P4_3->Location = System::Drawing::Point(980, 154);
			this->P4_3->Name = L"P4_3";
			this->P4_3->Size = System::Drawing::Size(25, 25);
			this->P4_3->TabIndex = 25;
			this->P4_3->Text = L"3";
			this->P4_3->UseVisualStyleBackColor = true;
			// 
			// P4_5
			// 
			this->P4_5->Location = System::Drawing::Point(980, 123);
			this->P4_5->Name = L"P4_5";
			this->P4_5->Size = System::Drawing::Size(25, 25);
			this->P4_5->TabIndex = 27;
			this->P4_5->Text = L"5";
			this->P4_5->UseVisualStyleBackColor = true;
			// 
			// P5_1
			// 
			this->P5_1->Location = System::Drawing::Point(61, 123);
			this->P5_1->Name = L"P5_1";
			this->P5_1->Size = System::Drawing::Size(25, 25);
			this->P5_1->TabIndex = 29;
			this->P5_1->Text = L"1";
			this->P5_1->UseVisualStyleBackColor = true;
			// 
			// P5_2
			// 
			this->P5_2->Location = System::Drawing::Point(61, 92);
			this->P5_2->Name = L"P5_2";
			this->P5_2->Size = System::Drawing::Size(25, 25);
			this->P5_2->TabIndex = 31;
			this->P5_2->Text = L"2";
			this->P5_2->UseVisualStyleBackColor = true;
			// 
			// P5_3
			// 
			this->P5_3->Location = System::Drawing::Point(61, 61);
			this->P5_3->Name = L"P5_3";
			this->P5_3->Size = System::Drawing::Size(25, 25);
			this->P5_3->TabIndex = 33;
			this->P5_3->Text = L"3";
			this->P5_3->UseVisualStyleBackColor = true;
			// 
			// P5_4
			// 
			this->P5_4->Location = System::Drawing::Point(61, 30);
			this->P5_4->Name = L"P5_4";
			this->P5_4->Size = System::Drawing::Size(25, 25);
			this->P5_4->TabIndex = 35;
			this->P5_4->Text = L"4";
			this->P5_4->UseVisualStyleBackColor = true;
			// 
			// test
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1064, 561);
			this->Controls->Add(this->P5_4);
			this->Controls->Add(this->P5_3);
			this->Controls->Add(this->P5_2);
			this->Controls->Add(this->P5_1);
			this->Controls->Add(this->P4_5);
			this->Controls->Add(this->P4_3);
			this->Controls->Add(this->P4_2);
			this->Controls->Add(this->P4_1);
			this->Controls->Add(this->P3_5);
			this->Controls->Add(this->P3_4);
			this->Controls->Add(this->P3_2);
			this->Controls->Add(this->P3_1);
			this->Controls->Add(this->P2_5);
			this->Controls->Add(this->P2_4);
			this->Controls->Add(this->P2_3);
			this->Controls->Add(this->P2_1);
			this->Controls->Add(this->P1_5);
			this->Controls->Add(this->P1_4);
			this->Controls->Add(this->P1_3);
			this->Controls->Add(this->P1_2);
			this->Name = L"test";
			this->Text = L"4";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
