#include <dirent.h>
#include <unistd.h>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iomanip>

#include "linux_parser.h"

using std::stof;
using std::string;
using std::to_string;
using std::vector;

//loacl functions
long LinuxParser::getHz() { 
  return sysconf(_SC_CLK_TCK);
}


// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;
}

// DONE: An example of how to read data from the filesystem
string LinuxParser::Kernel() {
  string os, kernel, version;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >> version >> kernel;
  }
  return kernel;
}

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

// TODO: Read and return the system memory utilization
float LinuxParser::MemoryUtilization() {
  string line;
  string title; 
  int MemTotal, MemFree;
  
  std::ifstream fstream(kProcDirectory + kMeminfoFilename);
  if(fstream.is_open()) { 
    while(getline(fstream, line)) {
      int value;
      std::replace(line.begin(), line.end(), ':', ' ');
      std::istringstream linestream(line);
      while(linestream >> title >> value) {
        if (title == "MemTotal") {
          MemTotal = value;
        } else if (title == "MemFree"){ 
          MemFree = value;
        }
      }
    }
  }
  return (((float) (MemTotal - MemFree))/((float) MemTotal));
}

// TODO: Read and return the system uptime
long LinuxParser::UpTime() { 
  string line;
  string title; 
  long totalTime, idleTime;
  
  std::ifstream fstream(kProcDirectory + kUptimeFilename);
  if(fstream.is_open()) {
    std::getline(fstream, line);
    std::istringstream linestream(line);
    linestream >> totalTime >> idleTime;
  } else {
    throw std::invalid_argument("file is not open ");
  }
  return totalTime;
}

// TODO: Read and return the number of jiffies for the system
long LinuxParser::Jiffies() { 
  int Idle, NonIdle;
  int user, nice, system, idle, iowait, irq, 
  softirq, steal, guest, guest_nice;
  int Total;
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
  Total = Idle + NonIdle;
  return Total;
}

// TODO: Read and return the number of active jiffies for a PID
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::ActiveJiffies(int pid, long * starttime) { 
  std::ifstream ifile(kProcDirectory + std::to_string(pid) + kStatFilename);
  string line;
  string value, utime, stime, starttime_s;
  if(ifile.is_open()) {
    int count =1;
    getline(ifile, line); 
    std::istringstream lineStream(line);
    while(lineStream >> value) {
      if (count == 14) {
        utime = value;
      } else if (count == 15) { 
        stime = value;
      } else if (count == 22 ) {
        starttime_s = value;
        *starttime = stoi(starttime_s);
        break;
      }
      count++;
    }
  }
  return (std::stoi(utime)+std::stoi(stime));
}

// TODO: Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() { return 0; }

// TODO: Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() { return 0; }

// TODO: Read and return CPU utilization
double LinuxParser::CpuUtilization() { 
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
  idle = Idle;

  return CPU_Percentage; 
  // int processruntime, processstarttime;
  // processruntime = ActiveJiffies(pid, &processstarttime);
  // int seconds = UpTime() - processstarttime;
  // double cpu_usage = ((double)processruntime)/(double)seconds;

  // return 0;
}

// TODO: Read and return the total number of processes, not needed
int LinuxParser::TotalProcesses() { return 0; }

// TODO: Read and return the number of running processes
int LinuxParser::RunningProcesses() {
  std::ifstream ifile(kProcDirectory + kStatFilename);
  string line;
  string title, value, runningProcess;
  if(ifile.is_open()) {
    while (getline(ifile, line)) {
      std::istringstream lineStream(line);
      lineStream >> title >> value;
      if (title == "procs_running") {
        runningProcess = value;
        break;
      }
    }
  }
  if (runningProcess != "") { 
    return stoi(runningProcess);
  } else {
    return 0;
  }
}

// TODO: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Command(int pid) { 
    std::ifstream ifile(kProcDirectory + std::to_string(pid) + kCmdlineFilename);
    string command;
    if(ifile.is_open()) {
      getline(ifile, command);
    }
    return command; 
}

// TODO: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Ram(int pid) {
  std::ifstream ifile(kProcDirectory + std::to_string(pid) + kStatusFilename);
  string line;
  string title, value, Ram;
  if(ifile.is_open()) {
    while (getline(ifile, line)) {
      std::istringstream lineStream(line);
      lineStream >> title >> value;
      if (title == "VmRSS:") {
        Ram = value;
        break;
      }
    }
  }
  // change to MB instead of kb
  double Ram_d =0.0;
  if (Ram != "") {  
    Ram_d = std::stod(Ram);
    Ram_d = Ram_d/1000;
  }
  std::ostringstream Ram_ds;
  Ram_ds << std::setprecision(7) << Ram_d;  

  return Ram_ds.str(); 
}

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Uid(int pid) {
  std::ifstream ifile_s(kProcDirectory + std::to_string(pid) + kStatusFilename);
  string line;
  string name, uid_s;
  if(ifile_s.is_open()) {
    while (getline(ifile_s, line)) {
      std::istringstream lineStream(line);
      lineStream >> name >> uid_s;
      if (name == "Uid:"){
        break;
      }
    }
  }
  return uid_s; 
}

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid) {
  auto uid_s = Uid(pid);

  std::ifstream ifile(kPasswordPath);
  string line, username,passwd, uid;
  if(ifile.is_open()) {
    while (getline(ifile, line)) {
      std::replace(line.begin(), line.end(), ':', ' ');
      std::istringstream lineStream(line);
      lineStream >> username >> passwd >> uid;
      if (uid == uid_s){
        return username;
      }
    }
  } 
 return string();
 }

// TODO: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::UpTime(int pid) {
  long processstarttime=0;
  ActiveJiffies(pid, &processstarttime);
  long total_time = UpTime(); // in seconds
  if(total_time - processstarttime < 0){
    //throw std::runtime_error("uptime is negative");
  }
  return total_time - processstarttime/100;
}
