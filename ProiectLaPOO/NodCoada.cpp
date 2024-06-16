//---------------------------------------------------------------------------
#include <vcl.h>

#pragma hdrstop

#include "NodCoada.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

NodCoada::NodCoada(double v,char op)
{
    this->val=v;
    this->op=op;
    this->next=NULL;
}

void NodCoada::adauga(NodCoada*& c,double v,char o){
    NodCoada* nou=new NodCoada(v,o);
    if(!c)
        c=nou;
    else{
        NodCoada* t=c;
        while(t->next)
            t=t->next;
        t->next=nou;
    }
}

void NodCoada::elimina(NodCoada*& c,double *v, char *o){
    if(c){
        *v=c->getVal();
        *o=c->getOp();
        NodCoada* t=c;
        c=c->next;
        delete t;
    }
}