//---------------------------------------------------------------------------

#ifndef NodStivaH
#define NodStivaH
#include "Nod.h"

//---------------------------------------------------------------------------

class NodStiva: public Nod{

protected:
    NodStiva* next;
public:
    NodStiva(double v,char op, NodStiva* next);
    void adauga(NodStiva*& vf,double v,char c);
    void elimina(NodStiva*& vf,double *v,char *c);
};

#endif
