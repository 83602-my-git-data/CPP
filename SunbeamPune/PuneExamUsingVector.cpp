 #include <iostream>
 #include <vector>

 using namespace std;
class Product {
   int id;
   string name;
   double price;

   public:
    Product(){

    }
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
   vector< Product *> product;
   public:
    Customer(string name, string mobile): Person(name){
        this->mobile = mobile;
    }
    ~Customer(){
        for (int i = 0; i < product.size(); i++) 
            {
                        product.erase(product.begin() + i);
            }
    }
    string getMobile(){
        return mobile;
    }
    void setMobile(string mobile){
        this->mobile = mobile;
    }
    vector<Product *> getProduct(){
        return product;
    }

      void AddProduct(Product *ptr){
        product.push_back(ptr);
    }
    void displayProducts(){
          for (int i = 0; i < product.size(); i++)
                    product[i]->display(); 
    }

    void print(){
       Person::print();
        cout << "Mobile: " << mobile << endl;
        displayProducts();
        cout<<endl;
    }
};

int  main(){
    vector<Product *> product;
    vector<Customer *> customer;
    int index=0;
    int id;
    int choice=0;
    string name;
    string mobile;
    double price;
     
     do{
        cout<<"0. Exits"<<endl;
        cout<<"1. Add Product"<<endl;
        cout<<"2. Add Customers"<<endl;
        cout<<"3. Customers Purchased Products"<<endl;
        cout<<"4. Display ::"<<endl;
        cout<<"5. searching By Mobile No::"<<endl;
        cout<<"6. Customer Name And Purchased Products List."<<endl; 
        
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 0:{
                 for (int i = 0; i < product.size(); i++)
                        delete product[i];
            
                 for (int i = 0; i < customer.size(); i++)
                        delete customer[i]; 

                cout<<"Thank you :-)!!!!!!"<<endl;
            }
                break;
            case 1://Add products 
            cout<<"======================================================="<<endl;
                    cout<<"Enter Product Id: ";
                    cin>>id;
                    cout<<"Enter Product Name: ";
                    getchar();
                    //cin>>name;
                    getline(cin, name);
                    cout<<"Enter Product Price: ";
                    cin>>price;
                      // Product *ptr = new Product(id, name ,price);
                        product.push_back(new Product(id, name ,price));
                break;
            case 2://add customers 
            cout<<"======================================================="<<endl;
                    cout<<"Enter the Name ::"<<endl;
                    getchar();
                    getline(cin,name);
                    cout<<"Enter The Mobile NO ::"<<endl;
                    cin>>mobile;
                   customer.push_back(new Customer(name,mobile));
                cout<<"======================================================="<<endl;  
                break;
            case 3://Customers Purchased Products
               cout<<"======================================================="<<endl;
                    cout<<"Enter the Customer Name :: "<<endl;
                    getchar();
                    getline(cin,name);
                    for(int i=0; i<customer.size();i++){
                        if(customer[i]->getName() == name){
                            index = i+1;    
                            break;
                        }
                    }
                    if(index==0){
                        cout<<"Customer Not Found"<<endl;
                        continue;
                      }
                    cout<<"======================================================="<<endl;
                    cout<<"Product List :: "<<endl;
                    for(int i=0; i<product.size();i++){
                        product[i]->display();
                    }
                    cout<<"Enter Product Id ::-"<<endl;
                     cin>>id;
                     for(int i=0; i<product.size();i++){
                         if(product[i]->getId() == id){
                            customer[index-1]->AddProduct(product[i]);
                            cout<<"Product is Added..."<<endl;
                            break;
                          }
                      }
                    cout<<"======================================================="<<endl;
                     cout<<endl;   
                  
                break;

            case 4:
            cout<<"======================================================="<<endl;
            cout<<"Product Details :: "<<endl;
             for(int i=0;i<product.size();i++)
                product[i]->display();
             cout<<"=========================customer =============================="<<endl;
             for(int i=0;i<customer.size();i++)
                customer[i]->print();   
            cout<<"======================================================="<<endl;    
                break;
            case 5://searching By Mobile No
            cout<<"======================================================="<<endl;
               cout<<"Enter the Customer Mobile No ::"<<endl;
               cin>>mobile;
               for(int i=0; i<customer.size(); i++){
                if(customer[i]->getMobile() == mobile){
                    customer[i]->displayProducts();
                    break;
                }
               } 
            cout<<"======================================================="<<endl;
                break;
            case 6://Customer Name And Purchased Products List
            cout<<"======================================================="<<endl;
              for(int i=0;i<customer.size();i++){
                 cout<<"Customer Name ::- "<<customer[i]->getName()<<endl;
                    cout<<"Product List ::"<<endl;
                        for(int j=0; j<customer[i]->getProduct().size();j++){
                            customer[i]->getProduct()[j]->display();
                        }
                        cout<<endl;
              }
            cout<<"======================================================="<<endl;  
             break;    
            default:
                cout<<"Invalid Choice"<<endl;
                break;
        } 
     }while(choice!=0);

 return 0;
};