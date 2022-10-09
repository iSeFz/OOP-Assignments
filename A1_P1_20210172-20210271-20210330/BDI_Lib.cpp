#include "BDI_Header.hpp"

using namespace std;

// Main class that contain all program features
class BigDecimalInt{
    // Private data hiding
    private:
        string decStr;
        int decInt;
    // Public functions body
    public:
        // Constructor functions to check the format of the entered number
        BigDecimalInt(string decStr){
            string validNum = "^[+-]?[0-9]+$";
            regex correctNum(validNum);
            if (!regex_match(decStr, correctNum)){
                cerr << "INVALID FORMAT!!\n";
            }
        }
        BigDecimalInt(int decInt){
            // Check for the max value for the "int" data type
            if(decInt > 32767 || decInt < -32767){
                cerr << "INVALID INTEGER!!\n";
            }
        }
};