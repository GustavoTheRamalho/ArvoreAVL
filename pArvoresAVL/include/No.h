#ifndef NO_H
#define NO_H

#include <iostream>
using namespace std;

template <class T>
class No
{
    public:
        No(T, No*, No*);
        No(T);
        ~No();

        void setDir(No* ptr);
        void setEsq(No* ptr);
        void setEquilibrio(int);
        void setInfo(T);

        No* getDir();
        No* getEsq();
        int getEquilibrio();
        T getInfo();

        int ehFolha();
        int estaEquilibrado();

        char* toString();

        friend ostream &operator<<(ostream& out, const No<T>& no);




    protected:
    private:
        T info;
        int equilibrio;
        No* direita;
        No* esquerda;


};
#include "../src/No.cpp"
#endif // NO_H
