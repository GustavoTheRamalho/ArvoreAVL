#include <iostream>
#include "ArvoreAVL.h"
#include "No.h"


using namespace std;

int main()
{
    ArvoreAVL<int> *arv = new ArvoreAVL<int>();



    arv->incluir(1);
    arv->incluir(2);
    arv->incluir(3);
    arv->incluir(4);
    arv->incluir(7);
    arv->incluir(8);
    arv->incluir(10);
    arv->incluir(6);
    arv->incluir(0);
    arv->remover(10);
    //arv->test();





    cout << '\n' << arv->toStringPorNvl() << endl;






    return 0;
}
