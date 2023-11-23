#include<iostream>

using namespace std;

enum TYPE {COREA, COREB};

class SingleCore{
public:
    virtual void show() = 0;
};

class SingleCoreA: public SingleCore{
public:
    void show(){
        cout << "single core A" << endl;
    }
};

class SingleCoreB: public SingleCore{
public:
    void show(){
        cout << "single core B" << endl;
    }
};


class Factory{
public:
    SingleCore* crateSingleCore(enum TYPE t){
        if(t == COREA){
            return new SingleCoreA();
        }
        else if(t == COREB){
            return new SingleCoreB();
        }
        else{
            return nullptr;
        }
    }
};


int main(){

    Factory* f = new Factory();
    SingleCore* s = f->crateSingleCore(COREB);
    s->show();
    delete f;
    delete s;
    return 0;
}







