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
    Debug_(std::string filename)
    {
        filename_ = filename;
        logfile_ = std::ofstream(filename_);
        logfile_.clear();
    }

    ~Debug_()
    {
        logfile_.close();
    }

    void log_(std::string info, std::string data)
    {
        std::clog.rdbuf(logfile_.rdbuf());
        std::clog << "LOG: " << info << " " << data << std::endl;
        std::cout << "LOG: " << info << " " << data << std::endl;
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
    std::ofstream logfile_;
    std::string filename_;

};
#endif // _DEBUG