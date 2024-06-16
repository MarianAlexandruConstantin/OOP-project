//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ProiectulMeu.h"
#include "Configurez.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfMain *fMain;
//---------------------------------------------------------------------------

int TfMain::functiePrioritate(char c)
{
  switch(c)
  {
     case '(': return 1;
     case ')': return 2;
     case '+':
     case '-':
           return 3;
     case '*':
     case '/':
           return 4;
     default:
           return 5;
  }
}



__fastcall TfMain::TfMain(TComponent* Owner)
        : TForm(Owner)
{

   i = 0, k = 0, esteOperand=0, poloneza=0, rez=0;
   v=0;
   fMain->rezultat->Caption="";
}
//---------------------------------------------------------------------------


void __fastcall TfMain::btnConfigClick(TObject *Sender)
{
   fMain->Hide();
   fEdit->Show();
}
//---------------------------------------------------------------------------


void __fastcall TfMain::btnExitClick(TObject *Sender)
{
   exit(0);
}
//---------------------------------------------------------------------------


void __fastcall TfMain::btnPasUrmatorClick(TObject *Sender)
{
    if(i==0)
      strcpy(ExprInfix,fMain->textExpresie->Caption.c_str());

    if (i<strlen(ExprInfix))
    {
        k = 0;
        if (ExprInfix[i] >= '0' && ExprInfix[i] <= '9') {
            while (ExprInfix[i] >= '0' && ExprInfix[i] <= '9') {
                SubExpr[k] = ExprInfix[i];
                k++;
                i++;
            }
            SubExpr[k] = '\0';
            esteOperand = 1;
        }
        else {
            SubExpr[k] = ExprInfix[i];
            SubExpr[k + 1] = '\0';
            i++;
            esteOperand = 0;
        }

        if (esteOperand)
        {
            coada -> adauga(coada, atoi(SubExpr), 0);
            strcat(textCoada,SubExpr);
            strcat(textCoada," ");
        }
        else {
            if (SubExpr[0] == '(')
            {
                stiva -> adauga(stiva, 0, SubExpr[0]);
                textStiva[strlen(textStiva)]=SubExpr[0];
            }
            else {

                if (SubExpr[0] == ')')
                {
                    stiva -> elimina(stiva, &v, &o);
                    textStiva[strlen(textStiva)-1]=NULL;

                    while (o != '(')
                    {
                        coada -> adauga(coada, 0, o);
                        textCoada[strlen(textCoada)]=o;
                        strcat(textCoada," ");
                        stiva -> elimina(stiva, &v, &o);
                        textStiva[strlen(textStiva)-1]=NULL;
                    }
                }
                else
                {
                    while (stiva && functiePrioritate(stiva->getOp()) >= functiePrioritate(SubExpr[0]))
                    {
                        stiva -> elimina(stiva, &v, &o);
                        textStiva[strlen(textStiva)-1]=NULL;
                        coada -> adauga(coada, 0, o);
                        textCoada[strlen(textCoada)]=o;
                        strcat(textCoada," ");
                    }
                    stiva -> adauga(stiva, 0, SubExpr[0]);
                    textStiva[strlen(textStiva)]=SubExpr[0];
                }
            }
        }
    }
    else if(stiva && poloneza==0)
    {
        stiva -> elimina(stiva,&v,&o);
        textStiva[strlen(textStiva)-1]=NULL;
        coada -> adauga(coada,0,o);
        textCoada[strlen(textCoada)]=o;
        strcat(textCoada," ");
    }
    else if (coada) {

        poloneza=1;
        coada -> elimina(coada, &v, &o);

        if (!o)
        {
            stiva -> adauga(stiva, v, 0);
            sprintf(buf,"%g",v);
            strcat(textStiva,buf);
            strcat(textStiva," ");
            strcpy(textCoada,textCoada+strlen(buf)+1);
        }
        else
        {
            strcpy(textCoada,textCoada+2);

            stiva -> elimina(stiva, &opd2, &e);
            stiva -> elimina(stiva, &opd1, &e);

            lungime=2;
            sprintf(buf,"%g",opd1);
            lungime+=strlen(buf);
            sprintf(buf,"%g",opd2);
            lungime+=strlen(buf);
            textStiva[strlen(textStiva)-lungime]=NULL;

            switch (o){
            case '+':
                rez = opd1 + opd2;
                break;
            case '-':
                rez = opd1 - opd2;
                break;
            case '*':
                rez = opd1 * opd2;
                break;
            case '/':
                rez = opd1 / opd2;
                break;
            }
            stiva-> adauga(stiva, rez, 0);
            sprintf(buf,"%g",rez);
            strcat(textStiva,buf);
            strcat(textStiva," ");
        }
    }
    else
    {
      stiva -> elimina(stiva, &v, &o);
      strcpy(textStiva,"");
      strcpy(textCoada,"");
      rez=v;
      lungime=0;
      fMain->rezultat->Caption=rez;
    }

    labelStiva->Caption=textStiva;
    labelCoada->Caption=textCoada;

}
//---------------------------------------------------------------------------
