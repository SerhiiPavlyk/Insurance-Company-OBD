#include "Client.h"
System::Void OBD::Client::timer_date_Tick(System::Object^ sender, System::EventArgs^ e)
{
    tb_data->Text = DateTime::Now.ToString();
}

System::Void OBD::Client::backToMenuToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    return;
}

System::Void OBD::Client::btm_sign_Click(System::Object^ sender, System::EventArgs^ e)//sign in
{
	gb_or->Visible = false;
	btm_rgstr->Visible = false;
	label_name->Visible = false;
	tb_name->Visible = false;
	grp_autorization->Visible = true;
	label_log->Visible = true;
	label_pass->Visible = true;
	tb_loggin->Visible = true;
	tb_pass->Visible = true;
	btm_hide->Visible = true;
	btm_show->Visible = true;
	btm_log_in->Visible = true;
}

System::Void OBD::Client::btm_up_Click(System::Object^ sender, System::EventArgs^ e)// sign up
{
	gb_or->Visible = false;
	grp_autorization->Visible = true;
	label_log->Visible = true;
	label_pass->Visible = true;
	tb_loggin->Visible = true;
	tb_pass->Visible = true;
	btm_hide->Visible = true;
	btm_show->Visible = true;
	btm_log_in->Visible = false;
	tb_name->Visible = true;
	label_name->Visible = true;
	btm_rgstr->Visible = true;
}

System::Void OBD::Client::btm_hide_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (tb_pass->PasswordChar == '\0')
	{
		btm_show->BringToFront();
		tb_pass->PasswordChar = '*';
	}
}

System::Void OBD::Client::btm_show_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (tb_pass->PasswordChar == '*')
	{
		btm_hide->BringToFront();
		tb_pass->PasswordChar = '\0';
	}
}

System::Void OBD::Client::tb_pass_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	tb_pass->PasswordChar = '*';
}

System::Void OBD::Client::btm_log_in_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ login = tb_loggin->Text;
	String^ password = tb_pass->Text;
	String^ pattern = "\([A-Za-z]{8,16}\)+\([0-9]{3,5}\)";
	Regex^ regex = gcnew Regex(pattern);
	Match^ m = regex->Match(login);
	pattern = "\\w{8,16}";
	String^ pass = tb_pass->Text;
	Regex^ regex1 = gcnew Regex(pattern);
	Match^ m1 = regex1->Match(pass);
	if (tb_loggin->Text->Length == 0 || tb_pass->Text->Length == 0 || !(m->Success)|| !(m1->Success))
	{
		MessageBox::Show("Please enter USER NAME or PASSWORD in corret format:"+
			"\nCorrect format for USER NAME : \'8 - 16 letters and 3-5 digits\'." +
			"\nCorrect format for PASSWORD: \'8 - 16 any characters\'.");
		return;
	}
	try
	{
		String^ conecctionString = connectionString;
		SqlConnection sqlCon(conecctionString);
		sqlCon.Open();
		String^ sqlQuery = "SELECT * FROM userinfo WHERE login=@login AND password=@pwd;";
		SqlCommand command(sqlQuery, % sqlCon);
		command.Parameters->AddWithValue("@login", login);
		command.Parameters->AddWithValue("@pwd", password);
		SqlDataReader^ reader = command.ExecuteReader();
		if (reader->Read())
		{
			user = gcnew User;
			user->name = reader->GetString(1);
			user->id = reader->GetInt32(0);
		}
		else
		{
			MessageBox::Show("USER NAME or PASSWORD is incorrect, are you sure that you already have an account?");
			gb_or->Visible = true;
			btm_sign->Visible = false;
			return;
		}

	}
	catch (Exception^ e)
	{
			MessageBox::Show(e->Message, "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
	}

	if (user != nullptr && user->id > 100)
	{
		MessageBox::Show("Successfull Authentication of client " + user->name);
		//off log in
		grp_autorization->Visible = false;
		label_log->Visible = false;
		label_pass->Visible = false;
		tb_loggin->Visible = false;
		tb_pass->Visible = false;
		btm_hide->Visible = false;
		btm_show->Visible = false;
		btm_sign->Visible = false;
		gb_or->Visible = false;


		btm_action_ins->Visible = true;
		btm_prices->Visible = true;
		btm_repl_balance->Visible = true;
	}
	else
	{
		MessageBox::Show("You are not a client, probably you are an admin? : )\nAuthentication Canceled");
	}
}

