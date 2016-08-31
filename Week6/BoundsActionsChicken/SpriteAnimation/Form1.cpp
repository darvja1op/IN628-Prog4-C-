#include "Form1.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	SpriteAnimation::Form1 form;
	Application::Run(%form);
}