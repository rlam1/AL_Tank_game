/****************************************

DEBUG UTILITIES

****************************************/

#pragma once
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

        writeToCout = true;
    }

    Debug_(std::string filename, bool sendToCout)
    {
        filename_ = filename;
        logfile_ = std::ofstream(filename_);
        logfile_.clear();

        writeToCout = sendToCout;
    }

    ~Debug_()
    {
        logfile_.close();
    }

    void log_(std::string info, std::string data)
    {
        std::clog.rdbuf(logfile_.rdbuf());
        std::clog << "LOG: " << info << " " << data << std::endl;

        if (writeToCout)
        {
            std::cout << "LOG: " << info << " " << data << std::endl;
        }
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

    int strToInt(std::string sVal)
    {
        return atoi(sVal.c_str());
    }

private:
    std::ofstream logfile_;
    std::string filename_;

    bool writeToCout;
};