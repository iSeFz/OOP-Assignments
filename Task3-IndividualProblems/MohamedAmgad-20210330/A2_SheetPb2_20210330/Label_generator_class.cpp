#include "Label_generator_header.h"

LabelGenerator::LabelGenerator(){
    pattern = "";
    initIndex = 0;
}
LabelGenerator::LabelGenerator(const string & pattern, int initIndex):
        pattern(pattern), initIndex(initIndex){};

string LabelGenerator::nextLabel() {
    string label = pattern + to_string(initIndex++);
    return label;
}

FileLabelGenerator::FileLabelGenerator() : LabelGenerator(){
    fileName = "";
}

FileLabelGenerator::FileLabelGenerator(const string &pattern, int initIndex,const string &fileName_):LabelGenerator(pattern, initIndex){
    fileName = fileName_;
    lineNum = 1;
}

string FileLabelGenerator::nextLabel() {
    ifstream file(fileName);
    if(file.fail()){
        cout << "Can't open file please check file name\n";
        return "";
    }
    string line;
    stringstream ss;
    for(int i = 0;i<lineNum;i++){
        getline(file, line);
    }
    lineNum++;
    ss << pattern << " " << initIndex++ << " " << line;
    return ss.str();
}