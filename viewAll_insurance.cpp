#include "viewAll_insurance.h"
#include <msclr/marshal_cppstd.h>
#include<iostream>
using namespace System::Runtime::InteropServices;
System::Void OBD::viewAll_insurance::RefreshDB()
{
	try
	{
		sqlConn->ConnectionString = connectionString;
		sqlCmd->Connection = sqlConn;
		SqlDataAdapter^ sqlDtA1 = gcnew SqlDataAdapter("select name as \"User name\", ID_USER as \"User_ID\", ID_ITEM as \"Item ID\", object_name as \"Object name\", start_date as \"Start date\", end_date as \"End date\", price as \"Insurance price\", state as \"Insurance state\", balance as \"User's balance\" from registered_objects inner join userinfo on ID_USER = id order by id ASC", sqlConn);
		DataTable^ sqlDt1 = gcnew DataTable();
		sqlDtA1->Fill(sqlDt1);
		dataGridView1->DataSource = sqlDt1;
	}	
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}

}

System::Void OBD::viewAll_insurance::MembershipDB()
{
	try
	{
		sqlConn->ConnectionString = connectionString;
		sqlConn->Open();
		sqlCmd->Connection = sqlConn;
		sqlCmd->CommandText = "select name as \"User name\", ID_USER as \"User_ID\", ID_ITEM as \"Item ID\", object_name as \"Object name\", start_date as \"Start date\", end_date as \"End date\", price as \"Insurance price\", state as \"Insurance state\", balance as \"User's balance\" from registered_objects inner join userinfo on ID_USER = id order by id ASC";
		sqlRd = sqlCmd->ExecuteReader();
		sqlDt->Load(sqlRd);
		sqlRd->Close();
		sqlConn->Close();
		dataGridView1->DataSource = sqlDt;
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}
	
}

System::Void OBD::viewAll_insurance::timer_date_Tick(System::Object^ sender, System::EventArgs^ e)
{
    tb_data->Text = DateTime::Now.ToString();
}

System::Void OBD::viewAll_insurance::backToToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
	return;
}

System::Void OBD::viewAll_insurance::btm_clear_parametrs_Click(System::Object^ sender, System::EventArgs^ e)
{
	tb_jbj_name->Clear();
	tb_owner_id->Clear();
	data_picker_end->ResetText();
	cb_state->Text = "";
	tb_obj_id->Clear();
}



System::Void OBD::viewAll_insurance::btm_Update_Click(System::Object^ sender, System::EventArgs^ e)
{
	MembershipDB();
	RefreshDB();
}

System::Void OBD::viewAll_insurance::btm_search_Click(System::Object^ sender, System::EventArgs^ e)
{
	try
	{
			String^ conecctionString = connectionString;
			SqlConnection sqlCon(conecctionString);
			sqlCon.Open();
			SqlDataAdapter^ sqlDtA1 = gcnew SqlDataAdapter("select name as \"User name\", ID_USER as \"User_ID\", ID_ITEM as \"Item ID\", object_name as \"Object name\", start_date as \"Start date\", end_date as \"End date\", price as \"Insurance price\", state as \"Insurance state\", balance as \"User's balance\" from registered_objects inner join userinfo on ID_USER = id  where ID_USER = " +Convert::ToInt32(tb_owner_id->Text) + "order by id ASC", sqlConn);
			DataTable^ sqlDt1 = gcnew DataTable();
			sqlDtA1->Fill(sqlDt1);
			dataGridView1->DataSource = sqlDt1;
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}
}

System::Void OBD::viewAll_insurance::tb_owner_id_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
{
	try
	{
		if (e->KeyChar == (char)13)
		{
			DataView^ dv = sqlDt->DefaultView;
			dv->RowFilter = String::Format("User_ID = {0}", Convert::ToInt32(tb_owner_id->Text));
			dataGridView1->DataSource = dv->ToTable();
		}
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}
}

System::Void OBD::viewAll_insurance::btm_change_state_Click(System::Object^ sender, System::EventArgs^ e)
{
	sqlConn->ConnectionString = connectionString;
	sqlConn->Open();
	sqlCmd->Connection = sqlConn;
	try
	{
		sqlCmd->CommandText = " update registered_objects set state = '"+ cb_state->Text + "' where ID_ITEM = "+ Convert::ToInt32( tb_obj_id->Text)+" and state != 'оплачено'";
		sqlCmd->ExecuteNonQuery();
		sqlConn->Close();
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message,"Data Entry Form",MessageBoxButtons::OK,MessageBoxIcon::Information);
		return;
	}
}

struct date {
	int day, month, year;
};

