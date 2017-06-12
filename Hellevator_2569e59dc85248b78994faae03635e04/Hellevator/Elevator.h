#pragma once

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

	private: int cabinPosition = 0;

	public:
		Elevator(void)
		{
			InitializeComponent();
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
		}
#pragma endregion
	};
}
