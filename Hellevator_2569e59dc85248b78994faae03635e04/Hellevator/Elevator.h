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
		Pen^ pen = gcnew Pen(Color::BurlyWood);

		g->DrawLine(pen, Point(this->Location), Point(this->Location.X, this->Location.Y + this->Height));
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
