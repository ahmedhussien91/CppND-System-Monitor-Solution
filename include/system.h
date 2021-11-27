#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <vector>

#include "process.h"
#include "processor.h"

class System {
 public:
  Processor& Cpu();                  
  std::vector<Process>& Processes();  
  float MemoryUtilization();          
  long UpTime();                      
  int TotalProcesses();               
  int RunningProcesses();             
  std::string Kernel();               
  std::string OperatingSystem();      

 private:
  std::string kernel_ = "";
  std::string os_ = "";
  Processor cpu_ = {};
  std::vector<Process> processes_ = {};
  std::vector<int> pids = {};

  void add_remove_processes();
};

#endif