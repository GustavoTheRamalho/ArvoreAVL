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
        int altura(No<T>*);


    protected:
    private:
        void incluir(T, No<T>*, No<T>*);



        No<T>* raiz;


};
#include "../src/ArvoreAVL.cpp"
#endif // ARVOREAVL_H
