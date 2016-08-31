#include "Form1.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	CollisionDetection::Form1 form;
	Application::Run(%form);
}