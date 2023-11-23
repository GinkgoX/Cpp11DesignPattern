/************************************************************
* @Filename         :command.cpp
* @Description      :
* @Date             :2023/03/07 14:49:24
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

class Object{
 public:
    virtual void excute() = 0;
    virtual ~Object() = default;
};

class Controlor{
 public:
    void setCommand(Object* com) {
        obj_ = com;
    }
    void buttonOn() {
        obj_ -> excute();
    }
 private:
    Object* obj_;
};

class Electron: public Object {
 public:
    explicit Electron(const string& str): sig_(str) {}
    void excute() {
        cout << sig_ << " is opening " << endl;
    }
 private:
    string sig_;
};

class Light: public Object {
 public:
    explicit Light(const string& name): lig_(name) {}
    void excute() {
        cout << lig_ << " is opening " << endl;
    }
 private:
    string lig_;
};

int main(int argc, char* argv[]) {
    Controlor* con = new Controlor();
    Light* lig = new Light("light source");
    Electron* ele = new Electron("electronic source");

    con -> setCommand(lig);
    con -> buttonOn();
    con -> setCommand(ele);
    con -> buttonOn();

    delete con;
    delete lig;
    delete ele;
    return 0;
}
