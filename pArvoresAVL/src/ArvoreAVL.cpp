#ifndef ARVOREAVL_CPP
#define ARVOREAVL_CPP

#include "ArvoreAVL.h"
#include <iostream>

template <class T>
ArvoreAVL<T>::ArvoreAVL()
{
    this->raiz = NULL;
}

template <class T>
void ArvoreAVL<T>::incluir(T info)
{
    this->incluir(info, this->raiz, NULL);
}


template <class T>
void ArvoreAVL<T>::incluir(T info, No<T>* ptr, No<T>* pai)
{
    if (ptr == NULL)
        ptr = new No<T>(info);
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


template <class T>
void ArvoreAVL<T>::remover(T info)
{
    No<T>* atual = this->raiz;
    No<T>* anterior = NULL;

    while (atual->getInfo() != info && atual != NULL)
    {
        anterior = atual;

        if (info > atual->getInfo())
            atual = atual->direita;
        else
            atual = atual->esquerda;
    }

    if (atual == NULL)
        return;

    if (atual->ehFolha())
    {
        if (anterior->getEsquerda == atual)
            anterior->setEsquerda(NULL);
        else
            anterior->setDireita(NULL);

        delete atual;
    }
    else
    {
    //continua aq
    }
}

template <class T>
int ArvoreAVL<T>::altura(No<T>* ptr)
{
    if (ptr == NULL)
        return 0;

    if (ptr->ehFolha())
        return 1;
    else
        return std::max(this->altura(ptr->esquerda), this->altura(ptr->direita)) + 1;
}

#endif // ARVOREAVL_CPP