System::Void OBD::viewAll_insurance::btmAdd_New_Click(System::Object^ sender, System::EventArgs^ e)
{
	sqlConn->ConnectionString = connectionString;
	sqlConn->Open();
	sqlCmd->Connection = sqlConn;
	int idd = 0;
	try
	{
		SqlConnection sqlCon(connectionString);
		sqlCon.Open();
		String^ sqlQuery = "select MAX (Id_ITEM) from registered_objects";
		SqlCommand command(sqlQuery, % sqlCon);
		SqlDataReader^ reader = command.ExecuteReader();

		if (reader->Read() && !reader->IsDBNull(0))
		{
			idd = reader->GetInt32(0);
		}
		idd++;
		reader->Close();
		sqlCon.Close();
	}
	catch (Exception^ e)
	{
		MessageBox::Show("Failed to connect to the database");
		return;
	}
	try
	{
		data_picker_start->Format = DateTimePickerFormat::Custom;
		data_picker_start->CustomFormat = "dd.MM.yyyy";
		data_picker_end->Format = DateTimePickerFormat::Custom;
		data_picker_end->CustomFormat = "dd.MM.yyyy";
		int counter = 1;
		std::string temp ="";
		date dateStart, dateEnd;
		String ^ Start_str = data_picker_start->Value.ToShortDateString();
		Start_str += ".";
		char* start_str = (char*)(void*)Marshal::StringToHGlobalAnsi(Start_str);
		String^ End_str = data_picker_end->Value.ToShortDateString();
		End_str += ".";
		char* end_str = (char*)(void*)Marshal::StringToHGlobalAnsi(End_str);
		for (size_t i = 0; i < strlen(start_str); i++)
		{

			if (start_str[i] != '-' && counter == 1)
				temp += start_str[i];
			if (start_str[i] != '.' && counter == 2)
				temp += start_str[i];
			if (start_str[i] != '.' && counter == 3)
				temp += start_str[i];
			if (start_str[i] == '.')
			{
				counter++;
				if (counter == 2)
				{
					dateStart.day = stoi(temp);
				}
				if (counter == 3)
				{
					dateStart.month = stoi(temp);
				}
				if (counter == 4)
				{
					dateStart.year = stoi(temp);
				}
				temp = "";
			}
		}
		counter = 1;
		for (size_t i = 0; i < strlen(end_str); i++)
		{

			if (end_str[i] != '.' && counter == 1)
				temp += end_str[i];
			if (end_str[i] != '.' && counter == 2)
				temp += end_str[i];
			if (end_str[i] != '.' && counter == 3)
				temp += end_str[i];
			if (end_str[i] == '.')
			{
				counter++;
				if (counter == 2)
				{
					dateEnd.day = stoi(temp);
				}
				if (counter == 3)
				{
					dateEnd.month = stoi(temp);
				}
				if (counter == 4)
				{
					dateEnd.year = stoi(temp);
				}
				temp = "";
			}
		}
		int price = (dateEnd.year - dateStart.year) * 1000 + (dateEnd.month - dateStart.month) * 90 + (dateEnd.day - dateStart.day) * 10 + 500;
		if ((dateEnd.year - dateStart.year >= 1) && (dateEnd.month - dateStart.month >= 3))
			price = price * 0.9;
		if ((dateEnd.year - dateStart.year >= 2) && (dateEnd.month - dateStart.month >= 3))
			price = price * 0.8;
		sqlCmd->CommandText = "insert into registered_objects (ID_USER, ID_ITEM, object_name, start_date, end_date,price, state)" + 
			"values(" + Convert::ToInt32(tb_owner_id->Text) + "," + idd + ",'" + tb_jbj_name->Text + "','" + data_picker_start->Text + "','" + data_picker_end->Text + "'," + price + ",'очікування')";
		sqlCmd->ExecuteNonQuery();
		sqlConn->Close();
		MembershipDB();
		RefreshDB();
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}
}

System::Void OBD::viewAll_insurance::btm_Delete_insurance_Click(System::Object^ sender, System::EventArgs^ e)
{
	try
	{
		sqlConn->ConnectionString = connectionString;
		sqlCmd->Connection = sqlConn;
		if (cb_state->Text == "скасовано(під видалення)")
		{
			sqlConn->Open();
			String^ State = cb_state->Text;
			sqlCmd->CommandText  = "delete from registered_objects where state ='" + State + "'";
			sqlCmd->ExecuteNonQuery();
			sqlConn->Close();
			MessageBox::Show("Records were deleted", "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information); 
			sqlConn->Close();
		}
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
		//MessageBox::Show("You did not specify a status to delete");
		return;
	}
	RefreshDB();
}
