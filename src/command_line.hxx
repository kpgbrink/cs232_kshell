#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
read a command-line
*/
class CommandLine {
    public:
        CommandLine(istream& in);
        const string& getCommand() const;
        const vector<string>& getArgVector() const;
        bool noAmpersand() const;
        bool isValid() const;
    private:
        vector<string> args;
        bool noAmpersandBool;
};
