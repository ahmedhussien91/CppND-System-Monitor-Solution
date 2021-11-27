#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

// TODO: Return this process's ID
int Process::Pid() { return pid; }
void Process::Pid(int pid) { 
    this->pid = pid;
    command = LinuxParser::Command(pid);
    user = LinuxParser::User(pid);
}

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() { 
    long startTime;
    long total_p; 
    total_p = LinuxParser::ActiveJiffies(pid, &startTime)/LinuxParser::getHz();
    double total = (double) LinuxParser::UpTime();

    total = total - startTime/LinuxParser::getHz();
    cpu_util = total_p/(total);
    return  cpu_util;
}

// TODO: Return the command that generated this process
string Process::Command() { return command; }

// TODO: Return this process's memory utilization
string Process::Ram() { 
    ram = stoi(LinuxParser::Ram(pid));
    return  LinuxParser::Ram(pid);
}

// TODO: Return the user (name) that generated this process
string Process::User() { return user; }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(pid); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const {         
    bool ret =false;
    if (this->cpu_util - a.cpu_util > 0.000001) {
        ret = true;
    } else {
        ret = false;
    }
    return ret;
}