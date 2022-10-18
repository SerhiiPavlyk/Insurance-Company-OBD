#pragma once
#include "User.h"
#include "client.h"
#include "Admin.h"
namespace OBD {


	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MainMenu : public System::Windows::Forms::Form
	{
	public:
		MainMenu(void)
		{
			this->SetStyle(ControlStyles::SupportsTransparentBackColor, true);
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ tb_data;
	private: System::Windows::Forms::Timer^ timer_date;
	private: System::Windows::Forms::Button^ btn_adm;

	private: System::Windows::Forms::PictureBox^ adm_pic;
	private: System::Windows::Forms::Button^ btn_clnt;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::GroupBox^ grp_adm;
	private: System::Windows::Forms::GroupBox^ grp_clnt;







	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ logOutToolStripMenuItem;
























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
		/// 
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainMenu::typeid));
			this->tb_data = (gcnew System::Windows::Forms::TextBox());
			this->timer_date = (gcnew System::Windows::Forms::Timer(this->components));
			this->btn_adm = (gcnew System::Windows::Forms::Button());
			this->adm_pic = (gcnew System::Windows::Forms::PictureBox());
			this->btn_clnt = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->grp_adm = (gcnew System::Windows::Forms::GroupBox());
			this->grp_clnt = (gcnew System::Windows::Forms::GroupBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->logOutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->adm_pic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->grp_adm->SuspendLayout();
			this->grp_clnt->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tb_data
			// 
			this->tb_data->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->tb_data->BackColor = System::Drawing::SystemColors::InfoText;
			this->tb_data->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb_data->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->tb_data->Location = System::Drawing::Point(968, -2);
			this->tb_data->MaximumSize = System::Drawing::Size(416, 84);
			this->tb_data->Name = L"tb_data";
			this->tb_data->ReadOnly = true;
			this->tb_data->Size = System::Drawing::Size(316, 44);
			this->tb_data->TabIndex = 0;
			this->tb_data->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// timer_date
			// 
			this->timer_date->Enabled = true;
			this->timer_date->Interval = 1000;
			this->timer_date->Tick += gcnew System::EventHandler(this, &MainMenu::timer1_Tick);
			// 
			// btn_adm
			// 
			this->btn_adm->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btn_adm->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 19.875F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_adm->Location = System::Drawing::Point(88, 0);
			this->btn_adm->Name = L"btn_adm";
			this->btn_adm->Size = System::Drawing::Size(204, 70);
			this->btn_adm->TabIndex = 1;
			this->btn_adm->Text = L"Admin";
			this->btn_adm->UseVisualStyleBackColor = true;
			this->btn_adm->Click += gcnew System::EventHandler(this, &MainMenu::button1_Click);
			// 
			// adm_pic
			// 
			this->adm_pic->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"adm_pic.BackgroundImage")));
			this->adm_pic->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->adm_pic->ImageLocation = L"";
			this->adm_pic->Location = System::Drawing::Point(1, 2);
			this->adm_pic->Name = L"adm_pic";
			this->adm_pic->Size = System::Drawing::Size(92, 70);
			this->adm_pic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->adm_pic->TabIndex = 2;
			this->adm_pic->TabStop = false;
			// 
			// btn_clnt
			// 
			this->btn_clnt->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btn_clnt->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 19.875F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_clnt->Location = System::Drawing::Point(0, 0);
			this->btn_clnt->Name = L"btn_clnt";
			this->btn_clnt->Size = System::Drawing::Size(213, 70);
			this->btn_clnt->TabIndex = 3;
			this->btn_clnt->Text = L"Client";
			this->btn_clnt->UseVisualStyleBackColor = true;
			this->btn_clnt->Click += gcnew System::EventHandler(this, &MainMenu::btn_clnt_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->ImageLocation = L"";
			this->pictureBox1->Location = System::Drawing::Point(210, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(86, 70);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// grp_adm
			// 
			this->grp_adm->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->grp_adm->Controls->Add(this->btn_adm);
			this->grp_adm->Controls->Add(this->adm_pic);
			this->grp_adm->Location = System::Drawing::Point(0, 595);
			this->grp_adm->Name = L"grp_adm";
			this->grp_adm->Size = System::Drawing::Size(292, 72);
			this->grp_adm->TabIndex = 5;
			this->grp_adm->TabStop = false;
			// 
			// grp_clnt
			// 
			this->grp_clnt->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->grp_clnt->Controls->Add(this->btn_clnt);
			this->grp_clnt->Controls->Add(this->pictureBox1);
			this->grp_clnt->Location = System::Drawing::Point(988, 597);
			this->grp_clnt->Name = L"grp_clnt";
			this->grp_clnt->Size = System::Drawing::Size(296, 70);
			this->grp_clnt->TabIndex = 6;
			this->grp_clnt->TabStop = false;
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->logOutToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1284, 40);
			this->menuStrip1->TabIndex = 14;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// logOutToolStripMenuItem
			// 
			this->logOutToolStripMenuItem->Name = L"logOutToolStripMenuItem";
			this->logOutToolStripMenuItem->Size = System::Drawing::Size(72, 36);
			this->logOutToolStripMenuItem->Text = L"Exit";
			this->logOutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainMenu::logOutToolStripMenuItem_Click);
			// 
			// MainMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1284, 668);
			this->Controls->Add(this->grp_clnt);
			this->Controls->Add(this->grp_adm);
			this->Controls->Add(this->tb_data);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainMenu";
			this->Text = L"Menu";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->adm_pic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->grp_adm->ResumeLayout(false);
			this->grp_clnt->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void logOutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btn_clnt_Click(System::Object^ sender, System::EventArgs^ e);
};
}
