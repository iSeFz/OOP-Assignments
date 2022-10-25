#include "BDI_Header.hpp"

// Setter function to set the value of data member
void BigDecimalInt::setDecStr(string diffStr){
    decStr = diffStr;
}

// Getter function to access the private data member
string BigDecimalInt::getDecStr(){
    return decStr;
}

// Function to invert sign of BigDecimalInt
BigDecimalInt BigDecimalInt::invertSign(BigDecimalInt num){
    string result = num.getDecStr();
    // If the number is negative, erase the sign to make it positve
    if(result[0] == '-'){
        result.erase(0, 1);
    }
    // If the number is positive, replace the sign to make it negative
    else if(result[0] == '+'){
        result[0] = '-';
    }
    // If there is no sign at all then it means that
    // the number is positive, so add a negative sign
    else{
        result = "-" + result;
    }
    // Return the inverted sign BigDecimalInt
    BigDecimalInt inverted(result);
    return inverted;
}

// Constructor function to check for the format of the entered number
BigDecimalInt::BigDecimalInt(string decString){
    // Accepts only numbers and one sign
    if (!regex_match(decString, regex("^[+-]?[0-9]+$"))){
        cerr << "INVALID FORMAT!!\n";
    }
    // If the format is valid, initialize data member
    decStr = decString;
}

// Overloading the constructor function to accept input as integer
BigDecimalInt::BigDecimalInt(int decInt){
    // Check for the max/min value for the "int" data type
    if (decInt > 32767 || decInt < -32767){
        cerr << "INVALID INTEGER!!\n";
    }
    // If the input is valid, initialize data member as string
    else{
        decStr = to_string(decInt);
    }
}

// Function to return size of BigDecimalInt
int BigDecimalInt::size(){
    // If there is a sign at the begginning of the number, ignore it
    if(decStr[0] == '+' || decStr[0] == '-'){
        return (int)decStr.length() - 1;
    }
    // If not return the length of the decimal string directly
    return (int)decStr.length();
}

// Function to return sign of BigDecimalInt
int BigDecimalInt::sign(){
    // If the sign is positive it returns 0
    if(decStr[0] == '+'){
        return 0;
    }
    // If the sign is negative it returns 1
    else if(decStr[0] == '-'){
        return 1;
    }
    // If there is no sign at all then it is positive, so returns 0
    return 0;
}

// Overloading the plus operator to work with BigDecimalInt objects
BigDecimalInt BigDecimalInt::operator + (BigDecimalInt anotherDec){
    // Variables necessary for the addition process
    string finalAns, temp;
    int carry = 0;
    // Taking a copy of the two numbers to work with
    string firstStr = decStr;
    int firstIsNeg = 0;
    string secondStr = anotherDec.getDecStr();
    int secondIsNeg = anotherDec.sign();
    // Check for the sign of the number before beginning the addition process
    // If any of the two numbers is positive, erase the sign
    if(firstStr[0] == '+'){
        firstStr.erase(0, 1);
    }
    if(secondStr[0] == '+'){
        secondStr.erase(0, 1);
    }
    // If any of the two numbers is negative, assign the value to the variable
    if(firstStr[0] == '-'){
        firstIsNeg = 1;
    }
    if(secondStr[0] == '-'){
        secondIsNeg = 1;
    }
    // If one of the two numbers is negative, erase the negative sign
    // Then call the subtraction function
    if(firstIsNeg && !secondIsNeg){
        firstStr.erase(0, 1);
        BigDecimalInt firstBig(firstStr);
        BigDecimalInt secondBig(secondStr);
        return(secondBig - firstBig);
    }
    if(!firstIsNeg && secondIsNeg){
        secondStr.erase(0, 1);
        BigDecimalInt firstBig(firstStr);
        BigDecimalInt secondBig(secondStr);
        return(firstBig - secondBig);
    }
    // If the two numbers are negative
    if(firstIsNeg && secondIsNeg){
        // Erase the negative sign
        firstStr.erase(0, 1);
        secondStr.erase(0, 1);
        BigDecimalInt firstBig(firstStr);
        BigDecimalInt secondBig(secondStr);
        // Add them normally then invert the sign of the final answer
        return(invertSign(firstBig + secondBig));
    }
    // Get the difference in the size of the two numbers
    int sizeDifference = firstStr.size() - secondStr.size();
    // Add zeros in the beginning of the smaller sized number
    // To make the two numbers have the same size
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
    // Loop over the numbers from the end to the beginning
    for(int i = (int)firstStr.length() - 1; i >= 0; i--){
        // Add each two digits after converting them into integers
        int sum = ((firstStr[i] - '0') + (secondStr[i] - '0'));
        // Add the carry to the sum and check if the sum is greater than 9
        if((sum += carry) > 9){
            // If so, subtract 10 from the sum and assign 1 to the carry
            sum -= 10;
            carry = 1;
        }
        // If the sum is less than 9, then there is no carry
        else{
            carry = 0;
        }
        // Concatenate the sum to the temporary string
        temp = "";
        temp.push_back(char(sum) + '0');
        // Concatenate the temporary string to the final answer
        finalAns = temp + finalAns;
    }
    // If there is a carry at the end, concatenate it to the final answer
    if(carry){
        finalAns = "1" + finalAns;
    }
    // Return the final answer as a BigDecimalInt object
    BigDecimalInt result(finalAns);
    return result;
}

