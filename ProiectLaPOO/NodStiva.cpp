//---------------------------------------------------------------------------
#include <vcl.h>

#pragma hdrstop

#include "NodStiva.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

NodStiva::NodStiva(double v,char op, NodStiva* next)
{
    this->val=v;
    this->op=op;
    this->next=next;
}

void NodStiva::adauga(NodStiva*& vf,double v,char c)
{
    NodStiva* nou=new NodStiva(v,c,vf);
    vf=nou;
}

void NodStiva::elimina(NodStiva*& vf,double *v,char *c){
    if(vf)
    {
        *v=vf->getVal();
        *c=vf->getOp();
        NodStiva* t=vf;
        vf=vf->next;
        delete t;
    }
}
