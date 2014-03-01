/****************************************

DEBUG UTILITIES

****************************************/

#pragma once
#ifdef _DEBUG
#include <iostream>
#include <fstream>
#include <time.h>
#include <string>

class Debug_ {
public:
    Debug_()
    {
        logfile = std::ofstream("logfile.txt");
        logfile.clear();
    }

    ~Debug_()
    {
        logfile.close();
    }

    void log_(std::string info, std::string data)
    {
        std::clog.rdbuf(logfile.rdbuf());
        std::clog << "LOG: " << info << " " << data << std::endl;
        std::cout << "To LOG: " << info << " " << data << std::endl;
    }

    std::string boolToStr(bool b)
    {
        return b ? "true" : "false";
    }

    std::string intToStr(int i)
    {
        char test[33];
        _itoa_s(i, test, 10);

        std::string stest = test;
        return stest;
    }

private:
    std::ofstream logfile;

};
#endif // _DEBUG