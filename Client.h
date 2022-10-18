#pragma once
#include "User.h"
#include "actions_with_insurance.h"
#include "replenishment_of_balance.h"
namespace OBD {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for Client
	/// </summary>
	public ref class Client : public System::Windows::Forms::Form
	{
		SqlConnection^ sqlConn = gcnew SqlConnection();
		SqlCommand^ sqlCmd = gcnew SqlCommand();
		SqlDataAdapter^ sqlDtA = gcnew SqlDataAdapter();
		DataTable^ sqlDt = gcnew DataTable();
	private: System::Windows::Forms::ToolStripMenuItem^ backToSignInupToolStripMenuItem;
	private: System::Windows::Forms::Button^ btm_action_ins;
	private: System::Windows::Forms::Button^ btm_prices;
	private: System::Windows::Forms::Label^ price_label;
	private: System::Windows::Forms::Button^ btm_repl_balance;
	private: System::Windows::Forms::Label^ lbl_sum;
	private: System::Windows::Forms::TextBox^ tb_sum;
	private: System::Windows::Forms::GroupBox^ gb_sum;
	private: System::Windows::Forms::Button^ btm_confirm;
	private: System::Windows::Forms::Button^ btm_ins_rase_done;





		   SqlDataReader^ sqlRd;
	public:
		Client(void)
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
		~Client()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ tb_data;
	private: System::Windows::Forms::Timer^ timer_date;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ backToMenuToolStripMenuItem;
	private: System::Windows::Forms::Label^ label_or;
	private: System::Windows::Forms::Button^ btm_sign;
	private: System::Windows::Forms::Button^ btm_up;
	private: System::Windows::Forms::GroupBox^ gb_or;
	private: System::Windows::Forms::GroupBox^ grp_autorization;
	private: System::Windows::Forms::Button^ btm_show;
	private: System::Windows::Forms::Button^ btm_log_in;
	private: System::Windows::Forms::TextBox^ tb_loggin;
	private: System::Windows::Forms::Button^ btm_hide;
	private: System::Windows::Forms::TextBox^ tb_pass;
	private: System::Windows::Forms::Label^ label_pass;
	private: System::Windows::Forms::Label^ label_log;
	private: System::Windows::Forms::TextBox^ tb_name;

	private: System::Windows::Forms::Label^ label_name;
	private: System::Windows::Forms::Button^ btm_rgstr;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Client::typeid));
			this->tb_data = (gcnew System::Windows::Forms::TextBox());
			this->timer_date = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->backToMenuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->backToSignInupToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->label_or = (gcnew System::Windows::Forms::Label());
			this->btm_sign = (gcnew System::Windows::Forms::Button());
			this->btm_up = (gcnew System::Windows::Forms::Button());
			this->gb_or = (gcnew System::Windows::Forms::GroupBox());
			this->grp_autorization = (gcnew System::Windows::Forms::GroupBox());
			this->btm_rgstr = (gcnew System::Windows::Forms::Button());
			this->tb_name = (gcnew System::Windows::Forms::TextBox());
			this->label_name = (gcnew System::Windows::Forms::Label());
			this->btm_show = (gcnew System::Windows::Forms::Button());
			this->btm_log_in = (gcnew System::Windows::Forms::Button());
			this->tb_loggin = (gcnew System::Windows::Forms::TextBox());
			this->btm_hide = (gcnew System::Windows::Forms::Button());
			this->tb_pass = (gcnew System::Windows::Forms::TextBox());
			this->label_pass = (gcnew System::Windows::Forms::Label());
			this->label_log = (gcnew System::Windows::Forms::Label());
			this->btm_action_ins = (gcnew System::Windows::Forms::Button());
			this->btm_prices = (gcnew System::Windows::Forms::Button());
			this->price_label = (gcnew System::Windows::Forms::Label());
			this->btm_repl_balance = (gcnew System::Windows::Forms::Button());
			this->lbl_sum = (gcnew System::Windows::Forms::Label());
			this->tb_sum = (gcnew System::Windows::Forms::TextBox());
			this->gb_sum = (gcnew System::Windows::Forms::GroupBox());
			this->btm_confirm = (gcnew System::Windows::Forms::Button());
			this->btm_ins_rase_done = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->gb_or->SuspendLayout();
			this->grp_autorization->SuspendLayout();
			this->gb_sum->SuspendLayout();
			this->SuspendLayout();
			// 
			// tb_data
			// 
			this->tb_data->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->tb_data->BackColor = System::Drawing::SystemColors::InfoText;
			this->tb_data->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb_data->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->tb_data->Location = System::Drawing::Point(967, 0);
			this->tb_data->MaximumSize = System::Drawing::Size(416, 84);
			this->tb_data->Name = L"tb_data";
			this->tb_data->Size = System::Drawing::Size(316, 44);
			this->tb_data->TabIndex = 1;
			this->tb_data->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// timer_date
			// 
			this->timer_date->Enabled = true;
			this->timer_date->Interval = 1000;
			this->timer_date->Tick += gcnew System::EventHandler(this, &Client::timer_date_Tick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->backToMenuToolStripMenuItem,
					this->backToSignInupToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1325, 40);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// backToMenuToolStripMenuItem
			// 
			this->backToMenuToolStripMenuItem->Name = L"backToMenuToolStripMenuItem";
			this->backToMenuToolStripMenuItem->Size = System::Drawing::Size(182, 36);
			this->backToMenuToolStripMenuItem->Text = L"Back to menu";
			this->backToMenuToolStripMenuItem->Click += gcnew System::EventHandler(this, &Client::backToMenuToolStripMenuItem_Click);
			// 
			// backToSignInupToolStripMenuItem
			// 
			this->backToSignInupToolStripMenuItem->Name = L"backToSignInupToolStripMenuItem";
			this->backToSignInupToolStripMenuItem->Size = System::Drawing::Size(231, 36);
			this->backToSignInupToolStripMenuItem->Text = L"Back to Sign in/up";
			this->backToSignInupToolStripMenuItem->Click += gcnew System::EventHandler(this, &Client::backToSignInupToolStripMenuItem_Click);
			// 
			// label_or
			// 
			this->label_or->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label_or->AutoSize = true;
			this->label_or->BackColor = System::Drawing::Color::Transparent;
			this->label_or->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_or->ForeColor = System::Drawing::Color::Snow;
			this->label_or->Location = System::Drawing::Point(158, 128);
			this->label_or->Name = L"label_or";
			this->label_or->Size = System::Drawing::Size(74, 42);
			this->label_or->TabIndex = 3;
			this->label_or->Text = L"OR";
			// 
			// btm_sign
			// 
			this->btm_sign->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btm_sign->AutoSize = true;
			this->btm_sign->BackColor = System::Drawing::Color::White;
			this->btm_sign->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btm_sign->Location = System::Drawing::Point(38, 28);
			this->btm_sign->Name = L"btm_sign";
			this->btm_sign->Size = System::Drawing::Size(341, 97);
			this->btm_sign->TabIndex = 4;
			this->btm_sign->Text = L"Sign in";
			this->btm_sign->UseVisualStyleBackColor = false;
			this->btm_sign->Click += gcnew System::EventHandler(this, &Client::btm_sign_Click);
			// 
			// btm_up
			// 
			this->btm_up->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btm_up->AutoSize = true;
			this->btm_up->BackColor = System::Drawing::Color::White;
			this->btm_up->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btm_up->Location = System::Drawing::Point(38, 190);
			this->btm_up->Name = L"btm_up";
			this->btm_up->Size = System::Drawing::Size(341, 97);
			this->btm_up->TabIndex = 5;
			this->btm_up->Text = L"Sign up";
			this->btm_up->UseVisualStyleBackColor = false;
			this->btm_up->Click += gcnew System::EventHandler(this, &Client::btm_up_Click);
			// 
			// gb_or
			// 
			this->gb_or->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->gb_or->BackColor = System::Drawing::Color::Transparent;
			this->gb_or->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->gb_or->Controls->Add(this->btm_sign);
			this->gb_or->Controls->Add(this->btm_up);
			this->gb_or->Controls->Add(this->label_or);
			this->gb_or->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->gb_or->Location = System::Drawing::Point(502, 437);
			this->gb_or->Name = L"gb_or";
			this->gb_or->Size = System::Drawing::Size(416, 293);
			this->gb_or->TabIndex = 6;
			this->gb_or->TabStop = false;
			// 
			// grp_autorization
			// 
			this->grp_autorization->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->grp_autorization->BackColor = System::Drawing::Color::Transparent;
			this->grp_autorization->Controls->Add(this->btm_rgstr);
			this->grp_autorization->Controls->Add(this->tb_name);
			this->grp_autorization->Controls->Add(this->label_name);
			this->grp_autorization->Controls->Add(this->btm_show);
			this->grp_autorization->Controls->Add(this->btm_log_in);
			this->grp_autorization->Controls->Add(this->tb_loggin);
			this->grp_autorization->Controls->Add(this->btm_hide);
			this->grp_autorization->Controls->Add(this->tb_pass);
			this->grp_autorization->Controls->Add(this->label_pass);
			this->grp_autorization->Controls->Add(this->label_log);
			this->grp_autorization->Location = System::Drawing::Point(293, 126);
			this->grp_autorization->Name = L"grp_autorization";
			this->grp_autorization->Size = System::Drawing::Size(814, 333);
			this->grp_autorization->TabIndex = 16;
			this->grp_autorization->TabStop = false;
			this->grp_autorization->Visible = false;
			// 
			// btm_rgstr
			// 
			this->btm_rgstr->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btm_rgstr->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btm_rgstr->Location = System::Drawing::Point(406, 220);
			this->btm_rgstr->Name = L"btm_rgstr";
			this->btm_rgstr->Size = System::Drawing::Size(238, 91);
			this->btm_rgstr->TabIndex = 19;
			this->btm_rgstr->Text = L"Register";
			this->btm_rgstr->UseVisualStyleBackColor = true;
			this->btm_rgstr->Click += gcnew System::EventHandler(this, &Client::btm_rgstr_Click);
			// 
			// tb_name
			// 
			this->tb_name->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tb_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb_name->Location = System::Drawing::Point(334, 13);
			this->tb_name->Name = L"tb_name";
			this->tb_name->Size = System::Drawing::Size(394, 49);
			this->tb_name->TabIndex = 18;
			this->tb_name->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_name->Visible = false;
			// 
			// label_name
			// 
			this->label_name->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label_name->AutoSize = true;
			this->label_name->BackColor = System::Drawing::Color::Transparent;
			this->label_name->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 19.875F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_name->ForeColor = System::Drawing::SystemColors::Window;
			this->label_name->Location = System::Drawing::Point(6, 13);
			this->label_name->Name = L"label_name";
			this->label_name->Size = System::Drawing::Size(330, 68);
			this->label_name->TabIndex = 17;
			this->label_name->Text = L"YOUR NAME";
			this->label_name->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label_name->Visible = false;
			// 
			// btm_show
			// 
			this->btm_show->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btm_show->BackColor = System::Drawing::SystemColors::Window;
			this->btm_show->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btm_show.BackgroundImage")));
			this->btm_show->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btm_show->Location = System::Drawing::Point(731, 140);
			this->btm_show->Name = L"btm_show";
			this->btm_show->Size = System::Drawing::Size(77, 70);
			this->btm_show->TabIndex = 12;
			this->btm_show->UseVisualStyleBackColor = false;
			this->btm_show->Visible = false;
			this->btm_show->Click += gcnew System::EventHandler(this, &Client::btm_show_Click);
			// 
			// btm_log_in
			// 
			this->btm_log_in->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btm_log_in->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btm_log_in->Location = System::Drawing::Point(27, 236);
			this->btm_log_in->Name = L"btm_log_in";
			this->btm_log_in->Size = System::Drawing::Size(164, 58);
			this->btm_log_in->TabIndex = 16;
			this->btm_log_in->Text = L"Log in";
			this->btm_log_in->UseVisualStyleBackColor = true;
			this->btm_log_in->Click += gcnew System::EventHandler(this, &Client::btm_log_in_Click);
			// 
			// tb_loggin
			// 
			this->tb_loggin->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tb_loggin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb_loggin->Location = System::Drawing::Point(334, 81);
			this->tb_loggin->Name = L"tb_loggin";
			this->tb_loggin->Size = System::Drawing::Size(394, 49);
			this->tb_loggin->TabIndex = 10;
			this->tb_loggin->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_loggin->Visible = false;
			// 
			// btm_hide
			// 
			this->btm_hide->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btm_hide->BackColor = System::Drawing::SystemColors::Window;
			this->btm_hide->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btm_hide.BackgroundImage")));
			this->btm_hide->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btm_hide->Location = System::Drawing::Point(731, 140);
			this->btm_hide->Name = L"btm_hide";
			this->btm_hide->Size = System::Drawing::Size(77, 70);
			this->btm_hide->TabIndex = 13;
			this->btm_hide->UseVisualStyleBackColor = false;
			this->btm_hide->Visible = false;
			this->btm_hide->Click += gcnew System::EventHandler(this, &Client::btm_hide_Click);
			// 
			// tb_pass
			// 
			this->tb_pass->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tb_pass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb_pass->Location = System::Drawing::Point(334, 149);
			this->tb_pass->Name = L"tb_pass";
			this->tb_pass->Size = System::Drawing::Size(394, 49);
			this->tb_pass->TabIndex = 11;
			this->tb_pass->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_pass->Visible = false;
			this->tb_pass->TextChanged += gcnew System::EventHandler(this, &Client::tb_pass_TextChanged);
			// 
			// label_pass
			// 
			this->label_pass->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label_pass->AutoSize = true;
			this->label_pass->BackColor = System::Drawing::Color::Transparent;
			this->label_pass->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 19.875F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_pass->ForeColor = System::Drawing::SystemColors::Window;
			this->label_pass->Location = System::Drawing::Point(15, 149);
			this->label_pass->Name = L"label_pass";
			this->label_pass->Size = System::Drawing::Size(308, 68);
			this->label_pass->TabIndex = 8;
			this->label_pass->Text = L"PASSWORD";
			this->label_pass->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label_pass->Visible = false;
			// 
			// label_log
			// 
			this->label_log->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label_log->AutoSize = true;
			this->label_log->BackColor = System::Drawing::Color::Transparent;
			this->label_log->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 19.875F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_log->ForeColor = System::Drawing::SystemColors::Window;
			this->label_log->Location = System::Drawing::Point(15, 81);
			this->label_log->Name = L"label_log";
			this->label_log->Size = System::Drawing::Size(316, 68);
			this->label_log->TabIndex = 9;
			this->label_log->Text = L"USER NAME";
			this->label_log->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label_log->Visible = false;
			// 
			// btm_action_ins
			// 
			this->btm_action_ins->BackColor = System::Drawing::Color::White;
			this->btm_action_ins->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btm_action_ins.BackgroundImage")));
			this->btm_action_ins->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btm_action_ins->Location = System::Drawing::Point(12, 123);
			this->btm_action_ins->Name = L"btm_action_ins";
			this->btm_action_ins->Size = System::Drawing::Size(220, 123);
			this->btm_action_ins->TabIndex = 17;
			this->btm_action_ins->Text = L"Actions with insurance";
			this->btm_action_ins->UseVisualStyleBackColor = false;
			this->btm_action_ins->Visible = false;
			this->btm_action_ins->Click += gcnew System::EventHandler(this, &Client::button1_Click);
			// 
			// btm_prices
			// 
			this->btm_prices->BackColor = System::Drawing::Color::White;
			this->btm_prices->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btm_prices->Location = System::Drawing::Point(12, 491);
			this->btm_prices->Name = L"btm_prices";
			this->btm_prices->Size = System::Drawing::Size(220, 123);
			this->btm_prices->TabIndex = 18;
			this->btm_prices->Text = L"Insurance rates";
			this->btm_prices->UseVisualStyleBackColor = false;
			this->btm_prices->Visible = false;
			this->btm_prices->Click += gcnew System::EventHandler(this, &Client::btm_prices_Click);
			// 
			// price_label
			// 
			this->price_label->AutoSize = true;
			this->price_label->BackColor = System::Drawing::Color::Transparent;
			this->price_label->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 19.875F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->price_label->ForeColor = System::Drawing::Color::White;
			this->price_label->Location = System::Drawing::Point(1, 627);
			this->price_label->Name = L"price_label";
			this->price_label->Size = System::Drawing::Size(724, 448);
			this->price_label->TabIndex = 19;
			this->price_label->Text = L"Ïîñëóãè ñòðàõîâî¿ êîìïàí³¿ 500ãðí\r\n1 ð³ê - 1000ãðí\r\n1 ì³ñÿöü - 90ãðí\r\n1 äåíü - 10"
				L"ãðí\r\nÇÍÈÆÊÈ\r\nâ³ä 15 ì³ñÿö³â 10% çíèæêè\r\nâ³ä 27 ì³ñÿö³â 20% çíèæêè\r\n";
			this->price_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->price_label->Visible = false;
			// 
			// btm_repl_balance
			// 
			this->btm_repl_balance->BackColor = System::Drawing::Color::White;
			this->btm_repl_balance->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btm_repl_balance->Location = System::Drawing::Point(1063, 342);
			this->btm_repl_balance->Name = L"btm_repl_balance";
			this->btm_repl_balance->Size = System::Drawing::Size(220, 123);
			this->btm_repl_balance->TabIndex = 20;
			this->btm_repl_balance->Text = L"Replenish the balance";
			this->btm_repl_balance->UseVisualStyleBackColor = false;
			this->btm_repl_balance->Visible = false;
			this->btm_repl_balance->Click += gcnew System::EventHandler(this, &Client::btm_repl_balance_Click);
			// 
			// lbl_sum
			// 
			this->lbl_sum->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lbl_sum->AutoSize = true;
			this->lbl_sum->BackColor = System::Drawing::Color::Transparent;
			this->lbl_sum->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_sum->ForeColor = System::Drawing::Color::White;
			this->lbl_sum->Location = System::Drawing::Point(30, 61);
			this->lbl_sum->Name = L"lbl_sum";
			this->lbl_sum->Size = System::Drawing::Size(749, 62);
			this->lbl_sum->TabIndex = 20;
			this->lbl_sum->Text = L"The amount you want to replenish";
			this->lbl_sum->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lbl_sum->Visible = false;
			// 
			// tb_sum
			// 
			this->tb_sum->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tb_sum->BackColor = System::Drawing::Color::White;
			this->tb_sum->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb_sum->ForeColor = System::Drawing::Color::Black;
			this->tb_sum->Location = System::Drawing::Point(185, 152);
			this->tb_sum->Name = L"tb_sum";
			this->tb_sum->Size = System::Drawing::Size(394, 62);
			this->tb_sum->TabIndex = 21;
			this->tb_sum->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_sum->Visible = false;
			// 
			// gb_sum
			// 
			this->gb_sum->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->gb_sum->BackColor = System::Drawing::Color::Transparent;
			this->gb_sum->Controls->Add(this->btm_confirm);
			this->gb_sum->Controls->Add(this->tb_sum);
			this->gb_sum->Controls->Add(this->lbl_sum);
			this->gb_sum->Location = System::Drawing::Point(1107, 114);
			this->gb_sum->Name = L"gb_sum";
			this->gb_sum->Size = System::Drawing::Size(799, 238);
			this->gb_sum->TabIndex = 21;
			this->gb_sum->TabStop = false;
			this->gb_sum->Visible = false;
			// 
			// btm_confirm
			// 
			this->btm_confirm->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btm_confirm->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btm_confirm.BackgroundImage")));
			this->btm_confirm->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btm_confirm->Location = System::Drawing::Point(86, 152);
			this->btm_confirm->Name = L"btm_confirm";
			this->btm_confirm->Size = System::Drawing::Size(68, 62);
			this->btm_confirm->TabIndex = 22;
			this->btm_confirm->UseVisualStyleBackColor = true;
			this->btm_confirm->Visible = false;
			this->btm_confirm->Click += gcnew System::EventHandler(this, &Client::btm_confirm_Click);
			// 
			// btm_ins_rase_done
			// 
			this->btm_ins_rase_done->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->btm_ins_rase_done->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btm_ins_rase_done.BackgroundImage")));
			this->btm_ins_rase_done->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btm_ins_rase_done->Location = System::Drawing::Point(238, 524);
			this->btm_ins_rase_done->Name = L"btm_ins_rase_done";
			this->btm_ins_rase_done->Size = System::Drawing::Size(68, 62);
			this->btm_ins_rase_done->TabIndex = 23;
			this->btm_ins_rase_done->UseVisualStyleBackColor = true;
			this->btm_ins_rase_done->Visible = false;
			this->btm_ins_rase_done->Click += gcnew System::EventHandler(this, &Client::btm_ins_rase_done_Click);
			// 
			// Client
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1325, 816);
			this->Controls->Add(this->btm_ins_rase_done);
			this->Controls->Add(this->gb_sum);
			this->Controls->Add(this->btm_repl_balance);
			this->Controls->Add(this->price_label);
			this->Controls->Add(this->btm_prices);
			this->Controls->Add(this->btm_action_ins);
			this->Controls->Add(this->grp_autorization);
			this->Controls->Add(this->gb_or);
			this->Controls->Add(this->tb_data);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Client";
			this->Text = L"Client";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->gb_or->ResumeLayout(false);
			this->gb_or->PerformLayout();
			this->grp_autorization->ResumeLayout(false);
			this->grp_autorization->PerformLayout();
			this->gb_sum->ResumeLayout(false);
			this->gb_sum->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer_date_Tick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void backToMenuToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		   public: User^ user = nullptr;
private: System::Void btm_sign_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btm_up_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btm_hide_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btm_show_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void tb_pass_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void btm_log_in_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btm_rgstr_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void backToSignInupToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btm_prices_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btm_repl_balance_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btm_confirm_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void btm_ins_rase_done_Click(System::Object^ sender, System::EventArgs^ e);
};
}
