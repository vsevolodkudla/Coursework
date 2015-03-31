//---------------------------------------------------------------------------
#include <vcl.h>
#ifndef StekSaveH
#define StekSaveH
//---------------------------------------------------------------------------
class Stek
{
                AnsiString Vuraz,Name,Kategory,Opus;
                int n;
                AnsiString *pMas;
                Stek *next;
        public:
                Stek(){n=0;}
                void AddVuraz(AnsiString t)
                {Vuraz=t;}
                void AddName(AnsiString t)
                {Name=t;}
                void AddKategory(AnsiString t)
                {Kategory=t;}
                void AddOpus(AnsiString t)
                {Opus=t;}
                void SetN(int t=0)
                {pMas=new AnsiString[t];n=t;}
                void AddZminna(AnsiString t)
                {if(n>0){pMas[n-1]=t;n--;}
};
//----------------------------------------------------------------------------
#endif
