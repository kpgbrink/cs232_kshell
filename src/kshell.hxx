#pragma once
#include "path.hxx"

using namespace std;

/*
shell class
*/
class KShell {
    public:
        KShell();
        void run();
    private:
        Path path;
};
