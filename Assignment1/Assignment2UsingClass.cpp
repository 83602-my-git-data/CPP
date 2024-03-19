#include <iostream>
using namespace std;

class Date
{  
    int day;
    int month;
    int year;

   public :
    void initDate(){
        //  this->day = 00;
        //  this->month = 00;
        //  this->year = 0000;
    } 
    void printDateOnConsole(){
        ::cout <<day <<"/" << month<<"/"<< year << endl;
    }
    void acceptDateFromConsole(){
        ::cout << "Enter the day : ";
        cin >> day;
        ::cout << "Enter the month : ";
        cin >> month;
        ::cout << "Enter the year : ";
        cin >> year;
    }
    int getYear(){ 
        return this->year;
    }

    bool isLeapYear(){ 
        if(year % 4 == 0 && year % 100!= 0 || year % 400 == 0)
            return true;
        else
            return false;
    }
};

int main(){
     
     int choice=0;
     Date d;
    d.initDate();
    do
    {
        ::cout << "0. EXIT" << endl;
        ::cout << "1. Accept Date" << endl;
        ::cout << "2. Display Date" << endl;
        ::cout << "3. Check Leap Year or Not" << endl;
        ::cout << "Enter your choice  - ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            ::cout << "Thank you... " << endl;
            break;
        case 1:
            d.acceptDateFromConsole();
            break;
        case 2:
              d.printDateOnConsole();
            break;
        case 3:
              if(d.isLeapYear())
                  ::cout << " This"<<d.getYear() << "Leap Year" << endl;
              else
                  ::cout <<"This "<<d.getYear() << " is Not Leap Year" << endl;
            break;
        default:
            ::cout << "Wrong choice... " << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}