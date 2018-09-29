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

    calcEquilibrio(this->raiz);
    balancear();
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

        calcEquilibrio(this->raiz);
        this->balancear();

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
    char* ret = new char[100];
    strcpy(ret, "");
    strcat(ret, "(");
    this->printaNo(this->raiz, ret);
    strcat(ret, ")");
    return ret;
}

template <class T>
void ArvoreAVL<T>::printaNo(No<T>* ptr, char* buff)
{
    if (ptr == NULL)
        return;
    if (ptr->getEsq() != NULL)
        strcat(buff, "(");


    this->printaNo(ptr->getEsq(), buff);

    strcat(buff, ptr->toString());

    if (ptr->getDir() != NULL)
        strcat(buff, "(");
    this->printaNo(ptr->getDir(), buff);

    if (ptr->ehFolha())
        strcat(buff, ")");

}

template <class T>
char* ArvoreAVL<T>::toStringPorNvl()
{

    int tam = altura(this->raiz);

    char** buff = new char*[tam];
    for (int i=0; i < tam; i++)
    {
        buff[i] = new char[100];
        strcpy(buff[i], "");
    }

    this->printaPorNvl(this->raiz, buff, 0);

    char* ret = new char[tam*100];
    strcpy(ret, "");

    for (int i=0; i<tam; i++)
    {
        strcat(ret, buff[i]);
        strcat(ret, "\n");
    }

    return ret;


}

template <class T>
void ArvoreAVL<T>::printaPorNvl(No<T>* ptr, char** buff, int nvl)
{
    if (ptr == NULL)
        return;

    printaPorNvl(ptr->getEsq(), buff, nvl+1);
    if (ptr == this->raiz)
        strcat(buff[nvl], "   ");
    strcat(buff[nvl], ptr->toString());
    strcat(buff[nvl], "     ");


    printaPorNvl(ptr->getDir(), buff, nvl+1);
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


template <class T>
void ArvoreAVL<T>::calcEquilibrio(No<T>* ptr)
{
    if (ptr == NULL)
        return;

    if (ptr->getEsq() != NULL)
        calcEquilibrio(ptr->getEsq());


    ptr->setEquilibrio(this->altura(ptr->getDir()) - altura(ptr->getEsq()));

    if (ptr->getDir() != NULL)
        calcEquilibrio(ptr->getDir());
}

template <class T>
void ArvoreAVL<T>::test()
{
    calcEquilibrio(this->raiz);
}

template <class T>
void ArvoreAVL<T>::balancear()
{
    this->balancear(raiz, NULL);
}

template <class T>
void ArvoreAVL<T>::balancear(No<T>* ptr, No<T>*ant)
{
    if (ptr == NULL)
        return;

    this->balancear(ptr->getEsq(), ptr);

    if (ptr->getEquilibrio() > 1)
        if (ptr->getDir()->getEquilibrio() < 0)
            rotacionarDuplaEsq(ptr, ant);
        else
            rotacionarEsq(ptr, ant);
    else
    if (ptr->getEquilibrio() < -1)
        if (ptr->getEsq()->getEquilibrio() > 0)
            rotacionarDuplaDir(ptr, ant);
        else
            rotacionarDir(ptr, ant);

    this->balancear(ptr->getDir(), ptr);
}

template <class T>
void ArvoreAVL<T>::rotacionarEsq(No<T>* ptr, No<T>* ant)
{
    No<T>* novaRaiz = ptr->getDir();

    if (ant == NULL)
        this->raiz = novaRaiz;
    else
        if (ant->getEsq() == ptr)
            ant->setEsq(novaRaiz);
        else
            ant->setDir(novaRaiz);

    ptr->setDir(novaRaiz->getEsq());
    novaRaiz->setEsq(ptr);
}

template <class T>
void ArvoreAVL<T>::rotacionarDir(No<T>* ptr, No<T>* ant)
{
    No<T>* novaRaiz = ptr->getEsq();

    if (ant == NULL)
        this->raiz = novaRaiz;
    else
        if (ant->getEsq() == ptr)
            ant->setEsq(novaRaiz);
        else
            ant->setDir(novaRaiz);

    ptr->setEsq(novaRaiz->getDir());
    novaRaiz->setDir(ptr);
}

template <class T>
void ArvoreAVL<T>::rotacionarDuplaEsq(No<T>* ptr, No<T>* ant)
{
    rotacionarDir(ptr->getDir(), ptr);
    rotacionarEsq(ptr, ant);
}

template <class T>
void ArvoreAVL<T>::rotacionarDuplaDir(No<T>* ptr, No<T>* ant)
{
    rotacionarEsq(ptr->getEsq(), ptr);
    rotacionarDir(ptr, ant);
}











#endif // ARVOREAVL_CPP






