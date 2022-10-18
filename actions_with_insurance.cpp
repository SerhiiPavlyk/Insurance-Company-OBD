#include "actions_with_insurance.h"
#include <string>
System::Void OBD::actions_with_insurance::MembershipDB()
{
	try
	{
		sqlConn->ConnectionString = connectionString;
		sqlConn->Open();
		sqlCmd->Connection = sqlConn;
		sqlCmd->CommandText = "select ID_ITEM as \"Item ID\", object_name as \"Object name\","+
			"start_date as \"Start date\", end_date as \"End date\", price as \"Insurance price\", state as \"Insurance state\""+
			"from registered_objects where ID_USER = "+ID+"order by ID_ITEM ASC";
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

System::Void OBD::actions_with_insurance::RefreshDB()
{
	try
	{
		sqlConn->ConnectionString = connectionString;
		sqlCmd->Connection = sqlConn;
		SqlDataAdapter^ sqlDtA1 = gcnew SqlDataAdapter("select ID_ITEM as \"Item ID\", object_name as \"Object name\"," +
			"start_date as \"Start date\", end_date as \"End date\", price as \"Insurance price\", state as \"Insurance state\"" +
			"from registered_objects where ID_USER = " + ID + "order by ID_ITEM ASC", sqlConn);
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

struct date {
	int day, month, year;
};


System::Void OBD::actions_with_insurance::btmAdd_New_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!(tb_jbj_name->Text->Length != 0  && data_picker_start->Text != data_picker_end->Text))
	{
		MessageBox::Show("You did not specify an object name or an incorrect time limits");
		return;
	}
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
		int counter = 1;
		std::string temp = "";
		date dateStart, dateEnd;
		char start_str[12] = { 0 };
		String^ Start_str = data_picker_start->Value.ToShortDateString();
		Start_str += ".";
		if (Start_str->Length < sizeof(start_str))
		{
			for (int i = 0; i < Start_str->Length; i++)
				start_str[i] = static_cast<char>(Start_str[i]);
		}
		char end_str[12] = { 0 };
		String^ End_str = data_picker_end->Value.ToShortDateString();
		End_str += ".";
		if (End_str->Length < sizeof(end_str))
		{
			for (int i = 0; i < End_str->Length; i++)
				end_str[i] = static_cast<char>(End_str[i]);
		}
		for (size_t i = 0; i < strlen(start_str); i++)
		{
			if (start_str[i] != '.' && counter == 1)
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
		data_picker_start->Format = DateTimePickerFormat::Custom;
		data_picker_start->CustomFormat = "dd-MM-yyyy";
		data_picker_end->Format = DateTimePickerFormat::Custom;
		data_picker_end->CustomFormat = "dd-MM-yyyy";
		sqlCmd->CommandText = "insert into registered_objects (ID_USER, ID_ITEM, object_name, start_date, end_date,price, state)" + "values(" + ID + "," + idd + ",'" + tb_jbj_name->Text + "','" + data_picker_start->Text + "','" + data_picker_end->Text + "'," + price + ",'очікування')";
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

System::Void OBD::actions_with_insurance::btm_upInfo_Click(System::Object^ sender, System::EventArgs^ e)
{
	RefreshDB();
}

System::Void OBD::actions_with_insurance::btm_pay_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (!(tb_obj_id->Text->Length != 0))
	{
		MessageBox::Show("You did not specify an object id");
		return;
	}
	try
	{
		String^ state;
		int bal = 0;
		int have_to_pay = 0;
		SqlConnection sqlCon(connectionString);
		sqlCon.Open();
		String^ sqlQuery = "select u.balance, r.price  from userinfo u inner join registered_objects r "+
			"on u.id = r.ID_USER where u.id = "+ ID + "  and r.ID_ITEM = " + Convert::ToInt32(tb_obj_id->Text);
		SqlCommand command(sqlQuery, % sqlCon);
		SqlDataReader^ reader = command.ExecuteReader();

		if (reader->Read() && !reader->IsDBNull(0))
		{
			bal = Convert::ToInt32(reader->GetDecimal(0));
			have_to_pay = reader->GetInt32(1);
		}
		reader->Close();
		sqlCon.Close();
		if (have_to_pay > bal)
		{
			MessageBox::Show("You do not have enough money to pay for this insurance!");
			return;
		}
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}

	try
	{
		String^ state;
		SqlConnection sqlCon(connectionString);
		sqlCon.Open();
		String^ sqlQuery = "select state from registered_objects r where r.ID_ITEM = " + Convert::ToInt32(tb_obj_id->Text);
		SqlCommand command(sqlQuery, % sqlCon);
		SqlDataReader^ reader = command.ExecuteReader();

		if (reader->Read() && !reader->IsDBNull(0))
		{
			state =reader->GetString(0);
		}
		reader->Close();
		sqlCon.Close();
		if (state == "оплачено")
		{
			MessageBox::Show("You have selected an item that has already been paid for!");
			return;
		}
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
		sqlCmd->CommandText = "update userinfo set balance -= registered_objects.price  from userinfo " +
			"inner join registered_objects on registered_objects.ID_USER = userinfo.id " +
			"where registered_objects.ID_ITEM =" + Convert::ToInt32(tb_obj_id->Text) + " and registered_objects.ID_USER = " + ID;
		sqlCmd->ExecuteNonQuery();
		sqlCmd->CommandText = "update registered_objects set state = \'оплачено\' from registered_objects r " +
			"where r.ID_ITEM =" + Convert::ToInt32(tb_obj_id->Text) + " and r.ID_USER = " + ID;
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

System::Void OBD::actions_with_insurance::dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	tb_obj_id->Text = Convert::ToString( dataGridView1->Rows[e->RowIndex]->Cells["Item ID"]->Value);
	tb_jbj_name->Text = Convert::ToString(dataGridView1->Rows[e->RowIndex]->Cells["Object name"]->Value);
	data_picker_start->Text = Convert::ToString(dataGridView1->Rows[e->RowIndex]->Cells["Start date"]->Value);
	data_picker_end->Text = Convert::ToString(dataGridView1->Rows[e->RowIndex]->Cells["End date"]->Value);

}

System::Void OBD::actions_with_insurance::btm_pay_MouseHover(System::Object^ sender, System::EventArgs^ e)
{
	data_picker_start->Visible = false;
	lb_start_date->Visible = false;
	data_picker_end->Visible = false;
	lb_end_date->Visible = false;
	btmAdd_New->Visible = false;
	btm_upInfo->Visible = false;
}

System::Void OBD::actions_with_insurance::btm_pay_MouseLeave(System::Object^ sender, System::EventArgs^ e)
{
	data_picker_start->Visible = true;
	lb_start_date->Visible = true;
	data_picker_end->Visible = true;
	lb_end_date->Visible = true;
	btmAdd_New->Visible = true;
	btm_upInfo->Visible = true;
}


System::Void OBD::actions_with_insurance::timer_date_Tick(System::Object^ sender, System::EventArgs^ e)
{
    tb_data->Text = DateTime::Now.ToString();
}

System::Void OBD::actions_with_insurance::backToActionToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Hide();
    return;
}

System::Void OBD::actions_with_insurance::btmAdd_New_MouseHover(System::Object^ sender, System::EventArgs^ e)
{
	btm_pay->Visible = false;
	btm_upInfo->Visible = false;
	lb_id->Visible = false;
	tb_obj_id->Visible = false;
}

System::Void OBD::actions_with_insurance::btmAdd_New_MouseLeave(System::Object^ sender, System::EventArgs^ e)
{
	btm_pay->Visible = true;
	btm_upInfo->Visible = true;
	lb_id->Visible = true;
	tb_obj_id->Visible = true;
}

System::Void OBD::actions_with_insurance::btm_update_bal_Click(System::Object^ sender, System::EventArgs^ e)
{
	try
	{
		SqlConnection sqlCon(connectionString);
		sqlCon.Open();
		String^ sqlQuery = "select balance from userinfo where id = "+ ID;
		SqlCommand command(sqlQuery, % sqlCon);
		SqlDataReader^ reader = command.ExecuteReader();

		if (reader->Read() && !reader->IsDBNull(0))
		{
			balance = Convert::ToString(reader->GetDecimal(0));
		}
		reader->Close();
		sqlCon.Close();
		tb_balance->Text = balance;
	}
	catch (Exception^ e)
	{
		MessageBox::Show(e->Message, "Data Entry Form", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}
	
}

void OBD::actions_with_insurance::setID(int id)
{
    this->ID = id;
	MembershipDB();
}
