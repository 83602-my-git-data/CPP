/*Write a class for Time and provide the functionality
Time()
Time(int h,int m,int s)
getHour()
getMinute()
getSeconds()
printTime()
setHour()
setMinute()
setSeconds()
Allocate the memory for the the object dynamically and test the functunalities using time ptr.*/

#include "Time.h"

int main(){
    int choice =0;
    int hour, min, seconds;
    Time *time = new Time();
     do
    {
        cout << "0. EXIT" << endl;
        cout << "1. Enter the Time" << endl;
        cout << "2. Display Time" << endl;
        cout << "3. Set Hours" << endl;
        cout << "4. Set Mins" << endl;
        cout << "5. Set seconds" << endl;
        cout<< "6. Get all Times " << endl;
        cout << "Enter choice - "<<endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            delete time;
            time = NULL;
            cout << "Thank you" << endl;
            break;
        case 1:
              cout<<"Enter The Hours:: "<<endl;
              cin>>hour;
              cout<<"Enter The Mins:: "<<endl;
              cin>>min;
              cout<<"Enter The Seconds:: "<<endl;
              cin>>seconds;
             time = new Time(hour,min,seconds);
            break;
        case 2:
             time->printTime();
            break;
        case 3:
            cout<<"Enter The New Hours:: "<<endl;
              cin>>hour;
              time->setHour(hour);
            break;
        case 4:
           cout<<"Enter The New mins:: "<<endl;
              cin>>min;
              time->setMinute(min);
            break;
        case 5:
           cout<<"Enter The New Seconds:: "<<endl;
              cin>>seconds;
              time->setSeconds(seconds);
           break;
        case 6:
            cout<<"Hours::"<<time->getHour()<<endl;
            cout<<"Mins::"<<time->getMinute()<<endl;
            cout<<"Seconds::"<<time->getSeconds()<<endl;
           break;      
        default:
            cout << "Wrong choice..." << endl;
            break;
        }   
     }while(choice!=0);
     return 0;
};