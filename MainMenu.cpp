#include "MainMenu.h"



System::Void OBD::MainMenu::timer1_Tick(System::Object^ sender, System::EventArgs^ e)
{
	tb_data->Text = DateTime::Now.ToString();
}

System::Void OBD::MainMenu::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
	Admin^ admin_form = gcnew Admin() ;
	admin_form->ShowDialog();
	this->Show();
}



System::Void OBD::MainMenu::logOutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("Close the program?", "WARNING!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes)
	{
		Application::Exit();
	}
	return System::Void();
}



System::Void OBD::MainMenu::btn_clnt_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
	Client^ form_client = gcnew Client();
	form_client->ShowDialog();
	this->Show();
}
