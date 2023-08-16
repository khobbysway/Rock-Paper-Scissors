#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to get user's choice
string get_user_choice() {
    string choice;
            std::cout <<"       *=========================*\n";
            std::cout <<"       *  Rock Paper Scissors!   *\n";
            std::cout <<"       *=========================*\n";
    cout << "Enter rock, paper, or scissors: ";

    cin >> choice;
    while (choice != "rock" && choice != "paper" && choice != "scissors") {
        cout << "Invalid input. Enter rock, paper, or scissors: ";
        cin >> choice;
    }
    return choice;
}



// Function to get computer's choice
string get_computer_choice() {
    srand(time(NULL));  // Seed the random number generator
    int num = rand() % 3;
    if (num == 0) {
        return "rock";
    } else if (num == 1) {
        return "paper";
    } else {
        return "scissors";
    }
}

// Function to check who wins
string check_winner(string user_choice, string computer_choice) {
    if (user_choice == computer_choice) {
        return "Tie";
    } else if ((user_choice == "rock" && computer_choice == "scissors") || (user_choice == "paper" && computer_choice == "rock") || (user_choice == "scissors" && computer_choice == "paper")) {
        return "You win!";
    } else {
        return "Computer wins!";
    }
}

// Main function to play the game
int main() {
    while (true) {
        string user_choice = get_user_choice();
        string computer_choice = get_computer_choice();
        cout << "\nYou chose " << user_choice << ". Computer chose " << computer_choice << "." << endl;
        string result = check_winner(user_choice, computer_choice);
        cout << result << endl;
        string play_again;
        cout << "\nDo you want to play again? (yes/no) ";
        cin >> play_again;
        if (play_again != "yes") {
            cout << "Thanks for playing!" << endl;
            break;
        }
    }
    return 0;
}