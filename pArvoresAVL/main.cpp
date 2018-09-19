#include <iostream>
#include "ArvoreAVL.h"
#include "No.h"


using namespace std;

int main()
{
    /*ArvoreAVL<int> *arv = new ArvoreAVL<int>();


    arv->incluir(2);
    arv->incluir(1);
    arv->incluir(3);
    arv->incluir(4);
    arv->remover(2);


    cout << arv->altura() << endl;*/
    No<int> *no = new No<int>(2);




    cout << no->toString() << endl;
    return 0;
}
