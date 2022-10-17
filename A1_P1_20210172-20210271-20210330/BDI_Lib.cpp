#include "BDI_Header.hpp"
using namespace std;


void BigDecimalInt::setDecStr(string diffStr){
    decStr = diffStr;
}
string BigDecimalInt::getDecStr(){
    return decStr;
}

// Constructor functions to check the format of the entered number
BigDecimalInt::BigDecimalInt(string decString){
    string validNum = "^[+-]?[0-9]+$";
    regex correctNum(validNum);
    if (!regex_match(decString, correctNum)){
        cerr << "INVALID FORMAT!!\n";
    }
    decStr = decString;
}

BigDecimalInt::BigDecimalInt(int decInt){
            // Check for the max value for the "int" data type
            if (decInt > 32767 || decInt < -32767){
                cerr << "INVALID INTEGER!!\n";
            }
            else{
                decStr = to_string(decInt);
            }
        }

// Returns the size of BigDecimalInt
int BigDecimalInt::size(){
    if(decStr[0] == '+' || decStr[0] == '-'){
        return (int)decStr.length() - 1;
    }
    return (int)decStr.length();
}

// Returns the sign of BigDecimalInt
int BigDecimalInt::sign(){
    if(decStr[0] == '+'){
        return 0;
    }
    else if(decStr[0] == '-'){
        return 1;
    }
    return 0;
}

BigDecimalInt BigDecimalInt::inv(BigDecimalInt x){
    string result = x.getDecStr();
if(result[0] == '-'){
    result.erase(0, 1);
}
else if(result[0] == '+'){
    result[0] = '-';
}
else{
    result = "-" + result;
}
    BigDecimalInt inverted(result);
return inverted;
}

// Overloading the plus operator to work with BigDecimalInt objects
BigDecimalInt BigDecimalInt::operator + (BigDecimalInt & anotherDec){
    string finalAns, temp;
    string firstStr = decStr;
    string secondStr = anotherDec.getDecStr();
    int carry = 0;
    // Check for the sign of the number before beginning the addition process
    if(firstStr[0] == '+'){
        firstStr.erase(0, 1);
    }
    if(secondStr[0] == '+'){
        secondStr.erase(0, 1);
    }

    // Check for the minus sign is still uncovered !!

    int sizeDifference = firstStr.size() - secondStr.size();
    // Add zeros in the beginning of the smaller sized number
    if(sizeDifference < 0){
        for(int i = sizeDifference; i < 0; i++){
            firstStr = "0" + firstStr;
        }
    }
    else if(sizeDifference > 0){
        for(int i = sizeDifference; i > 0; i--){
            secondStr = "0" + secondStr;
        }
    }
    // Begin the addition process only if the two numbers are the same size
    for(int i = (int)firstStr.length() - 1; i >= 0; i--){
        int sum = ((firstStr[i] - '0') + (secondStr[i] - '0'));
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

// Overloading the minus operator to work with BigDecimalInt objects
BigDecimalInt BigDecimalInt::operator- (BigDecimalInt & anotherDec){
    int inverse = 0;
    string result, temp;
    int sum = 0;
    int isCarry = 0;
    string firstStr = decStr;
    int firstIsNeg = 0;
    string secondStr = anotherDec.getDecStr();
    int secondIsNeg = anotherDec.sign();


    if(firstStr[0] == '-'){
        firstIsNeg = 1;
    }
    if(firstStr[0] == '-' || firstStr[0] == '+'){
        firstStr.erase(0, 1);
    }
    if(secondStr[0] == '-' || secondStr[0] == '+'){
        secondStr.erase(0, 1);
    }
    if (firstIsNeg && !secondIsNeg){
        return (inv(BigDecimalInt(firstStr) + anotherDec));
    }
    else if(!firstIsNeg && secondIsNeg){
        //TODO: needs fixing ->   + operator is trolling
        anotherDec.setDecStr(secondStr);
        return (BigDecimalInt(firstStr) + anotherDec);
    }
    else if(!firstIsNeg && !secondIsNeg){
        if(BigDecimalInt(firstStr) < anotherDec) {
            string temp = secondStr;
            secondStr = firstStr;
            firstStr = temp;
            inverse = 1;
        }
    }
    else{
        if(BigDecimalInt(firstStr) < anotherDec){
            string temp = secondStr;
            secondStr = firstStr;
            firstStr = temp;
        }
        else {
            inverse = 1;
        }
    }

    int sizeDifference = firstStr.size() - secondStr.size();
    // Add zeros in the beginning of the smaller sized number
    if(sizeDifference < 0){
        for(int i = sizeDifference; i < 0; i++){
            firstStr = "0" + firstStr;
        }
    }
    else if(sizeDifference > 0){
        for(int i = sizeDifference; i > 0; i--){
            secondStr = "0" + secondStr;
        }
    }
    for(int i = firstStr.size() - 1; i >= 0; i--){
        if(isCarry){
            firstStr[i] = ((firstStr[i] - '0') - 1) + '0';
            isCarry = 0;
        }
        if(firstStr[i] < secondStr[i]){
            sum = (firstStr[i] - '0') - (secondStr[i] - '0') + 10;
            isCarry = 1;
        }
        else{
            sum = (firstStr[i] - '0') - (secondStr[i] - '0');
        }
        temp = "";
        temp.push_back(char(sum) + '0');
        result = temp + result;
    }
    while(result[0] == '0'){
        result.erase(0, 1);
    }
    BigDecimalInt final(result);
    if(inverse){
        final = inv(final);
    }
    return final;
}

// Overloading the greater than ">" operator to work with BigDecimalInt objects
bool BigDecimalInt::operator > (BigDecimalInt & anotherDec){
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
bool BigDecimalInt::operator < (BigDecimalInt & anotherDec){

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

// Overload the equality "==" operator to check if the two numbers are equal
bool BigDecimalInt::operator == (BigDecimalInt anotherDec){
    string leftStr = anotherDec.getDecStr();
    string rightStr = decStr;
    if(leftStr[0] == '+'){
        leftStr.erase(0, 1);
    }
    if(rightStr[0] == '+'){
        rightStr.erase(0, 1);
    }
    if(leftStr == rightStr){
        return true;
    }
    return false;
}

// Overload the equal "=" operator to deal with objects
BigDecimalInt BigDecimalInt::operator = (BigDecimalInt anotherDec){
    decStr = anotherDec.getDecStr();
    // Return the left value assuming num1 = num2, it returns "num1"
    return *this;
}
        
// Overload the exertion operator "<<" to print objects
ostream & operator << (ostream & out, BigDecimalInt b){
    // Check if the first character is a "+" sign & if so, erase it
    if(b.getDecStr()[0] == '+'){
        b.decStr.erase(0, 1);
    }
    out << b.decStr;
    return out;
}
