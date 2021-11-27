#ifndef PROCESS_H
#define PROCESS_H

#include <string>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  int Pid();                               
  void Pid(int pid);
  std::string User();                      
  std::string Command();                   
  float CpuUtilization();                  
  std::string Ram();                       
  long int UpTime();                       
  bool operator<(Process const& a) const;  
  
  friend bool operator==(Process &a,  Process &b)  { 
    auto is_equal = a.Pid() == b.Pid()?  true : false;
    return is_equal;
  }
  friend bool operator==(Process &a,  const int &b)  { 
    auto is_equal = a.Pid() == b?  true : false;
    return is_equal;
  }

 private:
    int pid =0;
    std::string command = "";
    std::string user = "";
    double cpu_util =0;
    int ram =0;
};

#endif