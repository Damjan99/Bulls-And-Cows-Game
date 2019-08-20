#pragma once
#include <string>
using string = std::string;

struct BullCowCount
{
    int Bulls=0;
    int Cows=0;
};

enum class GuessStatus
{
    Invalid_Status,
    OK,
    Not_Isogram,
    Wrong_Length,
    Not_Lowercase
};

class BullCowGame
{
    
public:
    BullCowGame();
    string GetHiddenWord();
    int GetHiddenWordLength() const;
    int GetMaxTries() const;
    int GetCurrentTry() ;
    bool IsGameWon() const;
    GuessStatus CheckGuessValidity(string) const;
    void Reset();
    BullCowCount SubmitGuess(string);
    string GetRandomWord();
    
private:
    int MyCurrentTry;
    string MyHiddenWord;
    bool bGameIsWon;
    bool IsIsogram(string) const;
    bool IsLowercase(string) const;
};
