//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Geoff Markley on 16/11/2016.
//  Copyright © 2016 Geoff Markley. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <stdio.h>
#include <string>

#endif /* FBullCowGame_hpp */


class FBullCowGame
{
    
public:
    
    FBullCowGame(); // constructor
    
    
    // public methods
    // Getters - constant functions
    int GetMaxTries() const;
    int GetCurrentTry() const;
    bool IsGameWon() const;
    
    // functions to change values
    void Reset();  // TO DO make a richer return value
    bool CheckGuessValidity(std::string);
        
private: // Keep the variables private
    int MyCurrentTry ;  // initialised in the constructor
    int MyMaxTries ;
    bool IsIsogram();
};
