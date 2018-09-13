#include "ArvoreAVL.h"
#include <iostream>
ArvoreAVL::ArvoreAVL()
{
    this->raiz = NULL;
}

void ArvoreAVL::incluir(int info)
{
    this->incluir(info, raiz, NULL);
}


void ArvoreAVL::incluir(int info, No* ptr, No* pai)
{
    if (ptr == NULL)
        ptr = new No(info);
        if (pai != NULL)
            if (info > pai->getDir()->getInfo())
                pai->setDir(ptr);
            else
                pai->setEsq(ptr);
    else
        if (info > ptr->getInfo())
            incluir(info, ptr->getDir(), ptr);
        if (info < ptr->getInfo())
            incluir(info, ptr->getEsq(), ptr);
}
