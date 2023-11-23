/************************************************************
* @Filename         :bridge.cpp
* @Description      :
* @Date             :2023/03/07 14:44:41
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

class OS{
 public:
    virtual void installOS_impl() {}
};

class LinuxOS: public OS{
 public:
    void installOS_impl() {
        std::cout << "installing Linux System. " << std::endl;
    }
};

class WinOS: public OS{
 public:
    void installOS_impl() {
        std::cout << "installing Windows System. " << std::endl;
    }
};

class IOS: public OS{
 public:
    void installOS_impl() {
        std::cout << "installing IOS System now . " << std::endl;
    }
};

class Computer {
 public:
     virtual void installOS(OS* os) {
         os -> installOS_impl();
     }
    explicit  Computer(string str): name(str) {}
    Computer(): name("") {}
     virtual void setName(string str) {
         name = str;
     }
     virtual void getName() const {
         std::cout << "my name is " << name << " , ";
     }
 private:
    string name;
};

class Apple: public Computer{};

class XiaoMi: public Computer{};

class HuaWei: public Computer{};

int main(int argc, char* argv[]) {
    Computer* com = new Apple();
    com -> setName("apple");
    OS* os = new LinuxOS();
    OS* os1 = new IOS();

    com -> getName();
    com -> installOS(os);

    std::cout << "Now, I want to install IOS System. " << endl;
    com -> getName();
    com -> installOS(os1);

    delete os;
    delete os1;
    delete com;

    return 0;
}
