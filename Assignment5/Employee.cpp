#include "Person.h"

class Employee : Person{

     int const Emp_Id;
     Date joining;
     double salary;
     int static generatedEmp_Id;
   public: 
     Employee(string name,string address , int day,int month ,int year,
              int jDay,int jMonth, int jYear,double salary):Emp_Id(++generatedEmp_Id),Person(name,address,day,month,year){
        this->salary = salary;
        this->joining = Date(jDay,jMonth,jYear);
     }

    void didplayEmployee(){
        cout<<"Employee ID: "<<this->Emp_Id<<endl;
        display();
        cout<<"Salary: "<<this->salary<<endl;
        cout<<"Joining Date: "<<endl;
         joining.printDate();
    }    
};

int Employee::generatedEmp_Id =1000;


int main() {
   Employee emp1("J","NY",1,1,2000,1,1,2019,10000);
   Employee emp2("M","New",2,6,2001,1,1,2020,1000);
   Employee emp3("P","York",3,7,2002,1,1,2021,100);
   Employee emp4("Jo","Sr",4,8,2003,1,1,2022,10);
   Employee emp5("S","New York",5,9,2004,1,1,2023,1);

   emp1.didplayEmployee();
   cout<<endl;
   emp2.didplayEmployee();
   cout<<endl;
   emp3.didplayEmployee();
   cout<<endl;
   emp4.didplayEmployee();
   cout<<endl;
   emp5.didplayEmployee();
   return 0;

};
