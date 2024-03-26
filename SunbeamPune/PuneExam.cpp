 #include <iostream>
 using namespace std;
class Product {
   int id;
   string name;
   double price;

   public:
    Product();
    Product(int id, string name, double price){
       this->id = id;
       this->name = name;
       this->price = price;
    }
    void setId(int id) { 
      this->id = id; 
      }
    void setName(string name){
        this->name = name;
    }
    void setPrice(double price){
        this->price = price;
    }
    int getId(){
        return id;
    }
    string getName(){
        return name;
    }
    double getPrice(){
        return price;
    }
    void display(){
       cout<<"Product Id: "<<id<<endl;
       cout<<"Product Name: "<<name<<endl;
       cout<<"Product Price: "<<price<<endl;
    }
};

class Person{
   string name;
   public:
    Person(string name){
        this->name = name;
    }
    string getName(){
        return name;
    }
    void setName(string name){
        this->name = name;
    }
   virtual void print(){
        cout << "Name: " << name << endl;
    }
};

class Customer : public Person{
   string mobile;
   Product *product;
   int size=0;
   int index=0;
   public:
    Customer(string name, string mobile):Person(name){
        this->mobile = mobile;
    }
    string getMobile(){
        return mobile;
    }
    void setMobile(string mobile){
        this->mobile = mobile;
    }
    void purchasedProducts(int size){
        this->size = size;
        product = new Product[size];
    }
    
    void acceptProduct(){
        int id;
        string name;
        double price;
        cout<<"Enter Product Id: ";
        cin>>id;
        cout<<"Enter Product Name: ";
        cin>>name;
        cout<<"Enter Product Price: ";
        cin>>price;
        product[index].setId(id);
        product[index].setName(name);
        product[index].setPrice(price);
        index++;

    }
};