/************************************************************
* @Filename         :facade.cpp
* @Description      :
* @Date             :2023/03/07 14:54:08
* @Author           :Maxwell
* @Email            :Maxwell.xie@ovt.com
* @Version          :1.0
* @ Copyright (c) 2023 Maxwell Xie. All rights reserved
************************************************************/


#include<iostream>
#include<sstream>
#include<cassert>
#include<string>
#include<unordered_map>
#include<fstream>

using std::cout;
using std::endl;
using std::string;

class DataBase {
 public:
    ~DataBase() = default;
    static DataBase& getInstance() {
        static DataBase db;
        return db;
    }
    string getNameByEmail(const string& email) const {
        auto iter = mp_.find(email);
        if (iter != mp_.end()) {
            return iter -> second;
        } else {
            return {};
        }
    }

 protected:
    DataBase(const DataBase&) = delete;
    DataBase(DataBase&&) = delete;
    DataBase& operator=(const DataBase&) = delete;
    DataBase& operator=(DataBase&&) = delete;

 private:
    DataBase() {}
    std::unordered_map<string, string> mp_ {
        {"cpp@language.com", "cpp"},
        {"python@language.com", "python"},
        {"java@language.com", "java"}
    };
};


class Html{
 public:
    void title(const string& title) {
        msg_ << "<html> <head> <title> " + title
         << " </title> </head> <body>\n" << "<h1> " + title << " </h1>\n";
    }

    void paragraph(const string& str) {
        msg_ << "<p> " + str << " </p>\n";
    }
    void link(const string& herf, const string& caption) {
        paragraph("<a herf=\""+ herf + "\">" + caption + "</a>");
    }
    void close() {
        msg_ << "</body> </html>\n";
    }
    string info() const {
        std::ofstream ofile;
        ofile.open("test.html", std::ios::app);
        if (!ofile.is_open()) {
            cout << "open file failed ." << endl;
        }
        ofile << msg_.str();
        ofile.close();
        return msg_.str();
    }

 private:
    std::stringstream msg_;
};

class Pager{
 public:
    ~Pager() = default;
    Pager(const Pager&) = delete;
    Pager(Pager &&) = delete;
    Pager& operator=(const Pager&) = delete;
    Pager& operator=(Pager &&) = delete;

    static Pager& getInstance() {
        static Pager pager_;
        return pager_;
    }
    void welcome(const string& email) {
        auto name = DataBase::getInstance().getNameByEmail(email);
        Html html;
        html.title("Welcome to " + name + "'s page !");
        html.paragraph(name + " Nice to meet you !");
        html.paragraph("Hope enjoy yourself, and best wish .");
        html.close();
        cout << html.info() << endl;
    }
 protected:
        Pager() {}
};



int main(int argc, char* argv[]) {
    assert(DataBase::getInstance().getNameByEmail("").empty());
    Pager::getInstance().welcome("cpp@language.com");
    return 0;
}
