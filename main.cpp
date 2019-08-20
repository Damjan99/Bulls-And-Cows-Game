#include <iostream>
#include <string>
#include "BullsAndCows.hpp"
using namespace std;

void PrintIntro();
void AskGuess();
void PlayGame();
void PrintInstructions();
void PrintGameSummary();
bool AskorInstructions();
bool AskToPlayAgain();
string GetValidGuess();
BullCowGame BCGame;

int main()
{
    PrintIntro();
    bool Instructions = AskorInstructions();
    if (Instructions)
        PrintInstructions();
    
    bool PlayAgain = false;
    
    do {
        AskGuess();
        PlayGame();
        PlayAgain = AskToPlayAgain();
        } while (PlayAgain);
    
    return 0;
}

void AskGuess()
{
    int WORD_LENGTH = BCGame.GetHiddenWordLength();
    cout << endl<< "Can you guess the " << WORD_LENGTH;
    cout << " letter isogram (noun) I am thinking of?\n";
    cout << endl;
}

void PlayGame()
{
    int MaxTries = BCGame.GetMaxTries();
    while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
    {
        string Guess = GetValidGuess();
        BullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
        cout << "Bulls = " << BullCowCount.Bulls;
        cout << " | Cows = " << BullCowCount.Cows << endl;
        cout << endl;
    }
    PrintGameSummary();
    BCGame.Reset();
    return;
}

string GetValidGuess()
{
    string Guess = "";
    GuessStatus Status = GuessStatus::Invalid_Status;
    
    do {
        int CurrentTry = BCGame.GetCurrentTry();
        cout << "Try " << CurrentTry << " o " << BCGame.GetMaxTries();
        cout << ". Enter your guess: ";
        getline(cin, Guess);
        Status = BCGame.CheckGuessValidity(Guess);
        switch (Status)
        {
            case GuessStatus::Wrong_Length:
                cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
                break;
                
           case GuessStatus::Not_Isogram:
                cout << "Please enter a word without repeating letters.\n";
                break;
                
            case GuessStatus::Not_Lowercase:
                cout << "Please enter all lowercase letters.\n";
                break;
                
            deault:
                break;
        }
        cout << endl;
    } while (Status != GuessStatus::OK);
    
    return Guess;
}

bool AskToPlayAgain()
{
     string Response = "";
    cout << "Do you want to play again (yes/no)? ";
    getline(cin, Response);
    
    if (Response=="yes")
        return true;
    
    cout<<endl<<"Thanks for playing!"<<endl<<endl<<endl;
    cout<<endl<<endl<<endl<<endl;
    return false;
}

void PrintGameSummary()
{
    if (BCGame.IsGameWon())
    {
        cout << "CORRECT! - YOU WIN!\n";
    }
    else
    {
        cout << "You lost :(  The word was: "<<BCGame.GetHiddenWord()<<endl;
    }
}

void PrintIntro()
{
    cout << "Welcome to Bulls and Cows, a un word game!\n";
    cout << endl;
    cout << "          }___{         ___ " << endl;
    cout << "          (o o)        (o o) " << endl;
    cout << "   /-------\\ /          \\ /-------\\ " << endl;
    cout << "  / | BULL |O            O| COW  | \\ " << endl;
    cout << " *  |-,--- |              |------|  * " << endl;
    cout << "    ^      ^              ^      ^ " << endl<<endl;
}

void PrintInstructions()
{
    cout<<"An ISOGRAM is a word with no repeating letters."<<endl;
    cout<<"You need to guess a given isogram o a given length.\n";
    cout<<"Each BULL means you have guessed a correct letter in the correct place o the word.\n";
    cout<<"Each COW means you have guessed a correct letter in the wrong place o the word."<<endl;
    cout<<"The goal o the game is to guess the word within the given tries. Good luck!"<<endl;
    cout<<endl;
}

bool AskorInstructions()
{
        string Response = "";
        cout << "Do you want to see the instructions (yes/no)? ";
        getline(cin, Response);
        if (Response=="yes")
            return true;
    
        return false;
}
