#include "Time.h"

Time::Time(): Time(00,00,00){}

Time::Time(int hour, int minute, int second){
    this->hour = hour;
    this->minute = minute;
    this->second = second;
}

int Time::getHour(){
    return hour;
}

 int Time::getMinute(){
    return minute;
}

int Time::getSeconds(){
    return second;
}

void Time::setHour(int hour){
    this->hour = hour;
}

void Time::setMinute(int minute){
    this->minute = minute;
}

void Time::setSeconds(int second){
    this->second = second;
}

void Time::printTime(){
    cout << hour << ":" << minute << ":" << second << endl;
}
