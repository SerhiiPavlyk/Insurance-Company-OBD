#pragma once
#include "User.h"
namespace OBD {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for replenishment_of_balance
	/// </summary>
	public ref class replenishment_of_balance : public System::Windows::Forms::Form
	{
	public:
		replenishment_of_balance(void)
		{
			InitializeComponent();
			MessageBox::Show("Enter the card number in the format:\nXXXX XXXX XXXX XXXX");
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~replenishment_of_balance()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::TextBox^ tb_m_y;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ tb_card_numb;
	private: System::Windows::Forms::TextBox^ tb_cvc;

	private: System::Windows::Forms::Label^ lb_cvc;
	private: System::Windows::Forms::Button^ btm_edit;




	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(replenishment_of_balance::typeid));
			this->tb_m_y = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->tb_card_numb = (gcnew System::Windows::Forms::TextBox());
			this->tb_cvc = (gcnew System::Windows::Forms::TextBox());
			this->lb_cvc = (gcnew System::Windows::Forms::Label());
			this->btm_edit = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// tb_m_y
			// 
			this->tb_m_y->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb_m_y->Location = System::Drawing::Point(427, 409);
			this->tb_m_y->Name = L"tb_m_y";
			this->tb_m_y->Size = System::Drawing::Size(166, 74);
			this->tb_m_y->TabIndex = 2;
			this->tb_m_y->TextChanged += gcnew System::EventHandler(this, &replenishment_of_balance::tb_m_y_TextChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(83, 374);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(147, 73);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// tb_card_numb
			// 
			this->tb_card_numb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb_card_numb->Location = System::Drawing::Point(83, 310);
			this->tb_card_numb->Name = L"tb_card_numb";
			this->tb_card_numb->Size = System::Drawing::Size(800, 62);
			this->tb_card_numb->TabIndex = 4;
			this->tb_card_numb->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_card_numb->TextChanged += gcnew System::EventHandler(this, &replenishment_of_balance::tb_card_numb_TextChanged);
			// 
			// tb_cvc
			// 
			this->tb_cvc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tb_cvc->Location = System::Drawing::Point(723, 422);
			this->tb_cvc->Name = L"tb_cvc";
			this->tb_cvc->Size = System::Drawing::Size(132, 56);
			this->tb_cvc->TabIndex = 5;
			this->tb_cvc->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->tb_cvc->TextChanged += gcnew System::EventHandler(this, &replenishment_of_balance::tb_cvc_TextChanged);
			// 
			// lb_cvc
			// 
			this->lb_cvc->AutoSize = true;
			this->lb_cvc->BackColor = System::Drawing::Color::Transparent;
			this->lb_cvc->ForeColor = System::Drawing::Color::White;
			this->lb_cvc->Location = System::Drawing::Point(733, 394);
			this->lb_cvc->Name = L"lb_cvc";
			this->lb_cvc->Size = System::Drawing::Size(122, 25);
			this->lb_cvc->TabIndex = 6;
			this->lb_cvc->Text = L"CVC CODE";
			// 
			// btm_edit
			// 
			this->btm_edit->BackColor = System::Drawing::Color::DarkRed;
			this->btm_edit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btm_edit->ForeColor = System::Drawing::Color::White;
			this->btm_edit->Location = System::Drawing::Point(699, 218);
			this->btm_edit->Name = L"btm_edit";
			this->btm_edit->Size = System::Drawing::Size(184, 60);
			this->btm_edit->TabIndex = 7;
			this->btm_edit->Text = L"Clear data";
			this->btm_edit->UseVisualStyleBackColor = false;
			this->btm_edit->Click += gcnew System::EventHandler(this, &replenishment_of_balance::btm_edit_Click);
			// 
			// replenishment_of_balance
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(999, 582);
			this->Controls->Add(this->btm_edit);
			this->Controls->Add(this->lb_cvc);
			this->Controls->Add(this->tb_cvc);
			this->Controls->Add(this->tb_card_numb);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->tb_m_y);
			this->Name = L"replenishment_of_balance";
			this->Text = L"replenishment_of_balance";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &replenishment_of_balance::replenishment_of_balance_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void tb_card_numb_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void tb_m_y_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void tb_cvc_TextChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void btm_edit_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void replenishment_of_balance_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
private: bool payment_was_successful = false;
public:bool getPayment_was_successful();
};
}
