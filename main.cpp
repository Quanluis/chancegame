#include <iostream>
#include <cstdlib>
#include <ctime>
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
        int roll();
        int display();
        void again();

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

int Game::display(){

    int balance = setbalance();
    int rolledVal = roll();

    if(rolledVal % 2 == 0){
        cout << "Even number" << endl;
    } else {
        balance = balance - 1;
        cout << "Odd" << endl;
    }  
    cout << "Current Balance is: " << balance << endl;

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

}

int main(){

    int balance;

    Game m;

    balance = m.display();

    cout << balance << endl;

    return 0;
}