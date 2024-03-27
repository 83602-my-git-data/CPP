#ifndef TIME_H
#define TIME_H

 #include <iostream>
 using namespace std;
class Time{
    private:
    int hour,minute,second;
    public:
     
     Time();
     Time(int hour,int minute,int second);
     int getHour();
     int getMinute();
     int getSeconds();
     void printTime();
     void setHour(int hour);
     void setMinute(int minute);
     void setSeconds(int second);

};
#endif