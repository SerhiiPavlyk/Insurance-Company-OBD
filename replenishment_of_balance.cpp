#include "replenishment_of_balance.h"


System::Void OBD::replenishment_of_balance::tb_card_numb_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    String^ card = tb_card_numb->Text;
    String^ pattern = "\([0-9]{4}\)+\\s+\([0-9]{4}\)+\\s+\([0-9]{4}\)+\\s+\([0-9]{4}\)+\\b";
    Regex^ regex = gcnew Regex(pattern);
    Match^ m = regex->Match(card);
    tb_m_y->ReadOnly = true;
    tb_cvc->ReadOnly = true;
    if (m->Success)
    {
            MessageBox::Show("Ñard number entered successfully!\nEnter the expiration date in the format\n\'mm/yy\'");
            tb_card_numb->ReadOnly = true;
            tb_m_y->ReadOnly = false;
    }
    else if(card->Length == 16 || card->Length >=20)
    {
        MessageBox::Show("The card number was entered incorrectly - please try again!\nEnter the card number in the format:\nXXXX XXXX XXXX XXXX");
        return;
    }
}

System::Void OBD::replenishment_of_balance::tb_m_y_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    String^ date = tb_m_y->Text;
    String^ pattern = "\([0-1][0-9]\)+/+2[2-9]\\b";
    Regex^ regex = gcnew Regex(pattern);
    Match^ m = regex->Match(date);
    if (m->Success)
    {
        MessageBox::Show("The expiration date entered successfully!\n");
        tb_m_y->ReadOnly = true;
        tb_cvc->ReadOnly = false;
    }

    else if (date->Length >= 4)
    {
        MessageBox::Show("The expiration date was entered incorrectly - please try again!\nEnter the expiration date in the format\n\'mm/yy\'");
        return;
    }
}

System::Void OBD::replenishment_of_balance::tb_cvc_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    tb_cvc->PasswordChar = '*';
    String^ date = tb_cvc->Text;
    String^ pattern = "\([0-9]{3}\)+\\b";
    Regex^ regex = gcnew Regex(pattern);
    Match^ m = regex->Match(date);
    if (m->Success)
    {
        MessageBox::Show("The CVC code was entered successfully!\n");
        tb_cvc->ReadOnly = true;
        MessageBox::Show("Ñonnection... please wait...\n");
        System::Threading::Thread::Sleep(1000);
        MessageBox::Show("Withdrawals were successful!!");
        payment_was_successful = true;
        this->Hide();
    }
    else if (date->Length >= 4)
    {
        MessageBox::Show("The CVC code was entered incorrectly - please try again!\nEnter the CVC code in the format\n\'XXX\'");
        return;
    }
}

System::Void OBD::replenishment_of_balance::btm_edit_Click(System::Object^ sender, System::EventArgs^ e)
{
    tb_cvc->Clear();
    tb_cvc->ReadOnly = false;
    tb_m_y->Clear();
    tb_m_y->ReadOnly = false;
    tb_card_numb->Clear();
    tb_card_numb->ReadOnly = false;
}

System::Void OBD::replenishment_of_balance::replenishment_of_balance_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e)
{
    MessageBox::Show("You have canceled the payment!");
}

bool OBD::replenishment_of_balance::getPayment_was_successful()
{
    return payment_was_successful;
}

