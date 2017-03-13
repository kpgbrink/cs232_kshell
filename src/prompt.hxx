#pragma once
#include <string>

using namespace std;

/*
Represents the command-line prompt
*/
class Prompt {
    public:
        Prompt();
        string get() const;
        string getPWD() const;
    private:
        string workingDirectory;
};