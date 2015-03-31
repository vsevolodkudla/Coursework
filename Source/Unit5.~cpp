//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit1.h"
#include <stdlib.h>
#include "Operations.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CGAUGES"
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button5Click(TObject *Sender)
{
        Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::RadioButton1Click(TObject *Sender)
{
        StaticText5->Font->Color=clBlack;
        StaticText6->Font->Color=clGray;
        Edit4->Font->Color=clBlack;
        Edit5->Font->Color=clGray;
        Edit4->ReadOnly=false;
        Edit5->ReadOnly=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::RadioButton2Click(TObject *Sender)
{
        StaticText6->Font->Color=clBlack;
        StaticText5->Font->Color=clGray;
        Edit5->Font->Color=clBlack;
        Edit4->Font->Color=clGray;
        Edit5->ReadOnly=false;
        Edit4->ReadOnly=true;
}
//---------------------------------------------------------------------------
double trupec(Derevo *p,double a,double b,double h)
{
        double dTmp=0;
        for(double i=a;i<b;i+=h)
        {
                p->SetVar("x",i);
                double x1=p->Rezult();
                if(i+h>b)
                        h=b-i;
                p->SetVar("x",i+h);
                double x2=p->Rezult();
                dTmp+=h*(x1+x2)/2;
        }
        return dTmp;
}
//---------------------------------------------------------------------------
double Simpson(Derevo *p,double a,double b,double h)
{
        double dTmp=0;
        for(double i=a;i<b;i+=h)
        {
                p->SetVar("x",i);
                double x1=p->Rezult();
                if(i+h>b)
                        h=b-i;
                p->SetVar("x",i+h);
                double x2=p->Rezult();
                p->SetVar("x",i+h/2);
                double x3=p->Rezult();
                dTmp+=h*(x1+4*x3+x2)/6;
        }
        return dTmp;
}
//---------------------------------------------------------------------------
double MonteKarlo(Derevo *p,double a,double b,int k)
{
        double dTmp=0;
        double h=(b-a)/k;
        for(int i=0;i<k;i++)
        {
                int t=h*1000000;
                p->SetVar("x",a+i*h+(rand()%t)/1000000);
                dTmp+=p->Rezult();
        }
        dTmp*=(b-a)/k;
        return dTmp;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button1Click(TObject *Sender)
{
        Series1->Clear();
        Derevo *pVuraz;
        Zminna *pZm=new Zminna;
        pZm->Name="x";
        pZm->next=NULL;
        double dRezult=0;
        double a=Edit2->Text.ToDouble();
        double b=Edit3->Text.ToDouble();
        double h;
        int k;
        pVuraz=Obchuslutu(Edit1->Text,pZm);
        if(RadioButton1->Checked)
        {
                h=Edit4->Text.ToDouble();
                k=(b-a)/h;
        }
        else
        {
                k=Edit5->Text.ToInt();
                double h=(b-a)/k;

        }
        for(double i=a;i<=b;i+=h)
        {
                pVuraz->SetVar("x",i);
                Series1->Add(pVuraz->Rezult(),i,clGreen);
        }
        if(ComboBox1->ItemIndex==0)
        {
                dRezult=trupec(pVuraz,a,b,h);
        }
        if(ComboBox1->ItemIndex==1)
        {
                dRezult=Simpson(pVuraz,a,b,h);
        }
        if(ComboBox1->ItemIndex==2)
        {
                dRezult=MonteKarlo(pVuraz,a,b,k);
        }
        Edit6->Text=FloatToStr(dRezult);
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button2Click(TObject *Sender)
{
        Edit1->Text="(1+th(x))^(-23/10)";
        Edit2->Text="0";
        Edit3->Text="4";
        Edit4->Text="0,001";
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button3Click(TObject *Sender)
{
        Form1->Show();
        Form5->Visible=false;
}
//---------------------------------------------------------------------------

