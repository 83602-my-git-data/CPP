#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

class Servicing {
    string name;
    int vehicleNo;
    string mobile;
    double totalBill=0;

    public:
    Servicing(string name, int vehicleNo, string mobile) {
        this->name = name;
        this->vehicleNo = vehicleNo;
        this->mobile = mobile;
    }
    void setName(string name) {
        this->name = name;
    }
    void setVehicleNo(int vehicleNo) {
        this->vehicleNo = vehicleNo;
    }
    void setTotalBill(double totalBill) {
        this->totalBill = totalBill;
    }
    void setMobile(string mobile) {
        this->mobile = mobile;
    }
  
    string getName() {
        return name;
    }
    int getVehicleNo() {
        return vehicleNo;
    }
    string getMobile() {
        return mobile;
    }
    double getTotalBill() {
        return totalBill;
    }
      virtual void CalculateTotalBill() =0;
   virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Vehicle No: " << vehicleNo << endl;
        cout << "Mobile: " << mobile << endl;
    }
};
class OilChange : public Servicing{
    string oilname;
    double oilprice;

    public:
    OilChange(string name, int vehicleNo, string mobile, string oilname, double oilprice) : Servicing(name, vehicleNo, mobile) {
        this->oilname = oilname;
        this->oilprice = oilprice;
    }
    void setOilname(string oilname) {
        this->oilname = oilname;
    }
    void setOilprice(double oilprice) {
        this->oilprice = oilprice;
    }
    string getOilname() {
        return oilname;
    }
    double getOilprice() {
        return oilprice;
    }
    void CalculateTotalBill() {
        Servicing::setTotalBill(Servicing::getTotalBill() + (getOilprice()+getOilprice()*1.2));
        cout << "Total Bill: " << Servicing::getTotalBill() << endl;
    }
    void display() {
        cout<<"******************************************"<<endl;     
        Servicing::display();
        cout << "Oil Name: " << oilname << endl;
        cout << "Oil Price: " << oilprice << endl;
        CalculateTotalBill();
        cout<<"******************************************"<<endl;        
    }

};


class Maintenance : public Servicing{
    string partName;
    double partPrice;
    double laborCharge;

    public:
    Maintenance(string name, int vehicleNo, string mobile, string partName, double partPrice, double laborCharge) : Servicing(name, vehicleNo, mobile) {
        this->partName = partName;
        this->partPrice = partPrice;
        this->laborCharge = laborCharge;
    }
    void setPartName(string partName) {
        this->partName = partName;
    }
    void setPartPrice(double partPrice) {
        this->partPrice = partPrice;
    }
    void setLaborCharge(double laborCharge) {
        this->laborCharge = laborCharge;
    }
    void CalculateTotalBill() {
        Servicing::setTotalBill(Servicing::getTotalBill() + (getPartPrice()+getPartPrice()*0.5+getLaborCharge()+getLaborCharge()*0.5));
        cout << "Total Bill: " << Servicing::getTotalBill() << endl;
    }
    string getPartName() {
        return partName;
    }
    double getPartPrice() {
        return partPrice;
    }
    double getLaborCharge() {
        return laborCharge;
    }
    void display() {
        cout<<"******************************************"<<endl;
        Servicing::display();
        cout << "Part Name: " << partName << endl;
        cout << "Part Price: " << partPrice << endl;
        cout << "Labor Charge: " << laborCharge << endl;
       CalculateTotalBill();
       cout<<"******************************************"<<endl;
    }
};

class CustomException{
    string errorMessage;
    public:
    CustomException(string errorMessage) {
        this->errorMessage = errorMessage;
    }
    void printErrorMessage() {
        cout<<"*-*-*-*-*-*-*-*-*-"<<endl;
        cout<<errorMessage<<endl;
        cout<<"*-*-*-*-*-*-*-*-*-"<<endl;
    }
};
 int menu()
{
    int choice;
    cout<<"*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/"<<endl;
    cout << "1. Add Servicing----" << endl;
    cout << "2. Display " << endl;
    cout << "3. Total Bill Of Vehicle" << endl;
    cout << "4. Display All Students" << endl;
    cout << "Enter your choice - ";
    cin >> choice;
    cout<<"*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/"<<endl;

    return choice;
}

