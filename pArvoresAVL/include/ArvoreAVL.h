#ifndef ARVOREAVL_H
#define ARVOREAVL_H
#include "No.h"
template <class T>
class ArvoreAVL
{
    public:
        ArvoreAVL();
        void incluir(T);
        void remover(T);


    protected:
    private:
        void incluir(T, No<T>*, No<T>*);
        void remover(T, No<T>*, No<T>*);


        No<T>* raiz;


};

#endif // ARVOREAVL_H
