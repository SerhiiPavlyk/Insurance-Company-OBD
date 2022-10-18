#pragma once
#include "User.h"
#include "viewAll_insurance.h"

namespace OBD {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	/// <summary>
	/// Summary for Admin
	/// </summary>
	public ref class Admin : public System::Windows::Forms::Form
	{
	public:
		Admin(void)
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
		~Admin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ tb_data;
	private: System::Windows::Forms::Timer^ timer_date;

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ logOutToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ grp_autorization;
	private: System::Windows::Forms::Button^ btm_show;
	private: System::Windows::Forms::Button^ btm_log_in;
	private: System::Windows::Forms::TextBox^ tb_loggin;
	private: System::Windows::Forms::Button^ btm_hide;
	private: System::Windows::Forms::TextBox^ tb_pass;
	private: System::Windows::Forms::Label^ label_pass;
	private: System::Windows::Forms::Label^ label_log;
	private: System::Windows::Forms::ToolStripMenuItem^ viewAllToolStripMenuItem;

	private: System::ComponentModel::IContainer^ components;
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Admin::typeid));
			this->tb_data = (gcnew System::Windows::Forms::TextBox());
			this->timer_date = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->logOutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewAllToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->grp_autorization = (gcnew System::Windows::Forms::GroupBox());
			this->btm_show = (gcnew System::Windows::Forms::Button());
			this->btm_log_in = (gcnew System::Windows::Forms::Button());
			this->tb_loggin = (gcnew System::Windows::Forms::TextBox());
			this->btm_hide = (gcnew System::Windows::Forms::Button());
			this->tb_pass = (gcnew System::Windows::Forms::TextBox());
			this->label_pass = (gcnew System::Windows::Forms::Label());
			this->label_log = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->grp_autorization->SuspendLayout();
			this->SuspendLayout();
			// 
			// tb_data
			// 
			this->tb_data->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->tb_data->BackColor = System::Drawing::SystemColors::InfoText;
			this->tb_data->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb_data->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->tb_data->Location = System::Drawing::Point(969, -1);
			this->tb_data->MaximumSize = System::Drawing::Size(416, 84);
			this->tb_data->Name = L"tb_data";
			this->tb_data->ReadOnly = true;
			this->tb_data->Size = System::Drawing::Size(316, 44);
			this->tb_data->TabIndex = 2;
			this->tb_data->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// timer_date
			// 
			this->timer_date->Enabled = true;
			this->timer_date->Interval = 1000;
			this->timer_date->Tick += gcnew System::EventHandler(this, &Admin::timer_date_Tick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->logOutToolStripMenuItem,
					this->viewAllToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1284, 40);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// logOutToolStripMenuItem
			// 
			this->logOutToolStripMenuItem->Name = L"logOutToolStripMenuItem";
			this->logOutToolStripMenuItem->Size = System::Drawing::Size(117, 36);
			this->logOutToolStripMenuItem->Text = L"Log out";
			this->logOutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Admin::logOutToolStripMenuItem_Click);
			// 
			// viewAllToolStripMenuItem
			// 
			this->viewAllToolStripMenuItem->Name = L"viewAllToolStripMenuItem";
			this->viewAllToolStripMenuItem->Size = System::Drawing::Size(226, 36);
			this->viewAllToolStripMenuItem->Text = L"View all insurance";
			this->viewAllToolStripMenuItem->Click += gcnew System::EventHandler(this, &Admin::viewAllToolStripMenuItem_Click);
			// 
			// grp_autorization
			// 
			this->grp_autorization->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->grp_autorization->BackColor = System::Drawing::Color::Transparent;
			this->grp_autorization->Controls->Add(this->btm_show);
			this->grp_autorization->Controls->Add(this->btm_log_in);
			this->grp_autorization->Controls->Add(this->tb_loggin);
			this->grp_autorization->Controls->Add(this->btm_hide);
			this->grp_autorization->Controls->Add(this->tb_pass);
			this->grp_autorization->Controls->Add(this->label_pass);
			this->grp_autorization->Controls->Add(this->label_log);
			this->grp_autorization->Location = System::Drawing::Point(243, 198);
			this->grp_autorization->Name = L"grp_autorization";
			this->grp_autorization->Size = System::Drawing::Size(814, 291);
			this->grp_autorization->TabIndex = 16;
			this->grp_autorization->TabStop = false;
			// 
			// btm_show
			// 
			this->btm_show->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btm_show->BackColor = System::Drawing::SystemColors::Window;
			this->btm_show->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btm_show.BackgroundImage")));
			this->btm_show->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btm_show->Location = System::Drawing::Point(731, 135);
			this->btm_show->Name = L"btm_show";
			this->btm_show->Size = System::Drawing::Size(77, 70);
			this->btm_show->TabIndex = 12;
			this->btm_show->UseVisualStyleBackColor = false;
			this->btm_show->Click += gcnew System::EventHandler(this, &Admin::btm_show_Click);
			// 
			// btm_log_in
			// 
			this->btm_log_in->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btm_log_in->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btm_log_in->Location = System::Drawing::Point(27, 215);
			this->btm_log_in->Name = L"btm_log_in";
			this->btm_log_in->Size = System::Drawing::Size(164, 58);
			this->btm_log_in->TabIndex = 16;
			this->btm_log_in->Text = L"Log in";
			this->btm_log_in->UseVisualStyleBackColor = true;
			this->btm_log_in->Click += gcnew System::EventHandler(this, &Admin::btm_log_in_Click);
			// 
			// tb_loggin
			// 
			this->tb_loggin->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tb_loggin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb_loggin->Location = System::Drawing::Point(334, 60);
			this->tb_loggin->Multiline = true;
			this->tb_loggin->Name = L"tb_loggin";
			this->tb_loggin->Size = System::Drawing::Size(394, 68);
			this->tb_loggin->TabIndex = 10;
			this->tb_loggin->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// btm_hide
			// 
			this->btm_hide->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btm_hide->BackColor = System::Drawing::SystemColors::Window;
			this->btm_hide->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btm_hide.BackgroundImage")));
			this->btm_hide->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btm_hide->Location = System::Drawing::Point(731, 135);
			this->btm_hide->Name = L"btm_hide";
			this->btm_hide->Size = System::Drawing::Size(77, 70);
			this->btm_hide->TabIndex = 13;
			this->btm_hide->UseVisualStyleBackColor = false;
			this->btm_hide->Click += gcnew System::EventHandler(this, &Admin::btm_hide_Click);
			// 
			// tb_pass
			// 
			this->tb_pass->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tb_pass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb_pass->Location = System::Drawing::Point(334, 128);
			this->tb_pass->Multiline = true;
			this->tb_pass->Name = L"tb_pass";
			this->tb_pass->Size = System::Drawing::Size(394, 68);
			this->tb_pass->TabIndex = 11;
			this->tb_pass->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_pass->TextChanged += gcnew System::EventHandler(this, &Admin::tb_pass_TextChanged);
			// 
			// label_pass
			// 
			this->label_pass->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label_pass->AutoSize = true;
			this->label_pass->BackColor = System::Drawing::Color::Transparent;
			this->label_pass->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 19.875F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_pass->ForeColor = System::Drawing::SystemColors::Window;
			this->label_pass->Location = System::Drawing::Point(15, 128);
			this->label_pass->Name = L"label_pass";
			this->label_pass->Size = System::Drawing::Size(308, 68);
			this->label_pass->TabIndex = 8;
			this->label_pass->Text = L"PASSWORD";
			this->label_pass->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_log
			// 
			this->label_log->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label_log->AutoSize = true;
			this->label_log->BackColor = System::Drawing::Color::Transparent;
			this->label_log->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 19.875F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_log->ForeColor = System::Drawing::SystemColors::Window;
			this->label_log->Location = System::Drawing::Point(15, 60);
			this->label_log->Name = L"label_log";
			this->label_log->Size = System::Drawing::Size(316, 68);
			this->label_log->TabIndex = 9;
			this->label_log->Text = L"USER NAME";
			this->label_log->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Admin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1284, 668);
			this->Controls->Add(this->grp_autorization);
			this->Controls->Add(this->tb_data);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Admin";
			this->Text = L"Admin";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->grp_autorization->ResumeLayout(false);
			this->grp_autorization->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer_date_Tick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void logOutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void btm_log_in_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btm_hide_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btm_show_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void tb_pass_TextChanged(System::Object^ sender, System::EventArgs^ e);
public: User^ user = nullptr;
private: System::Void viewAllToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
