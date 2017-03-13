#include "prompt.hxx"
#include <stdexcept>
#include <vector>

extern "C" {
    #include <stdlib.h>
    #include <errno.h>
    #include <unistd.h>
}

// http://pubs.opengroup.org/onlinepubs/9699919799/functions/getcwd.html
static string getCWD() {
    long path_max;
    size_t size;
    vector<char> buf;
    char *ptr;

    path_max = pathconf(".", _PC_PATH_MAX);
    if (path_max == -1)
    size = 1024;
    else if (path_max > 10240)
    size = 10240;
    else
    size = path_max;

    for (ptr = NULL; ptr == NULL; size *= 2)
    {
        buf.resize(size);

        ptr = getcwd(buf.data(), size);
        if (ptr == NULL && errno != ERANGE)
        {
            throw runtime_error("Unable to get current working directory");
        }
    }
    return string(buf.data());
}

Prompt::Prompt()
: workingDirectory(getCWD())
{
}

// an accessor that returns the current value of the Prompt
string Prompt::get() const {
    return workingDirectory + "$ ";
}

string Prompt::getPWD() const {
    return workingDirectory;
}