int main(){
    int choice;
    int vehicleNo;
    string name;
    string mobile;
    string partName;
    double partPrice;
    double laborCharge;
    vector<Servicing *> ServicingList;
         
    while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
         try{
            int choice1;
          cout<<"1. Oil Change of vehicle"<<endl;  
          cout<<"2. Maintenance of vehicle"<<endl;
          cout<<"Enter your choice - ";
          cin >> choice1;
           cout << "Enter Vehicle No: ";
            cin >> vehicleNo;
           cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Mobile: ";
            cin >> mobile;
          switch(choice1){
            case 1:{
                string oilname;
                cout<<"Oil Name: "<<endl;
                cin>>oilname;
                double oilCharge;
                cout<<"Oil Charge: "<<endl;
                cin>>oilCharge;
                  if(oilCharge< 1)
                    throw CustomException("Oil Charge is less than 1");
                ServicingList.push_back(new OilChange(name, vehicleNo, mobile, oilname, oilCharge));
                break;
            }
             break;
            case 2:
            { 
            cout << "Enter Part Name: ";
            cin >> partName;
            cout << "Enter Part Price: ";
            cin >> partPrice;
            if(partPrice < 1)
               throw CustomException("Part Price must be greater than zero");
            cout << "Enter Labor Charge: ";
            cin >> laborCharge;
             if(laborCharge < 1)
               throw CustomException("laborCharge must be greater than zero");
            ServicingList.push_back(new Maintenance(name, vehicleNo, mobile, partName, partPrice, laborCharge));
        break;
            }
          }
          }catch(CustomException c){
            c.printErrorMessage();
        }
          break; 
        case 2: 
            {  int choice2;
                cout<<"1. Maintenance of vehicle"<<endl;
                cout<<"2. Oil Change of vehicle"<<endl;
                cout<<"Enter your choice - ";
                cin >> choice2;
                switch(choice2) {
                 case 1:
                     for (int i = 0; i < ServicingList.size(); i++){
                        if(typeid(*ServicingList[i]) == typeid(Maintenance)){
                         ServicingList[i]->display();
                        } 
                     } 
                    break;
                case 2: 
                   for (int i = 0; i < ServicingList.size(); i++){
                    if(typeid(*ServicingList[i]) == typeid(OilChange)){
                         ServicingList[i]->display();
                        }         
                   }   
                    break;
                }
            }
            break;
        case 3:
            {   cout<<"Enter the Vehicle Number :"<<endl; 
                cin>>vehicleNo;
                bool flag = true;
                for(int i = 0; i < ServicingList.size(); i++){
                    if(ServicingList[i]->getVehicleNo() == vehicleNo){
                        flag = false;
                        cout<<"Vehicle No is "<<vehicleNo<<endl;
                        ServicingList[i]->CalculateTotalBill();
                        break;
                    }
                }
                if(flag){
                    cout<<"Vehicle No is "<<vehicleNo<<" is not Founds...."<<endl;
                }
            }
            break;
        case 4:
            {
                
            }
            break;
        default:
            cout << "Wrong choice..." << endl;
            break;
        }
    }

     for (int i = 0; i < ServicingList.size(); i++)
        delete ServicingList[i];
    return 0;
};




//cout<<"/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/"<<endl;

/*
int menu()
{
    int choice;*/
    //cout<<"*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/"<<endl;
   /*cout<<endl;
    cout << "1. Add ----" << endl;
    cout << "2. Display " << endl;
    cout << "3. " << endl;
    cout << "4. " << endl;
    cout << "Enter your choice - ";
    cin >> choice;*/

    //cout<<"*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/"<<endl;
   /* cout<<endl;

    return choice;
}
cout<<"******************************************"<<endl;
    cout<<endl;
   while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1:
        {
        }
        break;
        case 2:
            {

            }
            break;
        case 3:
            {

            }
            break;
        case 4:
            {
                
            }
            break;
        default:
            cout << "Wrong choice..." << endl;
            break;
        }
    }

     for (int i = 0; i < ; i++)
        delete [i];
*/