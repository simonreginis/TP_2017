#pragma once
#include "Passenger.h"
#include "Floor.h"
#include "FloorEventArgs.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Hellevator {

	/// <summary>
	/// Summary for Elevator
	/// </summary>
	public ref class Elevator : public System::Windows::Forms::UserControl
	{
	public: int cabinHeight = 200;
	public: ArrayList^ floors = gcnew ArrayList();

	private: Floor^ defaultFloor;
	private: int cabinPosition = 0;
	private: int waitLeft = 0;
	private: ArrayList^ floorsWaiting = gcnew ArrayList();
	private: ArrayList^ passengers = gcnew ArrayList();

	public: event EventHandler^ FloorReached;

	public:
		Elevator(void)
		{
			InitializeComponent();
		}

	public:
		Elevator(Floor^ defaultFloor)
		{
			InitializeComponent();
			this->defaultFloor = defaultFloor;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Elevator()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: virtual void OnPaint(PaintEventArgs^ e) override
	{
		UserControl::OnPaint(e);
		Graphics^ g = e->Graphics;

		// draw frame
		Pen^ framePen = gcnew Pen(Color::Black);
		framePen->Width = 3.0f;

		int offset_x = 2;
		int offset_y = 2;
		g->DrawLine(framePen, offset_x, offset_y, offset_x, this->Height - offset_y);
		g->DrawLine(framePen, offset_x, offset_y, this->Width - offset_x, offset_y);
		g->DrawLine(framePen, this->Width + offset_x, this->Height - offset_y, offset_x, this->Height - offset_y);
		g->DrawLine(framePen, this->Width - offset_x, this->Height - offset_y, this->Width - offset_x, offset_y);

		// draw cabin
		Pen^ cabinPen = gcnew Pen(Color::SaddleBrown);
		cabinPen->Width = 3.0f;

		int coffset_x = 0;
		int coffset_y = 0;
		g->DrawLine(cabinPen, offset_x + coffset_x, cabinPosition + offset_y + coffset_y, offset_x + coffset_x, cabinPosition + cabinHeight - offset_y - coffset_y);
		g->DrawLine(cabinPen, offset_x + coffset_x, cabinPosition + offset_y + coffset_y, this->Width - offset_x - coffset_x, cabinPosition + offset_y + coffset_y);
		g->DrawLine(cabinPen, this->Width - offset_x - coffset_x, cabinPosition + cabinHeight - offset_y - coffset_y, offset_x, cabinPosition + cabinHeight - offset_y - coffset_y);
		g->DrawLine(cabinPen, this->Width - offset_x - coffset_x, cabinPosition + cabinHeight - offset_y - coffset_y, this->Width - offset_x - coffset_x, cabinPosition + offset_y + coffset_y);

		// passengers
		for (int i = 0; i < passengers->Count; i++)
		{
			Passenger^ p = (Passenger^) passengers[i];
			p->Left = i * 40;
			this->Controls->Add(p);
		}
	}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			DoubleBuffered = true;
		}
#pragma endregion

	public: virtual void OnFloorReached(EventArgs^ e) {
		FloorReached(this, e);
	}

	public: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (waitLeft > -300)
			waitLeft--;
		else if(defaultFloor != nullptr)
			floorsWaiting->Add(defaultFloor);

		if (waitLeft <= 0 && floorsWaiting->Count > 0) {
			int floorY = ((Floor^)floorsWaiting[0])->Location.Y;
			if (cabinPosition + cabinHeight < floorY) {
				cabinPosition++;
				waitLeft = 0;
			}
			else if (cabinPosition + cabinHeight > floorY) {
				cabinPosition--;
				waitLeft = 0;
			}
			else {
				int tag = Convert::ToInt32(((Floor^)floorsWaiting[0])->Tag);
				FloorEventArgs^ fe = gcnew FloorEventArgs(tag);
				OnFloorReached(fe);
				waitLeft = 200;
				floorsWaiting->RemoveAt(0);
			}
		}

		Invalidate(true);
	}

	public: void AddWaitingFloor(Floor^ floor) {
		if (!floorsWaiting->Contains(floor)) {
			floorsWaiting->Add(floor);
		}
	}

	public: void AddPassenger(Passenger^ passenger) {
		if (!passengers->Contains(passenger)) {
			passengers->Add(passenger);
		}
	}
	};
}
