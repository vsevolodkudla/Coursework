//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit1.h"
#include "Operations.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CGAUGES"
#pragma resource "*.dfm"
TForm4 *Form4;
Zminna *p=NULL;
Derevo *pVuraz;
bool HidePanel=false;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
        StringGrid1->Cells[0][0]="Змінна";
        StringGrid1->Cells[1][0]="Значення";
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
    try
    {
        //zanosumo u vuraz
        if(Edit1->Text!="")
        {
                Series1->Clear();
                int g=StringGrid1->RowCount-1;
                while(p)
                {
                        Zminna *tm=p;
                        p=p->next;
                        delete tm;
                }
                while(g)
                {
                        if(StringGrid1->Cells[0][g]!=""
                                && StringGrid1->Cells[1][g]!="")
                        {
                                Zminna *tmp=new Zminna;
                                tmp->Name=StringGrid1->Cells[0][g];
                                if(Provirka(StringGrid1->Cells[1][g]))
                                        tmp->var=StrToFloat(StringGrid1->Cells[1][g]);
                                else
                                        throw 4;
                                tmp->next=p;
                                p=tmp;
                        }
                        g--;
                }
                pVuraz=Obchuslutu(Edit1->Text,p);
                Zminna *tmp=p;
                while(tmp)
                {
                        pVuraz->SetVar(tmp->Name,tmp->var);
                        tmp=tmp->next;
                }
        }
        //maluemo
        double y,x,z;
        y = Edit3->Text.ToDouble();
        x = Edit4->Text.ToDouble();
        z = StrToFloat(Edit5->Text);
        CGauge1->MinValue=y;
        CGauge1->MaxValue=x;
        for(double Pozit=y;Pozit<=x;Pozit+=z)
        {
                pVuraz->SetVar(ComboBox3->Items->operator [](ComboBox3->ItemIndex)
                ,Pozit);
                Series1->Add(pVuraz->Rezult(),Pozit,ColorBox1->Selected);
                CGauge1->Progress=Pozit;
        }
        CGauge1->Progress++;
    }
    catch(int a)
    {
    }    
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button3Click(TObject *Sender)
{
        Form1->Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm4::Chart1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        if(Y>=Chart1->Height-20)
                Panel1->Height=243;
        else
                Panel1->Height=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button2Click(TObject *Sender)
{
        Form1->Show();
        Form4->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::RadioButton1Click(TObject *Sender)
{
        RichEdit1->Text="Виняткові ситуації будуть пропускатися";
}
//---------------------------------------------------------------------------

void __fastcall TForm4::RadioButton2Click(TObject *Sender)
{
        RichEdit1->Text="При виняткові ситуації програма зупиниться";
}
//---------------------------------------------------------------------------

void __fastcall TForm4::RadioButton3Click(TObject *Sender)
{
        RichEdit1->Text="При виняткові ситуації графік не попудується";
}
//---------------------------------------------------------------------------

