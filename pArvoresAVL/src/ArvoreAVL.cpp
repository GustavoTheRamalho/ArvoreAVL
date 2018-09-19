#ifndef ARVOREAVL_CPP
#define ARVOREAVL_CPP

#include "ArvoreAVL.h"
#include <iostream>
#include <string.h>

template <class T>
ArvoreAVL<T>::ArvoreAVL()
{
    this->raiz = NULL;
}

template <class T>
void ArvoreAVL<T>::incluir(T info)
{
    No<T>* novo = new No<T>(info);

    if (this->raiz == NULL)
        this->raiz = novo;
    else
    {
        No<T>* atual = this->raiz;
        No<T>* anterior = NULL;
        while(atual != NULL)
        {
            anterior = atual;
            if (novo->getInfo() > atual->getInfo())
                atual = atual->getDir();
            else
                atual = atual->getEsq();
        }

        if (novo->getInfo() > anterior->getInfo())
            anterior->setDir(novo);
        else
        if (novo->getInfo() < anterior->getInfo())
            anterior->setEsq(novo);
    }
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
            atual = atual->getDir();
        else
            atual = atual->getEsq();
    }

    if (atual == NULL)
        return;

    if (atual->ehFolha())
    {
        if (anterior->getEsq() == atual)
            anterior->setEsq(NULL);
        else
            anterior->setDir(NULL);

        delete atual;
    }
    else
    {
        int esq = this->altura(atual->getEsq());
        int dir = this->altura(atual->getDir());

        if (esq > dir)
        {
            int maior = this->getMaior(atual->getEsq());
            this->remover(maior);
            atual->setInfo(maior);
        }
        else
        {
            int menor = this->getMenor(atual->getDir());
            this->remover(menor);
            atual->setInfo(menor);
        }


    }
}





template <class T>
int ArvoreAVL<T>::altura()
{
    return this->altura(this->raiz);
}

template <class T>
int ArvoreAVL<T>::altura(No<T>* ptr)
{
    if (ptr == NULL)
        return 0;

    if (ptr->ehFolha())
        return 1;

    return std::max(this->altura(ptr->getEsq()), this->altura(ptr->getDir())) + 1;
}

template <class T>
char* ArvoreAVL<T>::toString()
{



}

template <class T>
char* ArvoreAVL<T>::toString(No*<T> ptr, char* buff)
{



}



template <class T>
T ArvoreAVL<T>::getMaior(No<T>* ptr)
{
    No<T>* atual = ptr;
    No<T>* anterior = NULL;

    while (atual != NULL)
    {
        anterior = atual;
        atual = atual->getDir();
    }

    return anterior->getInfo();
}


template <class T>
T ArvoreAVL<T>::getMenor(No<T>* ptr)
{
    No<T>* atual = ptr;
    No<T>* anterior = NULL;

    while (atual != NULL)
    {
        anterior = atual;
        atual = atual->getEsq();
    }

    return anterior->getInfo();
}







#endif // ARVOREAVL_CPP






