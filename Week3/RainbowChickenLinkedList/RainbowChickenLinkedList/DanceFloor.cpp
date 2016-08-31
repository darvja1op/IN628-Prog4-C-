#include "DanceFloor.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	RainbowChickenLinkedList::DanceFloor form;
	Application::Run(%form);
}