#include <iostream>
using namespace std;

class Date{

int day;
int month;
int year;

public:
 void acceptDate(){
    cout<<"Enter day: "<<endl;
    cin>>day;
    cout<<"Enter Month: "<<endl;
    cin>>month;
    cout<<"Enter Year: "<<endl;
    cin>>year;
    cout<<endl;
 };
  void displayDate(){
    cout<<"Day: "<<day<<endl;
    cout<<"Month: "<<month<<endl;
    cout<<"Year: "<<year<<endl;
    cout<<endl;
  };
};


class Person{
string name;
string address;
Date birthDate;
public:

virtual  void acceptData(){
    cout<<"Enter name: ";
    getchar();
    getline(cin,name);
    cout<<"Enter address: ";
    cin>>address;
    cout<<"Enter date of birth: "<<endl;
    birthDate.acceptDate();
}; 
// call displayDate inside this fun to display birthdate
virtual void displayData(){
    cout<<"Name: "<<name<<endl;
    cout<<"Address: "<<address<<endl;
    birthDate.displayDate();
};
};

class Employee:public Person{
int empid;
string dept;
double salary;
Date doj;

public:
void acceptData(){
    cout<<"Enter employee id: ";
    cin>>empid;
    Person::acceptData();
    cout<<"Enter department: ";
    cin>>dept;
    cout<<"Enter salary: ";
    cin>>salary;
    cout<<"Enter date of joining: ";
    doj.acceptDate();
}; 
void displayData(){
    cout<<"Employee id: "<<empid<<endl;
    Person::displayData();
    cout<<"Department: "<<dept<<endl;
    cout<<"Salary: "<<salary<<endl;
    cout<<"Date of joining: ";
    doj.displayDate();
    cout<<endl;
};
};

int main()
{//   Date d;
//     d.acceptDate();
//     d.displayDate();
    Person p;
    p.acceptData();
    p.displayData();
    Employee e;
    e.acceptData();
    e.displayData();

    Person *ptr = new Employee;
    ptr->acceptData();
    ptr->displayData();
    delete ptr;

    ptr=NULL;
    return 0;
};
