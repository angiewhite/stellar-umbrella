//---------------------------------------------------------------------------

#ifndef FormH
#define FormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TPostfixExpressions : public TForm
{
__published:	// IDE-managed Components
	TEdit *Infix;
	TLabel *Label1;
	TEdit *Postfix;
	TLabel *Label2;
	TButton *Translate;
	TButton *Calculate;
	TPanel *Result;
	TLabel *Label4;
	TStringGrid *Operands;
	void __fastcall TranslateClick(TObject *Sender);
	void __fastcall CalculateClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TPostfixExpressions(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPostfixExpressions *PostfixExpressions;
//---------------------------------------------------------------------------
#endif
