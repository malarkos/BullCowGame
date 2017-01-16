//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Geoff Markley on 16/11/2016.
//  Copyright © 2016 Geoff Markley. All rights reserved.
//
#pragma once

#include "FBullCowGame.hpp"

// to make the code Unreal friendly
#include <map>
#define TMap std::map

// Default constructor
FBullCowGame::FBullCowGame() // overrides the class definition defaults
{
    Reset();
}

void FBullCowGame::Reset()  // Reset the values
{
    constexpr int MAX_TRIES = 8 ;
    MyCurrentTry = 1;
    MyMaxTries = MAX_TRIES;
    const FString HIDDEN_WORD = "planet";  // This must be an isogram
    MyHiddenWord= HIDDEN_WORD;
    bIsGameWon = false;
}

int32 FBullCowGame::GetMaxTries() const {
    
    // Create a map of word lengths and max tries
    TMap<int32, int32> WordLengthtoMaxTries {{3,4},{4,7},{5,10},{6,16},{7,20}};
    
    return WordLengthtoMaxTries[MyHiddenWord.length()];
}

// returns the current try
int32 FBullCowGame::GetCurrentTry() const{
    return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const {
    return bIsGameWon;
}

bool FBullCowGame::IsIsogram(FString Word) const {
    
    
    // Treat 0 and 1 letter strings as Isograms
    if (Word.length() <= 1 ) {return true;}
    
    // setup our map
    
    TMap<char, bool> LetterSeen;  // set up map of char to bool
    
    for (auto Letter : Word)  // for all letters of Word, use auto because compiler knows the type
    {
        Letter = tolower(Letter);  // to handle mixed case
        
        // if letter is in the map
        if(LetterSeen[Letter]) { return false; } // do not have an Isogram return false
        else { LetterSeen[Letter] = true;}// add letter to the map
    
    }
    return true;  // Default value if we haven't failed all other tests.
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
    if (!IsIsogram(Guess)) // if guess isn't isogram - return error

    {
        return EGuessStatus::Not_Isogram;
    } else if (!IsLowerCase(Guess))
    {
        return EGuessStatus::Not_Lowercase; // if the guess isn't lower case - return error

    } else if (Guess.length() != GetHiddenWordLength())
    {
        return EGuessStatus::Wrong_Length;// if guess length is wrong, return error

    }
    
    else
    {
        return EGuessStatus::OK;   // otherwise return ok
    }
   
}

bool FBullCowGame::IsLowerCase(FString Word) const {
    
   
    // step through string
    // if not islower, return false
    for (auto Letter: Word)
    {
        if (!islower(Letter))
        {
            return false; // have upper case letter
        }
    }
    return true; // by default, return true
    
}

//Receives a valid guess
// Increments turn and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)

{
    MyCurrentTry++;// increment return value
    FBullCowCount BullCowCount; // increment return value
  
    // Loop through all letters in the Hidden word
    int32 WordLength = (int32) MyHiddenWord.length(); // assume same length as guess
    
    for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
    {
        // Compare letters against the guess
        for (int32 GChar=0; GChar < WordLength; GChar++)
        {
            // if they match then
            if (Guess[GChar] == MyHiddenWord[MHWChar]) {
               
                if (MHWChar == GChar) { // if in same place
                    BullCowCount.Bulls++;//  increment bulls ,

                }
                else {
                    //increment cows
                    BullCowCount.Cows++;  // must be a cow
                }
                
            }
        }
    }
    
    
    if (BullCowCount.Bulls == WordLength) {
        bIsGameWon = true;
    } else {
        bIsGameWon = false;
    }
    return BullCowCount;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
    return (int32)MyHiddenWord.length();
}


