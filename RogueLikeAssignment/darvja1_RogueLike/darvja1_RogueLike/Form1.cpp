#include "Form1.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	darvja1_RogueLike::Form1 form;
	Application::Run(%form);
}