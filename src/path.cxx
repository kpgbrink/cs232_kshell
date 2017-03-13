#include "path.hxx"
#include <sstream>

extern "C" {
    #include <unistd.h>
    #include <stdlib.h>
}

Path::Path()
{
    string path = string(getenv("PATH"));
    stringstream ss(path);
    string token;
    while (getline(ss, token, ':')) {
        directories.push_back(token);
    }
}

/*
return the index of the directory containing program, or -1 if program is in 
no directory (you may find the opendir(), readdir(), and closedir() system calls to be of use here).
*/
bool Path::resolve(const string& program, string& fullPath) const {
    for (unsigned int i = 0; i < directories.size(); i++) {
        fullPath = directories[i] + '/' + program;
        if (!access(fullPath.c_str(), X_OK)) { // If accessible
            return true;
        }
    }
    return false;
}
