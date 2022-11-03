#include "BigRealClass.hpp"

// Check if the input is valid or not
bool BigReal ::isValidInput(string bigStr)
{
    return (regex_match(bigStr, regex("^[+-]?[0-9]+[.]?[0-9]*$")));
}

// Getter function to get number carried by object modifiedReal
BigDecimalInt &BigReal::getModifiedReal()
{
    return modifiedReal;
}

// Default constructor function that accept double as parameter
BigReal ::BigReal(double real)
{
    string doubleStr = to_string(real);
    if (!isValidInput(doubleStr))
    {
        cout << "INVALID NUMBER FORMAT!!\n";
    }
    // Pass the double value after casting it to string
    // To remove the decimal point and assign its value to the modifiedReal
    removeDecimalPoint(doubleStr);
}

// Overload the constructor function to accept string as parameter
BigReal ::BigReal(string real)
{
    if (!isValidInput(real))
    {
        cout << "INVALID NUMBER FORMAT!!\n";
    }
    // Pass the string to remove the decimal point
    // And assign its value to the modifiedReal
    removeDecimalPoint(real);
}

// Overload the constructor function to accept
// BigDecimalInt objects as a parameter
BigReal ::BigReal(BigDecimalInt bigInteger)
{
    if (!isValidInput(bigInteger.getnum()))
    {
        cout << "INVALID NUMBER FORMAT!!\n";
    }
    // Pass the string of BigDecimalInt object to assign its value
    // To the modifiedReal after removing the decimal point
    string bigStr = bigInteger.getnum();
    removeDecimalPoint(bigStr);
}

// Copy constructor to copy objects into each other
BigReal ::BigReal(const BigReal &other)
{
    // Assign values of attributes of current object
    // By values of attributes of the passed object
    this->modifiedReal = other.modifiedReal;
    this->pointPosition = other.pointPosition;
}

// Move constructor to move object into another object
BigReal ::BigReal(BigReal &&other)
{
    // Assign values of attributes of current object
    // By values of attributes of the passed object
    this->modifiedReal = other.modifiedReal;
    this->pointPosition = other.pointPosition;
}

// Overload the assignment operator to assign values to modifiedReal
BigReal &BigReal ::operator=(BigReal &other)
{
    // Check if the object is different from current object
    // To avoid unnecessary copying
    if (this != &other)
    {
        // Assign values of attributes of current object
        // By values of attributes of the passed object
        this->modifiedReal = other.modifiedReal;
        this->pointPosition = other.pointPosition;
    }
    // Return the updated verison of the object
    return *this;
}

// Move Assignment to move object into another object
BigReal &BigReal ::operator=(BigReal &&other)
{
    // Check if the object is different from current object
    // To avoid unnecessary moving
    if (this != &other)
    {
        // Assign values of attributes of current object
        // By values of attributes of the passed object
        this->modifiedReal = other.modifiedReal;
        this->pointPosition = other.pointPosition;
    }
    // Return the updated verison of the object
    return *this;
}

// Overload the plus operator to work with BigReal objects
BigReal BigReal ::operator+(BigReal &other)
{
    int newPosition = 0;
    char sign1 {'-'},sign2 {'-'};
    if(modifiedReal.Sign()){
        sign1 = '+';
    }

    if(other.modifiedReal.Sign()){
        sign2 = '+';
    }

    string firstNum = sign1 + modifiedReal.getnum();
    string secondNum = sign2 + other.modifiedReal.getnum();
    
    // Check if the size difference is positive or negative
    int sizeDiff = (secondNum.size() - (other.pointPosition)) - (firstNum.size() - (this->pointPosition));
    if (sizeDiff > 0)
    {
        // If the size difference is positive
        // Add zeros to the end of the number
        for (int i = 0; i < sizeDiff; i++)
        {
            firstNum += "0";

        }
        int pos = other.pointPosition + 1;
        newPosition = (secondNum.size() - pos);
    }
    else
    {
        // If the size difference is negative
        // Add zeros to the end of the number
        for (int i = 0; i < abs(sizeDiff); i++)
        {
            secondNum += "0";
        }
        int pos = this->pointPosition + 1;
        newPosition = (firstNum.size() - pos);
    }
    BigDecimalInt result = BigDecimalInt(firstNum) + BigDecimalInt(secondNum);
    string resultStr = result.getnum();
    while(resultStr.size() < newPosition){
        resultStr = "0" + resultStr;
    }
    if (!result.Sign())
    {
        resultStr = "-" + resultStr;
    }
    resultStr.insert(resultStr.size() - newPosition, ".");
    BigReal final(resultStr);
    return final;
}

// Overload the minus operator to work with BigReal objects
BigReal BigReal ::operator-(BigReal &other)
{
    int newPosition = 0;
    char sign1 {'-'},sign2 {'-'};
    if(modifiedReal.Sign()){
        sign1 = '+';
    }

    if(other.modifiedReal.Sign()){
        sign2 = '+';
    }
    string firstNum = sign1 + modifiedReal.getnum();
    string secondNum = sign2 + other.modifiedReal.getnum();
    // Check if the size difference is positive or negative
    int sizeDiff = (secondNum.size() - (other.pointPosition)) - (firstNum.size() - (this->pointPosition));
    if (sizeDiff > 0)
    {
        // If the size difference is positive
        // Add zeros to the end of the number
        for (int i = 0; i < sizeDiff; i++)
        {
            firstNum += "0";

        }
        int pos = other.pointPosition + 1;
        newPosition = (secondNum.size() - pos);
    }
    else
    {
        // If the size difference is negative
        // Add zeros to the end of the number
        for (int i = 0; i < abs(sizeDiff); i++)
        {
            secondNum += "0";
        }
        int pos = this->pointPosition + 1;
        newPosition = (firstNum.size() - pos);
    }
    BigDecimalInt result = BigDecimalInt(firstNum) - BigDecimalInt(secondNum);
    string resultStr = result.getnum();
    while(resultStr.size() < newPosition){
        resultStr = "0" + resultStr;
    }
    if (!result.Sign())
    {
        resultStr = "-" + resultStr;
    }
    resultStr.insert(resultStr.size() - newPosition, ".");
    BigReal final(resultStr);
    return final;
}

