#include <string>
#include <sstream>
#include <iomanip>

#include "format.h"

using std::string;
using namespace std;


string Format::ElapsedTime(long seconds) { 
    // total minutes, hours
    int minutes = seconds/60;
    int hours   = minutes/60;
    
    minutes = minutes % 60;
    seconds = seconds % 60;

    std::ostringstream stream;    
    stream << hours << ":" << setw (2) << setfill ('0') << minutes << ":"  << setw (2) << setfill ('0') << seconds;
    return  stream.str();
}