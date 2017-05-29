#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;



[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	TP_4::MyForm form;
	Application::Run(%form);

}
