#include <string>
#include <sstream>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring secondsint 
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
    // total minutes, hours
    int minutes = seconds/60;
    int hours   = minutes/60;
    
    minutes = minutes % 60;
    seconds = seconds % 60;

    std::ostringstream stream;    
    stream << hours << ":" << minutes << ":"  << seconds;
    return  stream.str();
}