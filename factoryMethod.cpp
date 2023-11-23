#include<iostream>

using namespace std;

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
    virtual SingleCore* createSingleCore() = 0;
};

class FactoryA: public Factory{
public:
    SingleCore* createSingleCore(){
        return new SingleCoreA();
    }
};

class FactoryB: public Factory{
public:
    SingleCore* createSingleCore(){
        return new SingleCoreB();
    }
};

int main(){
    
    FactoryA* fa = new FactoryA();
    FactoryB* fb = new FactoryB();
    SingleCore* s = fa->createSingleCore();
    s->show();
    s = fb->createSingleCore();
    s->show();
    delete fa;
    delete fb;
    delete s;
    return 0;
}