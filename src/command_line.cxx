#include <sstream>

#include "command_line.hxx"

CommandLine::CommandLine(istream& in) {
    string line;
    noAmpersandBool = true;
    if (!in.good() || in.eof()) {
        line = "exit";
    } else {
        getline(in, line);
    }
    if (!line.length()) {
        return;
    }
    stringstream ss(line);
    while (!ss.eof()) {
        string s;
        ss >> s;
        if (s == "&") {
            noAmpersandBool = false;
            break;
        }
        args.push_back(s);
    }
}

// return a reference to the command portion of the command-line (i.e., argv[0])
const string& CommandLine::getCommand() const {
    return args[0];
}

/*
return a reference to a char* array, each entry of which points to one 'word' 
of the command-line (i.e., argv).
 */
const vector<string>& CommandLine::getArgVector() const {
    return args;
}


// returns true if and only if no ampersand was given on the command-line
bool CommandLine::noAmpersand() const {
    return noAmpersandBool;
}

// checks if there are args
bool CommandLine::isValid() const {
    return args.size();
}
