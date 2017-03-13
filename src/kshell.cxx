#include "kshell.hxx"
#include "prompt.hxx"
#include "command_line.hxx"
extern "C" {
    #include <unistd.h>
    #include <stdlib.h>
    #include <sys/wait.h>
}

KShell::KShell ()
:path() 
{
}

void KShell::run () {
    while (true) {
        cout << Prompt().get() << flush;
        CommandLine commandLine(cin);
        if (!commandLine.isValid()) { // if commandLine args size is 0 skip
            cout << "arguments are empty" << endl;
            continue;
        }
        if (commandLine.getCommand() == "exit") {
            break;
        }
         
        if (commandLine.getCommand() ==  "cd") { // change directory
            if (commandLine.getArgVector().size() != 2) {
                cout << "not correct amount of args" << endl;
                continue;
            }
            chdir(commandLine.getArgVector()[1].c_str());
            continue;
        }
        
        if (commandLine.getCommand() == "pwd")
        {
            if (commandLine.getArgVector().size() != 1) {
                cout << "not correct amount of args" << endl;
                continue;
            }
            cout << Prompt().getPWD() << endl;
            continue;
        }
        
        string pathString;
        if (path.resolve(commandLine.getCommand() , pathString)) {
            pid_t child_pid = fork();
            if (child_pid == -1) { // fork failed
                cout << "fork failed" << endl;
            } else if (child_pid) { // if I am the parent
                if (commandLine.noAmpersand()) {
                    waitpid(child_pid, NULL, 0);
                } 
            } else { // I am the child
                vector<char*> argVec;
                for (unsigned int i; i < commandLine.getArgVector().size(); i++) {
                    argVec.push_back((char*) commandLine.getArgVector()[i].c_str());
                }
                argVec.push_back(NULL);
                
                execv(pathString.c_str(), argVec.data());
                abort();
            }
            
            
        } else {
            cout << commandLine.getCommand() << ": command not found" << endl;
        }
    }
}
