#include "FBullsAndCows.hpp"
#include <iostream>
#include <map>
#include <cstdlib>
#include <ctime>
#define TMap std::map
using FString = std::string;
using int32 = int;
FString FBullCowGame::GetHiddenWord()
{
    return MyHiddenWord;
}

FBullCowGame::FBullCowGame()
{
    Reset();
}

bool FBullCowGame::IsGameWon() const
{
    return bGameIsWon;
    
}

int32 FBullCowGame::GetMaxTries() const
{
    TMap<int32, int32> WordLengthToMaxTries{ {3,8}, {4,10}, {5,12}, {6,14}, {7,16} , {8,18} , {9,20}, {10,25} };
    return WordLengthToMaxTries[MyHiddenWord.length()];
}

int32 FBullCowGame::GetCurrentTry() 
{
  
    return MyCurrentTry;
}

void FBullCowGame::Reset()
{
    MyHiddenWord=GetRandomWord();
    MyCurrentTry = 1;
    bGameIsWon = false;
    return;
}

FString FBullCowGame::GetRandomWord()
{
    FString words[] = { "random", "game", "habit", "coding","champion","caption",
        "box",  "math", "swing", "jungle", "house", "picture", "table","smoke","cream",
        "project", "think", "graphics","filter","dream","rice","update","store","peach",
        "company", "cow", "milk", "tea", "job", "cake","wish","water","mouse","candy",
        "movie", "story", "myth","duck","verb","black","fight","leopard","time","peanut",
        "article", "music", "script",  "key", "sun", "age", "joy", "volume","trip",
        "orange", "planet",  "outside","boat","sound","forest", "action","land","rapid",
        "fast","capture","cage","suitcase","chair","blanket","minute","hour","shoe",
        "keyboard", "display", "cornflakes","pen","bread","yoghurt","ocean","night",
        "computer", "string", "super","woman","lamp","salt","insult","work","guest",
        "fish", "lizard", "mouth", "triangle","vector","singer","shop","bike","leaf",
        "cup",  "company", "marketing", "video","format","touch","single","quiet",
        "lamp",  "menu", "pencil", "palindrome","jacket","cloud","phone","king","number",
        "side","slide","slope","frame","rating","dynamic","country","city","plate","grape"};
    
    srand(time(0));
    int32 size = sizeof(words)/sizeof(std::string);
    FString NewWord = words[rand() % size];
    return NewWord;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
    if (!IsIsogram(Guess))
    {
        return EGuessStatus::Not_Isogram;
    }
    
   else if (!IsLowercase(Guess))
    {
        return EGuessStatus::Not_Lowercase;
    }
    
    else if (Guess.length() != GetHiddenWordLength())
    {
        return EGuessStatus::Wrong_Length;
    }
    
    else
    {
        return EGuessStatus::OK;
    }
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
    MyCurrentTry++;
    FBullCowCount BullCowCount;
    int32 WordLength = MyHiddenWord.length();
  
    for (int32 i = 0; i < WordLength; i++)
    {
            if (Guess[i] == MyHiddenWord[i])
            {
                BullCowCount.Bulls++;
            }
               
            else if ((MyHiddenWord.find(Guess[i]) !=std::string::npos) && MyHiddenWord[i]!=Guess[i] )
            {
                    BullCowCount.Cows++;
            }
    }
    
    if (BullCowCount.Bulls == WordLength)
        bGameIsWon = true;
    
    else
        bGameIsWon = false;
    
    return BullCowCount;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
    return MyHiddenWord.length();
}

bool FBullCowGame::IsIsogram(FString Word) const
{
    if (Word.length() <= 1)
        return true;
    
    TMap<char, bool> LetterSeen;
    for (auto Letter : Word)
    {
        Letter = tolower(Letter);
        if (LetterSeen[Letter])
            return false;

        else
            LetterSeen[Letter] = true;
    }
   return true;
}

bool FBullCowGame::IsLowercase(FString Word) const
{
    for (auto Letter : Word)
    {
        if (!islower(Letter))
        {
            return false;
        }
    }
    return true;
}
