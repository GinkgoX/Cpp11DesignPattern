/************************************************************
* @Filename         :singleton.cpp
* @Description      :
* @Date             :2023/02/08 18:39:42
* @Author           :Maxwell
* @Email            :Maxwell.xie@ovt.com
* @Version          :1.0
* @ Copyright (c) 2023 Maxwell Xie. All rights reserved
************************************************************/

#include<iostream>
#include<utility>
#include<string>

using std::cout;
using std::endl;

template<typename T>
class Singleton{
 public:
    static T& getInstance() {
        static T singleton;
        return singleton;
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator= (const Singleton&) = delete;
    virtual void show() { cout << __FUNCTION__ << endl;}
    virtual ~Singleton() {}
 protected:
    Singleton() {}
};

class Apple: public Singleton<Apple>{
    friend Singleton<Apple>;
 public:
    ~Apple() {
        cout << __FUNCTION__ << endl;
    }
 protected:
    Apple() {}
};

class Orange: public Singleton<Orange>{
    friend Singleton<Orange>;
 public:
    ~Orange() {
        cout << __FUNCTION__ << endl;
    }
 protected:
  Orange() {}
};

int main() {
    Apple::getInstance().show();
    cout << &Apple::getInstance() << endl;
    Apple::getInstance().show();
    cout << &Apple::getInstance() << endl;

    Orange::getInstance().show();
    cout << &Orange::getInstance() << endl;
    Orange::getInstance().show();
    Orange::getInstance().show();
    return 0;
}
