//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Chart.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Grids.hpp>
#include "CGAUGES.h"
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
        TChart *Chart1;
        TPanel *Panel1;
        TImage *Image1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TComboBox *ComboBox3;
        TEdit *Edit3;
        TEdit *Edit4;
        TEdit *Edit1;
        TEdit *Edit5;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TStringGrid *StringGrid1;
        TPanel *Panel2;
        TRadioGroup *RadioGroup1;
        TRadioButton *RadioButton3;
        TRadioButton *RadioButton2;
        TRadioButton *RadioButton1;
        TRichEdit *RichEdit1;
        TDrawGrid *DrawGrid1;
        TLabel *Label4;
        TColorBox *ColorBox1;
        TCGauge *CGauge1;
        TButton *Button4;
        TLineSeries *Series1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Chart1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall RadioButton1Click(TObject *Sender);
        void __fastcall RadioButton2Click(TObject *Sender);
        void __fastcall RadioButton3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
