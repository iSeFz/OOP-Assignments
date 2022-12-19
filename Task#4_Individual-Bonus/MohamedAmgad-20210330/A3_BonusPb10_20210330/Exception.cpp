#include "Exception.h"
// Implementation of what function to MonthError class
const char* MonthError::what() {
    return "Error in Month format";
}
// Implementation of what function to DayError class
const char* DayError::what() {
    return "Error in Day format";
}