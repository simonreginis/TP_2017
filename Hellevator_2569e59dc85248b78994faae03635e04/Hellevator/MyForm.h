#pragma once
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Passenger.h"
#include "Elevator.h"
#include "Floor.h"
#include "FloorEventArgs.h"
#include "ElevatorCallButton.h"
#include "CreateButton.h"

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
	private: CreateButton^  P1_2;
	private: CreateButton^  P1_3;
	private: CreateButton^  P1_4;
	private: CreateButton^  P1_5;
	private: CreateButton^  P2_1;
	private: CreateButton^  P2_3;
	private: CreateButton^  P2_4;
	private: CreateButton^  P2_5;
	private: CreateButton^  P3_1;
	private: CreateButton^  P3_2;
	private: CreateButton^  P3_4;
	private: CreateButton^  P3_5;
	private: CreateButton^  P4_1;
	private: CreateButton^  P4_2;
	private: CreateButton^  P4_3;
	private: CreateButton^  P4_5;
	private: CreateButton^  P5_1;
	private: CreateButton^  P5_2;
	private: CreateButton^  P5_3;
	private: CreateButton^  P5_4;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::PictureBox^  pictureBox6;
	private: ElevatorCallButton^  floor1_button;
	private: ElevatorCallButton^  floor2_button;
	private: ElevatorCallButton^  floor3_button;
	private: ElevatorCallButton^  floor4_button;
	private: ElevatorCallButton^  floor5_button;
	private: Floor^ floor1;
	private: Floor^ floor2;
	private: Floor^ floor3;
	private: Floor^ floor4;
	private: Floor^ floor5;

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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->P1_2 = (gcnew CreateButton());
			this->P1_3 = (gcnew CreateButton());
			this->P1_4 = (gcnew CreateButton());
			this->P1_5 = (gcnew CreateButton());
			this->P2_1 = (gcnew CreateButton());
			this->P2_3 = (gcnew CreateButton());
			this->P2_4 = (gcnew CreateButton());
			this->P2_5 = (gcnew CreateButton());
			this->P3_1 = (gcnew CreateButton());
			this->P3_2 = (gcnew CreateButton());
			this->P3_4 = (gcnew CreateButton());
			this->P3_5 = (gcnew CreateButton());
			this->P4_1 = (gcnew CreateButton());
			this->P4_2 = (gcnew CreateButton());
			this->P4_3 = (gcnew CreateButton());
			this->P4_5 = (gcnew CreateButton());
			this->P5_1 = (gcnew CreateButton());
			this->P5_2 = (gcnew CreateButton());
			this->P5_3 = (gcnew CreateButton());
			this->P5_4 = (gcnew CreateButton());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->floor1_button = (gcnew ElevatorCallButton());
			this->floor2_button = (gcnew ElevatorCallButton());
			this->floor3_button = (gcnew ElevatorCallButton());
			this->floor4_button = (gcnew ElevatorCallButton());
			this->floor5_button = (gcnew ElevatorCallButton());
			this->floor1 = (gcnew Floor());
			this->floor2 = (gcnew Floor());
			this->floor3 = (gcnew Floor());
			this->floor4 = (gcnew Floor());
			this->floor5 = (gcnew Floor());
			this->elevator = (gcnew Elevator(floor1));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 15;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			this->timer1->Tick += gcnew System::EventHandler(elevator, &Elevator::timer1_Tick);
			// 
			// P1_2
			// 
			this->P1_2->Location = System::Drawing::Point(61, 517);
			this->P1_2->Name = L"P1_2";
			this->P1_2->Size = System::Drawing::Size(25, 25);
			this->P1_2->TabIndex = 0;
			this->P1_2->Text = L"2";
			this->P1_2->UseVisualStyleBackColor = true;
			this->P1_2->CurrentFloor = 1;
			this->P1_2->DestinationFloor = 2;
			this->P1_2->Click += gcnew System::EventHandler(this, &MyForm::create_button_Click);
			// 
			// P1_3
			// 
			this->P1_3->Location = System::Drawing::Point(61, 486);
			this->P1_3->Name = L"P1_3";
			this->P1_3->Size = System::Drawing::Size(25, 25);
			this->P1_3->TabIndex = 1;
			this->P1_3->Text = L"3";
			this->P1_3->UseVisualStyleBackColor = true;
			this->P1_3->CurrentFloor = 1;
			this->P1_3->DestinationFloor = 3;
			this->P1_3->Click += gcnew System::EventHandler(this, &MyForm::create_button_Click);
			// 
			// P1_4
			// 
			this->P1_4->Location = System::Drawing::Point(61, 455);
			this->P1_4->Name = L"P1_4";
			this->P1_4->Size = System::Drawing::Size(25, 25);
			this->P1_4->TabIndex = 2;
			this->P1_4->Text = L"4";
			this->P1_4->UseVisualStyleBackColor = true;
			this->P1_4->CurrentFloor = 1;
			this->P1_4->DestinationFloor = 4;
			this->P1_4->Click += gcnew System::EventHandler(this, &MyForm::create_button_Click);
			// 
			// P1_5
			// 
			this->P1_5->Location = System::Drawing::Point(61, 424);
			this->P1_5->Name = L"P1_5";
			this->P1_5->Size = System::Drawing::Size(25, 25);
			this->P1_5->TabIndex = 3;
			this->P1_5->Text = L"5";
			this->P1_5->UseVisualStyleBackColor = true;
			this->P1_5->CurrentFloor = 1;
			this->P1_5->DestinationFloor = 5;
			this->P1_5->Click += gcnew System::EventHandler(this, &MyForm::create_button_Click);
			// 
			// P2_1
			// 
			this->P2_1->Location = System::Drawing::Point(980, 390);
			this->P2_1->Name = L"P2_1";
			this->P2_1->Size = System::Drawing::Size(25, 25);
			this->P2_1->TabIndex = 5;
			this->P2_1->Text = L"1";
			this->P2_1->UseVisualStyleBackColor = true;
			this->P2_1->CurrentFloor = 2;
			this->P2_1->DestinationFloor = 1;
			this->P2_1->Click += gcnew System::EventHandler(this, &MyForm::create_button_Click);
			// 
			// P2_3
			// 
			this->P2_3->Location = System::Drawing::Point(980, 359);
			this->P2_3->Name = L"P2_3";
			this->P2_3->Size = System::Drawing::Size(25, 25);
			this->P2_3->TabIndex = 7;
			this->P2_3->Text = L"3";
			this->P2_3->UseVisualStyleBackColor = true;
			this->P2_3->CurrentFloor = 2;
			this->P2_3->DestinationFloor = 3;
			this->P2_3->Click += gcnew System::EventHandler(this, &MyForm::create_button_Click);
			// 
			// P2_4
			// 
			this->P2_4->Location = System::Drawing::Point(980, 328);
			this->P2_4->Name = L"P2_4";
			this->P2_4->Size = System::Drawing::Size(25, 25);
			this->P2_4->TabIndex = 9;
			this->P2_4->Text = L"4";
			this->P2_4->UseVisualStyleBackColor = true;
			this->P2_4->CurrentFloor = 2;
			this->P2_4->DestinationFloor = 4;
			this->P2_4->Click += gcnew System::EventHandler(this, &MyForm::create_button_Click);
			// 
			// P2_5
			// 
			this->P2_5->Location = System::Drawing::Point(980, 297);
			this->P2_5->Name = L"P2_5";
			this->P2_5->Size = System::Drawing::Size(25, 25);
			this->P2_5->TabIndex = 11;
			this->P2_5->Text = L"5";
			this->P2_5->UseVisualStyleBackColor = true;
			this->P2_5->CurrentFloor = 2;
			this->P2_5->DestinationFloor = 5;
			this->P2_5->Click += gcnew System::EventHandler(this, &MyForm::create_button_Click);
			// 
			// P3_1
			// 
			this->P3_1->Location = System::Drawing::Point(61, 309);
			this->P3_1->Name = L"P3_1";
			this->P3_1->Size = System::Drawing::Size(25, 25);
			this->P3_1->TabIndex = 13;
			this->P3_1->Text = L"1";
			this->P3_1->UseVisualStyleBackColor = true;
			this->P3_1->CurrentFloor = 3;
			this->P3_1->DestinationFloor = 1;
			this->P3_1->Click += gcnew System::EventHandler(this, &MyForm::create_button_Click);
			// 
			// P3_2
			// 
			this->P3_2->Location = System::Drawing::Point(61, 278);
			this->P3_2->Name = L"P3_2";
			this->P3_2->Size = System::Drawing::Size(25, 25);
			this->P3_2->TabIndex = 15;
			this->P3_2->Text = L"2";
			this->P3_2->UseVisualStyleBackColor = true;
			this->P3_2->CurrentFloor = 3;
			this->P3_2->DestinationFloor = 2;
			this->P3_2->Click += gcnew System::EventHandler(this, &MyForm::create_button_Click);
			// 
			// P3_4
			// 
			this->P3_4->Location = System::Drawing::Point(61, 247);
			this->P3_4->Name = L"P3_4";
			this->P3_4->Size = System::Drawing::Size(25, 25);
			this->P3_4->TabIndex = 17;
			this->P3_4->Text = L"4";
			this->P3_4->UseVisualStyleBackColor = true;
			this->P3_4->CurrentFloor = 3;
			this->P3_4->DestinationFloor = 4;
			this->P3_4->Click += gcnew System::EventHandler(this, &MyForm::create_button_Click);
			// 
			// P3_5
			// 
			this->P3_5->Location = System::Drawing::Point(61, 216);
			this->P3_5->Name = L"P3_5";
			this->P3_5->Size = System::Drawing::Size(25, 25);
			this->P3_5->TabIndex = 19;
			this->P3_5->Text = L"5";
			this->P3_5->UseVisualStyleBackColor = true;
			this->P3_5->CurrentFloor = 3;
			this->P3_5->DestinationFloor = 5;
			this->P3_5->Click += gcnew System::EventHandler(this, &MyForm::create_button_Click);
			// 
			// P4_1
			// 
			this->P4_1->Location = System::Drawing::Point(980, 216);
			this->P4_1->Name = L"P4_1";
			this->P4_1->Size = System::Drawing::Size(25, 25);
			this->P4_1->TabIndex = 21;
			this->P4_1->Text = L"1";
			this->P4_1->UseVisualStyleBackColor = true;
			this->P4_1->CurrentFloor = 4;
			this->P4_1->DestinationFloor = 1;
			this->P4_1->Click += gcnew System::EventHandler(this, &MyForm::create_button_Click);
			// 
			// P4_2
			// 
			this->P4_2->Location = System::Drawing::Point(980, 185);
			this->P4_2->Name = L"P4_2";
			this->P4_2->Size = System::Drawing::Size(25, 25);
			this->P4_2->TabIndex = 23;
			this->P4_2->Text = L"2";
			this->P4_2->UseVisualStyleBackColor = true;
			this->P4_2->CurrentFloor = 4;
			this->P4_2->DestinationFloor = 2;
			this->P4_2->Click += gcnew System::EventHandler(this, &MyForm::create_button_Click);
			// 
			// P4_3
			// 
			this->P4_3->Location = System::Drawing::Point(980, 154);
			this->P4_3->Name = L"P4_3";
			this->P4_3->Size = System::Drawing::Size(25, 25);
			this->P4_3->TabIndex = 25;
			this->P4_3->Text = L"3";
			this->P4_3->UseVisualStyleBackColor = true;
			this->P4_3->CurrentFloor = 4;
			this->P4_3->DestinationFloor = 3;
			this->P4_3->Click += gcnew System::EventHandler(this, &MyForm::create_button_Click);
			// 
			// P4_5
			// 
			this->P4_5->Location = System::Drawing::Point(980, 123);
			this->P4_5->Name = L"P4_5";
			this->P4_5->Size = System::Drawing::Size(25, 25);
			this->P4_5->TabIndex = 27;
			this->P4_5->Text = L"5";
			this->P4_5->UseVisualStyleBackColor = true;
			this->P4_5->CurrentFloor = 4;
			this->P4_5->DestinationFloor = 5;
			this->P4_5->Click += gcnew System::EventHandler(this, &MyForm::create_button_Click);
			// 
			// P5_1
			// 
			this->P5_1->Location = System::Drawing::Point(61, 123);
			this->P5_1->Name = L"P5_1";
			this->P5_1->Size = System::Drawing::Size(25, 25);
			this->P5_1->TabIndex = 29;
			this->P5_1->Text = L"1";
			this->P5_1->UseVisualStyleBackColor = true;
			this->P5_1->CurrentFloor = 5;
			this->P5_1->DestinationFloor = 1;
			this->P5_1->Click += gcnew System::EventHandler(this, &MyForm::create_button_Click);
			// 
			// P5_2
			// 
			this->P5_2->Location = System::Drawing::Point(61, 92);
			this->P5_2->Name = L"P5_2";
			this->P5_2->Size = System::Drawing::Size(25, 25);
			this->P5_2->TabIndex = 31;
			this->P5_2->Text = L"2";
			this->P5_2->UseVisualStyleBackColor = true;
			this->P5_2->CurrentFloor = 5;
			this->P5_2->DestinationFloor = 2;
			this->P5_2->Click += gcnew System::EventHandler(this, &MyForm::create_button_Click);
			// 
			// P5_3
			// 
			this->P5_3->Location = System::Drawing::Point(61, 61);
			this->P5_3->Name = L"P5_3";
			this->P5_3->Size = System::Drawing::Size(25, 25);
			this->P5_3->TabIndex = 33;
			this->P5_3->Text = L"3";
			this->P5_3->UseVisualStyleBackColor = true;
			this->P5_3->CurrentFloor = 5;
			this->P5_3->DestinationFloor = 3;
			this->P5_3->Click += gcnew System::EventHandler(this, &MyForm::create_button_Click);
			// 
			// P5_4
			// 
			this->P5_4->Location = System::Drawing::Point(61, 30);
			this->P5_4->Name = L"P5_4";
			this->P5_4->Size = System::Drawing::Size(25, 25);
			this->P5_4->TabIndex = 35;
			this->P5_4->Text = L"4";
			this->P5_4->UseVisualStyleBackColor = true;
			this->P5_4->CurrentFloor = 5;
			this->P5_4->DestinationFloor = 4;
			this->P5_4->Click += gcnew System::EventHandler(this, &MyForm::create_button_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(120, 450);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 100);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(860, 350);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(100, 100);
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(120, 250);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(100, 100);
			this->pictureBox4->TabIndex = 6;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(860, 150);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(100, 100);
			this->pictureBox5->TabIndex = 7;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(120, 50);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(100, 100);
			this->pictureBox6->TabIndex = 8;
			this->pictureBox6->TabStop = false;
			// 
			// floor1_button
			// 
			this->floor1_button->Location = System::Drawing::Point(300, 500);
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
			this->floor3_button->Location = System::Drawing::Point(300, 300);
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
			this->floor5_button->Location = System::Drawing::Point(300, 100);
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
			this->floor2_button->Location = System::Drawing::Point(700, 400);
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
			this->floor4_button->Location = System::Drawing::Point(700, 200);
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
			this->floor1->Location = System::Drawing::Point(70, 590);
			this->floor1->Name = L"floor1";
			this->floor1->Size = System::Drawing::Size(300, 10);
			this->floor1->Tag = L"1";
			// 
			// floor2
			// 
			this->floor2->Location = System::Drawing::Point(680, 490);
			this->floor2->Name = L"floor2";
			this->floor2->Size = System::Drawing::Size(300, 10);
			this->floor2->Tag = L"2";
			// 
			// floor3
			// 
			this->floor3->Location = System::Drawing::Point(70, 390);
			this->floor3->Name = L"floor3";
			this->floor3->Size = System::Drawing::Size(300, 10);
			this->floor3->Tag = L"3";
			// 
			// floor4
			// 
			this->floor4->Location = System::Drawing::Point(680, 290);
			this->floor4->Name = L"floor4";
			this->floor4->Size = System::Drawing::Size(300, 10);
			this->floor4->Tag = L"4";
			// 
			// floor5
			// 
			this->floor5->Location = System::Drawing::Point(70, 190);
			this->floor5->Name = L"floor5";
			this->floor5->Size = System::Drawing::Size(300, 10);
			this->floor5->Tag = L"5";
			//
			// elevator
			//
			this->elevator->BackColor = System::Drawing::Color::DarkGray;
			this->elevator->Location = System::Drawing::Point(380, 0);
			this->elevator->Name = L"elevator";
			this->elevator->Size = System::Drawing::Size(294, this->Height);
			this->elevator->TabIndex = 9;
			this->elevator->TabStop = false;
			this->elevator->FloorReached += gcnew System::EventHandler(this, &Hellevator::MyForm::OnFloorReached);
			// 
			// MyForm
			// 
			this->BackColor = System::Drawing::Color::LightCyan;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1080, 600);
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
			this->Controls->Add(this->floor1_button);
			this->Controls->Add(this->floor2_button);
			this->Controls->Add(this->floor3_button);
			this->Controls->Add(this->floor4_button);
			this->Controls->Add(this->floor5_button);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
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
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		movePassengers();

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
	private: System::Void floor_button_Click(System::Object^  sender, System::EventArgs^  e) {
		ElevatorCallButton^ b = ((ElevatorCallButton^)sender);
		b->SetActive(true);

		int floorTag = Convert::ToInt32(b->Tag);
		elevator->AddWaitingFloor(getFloorByTag(floorTag));
	}

	private: System::Void create_button_Click(System::Object^ sender, System::EventArgs^ e) {
		CreateButton^ cb = (CreateButton^)sender;
		
		Floor^ currentFloor = getFloorByTag(cb->CurrentFloor);
		Floor^ destinationFloor = getFloorByTag(cb->DestinationFloor);
		Passenger^ p;

		if (currentFloor->Location.X < elevator->Location.X) {
			p = gcnew Passenger(currentFloor->Location.X,
				currentFloor->Location.Y - Passenger::DEFAULT_SIZE,
				destinationFloor,
				Passenger::RIGHT);
		}
		else {
			p = gcnew Passenger(currentFloor->Location.X + currentFloor->Width - Passenger::DEFAULT_SIZE,
				currentFloor->Location.Y - Passenger::DEFAULT_SIZE,
				destinationFloor,
				Passenger::LEFT);
		}

		currentFloor->passengers->Add(p);
		this->Controls->Add(p);
	}

	private: void movePassengers() {
		for each (Floor^ f in elevator->floors)
		{
			for each (Passenger^ p in f->passengers)
			{
				int floorTag = Convert::ToInt32(f->Tag);
				ElevatorCallButton^ callButton = getFloorButtonByTag(floorTag);

				if (!p->isWaiting)
					p->direction == Passenger::RIGHT ? p->moveRight() : p->moveLeft();

				if(!p->isFinished)
					if ((p->direction == Passenger::RIGHT && ((p->Location.X + p->Width) > callButton->Location.X + 1))
						|| (p->direction == Passenger::LEFT && (p->Location.X < (callButton->Location.X + callButton->Width - 1))))
					{
						p->isWaiting = true;
						floor_button_Click(callButton, nullptr);
					}
			}
		}
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

	private: ElevatorCallButton^ getFloorButtonByTag(int tag) {
		switch (tag) {
		case 1:
			return floor1_button;
		case 2:
			return floor2_button;
		case 3:
			return floor3_button;
		case 4:
			return floor4_button;
		case 5:
			return floor5_button;
		default:
			return nullptr;
		}
	}
	
    void OnFloorReached(System::Object ^sender, System::EventArgs ^e);
};
}


