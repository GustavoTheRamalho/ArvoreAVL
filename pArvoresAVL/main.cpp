#include <iostream>
#include "ArvoreAVL.h"
#include "No.h"


using namespace std;

int main()
{
    ArvoreAVL<int> *arv = new ArvoreAVL<int>();



    arv->incluir(4);
    arv->incluir(3);
    arv->incluir(1);
    //arv->incluir(2);
    //arv->incluir(5);
    //arv->test();





    cout << '\n' << arv->toString() << endl;






    return 0;
}
