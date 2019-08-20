#include "BullsAndCows.hpp"
#include <iostream>
#include <map>
#include <cstdlib>
#include <ctime>
#define TMap std::map


string BullCowGame::GetHiddenWord()
{
    return MyHiddenWord;
}

BullCowGame::BullCowGame()
{
    Reset();
}

bool BullCowGame::IsGameWon() const
{
    return bGameIsWon;
    
}

int BullCowGame::GetMaxTries() const
{
    TMap<int, int> WordLengthToMaxTries{ {3,8}, {4,10}, {5,12}, {6,14}, {7,16} , {8,18} , {9,20}, {10,25} };
    return WordLengthToMaxTries[MyHiddenWord.length()];
}

int BullCowGame::GetCurrentTry() 
{
  
    return MyCurrentTry;
}

void BullCowGame::Reset()
{
    MyHiddenWord=GetRandomWord();
    MyCurrentTry = 1;
    bGameIsWon = false;
    return;
}

string BullCowGame::GetRandomWord()
{
    string words[] = { "random", "game", "habit", "coding","champion","caption",
        "box",  "math", "swing", "jungle", "house", "picture", "table","smoke","cream",
        "project", "think", "graphics","ilter","dream","rice","update","store","peach",
        "company", "cow", "milk", "tea", "job", "cake","wish","water","mouse","candy",
        "movie", "story", "myth","duck","verb","black","ight","leopard","time","peanut",
        "article", "music", "script",  "key", "sun", "age", "joy", "volume","trip",
        "orange", "planet",  "outside","boat","sound","orest", "action","land","rapid",
        "ast","capture","cage","suitcase","chair","blanket","minute","hour","shoe",
        "keyboard", "display", "cornlakes","pen","bread","yoghurt","ocean","night",
        "computer", "string", "super","woman","lamp","salt","insult","work","guest",
        "ish", "lizard", "mouth", "triangle","vector","singer","shop","bike","lea",
        "cup",  "company", "marketing", "video","ormat","touch","single","quiet",
        "lamp",  "menu", "pencil", "palindrome","jacket","cloud","phone","king","number",
        "side","slide","slope","rame","rating","dynamic","country","city","plate","grape"};
    
    srand(time(0));
    int size = sizeof(words)/sizeof(std::string);
    string NewWord = words[rand() % size];
    return NewWord;
}

GuessStatus BullCowGame::CheckGuessValidity(string Guess) const
{
    if (!IsIsogram(Guess))
    {
        return GuessStatus::Not_Isogram;
    }
    
   else if (!IsLowercase(Guess))
    {
        return GuessStatus::Not_Lowercase;
    }
    
    else if (Guess.length() != GetHiddenWordLength())
    {
        return GuessStatus::Wrong_Length;
    }
    
    else
    {
        return GuessStatus::OK;
    }
}

BullCowCount BullCowGame::SubmitGuess(string Guess)
{
    MyCurrentTry++;
    BullCowCount BullCowCount;
    int WordLength = MyHiddenWord.length();
  
    for (int i = 0; i < WordLength; i++)
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

int BullCowGame::GetHiddenWordLength() const
{
    return MyHiddenWord.length();
}

bool BullCowGame::IsIsogram(string Word) const
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

bool BullCowGame::IsLowercase(string Word) const
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
