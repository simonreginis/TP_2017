#pragma once
#include "Floor.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Hellevator {

	/// <summary>
	/// Podsumowanie informacji o Passenger
	/// </summary>
	public ref class Passenger : public System::Windows::Forms::PictureBox
	{
	public: static const int DEFAULT_SIZE = 90;
	public: static const int RIGHT = 1;
	public: static const int LEFT = -1;

	public: Floor^ destinationFloor;
	public: bool isWaiting = false;
	public: bool isFinished = false;
	public: int direction;

	public:
		Passenger(int posX, int posY, Floor^ destination, int direction)
		{
			this->destinationFloor = destination;
			this->direction = direction;

			InitializeComponent();
			this->Location = Point(posX, posY);
			this->Size = System::Drawing::Size(DEFAULT_SIZE, DEFAULT_SIZE);
			this->Load("Resources/deadpool.png");
			this->BackColor = System::Drawing::Color::Transparent;
			this->BringToFront();
		}
		Passenger(int posX, int posY)
		{
			InitializeComponent();
			this->Location = Point(posX, posY);
			this->Size = System::Drawing::Size(DEFAULT_SIZE, DEFAULT_SIZE);
			this->Load("Resources/deadpool.png");
			this->BackColor = System::Drawing::Color::Transparent;
			this->BringToFront();
		}
		Passenger()
		{

		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~Passenger()
		{
			if (components)
			{
				delete components;
			}
		}

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
			
		}
	public: void moveUp()
	{
		this->Top -= 1;
	}
	public: void moveDown()
	{
		this->Top += 1;
	}
	public: void moveRight()
	{
		this->Left += 3;
	}
	public: void moveLeft()
	{
		this->Left -= 3;
	}
#pragma endregion
	};
}
