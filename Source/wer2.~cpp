//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "wer2.h"
#include "Unit1.h"
#include "Operations.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "PERFGRAP"
#pragma resource "*.dfm"
TForm2 *Form2;           bool kt=false;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
        kt=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormShow(TObject *Sender)
{
        Edit1->Text=Form1->Edit1->Text;
}
//---------------------------------------------------------------------------



void __fastcall TForm2::Button3Click(TObject *Sender)
{
        Form2->Close();          
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
        Form1->BitBtn9->Click();
        Form2->Visible=false;
        Form2->Close();        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
        if(!kt)
        {
                ComboBox1->Items->Add(Edit2->Text);
                kt=true;
        }
        else
        {
                ComboBox1->Items->Delete(ComboBox1->Items->Count-1);
                ComboBox1->Items->Add(Edit2->Text);
        }        
}
//---------------------------------------------------------------------------

