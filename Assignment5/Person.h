#ifndef PERSON_H
#define PERSON_H

#include <iostream>
using namespace std;
#include "Date.h"
class Person{
    private:
    string name;
    string address;
    Date birthdate;

    public:
    Person(){
        name = "";
        address = "";
    }
    Person(string n, string a,int day, int month, int year):birthdate(day,month,year){
        name = n;
        address = a;
    }

    void setName(string n){
        name = n;
    }
    void setAddress(string a){
        address = a;
    }
    void setBirthdate(int day, int month, int year){
        birthdate = Date(day,month,year);
    }
    string getName(){
        return name;
    }
    string getAddress(){
        return address;
    }
    Date getBirthdate(){
        return birthdate;
    }
    void display(){
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
         birthdate.printDate();
    }
};

#endif 