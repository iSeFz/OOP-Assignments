#include "BigRealClass.hpp"

// Check if the input is valid or not
bool BigReal ::isValidInput(string longStr)
{
    return (regex_match(longStr, regex("^[+-]?[0-9]+[.]?[0-9]*$")));
}

// Getter function to get number carried by object modifiedReal
BigDecimalInt &BigReal::getModifiedReal()
{
    return modifiedReal;
}

// Setter function to set the number carried by object modifiedReal
void BigReal ::setModifiedReal(string realStr)
{
    // Check for valid input format of BigReal string
    if (!isValidInput(realStr))
    {
        cerr << "INVALID NUMBER FORMAT!!\n";
        return;
    }
    // Check if there is a sign at the beginning of number
    // If so, start scanning after the sign character
    int i = 0;
    if (realStr[0] == '+' || realStr[0] == '-')
    {
        i = 1;
    }

    // Remove leading zeros on the left of number
    for (i; i < realStr.length(); ++i)
    {
        if (realStr[i] == '0')
        {
            realStr.erase(i, 1);
            // Decrement "i" to overcome the decrease in size of string
            i--;
        }
        else
        {
            break;
        }
    }

    // Remove trailing zeros on the right of number
    for (int j = realStr.length() - 1; j > 0; --j)
    {
        if (realStr[j] == '0')
        {
            realStr.erase(j, 1);
        }
        else
        {
            break;
        }
    }
    
    // Check if there is a decimal point in the string or not
    if (realStr.find('.') < realStr.length())
    {
        // Get point position from the right
        pointPosition = (realStr.length()) - (realStr.find('.')) - 1;
        // Remove the point from the string after storing its position
        realStr.erase((realStr.length() - pointPosition - 1), 1);
    }
    // Assign the value of the modifiedReal with
    // the removed decimal point string as a BigDecimalInt object
    modifiedReal = BigDecimalInt(realStr);
}

// Default constructor function that accept double as parameter
BigReal ::BigReal(double realDouble)
{
    // If the default constructor is called assign modifiedReal with "0"
    if (realDouble == 0.0)
    {
        modifiedReal = BigDecimalInt("0");
        return;
    }
    // Convert the double number into string
    string doubleStr;
    doubleStr = to_string(realDouble);
    // Call the setter function to set the value of modifiedReal by the passed number
    setModifiedReal(doubleStr);
}

// Overload the constructor function to accept string as parameter
BigReal ::BigReal(string realStr)
{
    // Call the setter function to set the value of modifiedReal by the passed string
    setModifiedReal(realStr);
}

// Overload the constructor function to accept BigDecimalInt objects as a parameter
BigReal ::BigReal(BigDecimalInt bigInteger)
{
    // Get the number inside the BigDecimalInt object
    string bigStr = bigInteger.getnum();
    // Call the setter function to set the value of modifiedReal by the passed string
    setModifiedReal(bigStr);
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
    // Check for the sign of numbers
    char sign1 = this->sign() ? '+' : '-';
    char sign2 = other.sign() ? '+' : '-';

    // Take copy of numbers to make operations on them
    string firstNum = sign1 + this->getModifiedReal().getnum();
    string secondNum = sign2 + other.getModifiedReal().getnum();

    // Check if the size difference is positive or negative
    int sizeDiff = (other.pointPosition) - (this->pointPosition);
    if (sizeDiff > 0)
    {
        // If the size difference is positive
        // Add zeros to the end of the first number (smaller in size)
        for (int i = 0; i < sizeDiff; i++)
        {
            firstNum += "0";
        }
        newPosition = other.pointPosition;
    }
    else
    {
        // If the size difference is negative
        // Add zeros to the end of the second number (smaller in size)
        for (int i = 0; i < abs(sizeDiff); i++)
        {
            secondNum += "0";
        }
        newPosition = this->pointPosition;
    }
    BigDecimalInt result = BigDecimalInt(firstNum) + BigDecimalInt(secondNum);
    string resultStr = result.getnum();
    while (resultStr.size() < newPosition)
    {
        resultStr = "0" + resultStr;
    }
    resultStr = (result.Sign() ? '+' : '-') + resultStr;
    resultStr.insert(resultStr.size() - newPosition, ".");
    BigReal final(resultStr);
    return final;
}

// Overload the minus operator to work with BigReal objects
BigReal BigReal ::operator-(BigReal &other)
{
    int newPosition = 0;
    // Check for the sign of numbers
    char sign1 = this->sign() ? '+' : '-';
    char sign2 = other.sign() ? '+' : '-';

    // Take copy of numbers to make operations on them
    string firstNum = sign1 + this->getModifiedReal().getnum();
    string secondNum = sign2 + other.getModifiedReal().getnum();

    // cout << "First Num: " << firstNum << " Second Num: " << secondNum << endl;
    // Check if the size difference is positive or negative
    int sizeDiff = (other.pointPosition) - (this->pointPosition);
    if (sizeDiff > 0)
    {
        // If the size difference is positive
        // Add zeros to the end of the first number (smaller in size)
        for (int i = 0; i < sizeDiff; i++)
        {
            firstNum += "0";
        }
        newPosition = other.pointPosition;
    }
    else
    {
        // If the size difference is negative
        // Add zeros to the end of the second number (smaller in size)
        for (int i = 0; i < abs(sizeDiff); i++)
        {
            secondNum += "0";
        }
        newPosition = this->pointPosition;
    }
    BigDecimalInt result = BigDecimalInt(firstNum) - BigDecimalInt(secondNum);
    string resultStr = result.getnum();
    while (resultStr.size() < newPosition)
    {
        resultStr = "0" + resultStr;
    }
    resultStr = (result.Sign() ? '+' : '-') + resultStr;
    resultStr.insert(resultStr.size() - newPosition, ".");
    BigReal final(resultStr);
    return final;
}

// Overload the smaller than operator
bool BigReal::operator<(BigReal anotherReal)
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
bool BigReal::operator>(BigReal anotherReal)
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
bool BigReal::operator==(BigReal anotherReal)
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
ostream &operator<<(ostream &out, BigReal real)
{
    string finalNum = real.getModifiedReal().getnum();
    // Return the point to its original postion
    finalNum.insert((real.size() - real.pointPosition), ".");
    // If there is a negative sign print it before the number
    // If not, print the number directly
    (!real.sign()) ? (out << "-" << finalNum) : (out << finalNum);
    return out;
}

// Overload the insertion operator to take input from user and initialize BigReal
istream &operator>>(istream &in, BigReal real)
{
    string realStr;
    in >> realStr;
    real.setModifiedReal(realStr);
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
