#include "Admin.h"
System::Void OBD::Admin::timer_date_Tick(System::Object^ sender, System::EventArgs^ e)
{
    tb_data->Text = DateTime::Now.ToString();
}

System::Void OBD::Admin::logOutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
	return;
}
System::Void OBD::Admin::btm_hide_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (tb_pass->PasswordChar == '\0')
	{
		btm_show->BringToFront();
		tb_pass->PasswordChar = '*';
	}
}

System::Void OBD::Admin::btm_show_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (tb_pass->PasswordChar == '*')
	{
		btm_hide->BringToFront();
		tb_pass->PasswordChar = '\0';
	}

}

System::Void OBD::Admin::tb_pass_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	tb_pass->PasswordChar = '*';
}
System::Void OBD::Admin::viewAllToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (tb_loggin->Text->Length == 0 || tb_pass->Text->Length == 0)
	{
		MessageBox::Show("You do not sign in!");
		return;
	}
	else
	{
		this->Hide();
		viewAll_insurance^ form_view = gcnew viewAll_insurance();
		form_view->ShowDialog();
		this->Show();
	}
	
}
System::Void OBD::Admin::btm_log_in_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ login = tb_loggin->Text;
	String^ password = tb_pass->Text;
	if (tb_loggin->Text->Length == 0 || tb_pass->Text->Length == 0)
	{
		MessageBox::Show("Please enter USER NAME or PASSWORD");
		return;
	}

	try
	{
		String^ conecctionString = connectionString;
		SqlConnection sqlCon(conecctionString);
		sqlCon.Open();
		String^ sqlQuery = "SELECT * FROM userinfo WHERE login=@login AND password=@pwd";
		SqlCommand command(sqlQuery, % sqlCon);
		command.Parameters->AddWithValue("@login", login);
		command.Parameters->AddWithValue("@pwd", password);
		SqlDataReader^ reader = command.ExecuteReader();
		if (reader->Read())
		{
			user = gcnew User;
			user->name = reader->GetString(1);
			user->id = reader->GetInt32(0);
			sqlCon.Close();
		}
		else
		{
			MessageBox::Show("USER NAME or PASSWORD is incorrect");
			return;
		}

	}
	catch (Exception^ e)
	{
		MessageBox::Show("Failed to connect to the database");
		return;
	}

	if (user != nullptr && user->id < 100)
	{
		MessageBox::Show("Successfull Authentication of admin " + user->name);
		grp_autorization->Visible = false;
	}
	else
	{
		MessageBox::Show("You are not an admin  : )\nAuthentication Canceled");
	}

}
