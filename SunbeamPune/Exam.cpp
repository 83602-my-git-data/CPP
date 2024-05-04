#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Player {
private:
    int playerNo;
    string playerName;
public:
    Player(int no, string name){
        this->playerNo = no;
        this->playerName = name;
    }

    int getPlayerNo() {
        return playerNo;
    }
    string getPlayerName() {
        return playerName;
    }
    void setPlayerNo(int no) {
        playerNo = no;
    }
    void setPlayerName(string name) {
        playerName = name;
    }

    virtual void display() = 0;
    virtual int calculateIncome() = 0;
};

class FootballPlayer : public Player {
private:
    int matchCount;
    int goalsCount;
public:
    FootballPlayer(int no, string name, int matches, int goals) : Player(no, name) {
        this->matchCount = matches;
        this->goalsCount = goals;
    }

    void display() {
        cout << "Player No: " << Player::getPlayerNo() << ", Player Name: " << Player::getPlayerName() << ", Matches Played: " << matchCount << ", Goals Scored: " << goalsCount << endl;
    }

    int getMatchCount() { 
        return matchCount; 
        }
    int getGoalsCount() {
         return goalsCount; 
         }
    void setMatchCount(int matches) { 
        matchCount = matches; 
        }
    void setGoalsCount(int goals) { 
        goalsCount = goals; 
        }
    int calculateIncome() {
        int income = matchCount * 1000;
        if (goalsCount > 0)
            income += goalsCount * 2000;
        return income;
    }
};

class CricketPlayer : public Player {
private:
    int matchCount;
    int manOfTheMatchCount;
public:
    CricketPlayer(int no, string name, int matches, int momCount) : Player(no, name){
        this->matchCount = matches;
        this->manOfTheMatchCount = momCount;
    }

    void display() override {
        cout << "Player No: " << Player::getPlayerNo() << ", Player Name: " << Player::getPlayerName() << ", Matches Played: " << matchCount << ", Man of the Match Count: " << manOfTheMatchCount << endl;
    }

    int getMatchCount() {
        return matchCount;
    }
    int getManOfTheMatchCount() {
        return manOfTheMatchCount;
    }
    void setMatchCount(int matches) {
        matchCount = matches;
    }
    void setManOfTheMatchCount(int momCount) {
        manOfTheMatchCount = momCount;
    }


    int calculateIncome() override {
        int income = matchCount * 2000;
        if (manOfTheMatchCount > 0)
            income += manOfTheMatchCount * 3000;
        return income;
    }
};

int main() {
    vector<Player*> players;
    int choice;
    do {
        cout << "Menu:"<<endl;
        cout <<" 0. Exits " << endl;
        cout << "1. Add FootballPlayer"<<endl;
        cout << "2. Add CricketPlayer"<<endl;
        cout << "3. Display count of players according to their Types"<<endl;
        cout << "4. Display All Players"<<endl;
        cout << "5. Display all FootballPlayers"<<endl;
        cout << "6. Display all CricketPlayers"<<endl;
        cout << "7. Calculate income of each Types of Player " << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int playerNo, matchCount, goalsCount;
                string playerName;
                cout << "Enter player number: ";
                cin >> playerNo;
                cout << "Enter player name: ";
                cin >> playerName;
                cout << "Enter matches played: ";
                cin >> matchCount;
                cout << "Enter goals scored: ";
                cin >> goalsCount;
                FootballPlayer *footballplayer = new FootballPlayer(playerNo, playerName, matchCount, goalsCount);
                players.push_back(footballplayer);
                break;
            }
            case 2: {
                int playerNo, matchCount, momCount;
                string playerName;
                cout << "Enter player number: ";
                cin >> playerNo;
                cout << "Enter player name: ";
                cin >> playerName;
                cout << "Enter matches played: ";
                cin >> matchCount;
                cout << "Enter man of the match count: ";
                cin >> momCount;
                CricketPlayer *cricketplayer = new CricketPlayer(playerNo, playerName, matchCount, momCount);
                players.push_back(cricketplayer);
                break;
            }
            case 3: {
                int footballPlayers = 0, cricketPlayers = 0;
                for (Player* p : players) {
                    if (dynamic_cast<FootballPlayer*>(p))
                        footballPlayers++;
                    else if (dynamic_cast<CricketPlayer*>(p))
                        cricketPlayers++;
                }
                cout << "Football Players: " << footballPlayers << ", Cricket Players: " << cricketPlayers << endl;
                break;
            }
            case 4: {
                cout << "All Players:"<<endl;
                for (Player* p : players) {
                    p->display();
                }
                break;
            }
            case 5: {
                cout << "Football Players:"<< endl;
                for (Player* p : players) {
                    if (dynamic_cast<FootballPlayer*>(p))
                        p->display();
                }
                break;
            }
            case 6: {
                cout << "Cricket Players:\n";
                for (Player* p : players) {
                    if (dynamic_cast<CricketPlayer*>(p))
                        p->display();
                }
                break;
            }
            case 7: {
                cout << "Income of each Types of Player:\n";
                for (Player* p : players) {
                    cout << "Player Name: " << p->getPlayerName() << ", Income: " << p->calculateIncome() << endl;
                }
                break;
            }
            case 8: {
                cout << "Exiting...\n";
                break;
            }
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 0);

    for (Player* p : players) {
        delete p;
    }

    return 0;
}