// Overloading the minus operator to work with BigDecimalInt objects
BigDecimalInt BigDecimalInt::operator - (BigDecimalInt anotherDec){
    // Variables necessary for the subtraction process
    int inverse = 0;
    string result, temp;
    int difference = 0;
    int isCarry = 0;
    // Taking a copy of the two numbers to work with
    string firstStr = decStr;
    int firstIsNeg = 0;
    string secondStr = anotherDec.getDecStr();
    int secondIsNeg = anotherDec.sign();
    // If the first number is negative, assign the value to the variable
    if(firstStr[0] == '-'){
        firstIsNeg = 1;
    }
    // Erase the sign of the two numbers
    if(firstStr[0] == '-' || firstStr[0] == '+'){
        firstStr.erase(0, 1);
    }
    if(secondStr[0] == '-' || secondStr[0] == '+'){
        secondStr.erase(0, 1);
    }
    // If the first number is negative and the second is postive
    if (firstIsNeg && !secondIsNeg){
        // Add the numbers normally then inverse the sign of the final answer
        return (invertSign(BigDecimalInt(firstStr) + anotherDec));
    }
    // If the first number is positive and the second is negative
    else if(!firstIsNeg && secondIsNeg){
        // Update the value of the second number
        // before passing it to the addition function
        anotherDec.setDecStr(secondStr);
        // Call the addition function
        return (BigDecimalInt(firstStr) + anotherDec);
    }
    // If the two numbers are positive
    else if(!firstIsNeg && !secondIsNeg){
        // Check for the greater number
        if(BigDecimalInt(firstStr) < anotherDec){
            // Swap the two numbers
            string temp = secondStr;
            secondStr = firstStr;
            firstStr = temp;
            // Update the value of inverse
            inverse = 1;
        }
    }
    // If the two numbers are negative
    else{
        // Check for the greater number
        if(BigDecimalInt(firstStr) < anotherDec){
            // Swap the two numbers
            string temp = secondStr;
            secondStr = firstStr;
            firstStr = temp;
        }
        else{
            inverse = 1;
        }
    }
    // Get the difference in the size of the two numbers
    int sizeDifference = firstStr.size() - secondStr.size();
    // Add zeros in the beginning of the smaller sized number
    // To make the two numbers have the same size
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
    // Loop over the numbers from the end to the beginning
    for(int i = firstStr.size() - 1; i >= 0; i--){
        // If there is a carry from before, subtract 1 from the current digit
        if(isCarry){
            firstStr[i] = ((firstStr[i] - '0') - 1) + '0';
            // Reset the value of the carry
            isCarry = 0;
        }
        // If the second digit is greater than the first
        if(firstStr[i] < secondStr[i]){
            // Add 10 to the difference and set the carry to 1
            difference = (firstStr[i] - '0') - (secondStr[i] - '0') + 10;
            isCarry = 1;
        }
        // Otherwise normally subtract each two digits
        else{
            difference = (firstStr[i] - '0') - (secondStr[i] - '0');
        }
        // Concatenate the difference to the temporary string
        temp = "";
        temp.push_back(char(difference) + '0');
        // Concatenate the temporary string to the result
        result = temp + result;
    }
    // Erase the leading zeros from the result if any
    while(result[0] == '0'){
        result.erase(0, 1);
    }
    // Return the final answer as a BigDecimalInt object
    BigDecimalInt final(result);
    // If the inverse is 1, then invert the sign of the final answer
    if(inverse){
        final = invertSign(final);
    }
    return final;
}

