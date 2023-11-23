/************************************************************
* @Filename         :proxy.cpp
* @Description      :
* @Date             :2023/03/07 14:56:56
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

class Image{
 public:
    explicit Image(string name): name_(name) {}
    virtual ~Image() {}
    virtual void show() {
        cout << name_  <<  " is general image show. " << endl;
    }
 protected:
    string name_;
};

class BigImage: public Image {
 public:
    explicit BigImage(string name):Image(name) {}
    ~BigImage() {}
    void show() {
        cout << name_  << " is big image show. " << endl;
    }
};

class BigImageProxy: public Image {
 public:
    explicit BigImageProxy(string name): Image(name), bimg_(0) {}
    ~BigImageProxy() {
        delete bimg_;
    }
    void show() {
        if (bimg_ == nullptr) {
            bimg_ = new BigImage(name_);
        }
        bimg_ -> show();
    }
 private:
    BigImage* bimg_;
};

int main(int argc, char* argv[]) {
    Image* img = new Image("middle.png");
    img -> show();
    img = new BigImageProxy("proxy.png");
    img -> show();
    delete img;
    return 0;
}
