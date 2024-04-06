#include <iostream>
#include <vector>
#include <typeinfo>
#include <fstream>
#include <sstream>
using namespace std;

class Product{
    int product_id;
    string product_name;
    double price;

    public:
    Product(int id, string name, double price){
        product_id = id;
        product_name = name;
        this->price = price;
    }

    virtual void display(){
        cout << "Product Id: " << product_id << endl;
        cout << "Product Name: " << product_name << endl;
        cout << "Product Price: " << price << endl;
    }
    void setPrice(double price){
        this->price = price;
    }
    double getPrice(){
        return price;
    }
    void setId(int id){
        product_id = id;
    }
    int getId(){
        return product_id;
    }
    void setName(string name){
        product_name = name;
    }
    string getName(){
        return product_name;
    }
};

class Book: public Product{
    string author;
    public:
    Book(int id, string name, double price, string author):Product(id, name, price){
        this->author = author;
    }
    void display(){
       Product::display();
        cout << "Product Author: " << author << endl;
    }
    void setAuthor(string author){
        this->author = author;
    }
    string getAuthor(){
        return author;
    }
};

class WristWatch: public Product{
    string type;
    public:
    WristWatch(int product_id,string product_name,double price,string type):Product(product_id,product_name,price){
        this->type = type;
    }
    void display(){
        Product::display();
        cout << "Product Type: " << type << endl;
    }
    void setType(string type){
        this->type = type;
    }
    string getType(){
        return type;
    }
};
int menu()
{
    int choice;
    cout<<"***************************"<<endl;
    cout<<endl;
    cout << "1. Add a Book in books container " << endl;
    cout << "2. Add a Watch in watch container " << endl;
    cout << "3. Purchase Product  " << endl;
    cout << "4. Generate Bill" << endl;
    cout << "5. Display all Books" << endl;
    cout << "6. Display all WristWatch"<<endl;
    cout << "Enter your choice - ";
    cin >> choice;
    cout<<"***************************"<<endl;
    return choice;
}
void saveBook(vector<Product *> &products)
{        
    vector<Book*> booklist;
    for(int i=0; i<products.size();i++){
                    if(typeid(*products[i])==typeid(Book)){
                         Book *wptr = dynamic_cast<Book *>(products[i]);
                         booklist.push_back(wptr);
                    }
                } 
    ofstream outfile;
    outfile.open("Book.txt");
    for (int i = 0; i < booklist.size(); i++)
    {
        outfile << booklist[i]->getId() << "," << booklist[i]->getName()<< "," << booklist[i]->getPrice()<< "," << booklist[i]->getAuthor() << endl;
    }
    outfile.close();
    cout << "*******************************" << endl;
    cout << "All Book are saved in file" << endl;
    cout << "*******************************" << endl;
}



void loadBooks(vector<Product *> &products)
{
    ifstream fin("Book.txt");
    string data;
    while (getline(fin, data))
    {
        stringstream obj(data);
        string id,name,price, author;
        getline(obj, id, ',');
        getline(obj, name, ',');
        getline(obj, price, ',');
        getline(obj, author, ',');
        products.push_back(new Book(stoi(id),name,stod(price),author));
    }
    fin.close();
    cout << "*******************************" << endl;
    cout << "All Books are loaded from file" << endl;
    cout << "*******************************" << endl;
}
void saveWristWatch(vector<Product *> &products)
{        
    vector<WristWatch *> watchlist;
    for(int i=0; i<products.size();i++){
                    if(typeid(*products[i])==typeid(WristWatch)){
                         WristWatch *wptr = dynamic_cast<WristWatch *>(products[i]);
                         watchlist.push_back(wptr);
                    }
                } 
    ofstream outfile;
    outfile.open("WristWatch.txt");
    for (int i = 0; i < watchlist.size(); i++)
    {
        outfile << watchlist[i]->getId() << "," << watchlist[i]->getName()<< "," << watchlist[i]->getPrice()<< "," << watchlist[i]->getType() << endl;
    }
    outfile.close();
    cout << "*******************************" << endl;
    cout << "All WristWatch are saved in file" << endl;
    cout << "*******************************" << endl;
}


void loadWristWatch(vector<Product *> &products)
{
    ifstream fin("WristWatch.txt");
    string data;
    while (getline(fin, data))
    {
        stringstream obj(data);
        string id,name,price, type;
        getline(obj, id, ',');
        getline(obj, name, ',');
        getline(obj, price, ',');
        getline(obj, type, ',');
        products.push_back(new WristWatch(stoi(id),name,stod(price),type));
    }
    fin.close();
    cout << "*******************************" << endl;
    cout << "All WristWatch are loaded from file" << endl;
    cout << "*******************************" << endl;
}


