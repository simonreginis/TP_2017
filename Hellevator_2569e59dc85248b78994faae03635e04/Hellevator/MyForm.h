#pragma once
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Passenger.h"
#include "Elevator.h"
#include "Floor.h"

#define FLOOR_1_HEIGHT 715
#define FLOOR_2_HEIGHT 545
#define FLOOR_3_HEIGHT 365
#define FLOOR_4_HEIGHT 184
#define FLOOR_5_HEIGHT 3

namespace Hellevator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		static int timer = 0;
		static int positionController = 0;
	private: ArrayList^ picList = gcnew ArrayList();
	private: ArrayList^ floorsWaiting = gcnew ArrayList();
	private: int elevatorWaitLeft = 0;

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::PictureBox^  pictureBox6;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  floor1_button;
	private: System::Windows::Forms::Button^  floor2_button;
	private: System::Windows::Forms::Button^  floor3_button;
	private: System::Windows::Forms::Button^  floor4_button;
	private: System::Windows::Forms::Button^  floor5_button;
	private: Floor^ floor1;
	private: Floor^ floor2;
	private: Floor^ floor3;
	private: Floor^ floor4;
	private: Floor^ floor5;

	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: Elevator^ elevator;

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
			srand(time(NULL));
			this->timer1->Start();
			this->elevator->Size = System::Drawing::Size(294, this->Height - 40);

			this->elevator->floors->Add(floor1);
			this->elevator->floors->Add(floor2);
			this->elevator->floors->Add(floor3);
			this->elevator->floors->Add(floor4);
			this->elevator->floors->Add(floor5);
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Timer^  timer1;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->floor1_button = (gcnew System::Windows::Forms::Button());
			this->floor2_button = (gcnew System::Windows::Forms::Button());
			this->floor3_button = (gcnew System::Windows::Forms::Button());
			this->floor4_button = (gcnew System::Windows::Forms::Button());
			this->floor5_button = (gcnew System::Windows::Forms::Button());
			this->floor1 = (gcnew Floor());
			this->floor2 = (gcnew Floor());
			this->floor3 = (gcnew Floor());
			this->floor4 = (gcnew Floor());
			this->floor5 = (gcnew Floor());
			this->elevator = (gcnew Elevator());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1600, 603);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"WejdŸ do Windy";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 15;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			this->timer1->Tick += gcnew System::EventHandler(elevator, &Elevator::timer1_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(215, 643);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 100);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(1303, 482);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(100, 100);
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(215, 343);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(100, 100);
			this->pictureBox4->TabIndex = 6;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(1303, 165);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(100, 100);
			this->pictureBox5->TabIndex = 7;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(215, 12);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(100, 100);
			this->pictureBox6->TabIndex = 8;
			this->pictureBox6->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(225, 798);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(90, 90);
			this->pictureBox3->TabIndex = 10;
			this->pictureBox3->TabStop = false;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1600, 506);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Twórz";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1600, 430);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 12;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// floor1_button
			// 
			this->floor1_button->Location = System::Drawing::Point(620, 800);
			this->floor1_button->Name = L"floor1_button";
			this->floor1_button->Size = System::Drawing::Size(60, 60);
			this->floor1_button->TabIndex = 13;
			this->floor1_button->Tag = L"1";
			this->floor1_button->Text = L"O";
			this->floor1_button->UseVisualStyleBackColor = true;
			this->floor1_button->Click += gcnew System::EventHandler(this, &MyForm::floor_button_Click);
			// 
			// floor3_button
			// 
			this->floor3_button->Location = System::Drawing::Point(620, 400);
			this->floor3_button->Name = L"floor3_button";
			this->floor3_button->Size = System::Drawing::Size(60, 60);
			this->floor3_button->TabIndex = 14;
			this->floor3_button->Tag = L"3";
			this->floor3_button->Text = L"O";
			this->floor3_button->UseVisualStyleBackColor = true;
			this->floor3_button->Click += gcnew System::EventHandler(this, &MyForm::floor_button_Click);
			// 
			// floor5_button
			// 
			this->floor5_button->Location = System::Drawing::Point(620, 80);
			this->floor5_button->Name = L"floor5_button";
			this->floor5_button->Size = System::Drawing::Size(60, 60);
			this->floor5_button->TabIndex = 15;
			this->floor5_button->Tag = L"5";
			this->floor5_button->Text = L"O";
			this->floor5_button->UseVisualStyleBackColor = true;
			this->floor5_button->Click += gcnew System::EventHandler(this, &MyForm::floor_button_Click);
			// 
			// floor2_button
			// 
			this->floor2_button->Location = System::Drawing::Point(1010, 600);
			this->floor2_button->Name = L"floor2_button";
			this->floor2_button->Size = System::Drawing::Size(60, 60);
			this->floor2_button->TabIndex = 16;
			this->floor2_button->Tag = L"2";
			this->floor2_button->Text = L"O";
			this->floor2_button->UseVisualStyleBackColor = true;
			this->floor2_button->Click += gcnew System::EventHandler(this, &MyForm::floor_button_Click);
			// 
			// floor4_button
			// 
			this->floor4_button->Location = System::Drawing::Point(1010, 240);
			this->floor4_button->Name = L"floor4_button";
			this->floor4_button->Size = System::Drawing::Size(60, 60);
			this->floor4_button->TabIndex = 17;
			this->floor4_button->Tag = L"4";
			this->floor4_button->Text = L"O";
			this->floor4_button->UseVisualStyleBackColor = true;
			this->floor4_button->Click += gcnew System::EventHandler(this, &MyForm::floor_button_Click);
			// 
			// floor1
			// 
			this->floor1->Location = System::Drawing::Point(70, 850);
			this->floor1->Name = L"floor1";
			this->floor1->Size = System::Drawing::Size(600, 10);
			this->floor1->Tag = L"1";
			// 
			// floor2
			// 
			this->floor2->Location = System::Drawing::Point(1000, 700);
			this->floor2->Name = L"floor2";
			this->floor2->Size = System::Drawing::Size(600, 10);
			this->floor2->Tag = L"2";
			// 
			// floor3
			// 
			this->floor3->Location = System::Drawing::Point(70, 550);
			this->floor3->Name = L"floor3";
			this->floor3->Size = System::Drawing::Size(600, 10);
			this->floor3->Tag = L"3";
			// 
			// floor4
			// 
			this->floor4->Location = System::Drawing::Point(1000, 380);
			this->floor4->Name = L"floor4";
			this->floor4->Size = System::Drawing::Size(600, 10);
			this->floor4->Tag = L"4";
			// 
			// floor5
			// 
			this->floor5->Location = System::Drawing::Point(70, 200);
			this->floor5->Name = L"floor5";
			this->floor5->Size = System::Drawing::Size(600, 10);
			this->floor5->Tag = L"5";
			//
			// elevator
			//
			this->elevator->BackColor = System::Drawing::Color::DarkGray;
			this->elevator->Location = System::Drawing::Point(705, 0);
			this->elevator->Name = L"elevator";
			this->elevator->Size = System::Drawing::Size(294, this->Height);
			this->elevator->TabIndex = 9;
			this->elevator->TabStop = false;
			// 
			// MyForm
			// 
			this->BackColor = System::Drawing::Color::LightCyan;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1700, 900);
			this->Controls->Add(this->floor1_button);
			this->Controls->Add(this->floor2_button);
			this->Controls->Add(this->floor3_button);
			this->Controls->Add(this->floor4_button);
			this->Controls->Add(this->floor5_button);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->floor1);
			this->Controls->Add(this->floor2);
			this->Controls->Add(this->floor3);
			this->Controls->Add(this->floor4);
			this->Controls->Add(this->floor5);
			this->Controls->Add(this->elevator);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->timer1->Start();
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

		/*if (timer != 175)
		{
		moveRight(pictureBox3);
		switch (positionController)
		{
		case 0: case 1: case 2:
		moveUp(pictureBox3);
		positionController++;
		break;
		case 3: case 4: case 5:
		moveDown(pictureBox3);
		positionController++;
		break;
		case 6:
		positionController = 0;
		break;
		default:
		positionController = 0;
		break;
		}
		}
		else
		{
		this->timer1->Stop();
		timer = 0;
		}

		timer++;*/
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		for (int i = 0; i < 5; i++)
		{
			// Generowanie ludzików po naciśnięciu buttona
			Passenger^ passenger = gcnew Passenger(rand() % 1000 + 100, rand() % 1000 + 100);
			picList->Add(passenger);
			this->Controls->Add(passenger);
		}
		//Operacje na tych obiektach tutaj działają

	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		((Passenger^)picList[0])->moveDown();
	}
	private: System::Void floor_button_Click(System::Object^  sender, System::EventArgs^  e) {
		Button^ b = ((Button^)sender);
		b->BackColor = Color::GreenYellow;

		int floorTag = Convert::ToInt32(b->Tag);
		elevator->AddWaitingFloor(getFloorByTag(floorTag));
	}

	private: Floor^ getFloorByTag(int tag) {
		switch (tag) {
		case 1:
			return floor1;
		case 2:
			return floor2;
		case 3:
			return floor3;
		case 4:
			return floor4;
		case 5:
			return floor5;
		default:
			return nullptr;
		}
	}

	private: void SetWaitingButtonInactiveColor(int floorNumber) {
		Button^ b;
		switch (floorNumber) {
		case 1:
			b = floor1_button;
			break;
		case 2:
			b = floor2_button;
			break;
		case 3:
			b = floor3_button;
			break;
		case 4:
			b = floor4_button;
			break;
		case 5:
			b = floor5_button;
			break;
		default:
			return;
			break;
		}
		b->BackColor = SystemColors::ButtonFace;
	}
};
}
