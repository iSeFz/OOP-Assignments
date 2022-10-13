#include "BDI_Header.hpp"

// Main class that contain all program features
class BigDecimalInt{
    // Private data hiding
    private:
        string decStr;
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
            if(decStr[0] == '+' || decStr[0] == '-'){
                return (int)decStr.length() - 1;
            }
            return (int)decStr.length();
        }

        // Returns the sign of BigDecimalInt
        int sign(){
            if(decStr[0] == '+'){
                return 0;
            }
            else if(decStr[0] == '-'){
                return 1;
            }
            return 0;
        }

        // Overloading the plus operator to work with BigDecimalInt objects
        BigDecimalInt operator + (BigDecimalInt & anotherDec){
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

        // Overloading the greater than ">" operator to work with BigDecimalInt objects
        bool operator > (BigDecimalInt & anotherDec){
            string firstStr = decStr;
            int firstIsNeg = 0;
            string secondStr = anotherDec.getDecStr();
            int secondIsNeg = anotherDec.sign();
            if(firstStr[0] == '-'){
                firstIsNeg = 1;
            }
            // Checks if first is positive and second is negative (1st > 2nd)
            if(!firstIsNeg && secondIsNeg){
                return true;
            }
            // Checks if first is negative and second is positive (1st < 2nd)
            else if(firstIsNeg && !secondIsNeg){
                return false;
            }
            // If both numbers are positive remove the sign
            else if(!firstIsNeg){
                // Check whether there is a "+" sign or not and if so, remove it.
                if(firstStr[0] == '+'){
                    firstStr.erase(0, 1);
                }
                if(secondStr[0] == '+'){
                    secondStr.erase(0, 1);
                }
            }
            // If both numbers are negative swap the values
            else{
                string temp = firstStr;
                firstStr = secondStr;
                secondStr = temp;
            }
            // Check for size firstly then check for each digit in the number
            if(firstStr.size() > secondStr.size()){
                return true;
            }
            else if(firstStr.size() < secondStr.size()){
                return false;
            }
            for(int i = 0; i < firstStr.size(); ++i){
                if(firstStr[i] > secondStr[i]){
                    return true;
                }
                else if(firstStr[i] < secondStr[i]){
                    return false;
                }
            }
            return false;
        }

        // Overloading the less than "<" operator to work with BigDecimalInt objects
        bool operator < (BigDecimalInt & anotherDec){

            string firstStr = anotherDec.getDecStr();
            int firstIsNeg = anotherDec.sign();
            string secondStr = decStr;
            int secondIsNeg = 0;

            if(secondStr[0] == '-'){
                secondIsNeg = 1;
            }
            // Checks if first is positive and second is negative (1st > 2nd)
            if(!firstIsNeg && secondIsNeg){
                return true;
            }
                // Checks if first is negative and second is positive (1st < 2nd)
            else if(firstIsNeg && !secondIsNeg){
                return false;
            }
                // If both numbers are positive remove the sign
            else if(!firstIsNeg){
                // Check whether there is a "+" sign or not and if so, remove it.
                if(secondStr[0] == '+'){
                    secondStr.erase(0, 1);
                }
                if(firstStr[0] == '+'){
                    firstStr.erase(0, 1);
                }
            }
                // If both numbers are negative swap the values
            else{
                string temp = firstStr;
                firstStr = secondStr;
                secondStr = temp;
            }
            // Check for size firstly then check for each digit in the number
            if(secondStr.size() < firstStr.size()){
                return true;
            }
            else if(secondStr.size() > firstStr.size()){
                return false;
            }
            for(int i = 0; i < secondStr.size(); ++i){
                if(secondStr[i] < firstStr[i]){
                    return true;
                }
                else if(secondStr[i] > firstStr[i]){
                    return false;
                }
            }
            return false;
        }
};