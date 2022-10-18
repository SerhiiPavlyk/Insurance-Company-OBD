#pragma once
#include "User.h"
namespace OBD {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	/// <summary>
	/// Summary for actions_with_insurance
	/// </summary>
	public ref class actions_with_insurance : public System::Windows::Forms::Form
	{
		SqlConnection^ sqlConn = gcnew SqlConnection();
		SqlCommand^ sqlCmd = gcnew SqlCommand();
		SqlDataAdapter^ sqlDtA = gcnew SqlDataAdapter();
		DataTable^ sqlDt = gcnew DataTable();
		SqlDataReader^ sqlRd;
	public:
		actions_with_insurance(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~actions_with_insurance()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer_date;
	protected:
	private: System::Windows::Forms::TextBox^ tb_data;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ backToActionToolStripMenuItem;


	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Panel^ panel2;


	private: System::Windows::Forms::DateTimePicker^ data_picker_end;
	private: System::Windows::Forms::Label^ lb_end_date;

	private: System::Windows::Forms::TextBox^ tb_jbj_name;
	private: System::Windows::Forms::Label^ lb_obj_name;



	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DateTimePicker^ data_picker_start;
	private: System::Windows::Forms::Label^ lb_start_date;



	private: System::Windows::Forms::Panel^ panel1;





	private: System::Windows::Forms::Button^ btmAdd_New;
	private: System::Windows::Forms::Button^ btm_pay;


	private: System::Windows::Forms::Button^ btm_upInfo;
	private: System::Windows::Forms::Label^ lb_id;
	private: System::Windows::Forms::TextBox^ tb_obj_id;
	private: System::Windows::Forms::TextBox^ tb_balance;
	private: System::Windows::Forms::Button^ btm_update_bal;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(actions_with_insurance::typeid));
			this->timer_date = (gcnew System::Windows::Forms::Timer(this->components));
			this->tb_data = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->backToActionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->btm_update_bal = (gcnew System::Windows::Forms::Button());
			this->tb_balance = (gcnew System::Windows::Forms::TextBox());
			this->lb_id = (gcnew System::Windows::Forms::Label());
			this->tb_obj_id = (gcnew System::Windows::Forms::TextBox());
			this->data_picker_end = (gcnew System::Windows::Forms::DateTimePicker());
			this->lb_end_date = (gcnew System::Windows::Forms::Label());
			this->tb_jbj_name = (gcnew System::Windows::Forms::TextBox());
			this->lb_obj_name = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->data_picker_start = (gcnew System::Windows::Forms::DateTimePicker());
			this->lb_start_date = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btm_pay = (gcnew System::Windows::Forms::Button());
			this->btm_upInfo = (gcnew System::Windows::Forms::Button());
			this->btmAdd_New = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// timer_date
			// 
			this->timer_date->Enabled = true;
			this->timer_date->Interval = 1000;
			this->timer_date->Tick += gcnew System::EventHandler(this, &actions_with_insurance::timer_date_Tick);
			// 
			// tb_data
			// 
			this->tb_data->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->tb_data->BackColor = System::Drawing::SystemColors::InfoText;
			this->tb_data->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb_data->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->tb_data->Location = System::Drawing::Point(966, 2);
			this->tb_data->MaximumSize = System::Drawing::Size(416, 84);
			this->tb_data->Name = L"tb_data";
			this->tb_data->ReadOnly = true;
			this->tb_data->Size = System::Drawing::Size(316, 44);
			this->tb_data->TabIndex = 2;
			this->tb_data->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->backToActionToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1284, 48);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// backToActionToolStripMenuItem
			// 
			this->backToActionToolStripMenuItem->Name = L"backToActionToolStripMenuItem";
			this->backToActionToolStripMenuItem->Size = System::Drawing::Size(185, 40);
			this->backToActionToolStripMenuItem->Text = L"Back to action";
			this->backToActionToolStripMenuItem->Click += gcnew System::EventHandler(this, &actions_with_insurance::backToActionToolStripMenuItem_Click);
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
			this->dataGridView1->Location = System::Drawing::Point(-8, 382);
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
			this->dataGridView1->Size = System::Drawing::Size(1300, 421);
			this->dataGridView1->TabIndex = 9;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &actions_with_insurance::dataGridView1_CellClick);
			// 
			// panel2
			// 
			this->panel2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->Controls->Add(this->btm_update_bal);
			this->panel2->Controls->Add(this->tb_balance);
			this->panel2->Controls->Add(this->lb_id);
			this->panel2->Controls->Add(this->tb_obj_id);
			this->panel2->Controls->Add(this->data_picker_end);
			this->panel2->Controls->Add(this->lb_end_date);
			this->panel2->Controls->Add(this->tb_jbj_name);
			this->panel2->Controls->Add(this->lb_obj_name);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->data_picker_start);
			this->panel2->Controls->Add(this->lb_start_date);
			this->panel2->ForeColor = System::Drawing::Color::White;
			this->panel2->Location = System::Drawing::Point(0, 43);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1282, 199);
			this->panel2->TabIndex = 8;
			// 
			// btm_update_bal
			// 
			this->btm_update_bal->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btm_update_bal->BackColor = System::Drawing::Color::White;
			this->btm_update_bal->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btm_update_bal.BackgroundImage")));
			this->btm_update_bal->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btm_update_bal->Location = System::Drawing::Point(612, 140);
			this->btm_update_bal->Name = L"btm_update_bal";
			this->btm_update_bal->Size = System::Drawing::Size(72, 56);
			this->btm_update_bal->TabIndex = 17;
			this->btm_update_bal->UseVisualStyleBackColor = false;
			this->btm_update_bal->Click += gcnew System::EventHandler(this, &actions_with_insurance::btm_update_bal_Click);
			// 
			// tb_balance
			// 
			this->tb_balance->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->tb_balance->BackColor = System::Drawing::SystemColors::InfoText;
			this->tb_balance->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb_balance->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->tb_balance->Location = System::Drawing::Point(325, 140);
			this->tb_balance->MaximumSize = System::Drawing::Size(416, 84);
			this->tb_balance->Name = L"tb_balance";
			this->tb_balance->ReadOnly = true;
			this->tb_balance->Size = System::Drawing::Size(285, 56);
			this->tb_balance->TabIndex = 10;
			this->tb_balance->Text = L"0,0000";
			this->tb_balance->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lb_id
			// 
			this->lb_id->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lb_id->AutoSize = true;
			this->lb_id->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lb_id->Location = System::Drawing::Point(385, 13);
			this->lb_id->Name = L"lb_id";
			this->lb_id->Size = System::Drawing::Size(159, 42);
			this->lb_id->TabIndex = 16;
			this->lb_id->Text = L"ITEM ID";
			// 
			// tb_obj_id
			// 
			this->tb_obj_id->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb_obj_id->Location = System::Drawing::Point(378, 60);
			this->tb_obj_id->Name = L"tb_obj_id";
			this->tb_obj_id->Size = System::Drawing::Size(166, 49);
			this->tb_obj_id->TabIndex = 15;
			this->tb_obj_id->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// data_picker_end
			// 
			this->data_picker_end->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->data_picker_end->Location = System::Drawing::Point(935, 68);
			this->data_picker_end->Name = L"data_picker_end";
			this->data_picker_end->Size = System::Drawing::Size(328, 40);
			this->data_picker_end->TabIndex = 13;
			// 
			// lb_end_date
			// 
			this->lb_end_date->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lb_end_date->AutoSize = true;
			this->lb_end_date->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lb_end_date->Location = System::Drawing::Point(630, 71);
			this->lb_end_date->Name = L"lb_end_date";
			this->lb_end_date->Size = System::Drawing::Size(247, 51);
			this->lb_end_date->TabIndex = 12;
			this->lb_end_date->Text = L"END DATE";
			// 
			// tb_jbj_name
			// 
			this->tb_jbj_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb_jbj_name->Location = System::Drawing::Point(7, 60);
			this->tb_jbj_name->Name = L"tb_jbj_name";
			this->tb_jbj_name->Size = System::Drawing::Size(300, 49);
			this->tb_jbj_name->TabIndex = 11;
			this->tb_jbj_name->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// lb_obj_name
			// 
			this->lb_obj_name->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lb_obj_name->AutoSize = true;
			this->lb_obj_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lb_obj_name->Location = System::Drawing::Point(43, 15);
			this->lb_obj_name->Name = L"lb_obj_name";
			this->lb_obj_name->Size = System::Drawing::Size(233, 42);
			this->lb_obj_name->TabIndex = 10;
			this->lb_obj_name->Text = L"ITEM NAME";
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(858, 80);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 33);
			this->label4->TabIndex = 7;
			// 
			// data_picker_start
			// 
			this->data_picker_start->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->data_picker_start->Location = System::Drawing::Point(935, 21);
			this->data_picker_start->Name = L"data_picker_start";
			this->data_picker_start->Size = System::Drawing::Size(328, 40);
			this->data_picker_start->TabIndex = 6;
			// 
			// lb_start_date
			// 
			this->lb_start_date->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lb_start_date->AutoSize = true;
			this->lb_start_date->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lb_start_date->Location = System::Drawing::Point(630, 29);
			this->lb_start_date->Name = L"lb_start_date";
			this->lb_start_date->Size = System::Drawing::Size(299, 51);
			this->lb_start_date->TabIndex = 2;
			this->lb_start_date->Text = L"START DATE";
			// 
			// panel1
			// 
			this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->btm_pay);
			this->panel1->Controls->Add(this->btm_upInfo);
			this->panel1->Controls->Add(this->btmAdd_New);
			this->panel1->Location = System::Drawing::Point(0, 234);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1300, 142);
			this->panel1->TabIndex = 7;
			// 
			// btm_pay
			// 
			this->btm_pay->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btm_pay->BackColor = System::Drawing::Color::White;
			this->btm_pay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btm_pay->Location = System::Drawing::Point(966, 23);
			this->btm_pay->Name = L"btm_pay";
			this->btm_pay->Size = System::Drawing::Size(275, 102);
			this->btm_pay->TabIndex = 3;
			this->btm_pay->Text = L"Pay";
			this->btm_pay->UseVisualStyleBackColor = false;
			this->btm_pay->Click += gcnew System::EventHandler(this, &actions_with_insurance::btm_pay_Click);
			this->btm_pay->MouseLeave += gcnew System::EventHandler(this, &actions_with_insurance::btm_pay_MouseLeave);
			this->btm_pay->MouseHover += gcnew System::EventHandler(this, &actions_with_insurance::btm_pay_MouseHover);
			// 
			// btm_upInfo
			// 
			this->btm_upInfo->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btm_upInfo->BackColor = System::Drawing::Color::White;
			this->btm_upInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btm_upInfo->Location = System::Drawing::Point(410, 23);
			this->btm_upInfo->Name = L"btm_upInfo";
			this->btm_upInfo->Size = System::Drawing::Size(228, 102);
			this->btm_upInfo->TabIndex = 1;
			this->btm_upInfo->Text = L"Update information";
			this->btm_upInfo->UseVisualStyleBackColor = false;
			this->btm_upInfo->Click += gcnew System::EventHandler(this, &actions_with_insurance::btm_upInfo_Click);
			// 
			// btmAdd_New
			// 
			this->btmAdd_New->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btmAdd_New->BackColor = System::Drawing::Color::White;
			this->btmAdd_New->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btmAdd_New->Location = System::Drawing::Point(12, 23);
			this->btmAdd_New->Name = L"btmAdd_New";
			this->btmAdd_New->Size = System::Drawing::Size(369, 102);
			this->btmAdd_New->TabIndex = 0;
			this->btmAdd_New->Text = L"Register a new insurance";
			this->btmAdd_New->UseVisualStyleBackColor = false;
			this->btmAdd_New->Click += gcnew System::EventHandler(this, &actions_with_insurance::btmAdd_New_Click);
			this->btmAdd_New->MouseLeave += gcnew System::EventHandler(this, &actions_with_insurance::btmAdd_New_MouseLeave);
			this->btmAdd_New->MouseHover += gcnew System::EventHandler(this, &actions_with_insurance::btmAdd_New_MouseHover);
			// 
			// actions_with_insurance
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1284, 806);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->tb_data);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"actions_with_insurance";
			this->Text = L"Actions with insurance";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void timer_date_Tick(System::Object^ sender, System::EventArgs^ e);
private: System::Void backToActionToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btmAdd_New_MouseHover(System::Object^ sender, System::EventArgs^ e);
private: System::Void btmAdd_New_MouseLeave(System::Object^ sender, System::EventArgs^ e);
private: System::Void btm_update_bal_Click(System::Object^ sender, System::EventArgs^ e);
private: int ID; String^ balance = "";
public: void setID(int id);
public:System::Void MembershipDB();
 public:System::Void RefreshDB();
private: System::Void btmAdd_New_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btm_upInfo_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btm_pay_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
private: System::Void btm_pay_MouseHover(System::Object^ sender, System::EventArgs^ e);
private: System::Void btm_pay_MouseLeave(System::Object^ sender, System::EventArgs^ e);
};
}
