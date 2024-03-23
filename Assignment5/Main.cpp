
#include "Date.h"
#include "Person.h"

int main(){

     /* string name;
    string address;
    Date birthdate;*/
    /*int day, month, year;*/
     string name, address;
     int day, month, year;

        cout << "Enter name: ";
        cin >> name;
        cout << "Enter address: ";
        cin >> address;
        cout << "Enter The birthdate: "<<endl;
        cout << "Enter day: ";
        cin >> day;
        cout << "Enter month: ";
        cin >> month;
        cout << "Enter year: ";
        cin >> year;
        cout<<endl;
     Person *person = new Person(name, address, day, month, year);
     cout<<endl;
     cout<<endl;
     cout<<"Person All Information"<<endl;
        person->display();
        cout<<endl;
     cout<<"All Getter from the Person and Date Class"<<endl;   
     cout << "Name: " << person->getName() << endl;
     cout << "Address: " << person->getAddress() << endl;
    cout<<endl;
    cout << "Birthdate: "<<endl;
     cout << "Day: " << person->getBirthdate().getDay()<< endl;
     cout << "Month: " << person->getBirthdate().getMonth() << endl;
     cout << "Year: " << person->getBirthdate().getYear()<< endl;

     delete person;
     person = NULL;


}