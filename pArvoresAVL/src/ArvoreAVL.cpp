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
    this->incluir(info, raiz, NULL);
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
void ArvoreAVL<T>::remover(T info, No<T>* ptr, No<T>* pai)
{

}
