#ifndef A3_BONUSPB10_20210330_EXCEPTION_H
#define A3_BONUSPB10_20210330_EXCEPTION_H
#include <iostream>
#include <exception>
using namespace std;
// class for month error handling
class MonthError:public exception{
public:
    const char* what();
};

// class for day error handling
class DayError:public exception{
public:
    const char* what();
};
#endif //A3_BONUSPB10_20210330_EXCEPTION_H
