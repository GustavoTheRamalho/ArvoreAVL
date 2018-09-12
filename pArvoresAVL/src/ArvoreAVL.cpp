#include "ArvoreAVL.h"

ArvoreAVL::ArvoreAVL()
{
    this->raiz = nullptr;
}

void ArvoreAVL::incluir(int info)
{
    this->incluir(info, raiz, nullptr);
}


void ArvoreAVL::incluir(int info, No* ptr, No* pai)
{
    if (ptr == nullptr)
        ptr = new No(info);
        if (pai != nullptr)
            if (info > pai.getDir().getInfo())
                pai.setDir(ptr);
            else
                pai.setEsq(ptr);
    else
        if (info > ptr.getInfo())
            incluir(info, ptr.getDir(), ptr);
        if (info < ptr.getInfo())
            incluir(info, ptr.getEsq(), ptr);
}