// Overload the smaller than operator
bool BigReal::operator<(BigReal &anotherReal)
{
    // make two objects have same number of digits
    if (modifiedReal.size() > anotherReal.size())
    {
        int numOfZeros = modifiedReal.size() - anotherReal.size();
        char sign = (anotherReal.getModifiedReal().Sign() == 1) ? '+' : '-';
        string modifications = sign + anotherReal.getModifiedReal().getnum() + string(numOfZeros, '0');
        // make number right to < have same number of digits to right one
        BigDecimalInt rightNum(modifications);
        return modifiedReal < rightNum;
    }
    else if (modifiedReal.size() < anotherReal.size())
    {
        int numOfZeros = anotherReal.size() - modifiedReal.size();
        char sign = (modifiedReal.Sign() == 1) ? '+' : '-';
        string modifications = sign + modifiedReal.getnum() + string(numOfZeros, '0');
        // make number left to < have same number of digits to right one
        BigDecimalInt leftNum(modifications);
        return leftNum < anotherReal.getModifiedReal();
    }
    // if the two object have same number of digits compare them
    return modifiedReal < anotherReal.getModifiedReal();
}

// Overload the greater than operator
bool BigReal::operator>(BigReal &anotherReal)
{
    // make two objects have same number of digits
    if (modifiedReal.size() > anotherReal.size())
    {
        int numOfZeros = modifiedReal.size() - anotherReal.size();
        char sign = (anotherReal.getModifiedReal().Sign() == 1) ? '+' : '-';
        string modifications = sign + anotherReal.getModifiedReal().getnum() + string(numOfZeros, '0');
        // make number right to > have same number of digits to right one
        BigDecimalInt rightNum(modifications);
        return modifiedReal > rightNum;
    }
    else if (modifiedReal.size() < anotherReal.size())
    {
        int numOfZeros = anotherReal.size() - modifiedReal.size();
        char sign = (modifiedReal.Sign() == 1) ? '+' : '-';
        string modifications = sign + modifiedReal.getnum() + string(numOfZeros, '0');
        // make number left to > have same number of digits to right one
        BigDecimalInt leftNum(modifications);
        return leftNum > anotherReal.getModifiedReal();
    }
    // if the two object have same number of digits compare them
    return modifiedReal > anotherReal.getModifiedReal();
}

// Overload the equality operator
bool BigReal::operator==(BigReal &anotherReal)
{
    // make two objects have same number of digits
    if (modifiedReal.size() > anotherReal.size())
    {
        int numOfZeros = modifiedReal.size() - anotherReal.size();
        char sign = (anotherReal.getModifiedReal().Sign() == 1) ? '+' : '-';
        string modifications = sign + anotherReal.getModifiedReal().getnum() + string(numOfZeros, '0');
        // make number right to == have same number of digits to right one
        BigDecimalInt rightNum(modifications);
        return modifiedReal == rightNum;
    }
    else if (modifiedReal.size() < anotherReal.size())
    {
        int numOfZeros = anotherReal.size() - modifiedReal.size();
        char sign = (modifiedReal.Sign() == 1) ? '+' : '-';
        string modifications = sign + modifiedReal.getnum() + string(numOfZeros, '0');
        // make number left to == have same number of digits to right one
        BigDecimalInt leftNum(modifications);
        return leftNum == anotherReal.getModifiedReal();
    }
    // if the two object have same number of digits compare them
    return modifiedReal == anotherReal.getModifiedReal();
}

// Overload the exertion operator to print BigReal in console
ostream &operator<<(ostream &out, BigReal &real)
{
    // if number is negative
    if (!real.sign())
        out << '-';
    out << real.returnPoint();
    return out;
}

// Overload the insertion operator to take input from user and initialize BigReal
istream &operator>>(istream &in, BigReal &real)
{
    string realStr;
    in >> realStr;
    real.removeDecimalPoint(realStr);
    return in;
}

// Return the size of the BigReal
int BigReal::size()
{
    return modifiedReal.size();
}

// Return the sign of the BigReal
int BigReal::sign()
{
    return modifiedReal.Sign();
}

// Remove decimal point and store its position
void BigReal::removeDecimalPoint(string &realStr)
{
    pointPosition = realStr.find('.');
    string realWithoutPoint;
    // Remove the point from the the realStr
    realWithoutPoint = realStr.erase(pointPosition, 1);
    // If the entered string has a sign at the beginning, adjust the pointPosition
    // to overcome the increase in size due to the sign character
    if (realStr[0] == '+' || realStr[0] == '-')
    {
        pointPosition--;
    }
    // Assign the value of the modifiedReal with
    // the removed decimal point string as a BigDecimalInt object
    modifiedReal = BigDecimalInt(realWithoutPoint);
}

// Return the decimal point to its original position
string BigReal::returnPoint()
{
    string realNumber = modifiedReal.getnum();
    realNumber.insert(pointPosition, ".");
    return realNumber;
}
