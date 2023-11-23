/************************************************************
* @Filename         :composite.cpp
* @Description      :
* @Date             :2023/03/07 14:49:31
* @Author           :Maxwell
* @Email            :Maxwell.xie@ovt.com
* @Version          :1.0
* @ Copyright (c) 2023 Maxwell Xie. All rights reserved
************************************************************/
#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Entry {
 public:
    virtual ~Entry() {}
    virtual string getName() const = 0;
    virtual int getSize() const = 0;
    virtual void addEntry(Entry* entry) {}
    virtual void print(const string& str) = 0;
    void print() {
        print("");
    }
    string info() const {
        return getName() + "(" + std::to_string(getSize()) + ")";
    }
};

class Directory: public Entry {
 public:
    explicit Directory(const string& str): name_(str) {}
    ~Directory() {
        for (auto entry : entries_) {
            delete entry;
        }
        entries_.clear();
    }
    string getName() const {
        return name_;
    }
    int getSize() const {
        return entries_.size();
    }
    void addEntry(Entry* entry) {
        entries_.push_back(entry);
    }
    void print(const string& str) {
        cout << str << "/" << info() << endl;
        for (auto entry : entries_) {
            entry -> print(str + "/" + name_);
        }
    }

 private:
    string name_;
    vector<Entry*> entries_;
};

class File: public Entry {
 public:
     File(const string& name, int size): name_(name), size_(size) {}
     string getName() const {
         return name_;
     }
     int getSize() const {
         return size_;
     }
     void print(const string& str) {
         cout << str << "/" << info() << endl;
     }
 private:
    string name_;
    int size_;
};

int main(int argc, char* argv[]) {
    Directory* root = new Directory("root");
    Directory* usr = new Directory("usr");
    Directory* bin = new Directory("bin");

    root -> addEntry(bin);
    root -> addEntry(usr);
    bin -> addEntry(new File("vi", 200));
    bin -> addEntry(new File("latex", 300));
    usr -> addEntry(new File("cpp", 100));
    static_cast<Entry*>(root)-> print();

    delete root;
    return 0;
}
