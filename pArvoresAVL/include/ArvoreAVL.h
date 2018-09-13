#ifndef ARVOREAVL_H
#define ARVOREAVL_H
#include "No.h"

class ArvoreAVL
{
    public:
        ArvoreAVL();
        void incluir(int);

    protected:
    private:
        void incluir(int, No*, No*);
        No* raiz;


};

#endif // ARVOREAVL_H
