/*Implement following classes. Test all functionalities in main().
Cretae a class Person with data members name,address and birthdate.  
The birthdate shoud be of type date.
Cretae a class Employee with data members 
id, sal, dept and joining date. The joining date should 
be of type date.*/

#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date
{
    int day, month, year;
    public:
     
     Date():Date(1,12,2000){}

     Date(int day, int month, int year){
            this->day = day;
            this->month = month;
            this->year = year;
     }

     int getDay(){
            return day;
     }
     int getMonth(){
            return month;
     }
     int getYear(){
            return year;
     }
     void setDay(int day){
            this->day = day;
     }
     void setMonth(int month){
            this->month = month;
     }
     void setYear(int year){
            this->year = year;
     }

     void printDate(){
        cout << "Day: " << day << endl;
        cout << "Month: " << month << endl;
        cout << "Year: " << year << endl;
     }    

};
#endif