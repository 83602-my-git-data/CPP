#include <iostream>
using namespace std;

class Product{
int id;
string title;
double price;

public:
virtual void accept(){
  cout<<"Enter The Id Of Product:: "<<endl;
  cin>>id;
  cout<<"Enter The Title Of Product:: "<<endl;
  cin>>title;
  cout<<"Enter The Price Of Product:: "<<endl;
  cin>>price;
}
  
virtual void display(){
  cout<<"The Id Of Product:: "<<id<<endl;
  cout<<"The Title Of Product:: "<<title<<endl;
  cout<<"The Price Of Product:: "<<price<<endl;
}
int getPrice(){
    return price;
}

void setPrice(int price){
    this->price = price;
}

};

class Book :  public Product{
string author;

public:
void accept(){
    Product::accept();
   cout<<"Enter The Author Of Book:: "<<endl;
    getchar();
    getline(cin, author);
   Product::setPrice(Product::getPrice()- Product::getPrice()*0.10);
}
void display(){
 Product::display();
   cout<<"The Author Of Book:: "<<author<<endl;
}
};

class Tape :  public Product{
string artist;

public:
void accept(){
    Product::accept();
    cout<<"Enter The Artist Of Tape:: "<<endl;
    getchar();
    getline(cin,artist);
    Product::setPrice(Product::getPrice()- Product::getPrice()*0.05);
}
void display(){
    Product::display();
    cout<<"The Artist Of Tape:: "<<artist<<endl;
}
};


int main(){
  Product *ptr[3];
    int choice=0;
    int index = 0;
    int price = 0;

    do
    {
        cout<<"0: Exit"<<endl;
        cout<<"1: Book"<<endl;
        cout<<"2: Tape"<<endl;
        cout<<"3: Display"<<endl;
        cout<<"4: Total Price"<<endl;

        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice)
        {
            case 0:
                for(int i=0; i<index; i++){
                    delete ptr[i];
                    ptr[i] = NULL;
                    }
            cout<<"Thank You !!"<<endl;
            break;

            case 1:
            if(index <3){
            ptr[index]= new Book();
             ptr[index]->accept(); 
            index++;
            }
            else{
                cout<<"No More Product"<<endl;
            }
            break;

            case 2:
            if(index <3){
            ptr[index]= new Tape();
             ptr[index]->accept(); 
             ptr[index]->display();
            index++;
            }
            else{
                cout<<"No More Product"<<endl;
            }

            break;

            case 3:
             cout<<endl;
            if(index !=0){
            for(int i=0;i<index;i++)
            {
                ptr[i]->display();
            }
            }
            else{
                cout<<"No Product"<<endl;
            } 
            break;
            case 4:
             cout<<endl;
            if(index !=0){
            for(int i=0;i<index;i++)
            {
               price += ptr[i]->getPrice();
            }
            }
            else{
                cout<<"No Product"<<endl;
            } 
            cout<<"Total Price : "<<price<<endl;
             break;
        }
        cout<<endl;
    }while(choice!=0);

    return 0;
};