//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit6.h"
#include "Unit1.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button5Click(TObject *Sender)
{
        Form1->Close();
}
//---------------------------------------------------------------------------
double VurazX(double x,double t)
{
        return sin(2*x*t)-exp(sqrt(x));
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button1Click(TObject *Sender)
{
        double h=0.1;
        double x=Edit1->Text.ToDouble();
        double b=Edit2->Text.ToDouble();
        double y=Edit3->Text.ToDouble();
        double k1,k2,k3,k4;
        do
        {
                k1=h*VurazX(x,y);
                k2=h*VurazX(x+h/2,y+h/2*k1);
                k3=h*VurazX(x+h/2,y+h/2*k2);
                k4=h*VurazX(x+h/2,y+h/2*k3);
                y=y+h/6/(k1+2*k2+2*k3+k4);
                x+=h;
        }
        while(x<b);
        Edit4->Text=FloatToStr(y);
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button2Click(TObject *Sender)
{
        Form1->Show();
        Form6->Visible=false;
}
//---------------------------------------------------------------------------

