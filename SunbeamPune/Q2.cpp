#include<iostream>
#include<vector>
#include<typeinfo>
using namespace std;

class Person{
    string name;
    int age;

    public:
    Person(string name, int age){
        this->name = name;
        this->age = age;
    }
    virtual void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
    void setName(string name){
        this->name = name;
    }
    void setAge(int age){
        this->age = age;
    }
    string getName(){
        return name;
    }

};

class Player:public Person{
    int playerId;
    string mobile;

    public:
    Player(string name, int age, int playerId, string mobile):Person(name, age){
        this->playerId = playerId;
        this->mobile = mobile;
    }
    void display(){
        cout<<"Player Id: "<<playerId<<endl;
        Person::display();
        cout<<"Mobile: "<<mobile<<endl;
    }
    void setPlayerId(int playerId){
        this->playerId = playerId;
    }
    void setMobile(string mobile){
        this->mobile = mobile;
    }
    int getPlayerId(){
        return this->playerId;
    }
    string getMobile(){
        return this->mobile;
    } 
};
class Sports{
    string sportsName;
    double fees;
    vector<Player *> players;
    public:
    Sports(string sportsName, double fees){
        this->sportsName = sportsName;
        this->fees = fees;
    }
    void display(bool code){
        if(code){
        cout<<"Sports Name: "<<sportsName<<endl;
        cout<<"Fees: "<<fees<<endl;
        cout<<"*-*-*-*-*-*-*-*-*-*-*"<<endl;
        displayPlayers();
        }
        else {
            cout<<"Sports Name: "<<sportsName<<endl;
            cout<<"Fees: "<<fees<<endl;
            cout<<"*-*-*-*-*-*-*-*-*-*-*"<<endl;
        }
          
    }
    void setSportsName(string sportsName){
        this->sportsName = sportsName;
    }
    vector<Player *> getPlayers()
    {
        return this->players;
    }
    void setFees(double fees){
        this->fees = fees;
    }
    void addPlayer(Player *player){
        players.push_back(player);
    }
    void displayPlayers(){
        for(int i=0; i<players.size(); i++){
            players[i]->display();
        }
     }
    string getSportsName(){
        return this->sportsName;
    } 
};
 int menu()
{
    int choice;
    cout << "************************************************"<<endl;
    cout << "1. Add Sports----" << endl;
    cout << "2. Add Players " << endl;
    cout << "3. Enroll Player into the sports" << endl;
    cout << "4. Take player name and display sports" << endl;
    cout << "5.display all "<<endl;
    cout << "Enter your choice - ";
    cin  >> choice;
    cout << "*************************************************"<<endl;

    return choice;
};
int main(){
    vector<Sports *> sportsList;
    vector<Player *> players;
    string name;
    string sportsName;
    double fees;
    int age;
    int choice;
    int playerId;
    string mobile;
     while ((choice = menu()) != 0)
    {
        switch (choice)
        {
        case 1://1. Add Sports
        {
            cout << "Enter sports name - ";
            cin >> sportsName;
            cout << "Enter fees - ";
            cin >> fees;
            Sports *sports = new Sports(sportsName, fees);
            sportsList.push_back(sports);
            break;
        }
        break;
        case 2://Add Players
            {   
                cout << "Enter ID -";
                cin>>playerId;
                cout << "Enter name - ";
                cin >> name;
                cout << "Enter age - ";
                cin >> age;
                cout << "Enter The Mobile No -";
                cin>>mobile;
                Player *player = new Player(name, age, playerId, mobile);
                players.push_back(player);
                break;
            }
            break;
        case 3: 
        {       int index=0;
                bool flag = false;
                cout<<"Enter Sports name ";
                cin>>sportsName;
                  for(int i=0 ; i<sportsList.size(); i++){
                    if(sportsList[i]->getSportsName() == sportsName){
                         flag=true;
                         index=i;
                      break;
                    }
                  }
                if(flag){  
                cout << "Enter Player ID - ";
                cin >> playerId;
                for(int i=0; i<players.size(); i++){
                    if(players[i]->getPlayerId() == playerId){
                        sportsList[index]->addPlayer(players[i]);
                        break;
                    }
                 }
                }
                else{
                    cout<<"Sports not found"<<endl;
                }
        }   
                break;
        case 4://take player name from user and display sports list
            {
                cout<<"Enter The Player Name :: "<<endl;
                cin>>name;
                cout<<"Player Name :: "<<name<<endl;
                cout<<"List Of Sports :: "<<endl;
                for(int i=0; i<sportsList.size(); i++){
                   for(int j=0; j<sportsList[i]->getPlayers().size(); j++){
                       if(sportsList[i]->getPlayers().at(j)->getName() == name){
                           sportsList[i]->display(false);
                           break;
                       }
                   }
                }
            }
            break;
        case 5://display all
          {
            for(int i=0; i<sportsList.size(); i++){
                sportsList[i]->display(true);
          } 
         cout<<"**********************************"<<endl;
          for(int i=0; i<players.size(); i++){
                players[i]->display();
          } 
          }
          break;   
        default:
            cout << "Wrong choice..." << endl;
            break;
        }
    }

     for (int i = 0; i < sportsList.size() ; i++)
        delete sportsList[i];
     for(int i = 0; i < players.size();i++){
         delete players[i];
     }   
    return 0;
}; 