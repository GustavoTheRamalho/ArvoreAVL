#include "No.h"
#include <iostream>
template <class T>
No<T>::No(T info)
{
    this->info = info;
    this->esquerda = NULL;
    this->direita = NULL;
}

template <class T>
No<T>::No(T info, No* esq, No* dir)
{
    this->info = info;
    this->esquerda = esq;
    this->direita = dir;
}

template <class T>
void No<T>::setDir(No* ptr)
{
    this->direita = ptr;
}

template <class T>
void No<T>::setEsq(No* ptr)
{
    this->esquerda = ptr;
}

template <class T>
No<T>* No<T>::getDir()
{
    return this->direita;
}

template <class T>
No<T>* No<T>::getEsq()
{
    return this->esquerda;
}

template <class T>
T No<T>::getInfo()
{

    return this->info;
}

template <class T>
void No<T>::setInfo(T info)
{
    this->info = info;
}

template <class T>
int No<T>::ehFolha()
{
    return this->esquerda == NULL && this->direita == NULL;
}




