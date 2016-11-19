//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Geoff Markley on 16/11/2016.
//  Copyright © 2016 Geoff Markley. All rights reserved.
//

#include "FBullCowGame.hpp"

FBullCowGame::FBullCowGame() // overrides the class definition defaults
{
    Reset();
}

void FBullCowGame::Reset()  // Reset the values
{
    constexpr int MAX_TRIES = 8 ;
    MyCurrentTry = 1;
    MyMaxTries = MAX_TRIES;
}

int FBullCowGame::GetMaxTries() const {
    
    return MyMaxTries;
}

int FBullCowGame::GetCurrentTry() const{
    return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const {
    return true;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
    return true;
}
