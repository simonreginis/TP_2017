#pragma once

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
	public:
		Passenger(int posX, int posY)
		{
			InitializeComponent();
			this->Location = Point(posX, posY);
			this->Size = System::Drawing::Size(90, 90);
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
