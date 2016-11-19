//
//  main.cpp
//  BullCowGame
//
//  Created by Geoff Markley on 12/11/2016.
//  Copyright © 2016 Geoff Markley. All rights reserved.
//


// Include libraries
#include <iostream>
#include <string>
#include "FBullCowGame.hpp"


// specify namespaces to use
//using namespace std;

// Forward declarations

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

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

void PlayGame()
{
    // Play the game
    
    BCGame.Reset();
    int MaxTries = BCGame.GetMaxTries();
    std::cout << MaxTries << std::endl;
  
    //constexpr int NUMBER_OF_TURNS = 5;
    // loop for number of turns asking for guesses
    for(int i=1; i<= MaxTries;i++)
    {
        std::string Guess = GetGuess();
        std::cout << "Your guess was: " << Guess << std::endl << std::endl;
        
    }
    
     // TODO : add a game summary
}

// print game introduction
void PrintIntro()
{
    constexpr int WORD_LENGTH = 9;
    
    // introduce the game
    std::cout  << "Welcome to Bulls and Cows.\n" ;
    std::cout << "Can you guess the " << WORD_LENGTH;
    std::cout << " letter isogram I'm thinking of?\n";
    return;   // void no return
    
}

// get a guess from the user
std::string GetGuess()
{
    int CurrentTry = BCGame.GetCurrentTry();
    std::string Guess = "";
    
    std::cout << "Try " << CurrentTry << ". Enter your guess: ";
    std::getline(std::cin, Guess);
    return Guess;
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again?";
    std::string Response = "";
    std::getline(std::cin,Response);
    
    //cout << "Is it Y?" << (Response[0] == 'y');
    //cout << endl;
    return (Response[0] == 'y' || Response[0] == 'Y');
 
   
}
