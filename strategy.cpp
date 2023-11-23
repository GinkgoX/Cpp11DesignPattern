/************************************************************
* @Filename         :strategy.cpp
* @Description      :
* @Date             :2023/02/08 11:09:38
* @Author           :Maxwell
* @Email            :Maxwell.xie@ovt.com
* @Version          :1.0
* @ Copyright (c) 2023 Maxwell Xie. All rights reserved
************************************************************/

#include <iostream>

using std::cout;
using std::endl;

class ReplaceAlgorithm{
 public:
    virtual void replace() = 0;
};

class FIFO_ReplaceAlgoithm: public ReplaceAlgorithm{
 public:
    void replace(){
        cout << "FIFO replace algorithm" << endl;
    }
};

class LRU_ReplaceAlgorithm: public ReplaceAlgorithm{
 public:
    void replace(){
        cout << "LRU replace algorithm" << endl;
    }
};

class Random_ReplaceAlgorithm: public ReplaceAlgorithm{
 public:
    void replace(){
        cout << "Random replace algorithm" << endl;
    }
};



// heap based template
template<typename T>
class Cache{
 public:
    explicit Cache(T* ra):mra(ra) { }
    ~Cache() {delete mra;}
    void replace() { mra -> replace(); }
 private:
    T* mra;
};

// stack-base template
template<typename T>
class Cache1{
 public:
    Cache1() { }
    ~Cache1() {}
    void replace() { mra.replace(); }
 private:
    T mra;
};

int main() {
    Cache<LRU_ReplaceAlgorithm> cache = Cache<LRU_ReplaceAlgorithm>(new LRU_ReplaceAlgorithm());
    cache.replace();
    Cache1<LRU_ReplaceAlgorithm> cache1;
    cache1.replace();
    return 0;
}


