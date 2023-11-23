/************************************************************
* @Filename         :observer.cpp
* @Description      :
* @Date             :2023/02/20 19:41:13
* @Author           :Maxwell
* @Email            :Maxwell.xie@ovt.com
* @Version          :1.0
* @ Copyright (c) 2023 Maxwell Xie. All rights reserved
************************************************************/

#include<vector>
#include<algorithm>
#include<iostream>
#include<functional>

using std::cout;
using std::endl;

template<typename T>
class Subject{
 public:
    void subscribe(T* object) {
        auto iter = std::find(m_subject.begin(), m_subject.end(), object);
        if ( m_subject.end() == iter ) {
            m_subject.push_back(object);
        }
    }

    void unsubcribe(T* object) {
        m_subject.erase(std::remove(m_subject.begin(), m_subject.end(), object));
    }

    template<typename F>
    void publish(F func) {
        for ( auto obs : m_subject ) {
            func(obs);
        }
    }

 private:
    std::vector<T*> m_subject;
};



class Observer{
 public:
    virtual void miao() = 0;
    virtual ~Observer() {}
};

class Tom : public Subject<Observer>{
 public:
    void miao(){
        cout << "miao !" << endl;
        publish(std::bind(&Observer::miao, std::placeholders::_1));
    }
};

class Jerry : public Observer{
 public:
    void miao() {
        runaway();
    }

    void runaway() {
        cout << "cat coming !" << endl;
    }
};


int main() {
    Tom tom;
    Jerry jerry;

    tom.subscribe(&jerry);
    tom.miao();
    return 0;
}





















