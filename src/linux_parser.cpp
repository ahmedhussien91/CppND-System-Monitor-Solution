#include <dirent.h>
#include <unistd.h>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

#include "linux_parser.h"

using std::stof;
using std::string;
using std::to_string;
using std::vector;

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
long LinuxParser::Jiffies() { return 0; }

// TODO: Read and return the number of active jiffies for a PID
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::ActiveJiffies(int pid[[maybe_unused]]) { return 0; }

// TODO: Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() { return 0; }

// TODO: Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() { return 0; }

// TODO: Read and return CPU utilization
vector<string> LinuxParser::CpuUtilization() { return {}; }

// TODO: Read and return the total number of processes, not needed
int LinuxParser::TotalProcesses() { return 0; }

// TODO: Read and return the number of running processes
int LinuxParser::RunningProcesses() { return 0; }

// TODO: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Command(int pid) { 
    std::ifstream ifile(kProcDirectory + std::to_string(pid) + kStatFilename);
    string line;
    string name, command;
    if(ifile.is_open()) {
      getline(ifile, line);
      std::istringstream lineStream(line);
      lineStream >> name >> command;
    }
    return command; 
  }

// TODO: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Ram(int pid[[maybe_unused]]) { return string(); }

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Uid(int pid[[maybe_unused]]) { return string(); }

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid) {
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
    std::ifstream ifile(kPasswordPath);
    string username,passwd, uid;
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
   return string(); }

// TODO: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::UpTime(int pid[[maybe_unused]]) { return 0; }
