//---------------------------------------------------------------------------

#ifndef Unit6H
#define Unit6H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm6 : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TButton *Button5;
        TButton *Button1;
        TStaticText *StaticText1;
        TImage *Image2;
        TStaticText *StaticText3;
        TEdit *Edit2;
        TStaticText *StaticText4;
        TEdit *Edit3;
        TStaticText *StaticText2;
        TEdit *Edit1;
        TStaticText *StaticText5;
        TEdit *Edit4;
        TButton *Button2;
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm6(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
