#include "No.h"
#include <iostream>
No::No(int info)
{
    this->info = info;
    this->esquerda = NULL;
    this->direita = NULL;

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

int No::getInfo()
{

    return this->info;
}




