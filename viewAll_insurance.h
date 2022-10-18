#pragma once
#define connectionString "Data Source=SQL8003.site4now.net;Initial Catalog=db_a87207_support;User Id=db_a87207_support_admin;Password=Df123456"
//#define connectionString "Data Source = DESKTOP - 54FNADR\SQL_OBD; Initial Catalog = SUPPORT; Persist Security Info = True; User ID = Serhii; Password = 16092003; Pooling = False"
namespace OBD {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	/// <summary>
	/// Summary for viewAll_insurance
	/// </summary>
	public ref class viewAll_insurance : public System::Windows::Forms::Form
	{
		SqlConnection^ sqlConn = gcnew SqlConnection();
		SqlCommand^ sqlCmd = gcnew SqlCommand();
		SqlDataAdapter^ sqlDtA = gcnew SqlDataAdapter();
		DataTable ^ sqlDt = gcnew DataTable();
		SqlDataReader^ sqlRd;
	private: System::Windows::Forms::Button^ btm_search;
	private: System::Windows::Forms::TextBox^ tb_obj_id;

	private: System::Windows::Forms::Label^ label8;


		 

	public:
		viewAll_insurance(void)
		{
			//this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			InitializeComponent();
			MembershipDB();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~viewAll_insurance()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ backToToolStripMenuItem;

	private: System::Windows::Forms::Timer^ timer_date;
	private: System::Windows::Forms::TextBox^ tb_data;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ btm_Update;
	private: System::Windows::Forms::Button^ btmAdd_New;
	private: System::Windows::Forms::Button^ btm_Delete_insurance;
	private: System::Windows::Forms::Button^ btm_change_state;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ tb_owner_id;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DateTimePicker^ data_picker_start;




	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ cb_state;


	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ tb_jbj_name;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::DateTimePicker^ data_picker_end;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ btm_clear_parametrs;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(viewAll_insurance::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->backToToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->timer_date = (gcnew System::Windows::Forms::Timer(this->components));
			this->tb_data = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btm_search = (gcnew System::Windows::Forms::Button());
			this->btm_clear_parametrs = (gcnew System::Windows::Forms::Button());
			this->btm_change_state = (gcnew System::Windows::Forms::Button());
			this->btm_Delete_insurance = (gcnew System::Windows::Forms::Button());
			this->btm_Update = (gcnew System::Windows::Forms::Button());
			this->btmAdd_New = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->tb_obj_id = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->data_picker_end = (gcnew System::Windows::Forms::DateTimePicker());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tb_jbj_name = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->cb_state = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->data_picker_start = (gcnew System::Windows::Forms::DateTimePicker());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tb_owner_id = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->menuStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->backToToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1300, 40);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// backToToolStripMenuItem
			// 
			this->backToToolStripMenuItem->Name = L"backToToolStripMenuItem";
			this->backToToolStripMenuItem->Size = System::Drawing::Size(185, 36);
			this->backToToolStripMenuItem->Text = L"Back to action";
			this->backToToolStripMenuItem->Click += gcnew System::EventHandler(this, &viewAll_insurance::backToToolStripMenuItem_Click);
			// 
			// timer_date
			// 
			this->timer_date->Enabled = true;
			this->timer_date->Interval = 1000;
			this->timer_date->Tick += gcnew System::EventHandler(this, &viewAll_insurance::timer_date_Tick);
			// 
			// tb_data
			// 
			this->tb_data->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->tb_data->BackColor = System::Drawing::SystemColors::InfoText;
			this->tb_data->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb_data->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->tb_data->Location = System::Drawing::Point(978, 0);
			this->tb_data->MaximumSize = System::Drawing::Size(416, 84);
			this->tb_data->Name = L"tb_data";
			this->tb_data->ReadOnly = true;
			this->tb_data->Size = System::Drawing::Size(310, 44);
			this->tb_data->TabIndex = 3;
			this->tb_data->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// panel1
			// 
			this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->btm_search);
			this->panel1->Controls->Add(this->btm_clear_parametrs);
			this->panel1->Controls->Add(this->btm_change_state);
			this->panel1->Controls->Add(this->btm_Delete_insurance);
			this->panel1->Controls->Add(this->btm_Update);
			this->panel1->Controls->Add(this->btmAdd_New);
			this->panel1->Location = System::Drawing::Point(0, 243);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1300, 54);
			this->panel1->TabIndex = 4;
			// 
			// btm_search
			// 
			this->btm_search->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btm_search->Location = System::Drawing::Point(132, 3);
			this->btm_search->Name = L"btm_search";
			this->btm_search->Size = System::Drawing::Size(197, 47);
			this->btm_search->TabIndex = 9;
			this->btm_search->Text = L"Search client";
			this->btm_search->UseVisualStyleBackColor = true;
			this->btm_search->Click += gcnew System::EventHandler(this, &viewAll_insurance::btm_search_Click);
			// 
			// btm_clear_parametrs
			// 
			this->btm_clear_parametrs->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btm_clear_parametrs->Location = System::Drawing::Point(1060, 3);
			this->btm_clear_parametrs->Name = L"btm_clear_parametrs";
			this->btm_clear_parametrs->Size = System::Drawing::Size(203, 47);
			this->btm_clear_parametrs->TabIndex = 8;
			this->btm_clear_parametrs->Text = L"Clear parametrs";
			this->btm_clear_parametrs->UseVisualStyleBackColor = true;
			this->btm_clear_parametrs->Click += gcnew System::EventHandler(this, &viewAll_insurance::btm_clear_parametrs_Click);
			// 
			// btm_change_state
			// 
			this->btm_change_state->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btm_change_state->Location = System::Drawing::Point(759, 3);
			this->btm_change_state->Name = L"btm_change_state";
			this->btm_change_state->Size = System::Drawing::Size(176, 47);
			this->btm_change_state->TabIndex = 7;
			this->btm_change_state->Text = L"Change state";
			this->btm_change_state->UseVisualStyleBackColor = true;
			this->btm_change_state->Click += gcnew System::EventHandler(this, &viewAll_insurance::btm_change_state_Click);
			// 
			// btm_Delete_insurance
			// 
			this->btm_Delete_insurance->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btm_Delete_insurance->Location = System::Drawing::Point(544, 3);
			this->btm_Delete_insurance->Name = L"btm_Delete_insurance";
			this->btm_Delete_insurance->Size = System::Drawing::Size(197, 47);
			this->btm_Delete_insurance->TabIndex = 6;
			this->btm_Delete_insurance->Text = L"Delete insurance";
			this->btm_Delete_insurance->UseVisualStyleBackColor = true;
			this->btm_Delete_insurance->Click += gcnew System::EventHandler(this, &viewAll_insurance::btm_Delete_insurance_Click);
			// 
			// btm_Update
			// 
			this->btm_Update->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btm_Update->Location = System::Drawing::Point(335, 3);
			this->btm_Update->Name = L"btm_Update";
			this->btm_Update->Size = System::Drawing::Size(203, 47);
			this->btm_Update->TabIndex = 5;
			this->btm_Update->Text = L"Update database";
			this->btm_Update->UseVisualStyleBackColor = true;
			this->btm_Update->Click += gcnew System::EventHandler(this, &viewAll_insurance::btm_Update_Click);
			// 
			// btmAdd_New
			// 
			this->btmAdd_New->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btmAdd_New->Location = System::Drawing::Point(9, 3);
			this->btmAdd_New->Name = L"btmAdd_New";
			this->btmAdd_New->Size = System::Drawing::Size(117, 47);
			this->btmAdd_New->TabIndex = 0;
			this->btmAdd_New->Text = L"Add New";
			this->btmAdd_New->UseVisualStyleBackColor = true;
			this->btmAdd_New->Click += gcnew System::EventHandler(this, &viewAll_insurance::btmAdd_New_Click);
			// 
			// panel2
			// 
			this->panel2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->Controls->Add(this->tb_obj_id);
			this->panel2->Controls->Add(this->label8);
			this->panel2->Controls->Add(this->data_picker_end);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->tb_jbj_name);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->cb_state);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->data_picker_start);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->tb_owner_id);
			this->panel2->Controls->Add(this->label1);
			this->panel2->ForeColor = System::Drawing::Color::White;
			this->panel2->Location = System::Drawing::Point(0, 43);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1300, 199);
			this->panel2->TabIndex = 5;
			// 
			// tb_obj_id
			// 
			this->tb_obj_id->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb_obj_id->Location = System::Drawing::Point(256, 118);
			this->tb_obj_id->Name = L"tb_obj_id";
			this->tb_obj_id->Size = System::Drawing::Size(230, 40);
			this->tb_obj_id->TabIndex = 15;
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(18, 125);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(176, 33);
			this->label8->TabIndex = 14;
			this->label8->Text = L"OBJECT ID";
			// 
			// data_picker_end
			// 
			this->data_picker_end->Location = System::Drawing::Point(1003, 68);
			this->data_picker_end->Name = L"data_picker_end";
			this->data_picker_end->Size = System::Drawing::Size(260, 31);
			this->data_picker_end->TabIndex = 13;
			this->data_picker_end->Format = DateTimePickerFormat::Custom;
			this->data_picker_end->CustomFormat = "dd-MM-yyyy";
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(797, 71);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(169, 33);
			this->label7->TabIndex = 12;
			this->label7->Text = L"END DATE";
			// 
			// tb_jbj_name
			// 
			this->tb_jbj_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb_jbj_name->Location = System::Drawing::Point(256, 63);
			this->tb_jbj_name->Name = L"tb_jbj_name";
			this->tb_jbj_name->Size = System::Drawing::Size(230, 40);
			this->tb_jbj_name->TabIndex = 11;
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(18, 71);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(232, 33);
			this->label6->TabIndex = 10;
			this->label6->Text = L"OBJECT NAME";
			// 
			// cb_state
			// 
			this->cb_state->FormattingEnabled = true;
			this->cb_state->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"оплачено", L"очікування", L"скасовано(під видалення)" });
			this->cb_state->Location = System::Drawing::Point(1003, 125);
			this->cb_state->Name = L"cb_state";
			this->cb_state->Size = System::Drawing::Size(260, 33);
			this->cb_state->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(867, 124);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(113, 33);
			this->label5->TabIndex = 8;
			this->label5->Text = L"STATE";
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(867, 80);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 33);
			this->label4->TabIndex = 7;
			// 
			// data_picker_start
			// 
			this->data_picker_start->Location = System::Drawing::Point(1003, 21);
			this->data_picker_start->Name = L"data_picker_start";
			this->data_picker_start->Size = System::Drawing::Size(260, 31);
			this->data_picker_start->Format = DateTimePickerFormat::Custom;
			this->data_picker_start->CustomFormat = "dd-MM-yyyy";
			this->data_picker_start->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(797, 29);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(205, 33);
			this->label2->TabIndex = 2;
			this->label2->Text = L"START DATE";
			// 
			// tb_owner_id
			// 
			this->tb_owner_id->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb_owner_id->Location = System::Drawing::Point(256, 11);
			this->tb_owner_id->Name = L"tb_owner_id";
			this->tb_owner_id->Size = System::Drawing::Size(230, 40);
			this->tb_owner_id->TabIndex = 1;
			this->tb_owner_id->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &viewAll_insurance::tb_owner_id_KeyPress);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(18, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(171, 33);
			this->label1->TabIndex = 0;
			this->label1->Text = L"OWNER ID";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::Black;
			this->dataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(0, 351);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 82;
			this->dataGridView1->RowTemplate->Height = 33;
			this->dataGridView1->Size = System::Drawing::Size(1300, 445);
			this->dataGridView1->TabIndex = 6;
			// 
			// viewAll_insurance
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1300, 792);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->tb_data);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"viewAll_insurance";
			this->Text = L"Admin view all insurance";
			this->TopMost = true;
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void RefreshDB();
private: System::Void MembershipDB();
private: System::Void timer_date_Tick(System::Object^ sender, System::EventArgs^ e);
private: System::Void backToToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btm_clear_parametrs_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btm_Update_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btm_search_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void tb_owner_id_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e);
private: System::Void btm_change_state_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btmAdd_New_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btm_Delete_insurance_Click(System::Object^ sender, System::EventArgs^ e);
};
}
