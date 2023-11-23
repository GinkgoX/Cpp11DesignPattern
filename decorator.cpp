/************************************************************
* @Filename         :decorator.cpp
* @Description      :
* @Date             :2023/03/07 14:52:50
* @Author           :Maxwell
* @Email            :Maxwell.xie@ovt.com
* @Version          :1.0
* @ Copyright (c) 2023 Maxwell Xie. All rights reserved
************************************************************/


#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

class Phone {
 public:
    Phone() {}
    virtual ~Phone() {}
    virtual void showDecorate() {}
};

class iPhone: public Phone{
 private:
    string name_;
 public:
    explicit iPhone(string str): name_(str) {}
    ~iPhone() {}
    void showDecorate() {
        cout << name_ << " 's basic decorators. " << endl;
    }
};

class Xiaomi: public Phone{
 private:
    string name_;
 public:
    explicit Xiaomi(string str):name_(str) {}
    ~Xiaomi() {}
    void showDecorate() {
        cout << name_ << " 's basic decorators. " << endl;
    }
};

class DecoratorPhone: public Phone{
 private:
    Phone* phone_;
 public:
    explicit DecoratorPhone(Phone* phone): phone_(phone) {}
    virtual void showDecorate() {
        phone_ -> showDecorate();
    }
};

class DecoratorScreen: public DecoratorPhone{
 public:
    explicit DecoratorScreen(Phone* phone):DecoratorPhone(phone) {}
    void showDecorate() {
        DecoratorPhone::showDecorate();
        addScreen();
    }
 private:
     void addScreen(){
         cout << "add screen decorator. " << endl;
     }
};

class DecoratorLogo: public DecoratorPhone{
 public:
    explicit DecoratorLogo(Phone* phone): DecoratorPhone(phone) {}
     void showDecorate() {
         DecoratorPhone::showDecorate();
         addLogo();
     }
 private:
    void addLogo() {
        cout << "add logo decorator. " << endl;
    }
};

int main(int argc, char* argv[]) {
    Phone* phone = new iPhone("iphone Max");
    Phone* phonescreen = new DecoratorScreen(phone);
    Phone* phonelogo = new DecoratorLogo(phone);
    phone -> showDecorate();
    phonescreen -> showDecorate();
    phonelogo -> showDecorate();
    phonelogo = new DecoratorLogo(phonescreen);
    phonelogo -> showDecorate();
    delete phone;
    delete phonescreen;
    delete phonelogo;
    return 0;
}
