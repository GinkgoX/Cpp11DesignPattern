/************************************************************
* @Filename         :adaptor.cpp
* @Description      :
* @Date             :2023/02/08 11:22:08
* @Author           :Maxwell
* @Email            :Maxwell.xie@ovt.com
* @Version          :1.0
* @ Copyright (c) 2023 Maxwell Xie. All rights reserved
************************************************************/

#include<iostream>

using std::cout;
using std::endl;

class Deque{
 public:
    void push_front(int x) {cout << "deque push front " << x << endl;}
    void push_back(int x) {cout << "deque push back" << x << endl;}
    void pop_front() {cout << "deque pop front" << endl;}
    void pop_back() {cout << "deque pop back" << endl;}
};

class Sequence{
 public:
    virtual void push(int x) = 0;
    virtual void pop() = 0;
};

class Queue: public Sequence{
 public:
    void push(int x) {
        deque.push_back(x);
    }
    void pop() {
        deque.pop_front();
    }
 private:
    Deque deque;
};

class Stack: public Sequence{
 public:
    void push(int x) {
        deque.push_back(x);
    }
    void pop() {
        deque.pop_back();
    }
 private:
    Deque deque;
};



int main() {
    Sequence* s1 = new Stack();
    // Sequence* s2 = new Stack();
    s1->push(1);
    s1->push(2);
    s1->pop();
    delete s1;
    return 0;
}







