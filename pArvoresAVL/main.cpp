#include <iostream>
#include "ArvoreAVL.h"
#include "No.h"


using namespace std;

int main()
{
    ArvoreAVL<int> *arv = new ArvoreAVL<int>();
    arv->incluir(2);
    arv->incluir(3);



    cout << "Hello world!" << endl;
    return 0;
}
