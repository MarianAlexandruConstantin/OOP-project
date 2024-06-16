//---------------------------------------------------------------------------

#ifndef ProiectulMeuH
#define ProiectulMeuH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Nod.h"
#include "NodStiva.h"
#include "NodCoada.h"
//---------------------------------------------------------------------------


class TfMain : public TForm
{
__published:	// IDE-managed Components
        TButton *btnConfig;
        TButton *btnExit;
        TLabel *textExpresie;
        TLabel *labelStiva;
        TLabel *labelCoada;
        TLabel *rezultat;
        TButton *btnPasUrmator;
        void __fastcall btnConfigClick(TObject *Sender);
        void __fastcall btnExitClick(TObject *Sender);
        void __fastcall btnPasUrmatorClick(TObject *Sender);
private:	// User declarations

  char ExprInfix[100];
  char SubExpr[100];
  char textCoada[100];
  char textStiva[100];
  char buf[10];
  NodStiva* stiva;
  NodCoada* coada;

  unsigned int i,k,esteOperand, poloneza, lungime;
  double v, rez, opd1, opd2;
  char o, e;
  int functiePrioritate(char c);

public:		// User declarations
        __fastcall TfMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfMain *fMain;
//---------------------------------------------------------------------------
#endif

