#pragma once
#include <string>

using namespace std;

class Path {
    public:
        Path();
        int find(const string& program) const;
        string getDirectory(int i) const;
};