System::Void OBD::Client::btm_rgstr_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ login = tb_loggin->Text;
	if (!(tb_loggin->Text->Length != 0 && tb_name->Text->Length != 0 && tb_pass->Text->Length != 0))
	{
		MessageBox::Show("You have not filled in all the fields!");
		return;
	}
	String^ pattern = "\([A-Za-z]{8,16}\)+\([0-9]{3,5}\)";
	Regex^ regex = gcnew Regex(pattern);
	Match^ m = regex->Match(login);
	if (!(m->Success))
	{
		MessageBox::Show("Unfortunately, inccorect format of USER NAME, Corect format is \'8 - 16 letters and 3-5 digits\'");
		return;
	}
	pattern = "\\w{8,16}";
	String^ pass = tb_pass->Text;
	Regex^ regex1 = gcnew Regex(pattern);
	Match^ m1 = regex1->Match(pass);
	if (!(m1->Success))
	{
		MessageBox::Show("Unfortunately, inccorect format of PASSWORD, Corect format is \'8 - 16 any characters\'");
		return;
	}
	pattern = "[A-Z][a-z]";
	String^ name = tb_name->Text;
	Regex^ regex2 = gcnew Regex(pattern);
	Match^ m2 = regex2->Match(name);
	if (!(m2->Success))
	{
		MessageBox::Show("Unfortunately, inccorect format of NAME, Corect format is \'Name\'");
		return;
	}
	String^ conecctionString = connectionString;
	SqlConnection sqlCon(conecctionString);
	sqlCon.Open();
	String^ sqlQuery = "SELECT * FROM userinfo WHERE login=@login";
	SqlCommand command(sqlQuery, % sqlCon);
	command.Parameters->AddWithValue("@login", login);
	SqlDataReader^ reader = command.ExecuteReader();

	if (reader->Read())
	{
		MessageBox::Show("Unfortunately, this USER NAME already exists, try something else, you are not registered!");
		sqlCon.Close();
		reader->Close();
		return;
		
	}
	else
	{
		int idd = 100;
		try
		{
			SqlConnection sqlCon(connectionString);
			sqlCon.Open();
			String^ sqlQuery = "select MAX (id) from userinfo";
			SqlCommand commandd(sqlQuery, % sqlCon);
			SqlDataReader^ readerr = commandd.ExecuteReader();

			if (readerr->Read() )
			{
				if (readerr->GetInt32(0) > idd)
				{
					idd = readerr->GetInt32(0);
				}
				idd++;
			}
		
			readerr->Close();
			sqlCon.Close();
		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->Message, "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}
		try
		{
			sqlConn->ConnectionString = connectionString;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;

			sqlCmd->CommandText = "INSERT INTO userinfo (id,name,login,password,balance) values (" + idd + ",'" +tb_name->Text + "','" + tb_loggin->Text + "','" + tb_pass->Text + "', 0)";
			sqlCmd->ExecuteNonQuery();
			sqlConn->Close();
			MessageBox::Show("Congratulations on your successful registration, " + tb_name->Text);			
		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->Message, "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}
	}
}

System::Void OBD::Client::backToSignInupToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	gb_or->Visible = true;
	btm_sign->Visible = true;
	btm_rgstr->Visible = true;
	label_or->Visible = true;
	btm_rgstr->Visible = false;
	grp_autorization->Visible = false;
	label_log->Visible = false;
	label_pass->Visible = false;
	tb_loggin->Visible = false;
	tb_pass->Visible = false;
	btm_hide->Visible = false;
	btm_show->Visible = false;
	btm_action_ins->Visible = false;
	btm_prices->Visible = false;
	btm_repl_balance->Visible = false;
	tb_loggin->Clear();
	tb_pass->Clear();
}

