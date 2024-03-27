/*Write a class to store Account information of Bank customer by using following class diagram. 
Use enum to store information of account type. 
Create an array of 5 Accounts in main() and accept their details from user. 
Write Menu driven program to deposit/withdraw amount from the account. 
After each transaction display updated account balance. 
Throw exceptions for invalid values. 
Also implement an exception class InsufficientFundsException. 
In withdraw if sufficient balance is not available in account or while deposit the entered amount is 
negative then throw this exception.*/
#include<iostream>
using namespace std;


enum AccountType{
    SAVINGS,
    CURRENT,
    DMAT
};
class InsufficientFundsException{
    int acc_id;
    double current_balance;
    double withdraw_amount;
    string description;
    int error_code=0;
    public:
    InsufficientFundsException(int error_code,string description){
            this->error_code = error_code;
            this->description = description;
    }
    InsufficientFundsException(int acc_id,double current_balance,double withdraw_amount,string description){
        this->acc_id = acc_id;
        this->current_balance = current_balance;
        this->withdraw_amount = withdraw_amount;
        this->description = description;
    }
    void 
    print()
    {
   
        cout<<"Insufficient Funds"<<endl;
        if(error_code == 0){
        cout<<"Account Id: "<<acc_id<<endl;
        cout<<"Current Balance: "<<current_balance<<endl;
        cout<<"Withdraw Amount: "<<withdraw_amount<<endl;
        cout<<"ERRORS: "<<description<<endl;
        }
        else 
        {   
            cout<<"Error Code "<<error_code<<endl;
            cout<<"ERRORS: "<<description<<endl;
        }
    }
};

class Account
 {
     private:
     int acc_no;
     string acc_type;
     double balance;
     public:

     Account(int acc_no, string acc_type, double balance){
         this->acc_no = acc_no;
         this->acc_type = acc_type;
         this->balance = balance;
     }

     void deposit(double amount){
        if( amount < 0){
            throw InsufficientFundsException(acc_no, balance,amount,"Amount is negative.....");
        }
        this->balance += amount;
     }
     void withdraw(double amount){
        if(this->balance < amount){
            throw InsufficientFundsException(acc_no, balance,amount,"Insufficient Funds...");
        }
        this->balance -= amount;
     }
     void display(){
        cout<<"Account No: "<<acc_no<<endl;
        cout<<"Account Type: "<<acc_type<<endl;
        cout<<"Balance: "<<balance<<endl;
     }
 };
 
 int main()
{
    Account *acc = NULL;
    try
    {   string acc_type;
        int choice;
         int acc_no;
        cout<<"Enter Account Number: ";
        cin>>acc_no;
        cout<<"Enter Account Type: ";
        cin>>choice;
        switch (AccountType(choice))
        {
    
        case SAVINGS:
            acc_type = "SAVINGS";
            break;
        case  CURRENT:
            acc_type = "CURRENT";
            break;
        case DMAT:
            acc_type = "DMAT";
            break;
        default:
            cout << "Wrong choice..." << endl;
            break;
        }
        cout<<"Enter Account Balance: ";
        double balance;
        cin>>balance;
        if(balance <1)
            throw InsufficientFundsException(1,"Balance is not less than 1.....");

        acc = new Account(acc_no,acc_type, balance);
        acc->display();
        cout<<"Enter Amount to Deposit: ";
        double amount;
        cin>>amount;
        acc->deposit(amount);   
        acc->display();
        cout<<"Enter Amount to Withdraw: ";
        cin>>amount;
        acc->withdraw(amount);
        acc->display();     
        delete acc;
         acc= NULL;
    }
    // catch (InsufficientFundsException e)
    // {
    //     e.print2();
    // }
    catch(InsufficientFundsException a){
        
        a.print();
    }
    cout << "Program complete" << endl;
    return 0;
}