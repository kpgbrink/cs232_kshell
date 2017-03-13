#pragma once
#include <string>
#include <vector>

using namespace std;

/* 
Represent directories in which the shell searches for executable programs
*/

class Path {
    public:
        Path();
        bool resolve(const string& program, string& path) const;
    private:
        vector<string> directories;
};