System::Void OBD::Client::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
	actions_with_insurance^ form_action = gcnew actions_with_insurance();
	form_action->setID(user->id);
	form_action->ShowDialog();
	this->Show();
	this->tb_sum->Clear();
}

System::Void OBD::Client::btm_prices_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->price_label->AutoSize = true;
	this->price_label->BackColor = System::Drawing::Color::Black;
	this->price_label->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 19.875F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->price_label->ForeColor = System::Drawing::Color::White;
	this->price_label->Location = System::Drawing::Point(163, 106);
	this->price_label->Name = L"price_label";
	this->price_label->Size = System::Drawing::Size(724, 448);
	this->price_label->TabIndex = 19;
	this->price_label->Text = L"Ïîñëóãè ñòðàõîâî¿ êîìïàí³¿ 500ãðí\r\n1 ð³ê - 1000ãðí\r\n1 ì³ñÿöü - 90ãðí\r\n1 äåíü - 10"
		L"ãðí\r\nÇÍÈÆÊÈ\r\nâ³ä 15 ì³ñÿö³â 10% çíèæêè\r\nâ³ä 27 ì³ñÿö³â 20% çíèæêè\r\n";
	this->price_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
	price_label->Visible = true;
	btm_ins_rase_done->Visible = true;
	gb_sum->Visible = false;
	btm_confirm->Visible = false;
	tb_sum->Visible = false;
	lbl_sum->Visible = false;
	this->tb_sum->Clear();
}

System::Void OBD::Client::btm_repl_balance_Click(System::Object^ sender, System::EventArgs^ e)
{
	gb_sum->Location = System::Drawing::Point(123, 140);
	this->btm_confirm->Location = System::Drawing::Point(40, 75);
	this->tb_sum->Location = System::Drawing::Point(85, 73);
	this->lbl_sum->Location = System::Drawing::Point(10, 23);
	gb_sum->Visible = true;
	this->btm_confirm->Visible = true;
	this->tb_sum->Visible = true;
	this->lbl_sum->Visible = true;
	btm_ins_rase_done->Visible = false;
	price_label->Visible = false;
}

System::Void OBD::Client::btm_confirm_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ bal = tb_sum->Text;
	String^ pattern = "^\([0-9]{0,5}\)$";
	Regex^ regex = gcnew Regex(pattern);
	Match^ m = regex->Match(bal);
	if (!(m->Success))
	{
		MessageBox::Show("Incorrect balance amount!!");
		return;
	}
	replenishment_of_balance^ form_balance = gcnew replenishment_of_balance();
	form_balance->ShowDialog();
	
	if (form_balance->getPayment_was_successful())
	{
		this->Show();
		try
		{
			sqlConn->ConnectionString = connectionString;
			sqlConn->Open();
			sqlCmd->Connection = sqlConn;
			sqlCmd->CommandText = "update userinfo set balance += " + Convert::ToInt32(tb_sum->Text) +
				"from userinfo where id = " + user->id;
			sqlCmd->ExecuteNonQuery();
			sqlConn->Close();
			MessageBox::Show("Congratulations, your balance has been replenished on " + tb_sum->Text);
			gb_sum->Visible = false;
			this->btm_confirm->Visible = false;
			this->tb_sum->Visible = false;
			this->tb_sum->Clear();
			this->lbl_sum->Visible = false;
		}
		catch (Exception^ e)
		{
			MessageBox::Show(e->Message, "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}
	}
	else
	{
		MessageBox::Show("Something went wrong, try again");
		gb_sum->Visible = false;
		this->btm_confirm->Visible = false;
		this->tb_sum->Visible = false;
		this->tb_sum->Clear();
		this->lbl_sum->Visible = false;
		return;
	}
}

System::Void OBD::Client::btm_ins_rase_done_Click(System::Object^ sender, System::EventArgs^ e)
{
	btm_ins_rase_done->Visible = false;
	price_label->Visible = false;
}
