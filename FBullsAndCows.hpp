#pragma once
#include <string>
using int32 = int;
using FString = std::string;

struct FBullCowCount
{
    int32 Bulls=0;
    int32 Cows=0;
};

enum class EGuessStatus
{
    Invalid_Status,
    OK,
    Not_Isogram,
    Wrong_Length,
    Not_Lowercase
};

class FBullCowGame
{
    
public:
    FBullCowGame();
    FString GetHiddenWord();
    int32 GetHiddenWordLength() const;
    int32 GetMaxTries() const;
    int32 GetCurrentTry() ;
    bool IsGameWon() const;
    EGuessStatus CheckGuessValidity(FString) const;
    void Reset();
    FBullCowCount SubmitGuess(FString);
    FString GetRandomWord();
    
private:
    int32 MyCurrentTry;
    FString MyHiddenWord;
    bool bGameIsWon;
    bool IsIsogram(FString) const;
    bool IsLowercase(FString) const;
    
};
