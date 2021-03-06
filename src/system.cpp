#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>
#include <unistd.h>

#include "process.h"
#include "processor.h"
#include "system.h"
#include "linux_parser.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

//  Return the system's CPU
Processor& System::Cpu() { return cpu_; }

//  Return a container composed of the system's processes
vector<Process>& System::Processes() { return processes_;}

//  Return the system's kernel identifier (string)
std::string System::Kernel() { 
    if(kernel_ == "") { 
        kernel_ = LinuxParser::Kernel();
    }
    return  kernel_;
}

//  Return the system's memory utilization
float System::MemoryUtilization() { 
    return LinuxParser::MemoryUtilization();
}

//  Return the operating system name
std::string System::OperatingSystem() {
    if (os_ == "")
        os_ = LinuxParser::OperatingSystem();
    return os_;
}
//  Return the number of processes actively running on the system
int System::RunningProcesses() { 
    return LinuxParser::RunningProcesses(); 
}
void System::add_remove_processes() {
    bool exists = false;
    static int counter =0;
    for(auto pid : pids) {
        for (auto process: processes_) {
            if(process.Pid() == pid){
                exists = true;
            }
        }
        if(exists) {
            exists = false;
            continue;
        } else { 
            // add processes that exist in pid and do not exist in processes_
            Process process;
            process.Pid(pid);
            processes_.push_back(process);
        } 
    }
    for(auto process: processes_) {
        for(auto pid : pids) {
            if(process.Pid() == pid) {
                exists = true;
                break;
            }
        }
        if (exists) {
            exists = false;
            continue;
        } else { 
            // remove processes that exist in processes_ and don't exist in pid
            auto found_process = std::find(processes_.begin(), processes_.end(), process.Pid());
            if (found_process != processes_.end()){
                processes_.erase(found_process);
            }
        }
    }
    std::sort(processes_.begin(), processes_.end());

    counter++;
}

//  Return the total number of processes on the system
// this function adds and erases processes_ vector according to their pid
int System::TotalProcesses() {
    pids = LinuxParser::Pids();
    add_remove_processes();
    
    return pids.size();
}

//  Return the number of seconds since the system started running
long int System::UpTime() { return (long int) LinuxParser::UpTime(); }
