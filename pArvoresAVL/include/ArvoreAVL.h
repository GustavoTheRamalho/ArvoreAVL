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




    protected:
    private:
        void incluir(T, No<T>*, No<T>*);
        int altura(No<T>*);
        No<T> *menorDaDireita();

        T getMaior(No<T> *ptr);
        T getMenor(No<T> *ptr);

        char* toString(No<T>*);


        No<T>* raiz;


};
#include "../src/ArvoreAVL.cpp"
#endif // ARVOREAVL_H
