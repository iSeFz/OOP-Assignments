#include "BDI_Header.hpp"

using namespace std;

// Main class that contain all program features
class BigDecimalInt{
    // Private data hiding
    private:
        string decStr;
        int decInt;
        void setDecStr(string diffStr){
            decStr = diffStr;
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
        BigDecimalInt(int decInt){
            // Check for the max value for the "int" data type
            if (decInt > 32767 || decInt < -32767){
                cerr << "INVALID INTEGER!!\n";
            }
            else{
                decStr = to_string(decInt);
            }
        }
        // Returns the size of BigDecimalInt
        int size(){
            if(decStr.substr(0, 1) == "+" || decStr.substr(0, 1) == "-"){
                return (int)decStr.length() - 1;
            }
            return (int)decStr.length();
        }
        // Returns the sign of BigDecimalInt
        int sign(){
            if(decStr.substr(0, 1) == "+"){
                return 0;
            }
            else if(decStr.substr(0, 1) == "-"){
                return 1;
            }
            return 0;
        }
        // Overloading the plus operator to work with BigDecimalInt objects
        BigDecimalInt operator+ (BigDecimalInt & anotherDec){
            string finalAns, temp;
            int carry = 0;
            int sizeDifference = decStr.size() - anotherDec.size();
            // Add zeros in the beginning of the smaller sized number
            if(sizeDifference < 0){
                for(int i = sizeDifference; i < 0; i++){
                    decStr = "0" + decStr;
                }
            }
            else if(sizeDifference > 0){
                for(int i = sizeDifference; i > 0; i--){
                    anotherDec.setDecStr("0" + anotherDec.getDecStr());
                }
            }
            // Begin the addition process only if the two numbers are the same size
            for(int i = (int)decStr.length() - 1; i >= 0; i--){
                int sum = ((decStr[i] - '0') + (anotherDec.getDecStr()[i] - '0'));
                if((sum += carry) > 9){
                    sum -= 10;
                    temp = "";
                    temp.push_back(char(sum) + '0');
                    finalAns = temp + finalAns;
                    carry = 1;
                }
                else{
                    temp = "";
                    temp.push_back(char(sum) + '0');
                    finalAns = temp + finalAns;
                    carry = 0;
                }
            }
            if(carry){
                finalAns = "1" + finalAns;
            }
            BigDecimalInt result(finalAns);
            return result;
        }
};