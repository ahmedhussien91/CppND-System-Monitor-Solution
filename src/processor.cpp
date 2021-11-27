#include "processor.h"
#include "linux_parser.h"
#include <sstream>
#include <fstream>
#include <string>

//  Return the aggregate CPU utilization
float Processor::Utilization() { 
    return LinuxParser::CpuUtilization();
}