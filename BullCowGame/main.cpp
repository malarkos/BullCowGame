//
//  main.cpp
//  BullCowGame
//
//  Created by Geoff Markley on 12/11/2016.
//  Copyright © 2016 Geoff Markley. All rights reserved.
//

/*
 This is the console executable that makes use of BullCow class. 
 This acts as the view in the MVC pattern and is responsible for all interaction.
 For game logic, see the FBullCowGame class.
 */

#pragma once

// Include libraries
#include <iostream>
#include <string>
#include "FBullCowGame.hpp"


// to make syntax Unreal friendly

using FText = std::string;  // make substituion
using int32 = int; // int is a primitive type so don't need std::

// specify namespaces to use
//using namespace std;

// Forward declarations and function prototypes

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame;  // Uninitialised

// entry point for the programme
int main(int argc, const char * argv[]) {
    
    
    
    do {
        PrintIntro();
        PlayGame();
    }
    while(AskToPlayAgain());
    
    return 0; // exit application
}


// Plays a single game to completion

void PlayGame()
{
    // Play the game
    
    BCGame.Reset();  // Reset all variables for a new game
    int32 MaxTries = BCGame.GetMaxTries();
    // loop asking for guesses until the game is won
    
    //for(int32 i=1; i<= MaxTries;i++)// TODO Make loop check for valid guess
    while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
    {
        FText Guess = GetValidGuess();
        // submit valid guess to the game
        
        FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess); // submit the guess
        
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
    }
    
     // TODO : add a game summary
    PrintGameSummary();
    return;
}

// print game introduction
void PrintIntro()
{
    // constexpr int32 WORD_LENGTH = 9;
    
    
    // introduce the game
    std::cout  << "\n\nWelcome to Bulls and Cows.\n" ;
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
    std::cout << " letter isogram I'm thinking of?\n";
    return;   // void no return
    
}

// loop through until get a valid guess from the user
FText GetValidGuess()  // TODO change to get ValidGuess
{
    
    EGuessStatus Status = EGuessStatus::Invalid;
    FText Guess = "";
    do {
        
        
        int32 CurrentTry = BCGame.GetCurrentTry();
        
        std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries() << ". Enter your guess: ";
        std::getline(std::cin, Guess);
        
        Status = BCGame.CheckGuessValidity(Guess);
        
        switch (Status)
        {
            case EGuessStatus::Wrong_Length:
                std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
                break;
            case EGuessStatus::Not_Isogram:
                std::cout << "Please enter an isogram.\n";  // TODO write function
                break;
            case EGuessStatus::Not_Lowercase:  //TODO write function
                std::cout << "Please enter the isogram all in lowercase.\n";
                break;
            case EGuessStatus::OK:
                break;
            default:
                // assume guess is valid
                break;
        }  //swithch
        std::cout << std::endl;
    } while (Status != EGuessStatus::OK);  // Keep looping until we get no error
    return Guess;
} // end of function

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again with the same hidden word (y/n)?";
    FText Response = "";
    std::getline(std::cin,Response);
    
    //cout << "Is it Y?" << (Response[0] == 'y');
    //cout << endl;
    return (Response[0] == 'y' || Response[0] == 'Y');
 
   
}

void PrintGameSummary() {
    
    //
    if (BCGame.IsGameWon())
    {
        std::cout << "Congralations - you WON!\n";
    } else{
        
        std::cout << "Better luck next time.\n";
    }
    return;
}
