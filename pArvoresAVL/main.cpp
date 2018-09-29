#include <iostream>
#include "ArvoreAVL.h"
#include "No.h"


using namespace std;

int main()
{
    ArvoreAVL<int> *arv = new ArvoreAVL<int>();


/*
    arv->incluir(2);
    //arv->test();
    arv->incluir(3);
    //arv->test();
    arv->incluir(1);
    //arv->test();
    arv->incluir(4);
    //arv->test();
    arv->incluir(0);
    //arv->test();
    arv->incluir(-1);
    arv->test();

*/


    arv->incluir(5);
    arv->incluir(8);
    arv->incluir(11);
    arv->incluir(12);
    arv->incluir(13);
    arv->test();



    cout << '\n' << arv->toStringPorNvl() << endl;






    return 0;
}
