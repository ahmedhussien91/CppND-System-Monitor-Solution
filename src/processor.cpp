#include "processor.h"
#include "linux_parser.h"
#include <sstream>
#include <fstream>
#include <string>

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() { 
    static int PrevIdle =0;
    static int  PrevNonIdle = 0;
    int Idle, NonIdle;
    int user, nice, system, idle, iowait, irq, 
    softirq, steal, guest, guest_nice;
    int Total, PrevTotal,totald, idled;
    double CPU_Percentage;
    std::string  cpu;
    std::ifstream fstream(LinuxParser::kProcDirectory + LinuxParser::kStatFilename);
    std::string line;
    if (fstream.is_open()) { 
        if (getline(fstream, line)) {
            std::istringstream string(line);
            string >> cpu >> user >> nice >> system >> idle >> iowait >> irq >>
            softirq >> steal >> guest >> guest_nice;
        }
    }

    // calculate the current Idle and NonIdle cpu utilization
    Idle = idle + iowait;
    NonIdle = user + nice + system + irq + softirq + steal + guest + guest_nice;
    // total cpu utilizatoin 
    PrevTotal = PrevIdle + PrevNonIdle;
    Total = Idle + NonIdle;
    // differentiate: actual value minus the previous one
    totald = Total - PrevTotal;
    idled = Idle - PrevIdle;
    CPU_Percentage = ((double)(totald - idled)/ (double) totald);
    // for the next function call;
    PrevIdle = Idle;
    PrevNonIdle = NonIdle;

    return CPU_Percentage; 
}