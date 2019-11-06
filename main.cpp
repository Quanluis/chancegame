#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Game {
    private: 
        int balance, rolledVal;
        char rollagain;

    public: 

        // Constructor
        Game(){
            cout << "Running Game..." << endl;
            again();
        }

        // Game function prototypes 

        int setbalance();
        int roll();
        int display();
        void again();

};

//Game member function implementation

int Game::setbalance(){
    int balance;

    cout << "Enter your starting balance (minimum of $1) :" << endl;
    cin >> balance;

    while(balance <= 0){
        cout << "Invalid amount entered, try again:";
        cin.clear();
        cin.ignore(1200, '\n');
        cin >> balance;
    }
    return balance;
}

int Game::display(){

    int balance = setbalance();

    cout << "Balance = $" << balance << endl;

    int rolledVal = roll();

    if(rolledVal % 2 == 0){
        cout << "Even number" << endl;
        cout << "You win $1" << endl;
        balance = balance + 1;
    } else {
        balance = balance - 1;
        cout << "Odd" << endl;
    }  
    cout << "Current Balance is: $" << balance << endl;

    return balance;
}

int Game::roll(){

    srand(time(0));
    int rolledVal =  1 + (rand() % 6);
    
    cout << "Rolling..." << endl;

    cout << rolledVal << endl;

    return rolledVal;
}

void Game::again(){

    char answer;

    int balance = display();

    while(balance > 0){
        cout << "Roll again?";
        cin >> answer;

        if(answer == 'Y' || answer == 'y'){
            cout << "Game running" << endl;
            int rolledVal = roll();

        if(rolledVal % 2 == 0){
        cout << "Even number" << endl;
        cout << "You win $1" << endl;
        balance = balance + 1;
        } else {
        balance = balance - 1;
        cout << "Odd" << endl;
        }  
        cout << "Current Balance is: $" << balance << endl;

        } else if(answer == 'N' || answer == 'n'){
            break;
        } else {
            cout << "Invalid answer try again (y = yes, n = no)";
            cin.clear();
            cin.ignore(1200, '\n');
            cin >> answer;
            continue;
        }
    } 
    cout << "Game over. Ending Balance = $" << balance;
}

int main(){

    Game m;

    return 0;
}