int main(){
    int choice =0;
    double purchasedBillValue;
    int product_id;
    string product_name;
    double price;
    string author;
    string type;
    vector<Product*> products;
    vector<Product *> purchaseProduct;
    cout<<endl;
       loadBooks(products);  
       loadWristWatch(products);       
   while ((choice = menu()) != 0)
    {
        switch (choice)
        {
          case 1:{
            cout<<"***************************"<<endl;
            cout<<endl;
            cout << "Enter product id - ";
            cin >> product_id;
            cout << "Enter product name - ";
            cin >> product_name;
            cout << "Enter product price - ";
            cin >> price;
            cout<<"Enter the Author"<<endl;
            cin>>author;
            products.push_back(new Book(product_id,product_name,price,author));
          }
           break;
          case 2:{
            cout<<"***************************"<<endl;
            cout<<endl;
            cout << "Enter product id - ";
            cin >> product_id;
            cout << "Enter product name - ";
            cin >> product_name;
            cout << "Enter product price - ";
            cin >> price;
            cout<<"Enter the Type(analog or smart) "<<endl;
            cin>>type;
            if(type=="analog" || type=="smart"){
            products.push_back(new WristWatch(product_id,product_name,price,type));
            }
            else
              cout<<"Invalid Type"<<endl;
          }
           break;
          case 3:{
            //3. Purchase Product
            bool flag = true;
            cout<<"***************************"<<endl;
            cout<<endl;
             for(int i=0; i<products.size();i++){
                products[i]->display();
             }
             int num=-1;
             cout<<"Enter the Purchese Items Type -1. BOOK or 2. WATCH"<<endl;
             cin>>num;
             if(num==1){
              cout << "Enter product id - ";
               cin >> product_id;
              for(int i=0; i<products.size();i++){
                if(typeid(*products[i])==typeid(Book)){
                   Book *bptr = dynamic_cast<Book *>(products[i]);
                  if(bptr->getId()==product_id){
                    purchaseProduct.push_back(bptr);
                    flag = false;
                    cout<<"Purchese is Successful"<<endl;
                    break;
                }
             }
              }
             }
             else{
                  cout << "Enter product id - ";
               cin >> product_id;
              for(int i=0; i<products.size();i++){
                if(typeid(*products[i])==typeid(WristWatch)){
                   WristWatch *wptr = dynamic_cast<WristWatch *>(products[i]);
                if(wptr->getId()==product_id){
                    purchaseProduct.push_back(wptr);
                    cout<<"Purchese is Successful"<<endl;
                    flag = false;
                    break;
                }
             }
            }
             }
             if(flag){
                cout << "Invalid product id" << endl;
             }
             cout<<"*********** /\ Purchase List Of Product /\ ****************"<<endl;
             cout<<endl;
             for(int i=0; i<purchaseProduct.size();i++){
                  purchaseProduct[i]->display();
             }
          }
           break;
          case 4:{//Generate Bill
            purchasedBillValue=0;
            for(int i=0; i<purchaseProduct.size();i++){
                    purchasedBillValue+=purchaseProduct[i]->getPrice();
            }
          }
          cout<<"Purchase Bill is :: "<<purchasedBillValue<<endl;
           break;

         case 5:{// Display all Books 
                cout<<"All Books"<<endl;
                cout<<"***************************"<<endl;
                cout<<endl;
                for(int i=0; i<products.size();i++){
                    if(typeid(*products[i])==typeid(Book)){
                        products[i]->display();
                    }
                } 
         }
         break;
         case 6:{
            // Display all WristWatch
            cout<<"All WristWatch"<<endl;
                cout<<"***************************"<<endl;
                cout<<endl;
                for(int i=0; i<products.size();i++){
                    if(typeid(*products[i])==typeid(WristWatch)){
                        products[i]->display();
                    }
                } 
         } 
         break; 
          default:
            cout << "Wrong choice..." << endl;
            break;
        }
    }
        saveBook(products);
        saveWristWatch(products);
    for(int i= 0 ;i<products.size();i++){
        delete products[i];
    }
    for(int i= 0 ;i<purchaseProduct.size();i++){
        delete products[i];
    }
return 0;
}


