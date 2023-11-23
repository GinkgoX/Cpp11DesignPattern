/************************************************************
* @Filename         :abstractFactory.cpp
* @Description      :
* @Date             :2023/02/08 11:04:59
* @Author           :Maxwell
* @Email            :Maxwell.xie@ovt.com
* @Version          :1.0
* @ Copyright (c) 2023 Maxwell Xie. All rights reserved
************************************************************/

#include <iostream>

// using namespace std;
using std::cout;
using std::endl;

class SingleCore{
 public:
    virtual void show() = 0;
};

class SingleCoreA : public SingleCore{
 public:
    void show(){
        cout << "single core A" << endl;
    }
};

class SingleCoreB : public SingleCore{
 public:
    void show(){
        cout << "single core B" << endl;
    }
};

class MultiCore{
 public:
    virtual void show() = 0;
};

class MultiCoreA : public MultiCore{
 public:
    void show(){
        cout << "multi core A" << endl;
    }
};

class MultiCoreB : public MultiCore{
 public:
    void show(){
        cout << "multi core B" << endl;
    }
};

class Factory{
 public:
    virtual SingleCore *createSingleCore() = 0;
    virtual MultiCore *createMultiCore() = 0;
};

class FactoryA : public Factory{
 public:
    SingleCore *createSingleCore() {
        return new SingleCoreA();
    }
    MultiCore *createMultiCore(){
        return new MultiCoreA();
    }
};

class FatoryB : public Factory{
 public:
    SingleCore *createSingleCore() {
        return new SingleCoreB();
    }
    MultiCore *createMultiCore() {
        return new MultiCoreB();
    }
};

int main()
{
    FactoryA *fa = new FactoryA();
    SingleCore *sa = fa->createSingleCore();
    sa->show();
    MultiCore *ma = fa->createMultiCore();
    ma->show();
    delete fa;
    delete sa;
    delete ma;
    return 0;
}