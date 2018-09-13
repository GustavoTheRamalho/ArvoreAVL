#include "No.h"

No::No(int info)
{
    this->info = info;
    this->esquerda = nullptr;
    this->direita = nullptr;

}

No::No(int info, No* esq, No* dir)
{
    this->info = info;
    this->esquerda = esq;
    this->direita = dir;
}

void No::setDir(No* ptr)
{
    this->direita = ptr;
}

void No::setEsq(No* ptr)
{
    this->esquerda = ptr;
}

No* No::getDir()
{
    return this->direita;
}

No* No::getEsq()
{
    return this->esquerda;
}



s
