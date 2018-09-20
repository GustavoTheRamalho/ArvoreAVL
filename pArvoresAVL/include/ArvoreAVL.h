#ifndef ARVOREAVL_H
#define ARVOREAVL_H
#include "No.h"
#include <iostream>

template <class T>
class ArvoreAVL
{
    public:
        ArvoreAVL();

        void incluir(T info);

        void remover(T);
        int altura();
        char* toString();
        char* toStringPorNvl();
        void test();




    protected:
    private:
        void incluir(T, No<T>*, No<T>*);
        int altura(No<T>*);

        No<T> *menorDaDireita();

        T getMaior(No<T> *ptr);
        T getMenor(No<T> *ptr);

        void printaNo(No<T>*, char*);
        void printaPorNvl(No<T> *ptr, char**, int);

        No<T>* raiz;


        int estaBalanceada();
        int estaBalanceada(No<T>*);

        void calcEquilibrio(No<T>* ptr);
        void rotacionarEsq(No<T>* ,No<T>*);
        void rotacionarDir(No<T>* ,No<T>*);
        void rotacionarDuplaEsq(No<T>* ,No<T>*);
        void rotacionarDuplaDir(No<T>* ,No<T>*);

        void balancear(No<T>* ptr);



};
#include "../src/ArvoreAVL.cpp"
#endif // ARVOREAVL_H
