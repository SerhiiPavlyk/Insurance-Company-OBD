#include "MainMenu.h"
using namespace System::Windows::Forms;
void main(array <String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	OBD::MainMenu form;
	Application::Run(% form);
}