// Overloading the greater than ">" operator to work with BigDecimalInt objects
bool BigDecimalInt::operator > (BigDecimalInt anotherDec){
    string firstStr = decStr;
    int firstIsNeg = 0;
    string secondStr = anotherDec.getDecStr();
    int secondIsNeg = anotherDec.sign();

    // Check if the first number is negative
    if(firstStr[0] == '-'){
        firstIsNeg = 1;
    }
    // Check if first is positive and second is negative (1st > 2nd)
    if(!firstIsNeg && secondIsNeg){
        return true;
    }
    // Check if first is negative and second is positive (1st < 2nd)
    else if(firstIsNeg && !secondIsNeg){
        return false;
    }
    // If both numbers are positive, remove the sign
    else if(!firstIsNeg){
        // Check whether there is a "+" sign or not and if so, remove it.
        if(firstStr[0] == '+'){
            firstStr.erase(0, 1);
        }
        if(secondStr[0] == '+'){
            secondStr.erase(0, 1);
        }
    }
    // If both numbers are negative, swap the values
    else{
        string temp = firstStr;
        firstStr = secondStr;
        secondStr = temp;
    }
    // Compare the size of numbers to decide which is bigger
    if(firstStr.size() > secondStr.size()){
        return true;
    }
    else if(firstStr.size() < secondStr.size()){
        return false;
    }
    // Compare each digit of the two numbers
    // As they are now the same size
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
bool BigDecimalInt::operator < (BigDecimalInt anotherDec){
    string firstStr = anotherDec.getDecStr();
    int firstIsNeg = anotherDec.sign();
    string secondStr = decStr;
    int secondIsNeg = 0;

    // Check if the second number (decStr) is negative
    if(secondStr[0] == '-'){
        secondIsNeg = 1;
    }
    // Check if first is positive and second is negative (1st > 2nd)
    if(!firstIsNeg && secondIsNeg){
        return true;
    }
    // Check if first is negative and second is positive (1st < 2nd)
    else if(firstIsNeg && !secondIsNeg){
        return false;
    }
    // If both numbers are positive, remove the sign
    else if(!firstIsNeg){
        // Check whether there is a "+" sign or not and if so, remove it.
        if(secondStr[0] == '+'){
            secondStr.erase(0, 1);
        }
        if(firstStr[0] == '+'){
            firstStr.erase(0, 1);
        }
    }
    // If both numbers are negative, swap the values
    else{
        string temp = firstStr;
        firstStr = secondStr;
        secondStr = temp;
    }
    // Compare the size of numbers to decide which is bigger
    if(secondStr.size() < firstStr.size()){
        return true;
    }
    else if(secondStr.size() > firstStr.size()){
        return false;
    }
    // Compare each digit of the two numbers
    // As they are now the same size
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

// Overloading the equality "==" operator to check if the two numbers are equal
bool BigDecimalInt::operator == (BigDecimalInt anotherDec){
    string leftStr = anotherDec.getDecStr();
    string rightStr = decStr;
    // If the first character of the string is a "+" sign, erase it
    if(leftStr[0] == '+'){
        leftStr.erase(0, 1);
    }
    if(rightStr[0] == '+'){
        rightStr.erase(0, 1);
    }
    // After removing the signs comapre the two strings
    if(leftStr == rightStr){
        return true;
    }
    return false;
}

// Overloading the assignment "=" operator to deal with objects
BigDecimalInt BigDecimalInt::operator = (BigDecimalInt anotherDec){
    decStr = anotherDec.getDecStr();
    // Return the left value assuming num1 = num2, it returns "num1"
    return *this;
}
        
// Overloading the exertion operator "<<" to print objects
ostream & operator << (ostream & out, BigDecimalInt number){
    // Check if the first character is a "+" sign & if so, erase it
    if(number.getDecStr()[0] == '+'){
        number.decStr.erase(0, 1);
    }
    out << number.decStr;
    return out;
}
