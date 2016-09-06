#include "GardenForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	WhackAGnome::GardenForm form;
	Application::Run(%form);
}