#include "Exception.h"
#include <map>
// Function to convert numerical date into alphabetical format
string numericalToAlphabeticDate(int month,int day) throw(MonthError,DayError){
    // Map of month number and it's corresponding value alphabetically
    map<int,string>months = {{1, "January"},{2, "February"},{3, "March"},
                             {4, "April"},{5,"May"},{6,"June"},
                             {7,"July"},{8,"August"},{9,"September"},
                             {10,"October"},{11,"November"},{12,"December"}
    };
    // result date
    string date;
    // if month exist in map
    if(months.count(month)){
        date = months[month] + " ";
    }
    else{
        MonthError mError;
        throw mError;
    }
    if(month == 2){
        if(day > 0 && day <= 29)
            date += to_string(day);
        else{
            DayError dError;
            throw dError;
        }
    }
    else if(month % 2 != 0){
        if(day > 0 && day <= 31)
            date += to_string(day);
        else{
            DayError dError;
            throw dError;
        }
    }
    else{
        if(day > 0 && day <= 30)
            date += to_string(day);
        else{
            DayError dError;
            throw dError;
        }
    }
    return date;
}



int main(){
    int month , day;
    cout << "Please enter month then day\n";
    // take month and day
    cin >> month >> day;
    try {

        cout << numericalToAlphabeticDate(month, day);
    }
    catch (MonthError &e){
        cout << e.what();
    }
    catch (DayError &e){
        cout << e.what();
    }
    return 0;
}