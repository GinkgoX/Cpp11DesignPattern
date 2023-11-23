/************************************************************
* @Filename         :singleton2.cpp
* @Description      : genererate given number of singletons
* @Date             :2023/02/09 17:06:44
* @Author           :Maxwell
* @Email            :Maxwell.xie@ovt.com
* @Version          :1.0
* @ Copyright (c) 2023 Maxwell Xie. All rights reserved
************************************************************/

#include<iostream>
#include<utility>

using std::cout;
using std::endl;

template<typename T>
class Bioton{
 public:
    static T& getInstance(int id) {
        int num = id % 2;
        switch (num) {
            case 0: {
                static T bioton;
                return bioton;
            }
            case 1:
            default: {
                static T bioton;
                return bioton;
            }
        }
    }

    virtual void show() {
        cout << __FUNCTION__ << endl;
    }
    Bioton(const Bioton&) = delete;
    Bioton& operator=(const Bioton&) = delete;

 protected:
    Bioton() { }
    ~Bioton() { }
};

class Apple: public Bioton<Apple>{
    friend class Bioton<Apple>;
 public:
    ~Apple() {
        cout << __FUNCTION__ << endl;
    }
 protected:
    Apple() { }
};

int main() {
    Apple::getInstance(0).show();
    cout << &Apple::getInstance(0) << endl;
    Apple::getInstance(1).show();
    cout << &Apple::getInstance(1) << endl;
    Apple::getInstance(2).show();
    cout << &Apple::getInstance(2) << endl;
    return 0;
}


