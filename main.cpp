#include <iostream>
using namespace std;

class Game {
    private: 
        int balance, rolledVal;
        char rollagain;

    // Game function prototypes 

    // void validateBalance();
    // void validateAgain();

    public: 

        // Constructor
        Game(){
            cout << "Running Game..." << endl;
        }

        // Game function prototypes 

        int setbalance();
        void roll();
        // void display();
        // void again();

};

//Game member function implementation

int Game::setbalance(){
    int balance;

    cout << "Enter balance, min of $1" << endl;
    cin >> balance;

    while(balance <= 0){
        cout << "Try again: ";
        cin.clear();
        cin.ignore(1200, '\n');
        cin >> balance;
    }
    return balance;
}

void Game::roll(){
    
    int balance = setbalance();
    cout << "Current Balance: " << balance << endl;
    cout << "Rolling..." << endl;
    
}


int main(){

    Game m;
    
    m.roll();

    return 0;
}