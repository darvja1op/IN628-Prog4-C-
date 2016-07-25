#include "CanvasForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	CanvasDrawing::CanvasForm form;
	Application::Run(%form);
}