#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class CommandLine {
    public:
        CommandLine(istream& in);
        string getCommand() const;
        vector<string> getArgVector() const;
        string getArgVector(int i) const;
        bool noAmpersand() const;
};
