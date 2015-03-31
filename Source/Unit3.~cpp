//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CGAUGES"
#pragma resource "*.dfm"
TForm3 *Form3;
double *vdX, *vdY, *vdXtmp, dX, dRezult;
bool Stop=false;
HANDLE pObch;
int i=0,j=0,n;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
        StringGrid1->Cells[0][0]="№";
        StringGrid1->Cells[1][0]="Xi";
        StringGrid1->Cells[2][0]="Yi";
        StringGrid1->Cells[2][1]="-0,7327";
        StringGrid1->Cells[2][2]="-1,2274";
        StringGrid1->Cells[2][3]="-1,7874";
        StringGrid1->Cells[2][4]="-2,4459";
        StringGrid1->Cells[2][5]="-3,2527";
        StringGrid1->Cells[2][6]="-4,2888";
        StringGrid1->Cells[2][7]="-5,6985";
        StringGrid1->Cells[2][8]="-7,7686";
        StringGrid1->Cells[2][9]="-11,1664";
        StringGrid1->Cells[2][10]="-0,7327";
        StringGrid2->Cells[0][0]="№";
        StringGrid2->Cells[1][0]="Xi(tmp)";
        for(int i=1;i<12;i++)
        {
                StringGrid1->Cells[0][i]=IntToStr(i);
                StringGrid2->Cells[0][i]=IntToStr(i);
                StringGrid1->Cells[1][i]=FloatToStr(0.05*i);
        }
        Series1->Clear();
        for(int i=1;i<StringGrid1->RowCount;i++)
        {
                Series1->Add(StringGrid1->Cells[2][i].ToDouble()
                        ,StringGrid1->Cells[1][i].ToDouble()
                        ,clGreen);
        }
}
//---------------------------------------------------------------------------
DWORD WINAPI func(void*)
{
        dRezult=0;
        for(i=0;i<n;i++)
        {
                Sleep(100);
                vdXtmp[i]=1;
                for(j=0;j<n;j++)
                {
                        while(Stop)
                                Sleep(50);
                        Sleep(20);
                        if(i!=j)
                                vdXtmp[i]*=(dX-vdX[j])/(vdX[i]-vdX[j]);
                }
                dRezult+=vdY[i]*vdXtmp[i];
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button5Click(TObject *Sender)
{
        Form1->Close();        
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
        Stop=false;
        dX=Edit1->Text.ToDouble();
        n=StringGrid1->RowCount-1;
        vdX=new double[n];
        vdXtmp=new double[n];
        vdY=new double[n];
        for(int i=1;i<StringGrid1->RowCount;i++)
        {
                vdX[i-1]=StrToFloat(StringGrid1->Cells[1][i]);
                vdY[i-1]=StrToFloat(StringGrid1->Cells[2][i]);
        }
        pObch=CreateThread(NULL,0,func,NULL,0,NULL);
        CGauge1->MaxValue=n-1;
        CGauge2->MaxValue=n-1;
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Timer2Timer(TObject *Sender)
{
        for(int k=0;k<n;k++)
        {
                StringGrid2->Cells[1][k+1]=FloatToStr(vdXtmp[k]);
        }
        Edit2->Text=FloatToStr(dRezult);
        CGauge1->Progress=i;
        CGauge2->Progress=j;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
        TerminateThread(pObch,0);
        CGauge1->Progress=0;
        CGauge2->Progress=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button3Click(TObject *Sender)
{
        if(Stop)
        {
                Stop=false;
                Button3->Caption="Призупинити";
        }
        else
        {
                Stop=true;
                Button3->Caption="Продовжити";
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button4Click(TObject *Sender)
{
        Form1->Show();
        Form3->Visible=false;        
}
//---------------------------------------------------------------------------