void Hellevator::MyForm::OnFloorReached(System::Object ^sender, System::EventArgs ^e)
{
	FloorEventArgs^ args = (FloorEventArgs^)e;

	ElevatorCallButton^ b = getFloorButtonByTag(args->FloorTag);

	b->SetActive(false);

	Floor^ f = getFloorByTag(args->FloorTag);
	for each (Passenger^ p in f->passengers)
	{
		if (p->isWaiting) {
			this->Controls->Remove(p);
			elevator->AddPassenger(p);

			int floorTag = Convert::ToInt32(p->destinationFloor->Tag);
			Button^ b = getFloorButtonByTag(floorTag);
			floor_button_Click(b, nullptr);
		}
	}
	
	ArrayList^ droppedPassengers = args->DroppedPassengers;
	for each (Passenger^ p in droppedPassengers)
	{
		int x, y;

		if (f->Location.X > elevator->Location.X) {
			x = b->Location.X + p->Width;
			p->direction = Passenger::RIGHT;
		}
		else {
			x = b->Location.X - p->Width;
			p->direction = Passenger::LEFT;
		}

		y = f->Location.Y - f->Height - p->Height;

		p->Location = Point(x, y);;
		p->isWaiting = false;
		p->isFinished = true;
		this->Controls->Add(p);
	}
}
