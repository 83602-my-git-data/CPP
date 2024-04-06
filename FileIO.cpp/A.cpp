#include <iostream>
#include <vector>
using namespace std;

class Vehicle
{
    private:
    string companyName;
    string modelName;
    int servicingPrice;
    public:
    Vehicle(string companyName, string modelName, int servicingPrice)
    {
        this->companyName = companyName;
        this->modelName = modelName;
        this->servicingPrice = servicingPrice;
    }
    virtual void display()
    {
        cout << "Company Name: " << companyName << endl;
        cout << "Model Name: " << modelName << endl;
        cout << "Individual Bill: " << servicingPrice << endl;
        cout << endl;
    }
    void setCompanyName(string companyName)
    {
        this->companyName = companyName;
    }
    void setModelName(string modelName)
    {
        this->modelName = modelName;
    }
    void setServicingPrice(int servicingPrice)
    {
        this->servicingPrice = servicingPrice;
    }
    string getCompanyName()
    {
        return companyName;
    }
    string getModelName()
    {
        return modelName;
    }
    int getServicingPrice()
    {
        return servicingPrice;
    }
    virtual void calculateBill()=0;
};

class MotorCar : public Vehicle{
    private:
    string type;
    int seatingCapacity;
    
    public:
    MotorCar(string companyName, string modelName, string type, int seatingCapacity) : Vehicle(companyName, modelName,500)
    {
        this->type = type;
        this->seatingCapacity = seatingCapacity;
    }
    void display()
    {
        Vehicle::display();
        cout << "Type: " << type << endl;
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << endl;
    }
    void setType(string type)
    {
        this->type = type;
    }
    void setSeatingCapacity(int seatingCapacity)
    {
        this->seatingCapacity = seatingCapacity;
    }
    string getType()
    {
        return type;
    }
    int getSeatingCapacity()
    {
        return seatingCapacity;
    }
    void calculateBill(){
        if(seatingCapacity > 4){
            Vehicle::setServicingPrice(Vehicle::getServicingPrice()+200) ;
        }
        else{
           Vehicle::setServicingPrice(Vehicle::getServicingPrice()) ;
        }
    }
};

class MotorCycle : public Vehicle{
    private:
      int cc;
      public:
      MotorCycle(string companyName, string modelName, int cc) : Vehicle(companyName, modelName,300)
      {
        this->cc = cc;
      }
      void display()
      {
         Vehicle::display();
         cout<<"MotorCycle cc is "<<cc<<endl;
         cout << endl;
      }
          
      void calculateBill(){
        if(cc > 110){
            Vehicle::setServicingPrice(Vehicle::getServicingPrice()+100) ;
        }
        else{
           Vehicle::setServicingPrice(Vehicle::getServicingPrice()) ;
        }
      }
};

class CustomException{
    string messages;

    public:
      CustomException(string messages){
        this->messages = messages;
      }
     void display(){
        cout<<"ERROR IS  "<<messages<<endl;
      }
};


int menu()
{
 
    int choice;
    cout<<"***************************"<<endl;
    cout<<endl;
    cout << "1. Add a MotorCar." << endl;
    cout << "2. Add a MotorCycle." << endl;
    cout << "3. Display all vehicles serviced along with their individual bill." << endl;
    cout << "4. Calculate total revenue of service station" << endl;
    cout << "5. " << endl;
    cout << "Enter your choice - ";
    cin >> choice;
    cout<<"***************************"<<endl;
    return choice;
}


int main(){
    int choice;
    string companyName, modelName,type;
     int cc,seatingCapacity;
     int totalRevenue;
    vector<Vehicle *> vehiclelist;
    cout<<"******************************************"<<endl;
    cout<<endl;
   while ((choice = menu()) != 0)
    {
        switch (choice)
        {
          case 1:{
            //1. Add a MotorCar.
            try{
            cout << "Enter company name - ";
            cin >> companyName;
            cout << "Enter model name - ";
            cin >> modelName;
            cout << "Enter type -(cng, petrol, diesel) ";
            cin >> type;
            cout << "Enter seating capacity - ";
            cin >> seatingCapacity;
            if(seatingCapacity <2)
              throw CustomException("Seating capacity is less than 2");
            if(type == "cng" || type == "petrol" || type == "diesel"){
                MotorCar *motorCar = new MotorCar(companyName, modelName, type, seatingCapacity);
                motorCar->calculateBill();
                vehiclelist.push_back(motorCar);
            }
            else{
                throw CustomException("Invalid Type");
            }
            }catch(CustomException c){
                c.display();
            }
          }
           break;
          case 2:{
            //2. Add a MotorCycle.
            try{
                cout << "Enter company name - ";
                cin >> companyName;
                cout << "Enter model name - ";
                cin >> modelName;
                cout << "Enter cc - ";
                cin >> cc;
                if(cc < 90){
                    throw CustomException("Engine capacity is less than 90cc");
                }
                MotorCycle *motorCycle = new MotorCycle(companyName, modelName, cc);
                motorCycle->calculateBill();
                vehiclelist.push_back(motorCycle);

            }catch(CustomException c){
                c.display();
            }
          }
           break;
          case 3:{
            //3. Display all vehicles serviced along with their individual bill.
            for(int i=0;i<vehiclelist.size();i++){
                vehiclelist[i]->display();
            }
          }
           break;
          case 4:{
            //4. Calculate total revenue of service station.
            totalRevenue = 0;
            for(int i=0;i<vehiclelist.size();i++){
                totalRevenue += vehiclelist[i]->getServicingPrice();
            }
            cout << "Total Revenue: " << totalRevenue << endl;
          }
           break;
          default:
            cout << "Wrong choice..." << endl;
            break;
        }
    }
    for(int i=0;i<vehiclelist.size();i++){
        delete vehiclelist[i];
    }
return 0;
}
