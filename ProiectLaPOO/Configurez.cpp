//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ProiectulMeu.h"
#include "Configurez.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfEdit *fEdit;
//---------------------------------------------------------------------------
__fastcall TfEdit::TfEdit(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfEdit::btnOkClick(TObject *Sender)
{
    fMain->textExpresie->Caption=fEdit->EditareExpresie->Text;
    fEdit->Hide();
    fMain->Show();
}
//---------------------------------------------------------------------------
