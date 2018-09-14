#ifndef NO_H
#define NO_H

template <class T>
class No
{
    public:
        No(T, No*, No*);
        No(T);
        void setDir(No* ptr);
        void setEsq(No* ptr);
        No* getDir();
        No* getEsq();
        T getInfo();
        void setInfo(T);
        int ehFolha();

    protected:
    private:
        T info;
        int equilibrio;
        No* direita;
        No* esquerda;


};

#endif // NO_H
