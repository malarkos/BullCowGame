//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Geoff Markley on 16/11/2016.
//  Copyright © 2016 Geoff Markley. All rights reserved.
//
/*
    The game logic - no view code or direct user interaction.
    Game is simple word guess game based on Mastermind
 */

#pragma once

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <stdio.h>
#include <string>

// to make the syntax Unreal friendly
using FString = std::string;  // standard types
using int32 = int;

#endif /* FBullCowGame_hpp */


// Two integers initialised to zero.
struct FBullCowCount {
    
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EGuessStatus
{
    Invalid,
    OK,
    Not_Isogram,
    Wrong_Length,
    Not_Lowercase
};

class FBullCowGame
{
    
public:
    
    FBullCowGame(); // constructor
    
    
    // public methods
    // Getters - constant functions
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    bool IsGameWon() const;
    EGuessStatus CheckGuessValidity(FString) const;
        // functions to change values
    void Reset();
    
    
    FBullCowCount SubmitValidGuess(FString);    
    
        
private: // Keep the variables private
    int32 MyCurrentTry ;  // initialised in the constructor
    int32 MyMaxTries ;
    FString MyHiddenWord;
    bool IsIsogram(FString) const;
    bool IsLowerCase(FString) const;
    bool bIsGameWon;
    

    
};
