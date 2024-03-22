#include <iostream>
using namespace std;
/*
1. When program executes take the input for accno, name and balance and then
create the object and then display the below menu
1. display account details
2. deposit
3. withdraw
4. check balance
*/


class Bank{
    int const accountID;
    string fullName;
    double balance;
    static int generatedAccountID;

    public:
    Bank(string fullName, double balance) : accountID(++generatedAccountID){
        this->fullName = fullName;
        this->balance = balance;
    }

    void deposit(int accid, double amount){
         if(this->accountID==accid){
            this->balance += amount;
            cout << "Name :: "<<this->fullName<<"Balance is ::  " << this->balance << endl;
         }
         else{
            cout<<"Account is not existing!!!"<<endl;
            cout<<"Please , register!!!!"<<endl;
         }
    }

    void withdraw(int accid, double amount){
        if(this->accountID == accid){
            if(this->balance >= amount){
                this->balance -= amount;
                cout << "Balance is ::  " << this->balance << endl;
            }
            else 
              cout<<"Insufficient balance!!!"<<endl;
          }
        else 
          cout<<"AccountId is not corrects!!!"<<endl;  
    } 

    void AccountDetails(){
        cout << "Account ID :: " << this->accountID << endl;
        cout << "Account Name :: " << this->fullName << endl;
        cout << "Balance :: " << this->balance << endl;
    }

    void tranferForOneToAnother(Bank &b2, double amount){
        if(this->getAccountID() != b2.getAccountID()){
            if(this->getBalance()>amount){
                this->setBalance(this->getBalance()-amount);
                b2.setBalance(b2.getBalance()+amount);
                cout<<"Completed!!!"<<endl;
            }
            else{
                cout<<"Insufficient balance!!!"<<endl;
            }
        }
       else{
        cout<<"Enter the Valid AccountId"<<endl;
       } 
    } 
     void setFullName(string fullName){
        this->fullName = fullName;
     }
     void setBalance(double balance){
        this->balance = balance;
     }
    int getAccountID() const{
        return this->accountID;
    }
    string getFullName() const{
        return this->fullName;
    }
    double getBalance() const{
        return this->balance;
    }
};

int Bank::generatedAccountID =1000;

int main(){
    //   Bank *acc1 = new Bank (1001,"Sham Girhe",5000);
    //   Bank *acc2 = new Bank(1002,"Pranav Shinde",10000);

         Bank acc1("Sham Girhe", 5000);

         Bank acc2("Pranav Shinde", 10000);

       acc1.AccountDetails();
       acc2.AccountDetails();

       acc1.deposit(1001,4000);
       acc2.tranferForOneToAnother(acc1,4000);//passed by reference it corrects

       acc1.AccountDetails();
       acc2.AccountDetails();

    //delete acc1,acc2;
    //acc1= null;
    //acc2 = null;
        

    return 0;
}