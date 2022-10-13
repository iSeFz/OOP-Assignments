#include "BDI_Header.hpp"

using namespace std;

// Main class that contain all program features
class BigDecimalInt{
    // Private data hiding
    private:
        string decStr;
        int decInt;
        void setDecStr(string decStr_){
            decStr = decStr_;
        }
        string getDecStr(){
            return decStr;
        }
    // Public functions body
    public:
        // Constructor functions to check the format of the entered number
        BigDecimalInt(string decString){
            string validNum = "^[+-]?[0-9]+$";
            regex correctNum(validNum);
            if (!regex_match(decString, correctNum)){
                cerr << "INVALID FORMAT!!\n";
            }
            decStr = decString;
        }
        BigDecimalInt(int decInt) {
            // Check for the max value for the "int" data type
            if (decInt > 32767 || decInt < -32767) {
                cerr << "INVALID INTEGER!!\n";
            }
            else {
                decStr = to_string(decInt);
            }
        }
};