#include <iostream>
#include <typeinfo>
using namespace std;

class Employee
{
private:    
    int id;
    double salary;

public:
    Employee()
    {
        cout << "Inside Employee()" << endl;
    }
    Employee(int id, double salary)
    {
        cout << "Inside Employee(int,double)" << endl;
    }
    virtual void accept()
    {
        cout << "Enter the empid - ";
        cin >> id;
        cout << "Enter the salary - ";
        cin >> salary;
    }
    virtual void display()
    {
        cout << "Id - " << id << endl;
        cout << "Salary - " << salary << endl;
    }
    virtual ~Employee()
    {
        cout << "~Employee()" << endl;
    }
};

class Manager : virtual public Employee
{
private:
    double bonus;

protected:
    void acceptManager()
    {
        cout << "Enter the bonus - ";
        cin >> bonus;
    }
    void displayManager()
    {
        cout << "Bonus - " << bonus << endl;
    }

public:
    Manager()
    {
        cout << "Inside Manager()" << endl;
    }
    Manager(int id, double salary, double bonus)
    {
        cout << "Inside Manager(int,double,double)" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
    }

    void display()
    {
        Employee::display();
        displayManager();
    }
    ~Manager()
    {
        cout << "~Manager()" << endl;
    }
};

class Salesman : virtual public Employee
{
private:
    double commission;

protected:
    void acceptSalesman()
    {
        cout << "Enter the Commission - ";
        cin >> commission;
    }
    void displaySalesman()
    {
        cout << "Commission - " << commission << endl;
    }

public:
    Salesman()
    {
        cout << "Inside Salesman()" << endl;
    }
    Salesman(int id, double salary, double commission)
    {
        cout << "Inside Salesman(int,double,double)" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displaySalesman();
    }
    ~Salesman()
    {
        cout << "~Salesman()" << endl;
    }
};
class SalesManager : public Manager, public Salesman
{
public:
    SalesManager()
    {
        cout << "Inside Salesmanager()" << endl;
    }
    SalesManager(int id, double salary, double bonus, double commission)
    {
        cout << "Inside SalesManager(int,double,double,double)" << endl;
    }
    ~SalesManager()
    {
        cout << "~Salesmanager()" << endl;
    }
    void accept()
    {
        Employee::accept();
        acceptManager();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displayManager();
        displaySalesman();
    }
};

int main()
{   
    Employee *employee[10];
    int choice;
    int index = 0;
    int countManager =0;
    int countSalesman =0;
    int countSalesManager =0;
    do
    {
        cout<<"0: Exit"<<endl;
        cout<<"1: Add Employee"<<endl;
        cout<<"2: Display Employee"<<endl;
        cout<<"3: Display all Manager"<<endl;
        cout<<"4: Display all SalesMan"<<endl;
        cout<<"5: Display all SalesManager"<<endl;
        cout<<"6: Display Designation Count"<<endl;
        cout<<endl;

        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice)
        {
            case 0:
            if(index>=0){
                for(int i=0; i<index; i++){
                    delete employee[i];
                    employee[i] = NULL;
                }
             }
            cout<<"Thank You !!"<<endl;
            break;
            case 1:{
                 int choice = 0;
                 do{
                    if(index<10){
                 cout<<"0: Exits"<<endl;   
                 cout<<"1: Manager"<<endl;
                 cout<<"2: Salesman"<<endl;
                 cout<<"3: SalesManager"<<endl;
                 cout<<"Enter your choice : ";
                 cin>>choice;
                 switch(choice){
                  case 1:
                   if(index<10){
                employee[index] = new Manager();
                employee[index]->accept();
                index++;
            }
            break;
            case 2:
             if(index<10){
                employee[index] = new Salesman();
                employee[index]->accept();
                index++;
            }
            break;
            case 3:
             if(index<10){
                employee[index] = new SalesManager();
                employee[index]->accept();
                index++;
            }
            break;
            }
        }

        else{
            cout<<"No More Employee"<<endl;
            break;
        }
           }while(choice!=0);
        }
             break;

            case 2:
            if(index>=0){
              for(int i=0; i<index;i++){
                employee[i]->display();
              }
             }
            else 
                cout<<"No Employee"<<endl;
                cout<<endl;
             break; 
            case 3:
                    countManager=0;
              for(int i=0; i<index; i++){
                if(typeid(*employee[i]) == typeid(Manager)){
                    employee[i]->display();
                    countManager++;
                    cout<<endl;
                }
            }
            break;
            case 4:
            countSalesman=0;
              for(int i=0; i<index; i++){
                if(typeid(*employee[i]) == typeid(Salesman)){
                    employee[i]->display();
                    countSalesman++;
                    cout<<endl;
                }
            }
            break;
            case 5:
              countSalesManager=0;
              for(int i=0; i<index; i++){
                if(typeid(*employee[i]) == typeid(SalesManager)){
                    employee[i]->display();
                    countSalesManager++;
                    cout<<endl;
                }
            }
            break;
            case 6:
               cout<<"Number Of Employees :: "<<index<<endl;
               cout<<"Number Of Managers :: "<<countManager<<endl;
               cout<<"Number Of Salesman :: "<<countSalesman<<endl;
               cout<<"Number Of SalesManager :: "<<countSalesManager<<endl;
               cout<<endl;
            break;
            default:
            cout<<"Invalid choice"<<endl;
            break;
           
        }       
          cout<<endl;
       }while(choice !=0);
    return 0;
};