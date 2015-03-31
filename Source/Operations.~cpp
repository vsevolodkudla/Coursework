//---------------------------------------------------------------------------
#pragma hdrstop
#include <string.h>
#include "Operations.h"
//---------------------------------------------------------------------------
int PosEnd(AnsiString asSt,AnsiString asT)
{
        int t=0,n=asSt.Length();
        for(int i=n;i>=1;i--)
        {
                if(asSt[i]=='(')
                        t++;
                if(asSt[i]==')')
                        t--;
                if(asSt.operator [](i)==asT.operator [](1) && !t)
                        return i;
        }
        return 0;
}
//---------------------------------------------------------------------------
int Func(AnsiString Gt,AnsiString t)
{
        for(int i=1;i<=t.Length();i++)
                if(Gt[i]!=t[i])
                        return 0;
        return t.Length()+1;
}
//---------------------------------------------------------------------------
int Provirka(AnsiString r)
{
  if(r=="" || r.Length()>25 || r[1]==',')
    return 0;
  AnsiString e={"-0123456789,"};
  int k=0,p=0;
  for(int i=1;i<=r.Length();i++)
    for(int j=1;j<=e.Length();j++){
      if(r[i]==',')
       p++;
      if(r[i]==e[j])
        k++;
    }
    if(k!=r.Length() || p>1)
      return 0;
    else
      return 1;
}
//---------------------------------------------------------------------------
int ProvirkaZmin(AnsiString r,Zminna *p)
{
        int t=0;
        while(p)
        {
                t+=Func(r,p->Name);
                p=p->next;
        }
        return t;
}
//---------------------------------------------------------------------------
AnsiString ProvirkaFunc(AnsiString t,int &g)
{
        g=t.Pos("(");
        AnsiString func=t.SubString(1,g-1),rez;
        if(g==1)
                rez="()";
        if(func=="sqrt")
                rez="sqrt";
        if(func=="sin")
                rez="sin";
        if(func=="cos")
                rez="cos";
        if(func=="tg")
                rez="tg";
        if(func=="ln")
                rez="ln";
        if(func=="exp")
                rez="exp";
        if(func=="lg")
                rez="lg";
        if(func=="abs")
                rez="abs";
        if(func=="arcsin")
                rez="arcsin";
        if(func=="arccos")
                rez="arccos";
        if(func=="arctg")
                rez="arctg";
        if(func=="ceil")
                rez="ceil";
        if(func=="floor")
                rez="floor";
        if(func=="sh")
                rez="sh";
        if(func=="ch")
                rez="ch";
        if(func=="th")
                rez="th";
        if(func=="cth")
                rez="cth";
        if(func=="sech")
                rez="sech";
        if(func=="csch")
                rez="csch";
        return rez;
}
//---------------------------------------------------------------------------
Derevo* Obchuslutu(AnsiString asText,Zminna *v)
{
        Derevo *Poz;
        AnsiString AS1,AS2;
        int p;
        if((p=PosEnd(asText,"+"))>1)
        {
                AS1=asText.SubString(1,p-1);
                AS2=asText.SubString(p+1,asText.Length()-p);
                Poz=new Plus(Obchuslutu(AS1,v),Obchuslutu(AS2,v));
        }
        else
        if((p=PosEnd(asText,"-"))>1)
        {
                AS1=asText.SubString(1,p-1);
                AS2=asText.SubString(p+1,asText.Length()-p);
                Poz=new Minus(Obchuslutu(AS1,v),Obchuslutu(AS2,v));
        }
        else
        if((p=PosEnd(asText,"*"))>1)
        {
                AS1=asText.SubString(1,p-1);
                AS2=asText.SubString(p+1,asText.Length()-p);
                Poz=new Mult(Obchuslutu(AS1,v),Obchuslutu(AS2,v));
        }
        else
        if((p=PosEnd(asText,"/"))>1)
        {
                AS1=asText.SubString(1,p-1);
                AS2=asText.SubString(p+1,asText.Length()-p);
                Poz=new Div(Obchuslutu(AS1,v),Obchuslutu(AS2,v));
        }
        else
        if((p=PosEnd(asText,"^"))>1)
        {
                AS1=asText.SubString(1,p-1);
                AS2=asText.SubString(p+1,asText.Length()-p);
                Poz=new Pidnesen(Obchuslutu(AS1,v),Obchuslutu(AS2,v));
        }
        else
        if(Provirka(asText))
                Poz=new Real(StrToFloat(asText));
        else
        if(ProvirkaZmin(asText,v))
        {
                Poz=new Var(asText);
        }
        else
        {
                AS2=ProvirkaFunc(asText,p);
                if(p)
                {
                        AS1=asText.SubString(p+1,asText.Length()-p-1);
                        Poz=new Duzku(Obchuslutu(AS1,v),AS2);
                }
                else throw 3;
        }
        return Poz;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)

