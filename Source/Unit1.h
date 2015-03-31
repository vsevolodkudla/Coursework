//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include "PERFGRAP.h"
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include "CSPIN.h"
#include <Graphics.hpp>
#include <Chart.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TImage *Image1;
        TEdit *Edit1;
        TEdit *Edit2;
        TStringGrid *StringGrid1;
        TCSpinEdit *CSpinEdit1;
        TListBox *ListBox1;
        TComboBox *ComboBox2;
        TRichEdit *RichEdit1;
        TRichEdit *RichEdit2;
        TBitBtn *BitBtn9;
        TEdit *Edit7;
        TLabel *Label4;
        TButton *Button2;
        TButton *Button3;
        TButton *Button5;
        TLabel *Label1;
        TButton *Button1;
        TPanel *Panel2;
        TLabel *Label2;
        TButton *Button4;
        TButton *Button6;
        TButton *Button7;
        TButton *Button8;
        TPanel *Panel3;
        TStringGrid *StringGrid2;
        TPanel *Panel4;
        TImage *Image2;
        TButton *Button9;
        TButton *Button10;
        TButton *Button11;
        TButton *Button12;
        void __fastcall CSpinEdit1Change(TObject *Sender);
        void __fastcall BitBtn9Click(TObject *Sender);
        void __fastcall ComboBox2Change(TObject *Sender);
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall Edit1Change(TObject *Sender);
        void __fastcall Edit1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Panel3MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Panel3MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Panel3MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall Button12Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
