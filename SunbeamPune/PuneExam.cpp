 #include <iostream>
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
    // void acceptProduct(){
        // int id;
        // string name;
        // double price;
        // cout<<"Enter Product Id: ";
        // cin>>id;
        // cout<<"Enter Product Name: ";
        // cin>>name;
        // cout<<"Enter Product Price: ";
        // cin>>price;
    // }
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
   Product *product=NULL;
   int size=0;
   int index=0;
   public:
    Customer(string name, string mobile): Person(name){
        this->mobile = mobile;
    }
    ~Customer(){
        delete[] product;
        product = NULL;
    }
    string getMobile(){
        return mobile;
    }
    void setMobile(string mobile){
        this->mobile = mobile;
    }
    Product *getProduct(){
        return product;
    }
    int getSize(){
        return size;
    }
    void purchasedProducts(int size){
        this->size = size;
        product = new Product[size];
    }
      void AddProduct(Product ptr){
        product[index] = ptr;
        index++;
    }
    void displayProducts(){
        if(product != NULL){
            product->display();
            cout<<endl;
         }
        else
         cout<<"No Products purchased"<<endl; 
    }
    void print(){
       Person::print();
        cout << "Mobile: " << mobile << endl;
        cout << "Size: " << size << endl;
        displayProducts();
        cout<<endl;
    }
};

int  main(){
    Product *product[10];
    Customer *customer[10];
    int indexForProduct = 0;
    int indexForCustomer = 0;
    int index=0;
    int size =0;
    int id=0;
    int choice=0;
    string name;
    string mobile;
    double price;
     
     do{
        cout<<"0. Exits"<<endl;
        cout<<"1. Add Product"<<endl;
        cout<<"2. Add Customers"<<endl;
        cout<<"3. Customers Purchased Products"<<endl;
        cout<<"4. Display Products ::"<<endl;
        cout<<"5. searching By Mobile No::"<<endl;
        cout<<"6. Customer Name And Purchased Products List."<<endl; 
        
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 0:{
                for(int i=0;i<indexForCustomer;i++)
                  {
                    delete customer[i];
                    customer[i] = NULL;
                  }
                for(int i=0;i<indexForProduct;i++)
                {
                    delete product[i];
                    product[i] = NULL;
                }  
            }
                break;
            case 1:
            cout<<"======================================================="<<endl;
             if(indexForProduct <10){
                    cout<<"Enter Product Id: ";
                    cin>>id;
                    cout<<"Enter Product Name: ";
                    cin>>name;
                    cout<<"Enter Product Price: ";
                    cin>>price;
                product[indexForProduct] = new Product(id,name,price);
                // product[indexForProduct]->acceptProduct();
                indexForProduct++;
              }
             else{
                cout<<"No more space"<<endl;
             } 
             cout<<"======================================================="<<endl;
                break;
            case 2:
            cout<<"======================================================="<<endl;
                if(indexForCustomer<10){
                    cout<<"Enter the Name ::"<<endl;
                    getchar();
                    getline(cin,name);
                    cout<<"Enter The Mobile NO ::"<<endl;
                    cin>>mobile;
                   customer[indexForCustomer] = new Customer(name,mobile);
                   indexForCustomer++;
                 }
                else 
                  cout<<"Customer Is Full...."<<endl; 
                cout<<"======================================================="<<endl;  
                break;
            case 3://Customers Purchased Products
               cout<<"======================================================="<<endl;
                    cout<<"Enter the Customer Name :: "<<endl;
                    getchar();
                    getline(cin,name);
                    for(int i=0; i<indexForCustomer;i++){
                      //  cout<<customer[i]->getName()<<"  "<<name <<endl;
                        if(customer[i]->getName() == name){
                            index = i+1;    
                            break;
                        }
                    }
                    if(index==0){
                        cout<<"Customer Not Found"<<endl;
                        continue;
                      }
                      cout<<"Enter the Basket Size :: "<<endl;
                      cin>>size;
                      customer[index-1]->purchasedProducts(size);
                    cout<<"======================================================="<<endl;
                    cout<<"Product List :: "<<endl;
                    for(int i=0; i<indexForProduct;i++){
                        product[i]->display();
                    }
                    cout<<"Enter Product Id ::-"<<endl;
                     cin>>id;
                     for(int i=0; i<indexForProduct;i++){
                        if(product[i]->getId() == id){
                            customer[index-1]->AddProduct(*product[i]);
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
             for(int i=0;i<indexForProduct;i++)
                product[i]->display();
             cout<<"=========================customer =============================="<<endl;
             for(int i=0;i<indexForCustomer;i++)
                customer[i]->print();   
            cout<<"======================================================="<<endl;    
                break;
            case 5://searching By Mobile No
            cout<<"======================================================="<<endl;
               cout<<"Enter the Customer Mobile No ::"<<endl;
               cin>>mobile;
               for(int i=0; i<indexForCustomer ; i++){
                if(customer[i]->getMobile() == mobile){
                    customer[i]->displayProducts();
                    break;
                }
               } 
            cout<<"======================================================="<<endl;
                break;
            case 6://Customer Name And Purchased Products List
            cout<<"======================================================="<<endl;
              for(int i=0;i<indexForCustomer;i++){
                 cout<<"Customer Name ::- "<<customer[i]->getName()<<endl;
                 if(customer[i]->getProduct() != NULL){
                    cout<<"Product List ::"<<endl;
                        customer[i]->getProduct()->display();
                        cout<<endl;
                 }
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