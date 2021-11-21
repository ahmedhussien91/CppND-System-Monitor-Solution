#ifndef PROCESS_H
#define PROCESS_H

#include <string>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  int Pid();                               // TODO: See src/process.cpp
  void Pid(int pid);
  std::string User();                      // TODO: See src/process.cpp
  std::string Command();                   // TODO: See src/process.cpp
  float CpuUtilization();                  // TODO: See src/process.cpp
  std::string Ram();                       // TODO: See src/process.cpp
  long int UpTime();                       // TODO: See src/process.cpp
  bool operator<(Process const& a) const;  // TODO: See src/process.cpp
  //bool Process::operator==(const Process &a);
  friend bool operator==(Process &a,  Process &b)  { 
    auto is_equal = a.Pid() == b.Pid()?  true : false;
    return is_equal;
  }
  friend bool operator==(Process &a,  const int &b)  { 
    auto is_equal = a.Pid() == b?  true : false;
    return is_equal;
  }
  // TODO: Declare any necessary private members
 private:
    int pid =0;
    std::string command = "";
    std::string user = "";
};

#endif