#pragma once
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Passenger.h"
#include "Elevator.h"

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
			// elevator
			//
			//this->elevator->BackColor = System::Drawing::Color::Transparent;
			this->elevator->Location = System::Drawing::Point(705, 715);
			this->elevator->Name = L"elevator";
			this->elevator->Size = System::Drawing::Size(294, 180);
			this->elevator->TabIndex = 9;
			this->elevator->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
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
		timer1_Tick_MoveElevator();

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

		if (!floorsWaiting->Contains(floorTag))
			floorsWaiting->Add(floorTag);
	}

	private: void timer1_Tick_MoveElevator() {
		if (elevatorWaitLeft > -300)
			elevatorWaitLeft--;
		else
			floorsWaiting->Add(1);

		if (elevatorWaitLeft <= 0 && floorsWaiting->Count > 0) {
			int elevatorLocation = elevator->Location.Y;

			if (elevatorLocation < GetFloorHeight((int)floorsWaiting[0])) {
				elevator->Location = Point(elevator->Location.X, elevator->Location.Y + 1);
				elevatorWaitLeft = 0;
			}
			else if (elevatorLocation > GetFloorHeight((int)floorsWaiting[0])) {
				elevator->Location = Point(elevator->Location.X, elevator->Location.Y - 1);
				elevatorWaitLeft = 0;
			}
			else {
				SetWaitingButtonInactiveColor((int)floorsWaiting[0]);
				elevatorWaitLeft = 200;
				floorsWaiting->RemoveAt(0);
			}
		}
	}

	private: int GetFloorHeight(int floorNumber) {
		switch (floorNumber) {
		case 1:
			return FLOOR_1_HEIGHT;
		case 2:
			return FLOOR_2_HEIGHT;
		case 3:
			return FLOOR_3_HEIGHT;
		case 4:
			return FLOOR_4_HEIGHT;
		case 5:
			return FLOOR_5_HEIGHT;
		default:
			return NULL;
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
