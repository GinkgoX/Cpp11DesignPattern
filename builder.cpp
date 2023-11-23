/************************************************************
* @Filename         :builder.cpp
* @Description      :
* @Date             :2023/02/09 19:25:17
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

class IBuilder{
 public:
    virtual void makeTitle(const string&) = 0;
    virtual void makeString(const string&) = 0;
    virtual void makeItems(const string&) = 0;
    virtual void clone() = 0;
};

class TextBuiler: public IBuilder{
 public:
    void makeTitle(const string& title) {
        mstr.append("======================\n");
        mstr.append("Title: [" + title + "] \n");
    }
    void makeString(const string& str) {
        mstr.append("String: " + str + "\n");
    }
    void makeItems(const string& items) {
        mstr.append("Item: " + items +"\n");
    }
    void clone() {
        mstr.append("======================\b");
    }
    string getResult() {
        return mstr;
    }
 private:
  string mstr;
};

class Director{
 public:
    explicit Director(IBuilder* ibu):mbu(ibu) {}
    void construct() {
        mbu->makeTitle("morning");
        mbu->makeString("good morning");
        mbu->makeItems("breakfirst");
        mbu->clone();
    }
 private:
    IBuilder* mbu;
};

int main() {
    TextBuiler* tbu = new TextBuiler;
    Director dir(tbu);
    dir.construct();
    cout << tbu->getResult() << endl;
    delete tbu;
    return 0;
}


