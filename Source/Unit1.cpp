//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <math.h>
#include "Unit1.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
#include "wer2.h"
#include "Operations.h"
#include "GIFImage.hpp"
#include "fstream.h"
#include <string.h>
#include <stdio.h>
#define cnRyadka 255
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "PERFGRAP"
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm1 *Form1;
Zminna *p=NULL;
Kategory *pStKat=NULL,*Vubran;
bool start=false;
Derevo *pVuraz;
VurazBloc *pVurVubr;
AnsiString Theme="Нова";
double Pozit;
double y1,x1,z;
bool Exp=false,prov=false;
bool g=false;  int xx1,yy1;
//---------------------------------------------------------------------------
Kategory* Download(char *t)
{
        Kategory *p=NULL,*tmp;
        ifstream file(t);
        while(!file.eof())
        {
                AnsiString Kat;
                char *g=new char[cnRyadka];
                file.getline(g,cnRyadka);
                Kat=g;
                Kat.Delete(1,12);
                strcat(g,".krv");
                ifstream file2(g,ios::in);
                if(!file2.eof())
                {
                        VurazBloc *pNew=new VurazBloc;
                        file2.getline(g,cnRyadka);
                        pNew->Vuraz=g;
                        file2.getline(g,cnRyadka);
                        pNew->Name=g;
                        file2.getline(g,cnRyadka);
                        pNew->Opus=g;
                        int h;
                        file2>>h;
                        pNew->n=h;
                        pNew->pMas=new AnsiString[pNew->n];
                        file2.getline(g,cnRyadka);
                        for(int i=0;i<pNew->n;i++)
                        {
                                file2.getline(g,cnRyadka);
                                pNew->pMas[i]=g;
                        }
                        tmp=new Kategory(pNew);
                        tmp->SetName(Kat);
                        while(!file2.eof())
                        {
                                VurazBloc *pNew=new VurazBloc;
                                file2.getline(g,cnRyadka);
                                pNew->Vuraz=g;
                                file2.getline(g,cnRyadka);
                                pNew->Name=g;
                                file2.getline(g,cnRyadka);
                                pNew->Opus=g;
                                int h;
                                file2>>h;
                                pNew->n=h;
                                file2.getline(g,cnRyadka);
                                pNew->pMas=new AnsiString[pNew->n];
                                for(int i=0;i<pNew->n;i++)
                                {
                                        file2.getline(g,cnRyadka);
                                        pNew->pMas[i]=g;
                                }
                                tmp->SetVuraz(pNew);
                        }
                        tmp->SetNext(p);
                        p=tmp;
                }
                file2.close();
        }
        file.close();
        return p;
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        StringGrid1->Cells[0][0]="Змінна";
        StringGrid1->Cells[1][0]="Значення";
        pStKat=Download("Бібліотека\\Категорії.krb");
        Kategory *tmp=pStKat;
        while(tmp)
        {
                ComboBox2->Items->Add(tmp->Name);
                tmp=tmp->GetNext();
        }
        StringGrid2->Cells[0][0]="Функція";
        StringGrid2->Cells[1][0]="Значення";
        StringGrid2->Cells[0][1]="sqrt";
        StringGrid2->Cells[1][1]="Корінь квадратний";
        StringGrid2->Cells[0][2]="sin";
        StringGrid2->Cells[1][2]="Синус";
        StringGrid2->Cells[0][3]="cos";
        StringGrid2->Cells[1][3]="Косинус";
        StringGrid2->Cells[0][4]="tg";
        StringGrid2->Cells[1][4]="Тангенс";
        StringGrid2->Cells[0][5]="ln";
        StringGrid2->Cells[1][5]="Логаритм натуральний";
        StringGrid2->Cells[0][6]="exp";
        StringGrid2->Cells[1][6]="Експонента";
        StringGrid2->Cells[0][7]="lg";
        StringGrid2->Cells[1][7]="Логаритм десятковий";
        StringGrid2->Cells[0][8]="sqrt";
        StringGrid2->Cells[1][8]="Корінь квадратний";
        StringGrid2->Cells[0][9]="abs";
        StringGrid2->Cells[1][9]="Абсолютна величина";
        StringGrid2->Cells[0][10]="arcsin";
        StringGrid2->Cells[1][10]="Арксинус";
        StringGrid2->Cells[0][11]="arccos";
        StringGrid2->Cells[1][11]="Арккосинус";
        StringGrid2->Cells[0][12]="arctg";
        StringGrid2->Cells[1][12]="Арктангенс";
        StringGrid2->Cells[0][13]="ceil";
        StringGrid2->Cells[1][13]="Заокруглення до більшого";
        StringGrid2->Cells[0][14]="floor";
        StringGrid2->Cells[1][14]="Заокруглення до меншого";
        StringGrid2->Cells[0][15]="sh";
        StringGrid2->Cells[1][15]="Гіперболічний синус";
        StringGrid2->Cells[0][16]="ch";
        StringGrid2->Cells[1][16]="Гіперболічний косинус";
        StringGrid2->Cells[0][17]="th";
        StringGrid2->Cells[1][17]="Гіперболічний тангенс";
        StringGrid2->Cells[0][18]="cth";
        StringGrid2->Cells[1][18]="Гіперболічний котангенс";
        StringGrid2->Cells[0][19]="sech";
        StringGrid2->Cells[1][19]="Гіперболічний секанс";
        StringGrid2->Cells[0][20]="csch";
        StringGrid2->Cells[1][20]="Гіперболічний косеканс";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CSpinEdit1Change(TObject *Sender)
{
        StringGrid1->RowCount=CSpinEdit1->Value+1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn9Click(TObject *Sender)
{
        AnsiString String="Бібліотека\\";
        VurazBloc *pNew=new VurazBloc;
        pNew->Vuraz=Edit1->Text;
        pNew->Name=Form2->Edit3->Text;
        pNew->Opus=Form2->RichEdit1->Lines->Text;
        pNew->n=StringGrid1->RowCount-1;
        pNew->pMas=new AnsiString[pNew->n];
        for(int i=1;i<=pNew->n;i++)
                pNew->pMas[i-1]=StringGrid1->Cells[0][i];
        Kategory *tmp=pStKat;
        if(ComboBox2->Items->Count<=Form2->ComboBox1->ItemIndex)
        {
                tmp=new Kategory(pNew);
                Kategory *tmpn=pStKat;
                while(tmpn->next!=NULL)
                        tmpn=tmpn->next;
                tmp->SetName(Form2->ComboBox1->Items->operator [](Form2->ComboBox1->ItemIndex));
                tmpn->SetNext(tmp);
                ComboBox2->Items->Add(Form2->ComboBox1->Items->operator [](Form2->ComboBox1->ItemIndex));
                String+="Категорії.krb";
                FILE *file1=fopen(String.c_str(),"a");
                String="Бібліотека\\\\";
                String+=tmp->Name.c_str();
                fputs("\n",file1);
                fputs(String.c_str(),file1);
                fclose(file1);

        }
        else
        {
                for(int i=0;i<Form2->ComboBox1->ItemIndex;i++)
                        tmp=tmp->GetNext();
                tmp->SetVuraz(pNew);
        }
        String="Бібліотека\\";
        String+=tmp->Name.c_str();
        String+=".krv";
        FILE *file2=fopen(String.c_str(),"a");
        fputs(pNew->Vuraz.c_str(),file2);
        fputs("\n",file2);
        fputs(pNew->Name.c_str(),file2);
        fputs("\n",file2);
        fputs(pNew->Opus.c_str(),file2);
        fputs(IntToStr(pNew->n).c_str(),file2);
        for(int i=0;i<pNew->n;i++)
        {
                fputs("\n",file2);
                fputs(pNew->pMas[i].c_str(),file2);
        }
        fputs("\n",file2);
        fclose(file2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox2Change(TObject *Sender)
{
        Vubran=pStKat;
        for(int i=0;i<ComboBox2->ItemIndex;i++)
                Vubran=Vubran->GetNext();
        if(Vubran)
        {
                ListBox1->Clear();
                VurazBloc *pNew=Vubran->GetVuraz();
                while(pNew)
                {
                        ListBox1->Items->Add(pNew->Name);
                        pNew=pNew->next;
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ListBox1Click(TObject *Sender)
{
        pVurVubr=Vubran->GetVuraz();
        for(int i=0;i<ListBox1->ItemIndex;i++)
                pVurVubr=pVurVubr->next;
        RichEdit1->Clear();
        RichEdit1->Lines->Add(pVurVubr->Opus);

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Edit1Change(TObject *Sender)
{
        if(Edit1->Text!="")
        {
                int q=0;
                for(int i=1;i<=Edit1->Text.Length();i++)
                {
                        if(Edit1->Text[i]=='(')
                                q++;
                        else
                        if(Edit1->Text[i]==')')
                                q--;
                        if(q<0)
                                q=10000;
                }
                if(q)
                {
                        Edit7->Text="Перевірте вираз";
                        prov=false;
                }
                else
                {
                        Edit7->Text="";
                        prov=true;
                }
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{

        if(Key==13)
        {
                Edit7->Clear();
try
{
        if(Edit1->Text!="")
        {
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
                Edit2->Text=FloatToStr(pVuraz->Rezult());
                start=true;
        }
}
    catch(int a)
    {
     switch(a)
     {
        case 1: Edit7->Text="Ділення на нуль";
        break;
        case 2: Edit7->Text="Корінь відємного числа";
        break;
        case 3: Edit7->Text="Ви ввели помилкові дані";
        break;
        case 4: Edit7->Text="Неправильно введено число змінної";
        break;
        default: Edit7->Text="Indefenite error";
     }
    }
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
        if(pVurVubr)
        {
                CSpinEdit1->Value=pVurVubr->n;
                Edit1->Text=pVurVubr->Vuraz;
                for(int i=1;i<=pVurVubr->n;i++)
                        StringGrid1->Cells[0][i]=pVurVubr->pMas[i-1];
        }        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        Form2->Show();
        Form2->ComboBox1->Clear();
        for(int i=0;i<ComboBox2->Items->Count;i++)
                Form2->ComboBox1->Items->Add(ComboBox2->Items->operator [](i));        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
        Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{

        Form4->Show();
        Form1->Visible=false;
        Form4->Edit1->Text=Edit1->Text;
        Form4->ComboBox3->Items=StringGrid1->Cols[0];
        Form4->ComboBox3->Items->Delete(0);
        Form4->StringGrid1->RowCount=StringGrid1->RowCount;
        for(int i=1;i<=StringGrid1->RowCount;i++)
                Form4->StringGrid1->Rows[i]=StringGrid1->Rows[i];
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
        RichEdit1->Clear();       
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Panel3MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
        if(g)
        {
                Panel3->Top+=Y+xx1;
                Panel3->Left+=X+yy1;
                Panel4->Top+=Y+xx1;
                Panel4->Left+=X+yy1;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Panel3MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        g=true;
        xx1=-Y;
        yy1=-X;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Panel3MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        g=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2Click(TObject *Sender)
{
        Panel3->Visible=false;
        Panel4->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
        Panel3->Visible=true;
        Panel4->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
        Form3->Show();
        Form1->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
        Form5->Show();
        Form1->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
        Form6->Show();
        Form1->Hide();
}
//---------------------------------------------------------------------------

