#ifndef INC_20210330_LABEL_GENERATOR_HEADER_H
#define INC_20210330_LABEL_GENERATOR_HEADER_H
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
// LabelGenerator Class (Base class)
class LabelGenerator
{
protected:
    string pattern;
    int initIndex;
public:
    // Default constructor
    LabelGenerator();
    // Constructor
    LabelGenerator(const string & pattern, int initIndex);
    // nextLabel function to print next label make it virtual to override it in derived class
    virtual string nextLabel();

};
// FileLabelGenerator (Derived class)
class FileLabelGenerator:public LabelGenerator{
private:
    string fileName;
    int lineNum;
public:
    // Default Constructor
    FileLabelGenerator();
    // Constructor
    FileLabelGenerator(const string & pattern, int initIndex, const string & fileName_);
    // nextLabel function to print next label override from base class
    string nextLabel()override;
};







#endif //INC_20210330_LABEL_GENERATOR_HEADER_H