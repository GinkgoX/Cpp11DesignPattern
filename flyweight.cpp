/************************************************************
* @Filename         :flyweight.cpp
* @Description      :
* @Date             :2023/03/07 14:55:56
* @Author           :Maxwell
* @Email            :Maxwell.xie@ovt.com
* @Version          :1.0
* @ Copyright (c) 2023 Maxwell Xie. All rights reserved
************************************************************/

#include<iostream>
#include<string>
#include<unordered_map>


using std::cout;
using std::endl;

static const char *orders[] = {
    "....####....\n"
    "..##....##..\n"
    "..##....##..\n"
    "..##....##..\n"
    "..##....##..\n"
    "....####....\n",

    ".....##.....\n"
    "...####.....\n"
    ".....##.....\n"
    ".....##.....\n"
    ".....##.....\n"
    "....####....\n",

    "....####....\n"
    "..##....##..\n"
    "........##..\n"
    ".......##...\n"
    ".....##.....\n"
    "....##......\n"
    "..########..\n",

    "....####....\n"
    "..##....##..\n"
    ".......##...\n"
    "....###.....\n"
    ".......##...\n"
    "......##....\n"
    "..####......\n",

    ".......##....\n"
    ".....####...\n"
    "...##..##...\n"
    "..##...##...\n"
    ".##########.\n"
    ".......##...\n"
    "......####..\n",

    "...######...\n"
    "...##.......\n"
    "...######...\n"
    "........##..\n"
    "...##...##..\n"
    "....#####...\n",

    "....#####...\n"
    "...##...##..\n"
    "...##.......\n"
    "...#######..\n"
    "...##....##.\n"
    "...##....##.\n"
    "...##....##.\n"
    "....#####...\n",

    "...########.\n"
    "........##..\n"
    ".......##...\n"
    "......##....\n"
    ".....##.....\n"
    ".....##.....\n"
    ".....##.....\n"};

class BigChar {
 public:
    explicit BigChar(int idx): char_(orders[idx % 8]) {}
    void show() {
        cout << char_;
    }
 private:
    const char* char_;
};


class BigCharFactory {
 public:
    ~BigCharFactory() {
        for (auto i : mp_) {
            delete i.second;
        }
        mp_.clear();
    }

    BigChar* getBigChar(int order) {
        BigChar* b = nullptr;
        int idx = order % 8;
        auto iter = mp_.find(idx);
        if (iter == mp_.end()) {
            b = new BigChar(idx);
            mp_.insert({idx, b});
            return b;
        } else {
            return iter -> second;
        }
    }

 private:
    std::unordered_map<int, BigChar*> mp_;
};


int main(int argc, char* argv[]) {
    BigCharFactory bc;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 2; j++) {
            BigChar *b = bc.getBigChar(i);
            cout << i << " " << b << endl;
            b -> show();
        }
    }
    return 0;
}
