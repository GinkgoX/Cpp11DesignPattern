/************************************************************
* @Filename         :prototype.cpp
* @Description      :
* @Date             :2023/02/08 19:32:08
* @Author           :Maxwell
* @Email            :Maxwell.xie@ovt.com
* @Version          :1.0
* @ Copyright (c) 2023 Maxwell Xie. All rights reserved
************************************************************/

#include<iostream>
#include<cassert>
#include<string>
#include<unordered_map>

using std::cout;
using std::endl;
using std::string;

class IProduct{
 public:
    virtual ~IProduct() {}
    virtual IProduct* clone() = 0;
    virtual void use(const string& str) = 0;
};

class MessageBox: public IProduct{
 public:
    explicit MessageBox(const string& str):mstr(str) {}
    IProduct* clone() {
        return new MessageBox(mstr);
    }
    void use(const string& str) {
        cout << "message box " << mstr << " " << str << endl;
    }
 private:
    string mstr;
};

class ProductMgr{
 public:
    void registerPM(const string& str, IProduct* ip) {
        pm.insert({str, ip});
    }

    IProduct* create(const string& str) {
        auto i = pm.find(str);
        if (i != pm.end()) {
            return i -> second -> clone();
        } else {
            return nullptr;
        }
    }
 private:
    std::unordered_map<string, IProduct*> pm;
};

int main() {
    ProductMgr mgr;
    IProduct* p1 = new MessageBox("hello");
    mgr.registerPM("MB", p1);
    p1 -> use("World");

    auto p2 = mgr.create("MB");
    p2 -> use("Word");

    cout << p1 << endl;
    cout << p2 << endl;
    
    delete p1;
    p2 -> use("Wrod");
    return 0;
}


