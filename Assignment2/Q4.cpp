/*Write a class Address. Implement constructors, getters, setters, accept(), and display() methods.
Instead of char[] use string datatype*/
#include <iostream>
using namespace std;
class Address{
    private:
     string building;
     string street;
     string city;
     int pin;
    
    public :
    Address(){
        building = "";
        street = "";
        city = "";
        pin = 0;
    }
    Address(string building, string street,string city,int pin){
        this-> building = building;
        this-> street = street;
        this-> city = city;
        this->pin   = pin;
    }

    void accept(){
            
    }

    void display(){
        cout<<building<<"\n"<<street<<"\n"<<city<<"\n"<<pin<<"\n";
    }

    string getBuilding(){
        return this->building;
    }
    string getStreet(){
        return this->street;
    }
    string getCity(){
        return this->city;
    }
    int getPin(){
        return this->pin;
    }

    void setBuilding(string building){
        this->building = building;
    }
    void setStreet(string street){
        this->street = street;
    }

    void setCity(string city){
        this->city = city;
    }

    void setPin(int pin){
        this->pin = pin;
    }
 
};