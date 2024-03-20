/*Imagine a tollbooth at a bridge. Cars passing by the booth are expected to pay a fifty-cent toll. 
Mostly they do, but sometimes a car goes by without paying.
The tollbooth keeps track of the number of cars that have gone by and of the total amount of money 
collected. Model this tollbooth with a class called tollbooth.
The two data items are a type unsigned int to hold the total number of cars, and a type double to 
hold the total amount of money collected.
A constructor initializes all data members to 0. A member function called payingCar() increments 
the car total and adds 0.50 to the cash total. An other function, called nopayCar()
increments the car total but adds nothing to the cash total. Finally, a member function called 
printOnConsole() displays the two totals and number of paying as well as non paying cars total.*/

#include <iostream>
using namespace std;


class tollbooth{
    int totalCount;
    int payCarCount;
    double cashTotal;

    public:
    tollbooth(){
        this->totalCount = 0;
        this->payCarCount = 0;
        this->cashTotal = 0;
    }
    void payingcar(){
        this->totalCount++;
        this->payCarCount++;
        this->cashTotal += 50;
    }
    void nopaycar(){
        this->totalCount++;
    }
    int getTotalCount(){
        return this->totalCount;
    }
    int getPayCarCount(){
        return this->payCarCount;
    }

    void printOnConsole(){
    cout << "Total number of cars: " << this->totalCount << endl;
    cout << "Total amount of money collected: " << this->cashTotal << endl;
    cout << "Number of cars paying: " << this->payCarCount << endl;
    cout << "Number of not paying cars : " <<this->totalCount - this->payCarCount << endl;
    }

};

int main()
{
       int choice = 0;
        tollbooth *tb = new tollbooth();
       do{
           cout<<endl;
            cout<<"0.exits"<<endl;
            cout<<"1.Enter a Paying Car"<<endl;
            cout<<"2.Enter a non paying car"<<endl;
            cout<<"3.Print on Console"<<endl;
             cout<<"Enter your choice: ";
             cout<<endl;
               cin>>choice;
            switch(choice){
                 case 1:
                 cout<<endl;
                     tb->payingcar();
                  cout<<endl;   
                     break;
                 case 2:
                 cout<<endl;
                     tb->nopaycar();
                     cout<<endl;
                     break;
                 case 3: 
                 cout<<endl;
                        tb->printOnConsole();

                   cout<<endl;     
                     break;    
                 case 0:
                 cout<<endl;
                      cout<<"Thank You!"<<endl;
                     break;
                 default:
                     cout<<"Invalid choice"<<endl;
                     break;
              }
       }while(choice!=0);

      return 0;
};