#ifndef NO_H
#define NO_H


class No
{
    public:
        No(int, No*, No*);
        No(int);
        void setDir(No* ptr);
        void setEsq(No* ptr);
        No* getDir();
        No* getEsq();
        int getInfo();
        void setInfo();

    protected:
    private:
        int info;
        No* direita;
        No* esquerda;


};

#endif // NO_H
