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
    arv->incluir(5);
    cout << arv->altura() << endl;



    cout << "Hello world!" << endl;
    return 0;
}
