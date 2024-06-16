//---------------------------------------------------------------------------

#ifndef NodCoadaH
#define NodCoadaH
#include "Nod.h"
//---------------------------------------------------------------------------

class NodCoada: public Nod{

protected:
    NodCoada* next;
public:
   NodCoada(double v,char op);
   void adauga(NodCoada*& c,double v,char o);
   void elimina(NodCoada*& c,double *v, char* o);
};

#endif
