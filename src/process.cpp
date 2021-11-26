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
    static double total_prev = 0;
    static double total_p_prev = 0;
    int startTime;
    double total_p; 
    total_p =(double) LinuxParser::ActiveJiffies(pid, &startTime);
    double total = LinuxParser::ActiveJiffies();

    cpu_util = (total_p - total_p_prev) / (total - total_prev);

    total_p_prev = total_p; 
    total = total_prev;

    this->cpu_util = cpu_util;
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
    if (a.cpu_util - this->cpu_util > 0.000001) {
        ret = true;
    } else if (a.cpu_util - this->cpu_util < 0.000001){
        ret = false;
    }
    return ret;
}