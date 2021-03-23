//
//  Centennial.cpp
//  Centennial
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Centennial.h"
#include "Die.h"
#include "Player.h"
#include <iostream>
#include <string>
using namespace std;
namespace cs31
{
    // human goes first
    Centennial::Centennial() : isHumanTurn( true )
    {
        
    }
    
    // prints the state of the game play with each round of play
    std::string Centennial::display( std::string msg )
    {
        using namespace std;
        std::string s( "" );
        if (isHumanTurn)
        {
            s += "Human-";
            s += mHuman.whatWasRolled();
        }
        else
        {
            s += "Computer-";
            s += mComputer.whatWasRolled();
        }
        s += mBoard.display();

        if (isGameOver())
        {
            if (determineGameOutcome() == HUMANWONGAME)
            {
                s = s + "\n\t\tyou won Centennial!\n";
            }
            else
            {
                s = s + "\n\t\tyou lost Centennial!\n";
            }
        }
        else
        {
            s = s + msg;
        }
        return( s );
    }
    
    // CS 31 TODO: randomly play a human turn in the game
    void Centennial::humanPlay( ){
        // mark that it is the human's turn => ONCE IT IS OVER NEED TO MARK NOT HUMAN TURN?????
        if ( isHumanTurn==true){
        // let the human player randomly roll
              mHuman.roll();
        // look at what was rolled and update the board spots accordingly
            Die d1, d2, d3;
            d1=mHuman.getDie1();
            d2=mHuman.getDie2();
            d3=mHuman.getDie3();
            int WhatDidYouRoll1=d1.getValue();
            int WhatDidYouRoll2=d2.getValue();
            int WhatDidYouRoll3=d3.getValue();
            int ComboFirstSecond=WhatDidYouRoll1+WhatDidYouRoll2;
            int ComboSecondTwo=WhatDidYouRoll2+WhatDidYouRoll3;
            int ComboFirstThird=WhatDidYouRoll1+WhatDidYouRoll3;
            int ComboAll=WhatDidYouRoll3+WhatDidYouRoll2+WhatDidYouRoll1;
            int HumArray[7]={WhatDidYouRoll1, WhatDidYouRoll2, WhatDidYouRoll3, ComboFirstSecond, ComboSecondTwo, ComboFirstThird, ComboAll};
                   // sort the array from smallest value to largest
            int indexOfNextSmallest=0;
            for (int index=0; index<6; index++){
                int min=HumArray[index];
                int indexOfMin=0;
                for(int index2=index+1; index2<7; index2++){
                    if (HumArray[index2]<min){
                        min=HumArray[index2];
                        indexOfMin=index2;
                        indexOfNextSmallest=indexOfMin;
                        int temp=HumArray[index];
                        HumArray[index]=HumArray[indexOfNextSmallest];
                        HumArray[indexOfNextSmallest]=temp;
                    } } }
            // then compare the spot comp is on to where it needs to be
                   for(int l=0; l<7; l++){
                    int k= HumArray[l];
                    int j=k-1;
                    if ((HumArray[l]==mHuman.whatSpotIsNeededNext()) && mBoard.getHumanSpot()==j){
                        
                        mBoard.setHumanSpot(k);
                        mHuman.rolled((k));
                        if(mBoard.getHumanSpot()==12){
                            mBoard.setGameOver(true);
                            mBoard.markHumanAsWinner();
                        }
                    } }
             isHumanTurn=false;
        }
    }
    // CS 31 TODO: force a certain roll in the human's turn of the game by cheating...
    void Centennial::humanPlay( Die d1, Die d2, Die d3 )
    {
       // mark that it is the human's turn => ONCE IT IS OVER NEED TO MARK NOT HUMAN TURN?????
             if ( isHumanTurn==true){
             // let the human player randomly roll
                   mHuman.roll(d1, d2, d3);
             // look at what was rolled and update the board spots accordingly
    int WhatDidYouRoll1=d1.getValue();
    int WhatDidYouRoll2=d2.getValue();
    int WhatDidYouRoll3=d3.getValue();
    int ComboFirstSecond=WhatDidYouRoll1+WhatDidYouRoll2;
    int ComboSecondTwo=WhatDidYouRoll2+WhatDidYouRoll3;
    int ComboFirstThird=WhatDidYouRoll1+WhatDidYouRoll3;
    int ComboAll=WhatDidYouRoll3+WhatDidYouRoll2+WhatDidYouRoll1;
    int HumArray[7]={WhatDidYouRoll1, WhatDidYouRoll2, WhatDidYouRoll3, ComboFirstSecond, ComboSecondTwo, ComboFirstThird, ComboAll};
           // sort the array from smallest value to largest
    int indexOfNextSmallest=0;
    for (int index=0; index<6; index++){
        int min=HumArray[index];
        int indexOfMin=0;
        for(int index2=index+1; index2<7; index2++){
            if (HumArray[index2]<min){
                min=HumArray[index2];
                indexOfMin=index2;
                indexOfNextSmallest=indexOfMin;
                int temp=HumArray[index];
                HumArray[index]=HumArray[indexOfNextSmallest];
                HumArray[indexOfNextSmallest]=temp;
            } } }
    // then compare the spot comp is on to where it needs to be
           for(int l=0; l<7; l++){
            int k= HumArray[l];
            int j=k-1;
            if ((HumArray[l]==mHuman.whatSpotIsNeededNext()) && mBoard.getHumanSpot()==j){
                
                mBoard.setHumanSpot(k);
                mHuman.rolled((k));
                if(mBoard.getHumanSpot()==12){
                    mBoard.setGameOver(true);
                    mBoard.markHumanAsWinner();
                }
            } }
        isHumanTurn=false;
             } }

    // CS 31 TODO: randomly play a computer turn in the game
    void Centennial::computerPlay( ){// mark that it is the human's turn => ONCE IT IS OVER NEED TO MARK NOT HUMAN TURN?????
    if ( isHumanTurn==false && isGameOver()==false){
          mComputer.roll(); // let the computer player randomly roll
    // look at what was rolled and update the board spots accordingly
        Die d1, d2, d3;
          d1=mComputer.getDie1();  d2=mComputer.getDie2(); d3=mComputer.getDie3();
                  int WhatDidCompRoll1=d1.getValue(); int WhatDidCompRoll2=d2.getValue(); int WhatDidCompRoll3=d3.getValue();
                  int ComboFirstSecond=WhatDidCompRoll1+WhatDidCompRoll2;
                  int ComboSecondTwo=WhatDidCompRoll2+WhatDidCompRoll3;
                  int ComboFirstThird=WhatDidCompRoll3+WhatDidCompRoll1;
                  int ComboAll=WhatDidCompRoll3+WhatDidCompRoll2+WhatDidCompRoll1;
                  int CompArray[7]={WhatDidCompRoll1, WhatDidCompRoll2, WhatDidCompRoll3, ComboFirstSecond, ComboSecondTwo, ComboFirstThird, ComboAll};
                  // sort the array from smallest value to largest
                  int indexOfNextSmallest=0;
                  for (int index=0; index<6; index++){
                      int min=CompArray[index];
                      int indexOfMin=0;
                      for(int index2=index+1; index2<7; index2++){
                          if (CompArray[index2]<min){
                              min=CompArray[index2];
                              indexOfMin=index2;
                              indexOfNextSmallest=indexOfMin;
                              int temp=CompArray[index];
                              CompArray[index]=CompArray[indexOfNextSmallest];
                              CompArray[indexOfNextSmallest]=temp;
                          } } }
                  // then compare the spot comp is on to where it needs to be
                         for(int l=0; l<7; l++){
                          int k= CompArray[l];
                          int j=k-1;
                          if ((CompArray[l]==mComputer.whatSpotIsNeededNext()) && mBoard.getComputerSpot()==j){
                              mBoard.setComputerSpot(k);
                              mComputer.rolled((k));
                              if(mBoard.getComputerSpot()==12){
                                  mBoard.setGameOver(true);
                                  mBoard.markComputerAsWinner();
                              }
                          } }
         isHumanTurn=true;
    }}
    
    // CS 31 TODO: force a certain roll in the computer's turn of the game by cheating...
   void Centennial::computerPlay( Die d1, Die d2, Die d3 )
{// mark that it is no longer the human's turn
        if ( isHumanTurn==false && isGameOver()==false){
            mComputer.roll(d1, d2, d3); // force the computer player to roll specific values
        // look at what was rolled and update the board spots accordingly
            d1=mComputer.getDie1();  d2=mComputer.getDie2(); d3=mComputer.getDie3();
            int WhatDidCompRoll1=d1.getValue(); int WhatDidCompRoll2=d2.getValue(); int WhatDidCompRoll3=d3.getValue();
            int ComboFirstSecond=WhatDidCompRoll1+WhatDidCompRoll2;
            int ComboSecondTwo=WhatDidCompRoll2+WhatDidCompRoll3;
            int ComboFirstThird=WhatDidCompRoll3+WhatDidCompRoll1;
            int ComboAll=WhatDidCompRoll3+WhatDidCompRoll2+WhatDidCompRoll1;
            int CompArray[7]={WhatDidCompRoll1, WhatDidCompRoll2, WhatDidCompRoll3, ComboFirstSecond, ComboSecondTwo, ComboFirstThird, ComboAll};
            // sort the array from smallest value to largest
            int indexOfNextSmallest=0;
            for (int index=0; index<6; index++){
                int min=CompArray[index];
                int indexOfMin=0;
                for(int index2=index+1; index2<7; index2++){
                    if (CompArray[index2]<min){
                        min=CompArray[index2];
                        indexOfMin=index2;
                        indexOfNextSmallest=indexOfMin;
                        int temp=CompArray[index];
                        CompArray[index]=CompArray[indexOfNextSmallest];
                        CompArray[indexOfNextSmallest]=temp;
                    } } }
            // then compare the spot comp is on to where it needs to be
                   for(int l=0; l<7; l++){
                    int k= CompArray[l];
                    int j=k-1;
                    if ((CompArray[l]==mComputer.whatSpotIsNeededNext()) && mBoard.getComputerSpot()==j){
                        mBoard.setComputerSpot(k);
                        mComputer.rolled((k));
                        if(mBoard.getComputerSpot()==12){
                            mBoard.setGameOver(true);
                            mBoard.markComputerAsWinner();
                        }
                    } }
             isHumanTurn=true;
        }}

    // CS 31 TODO: determine the current state of the game
    // Officially, the human won if that player has rolled 12,11,10,9,8,7,6,5,4,3,2 & 1
    // Officially, the computer won if that player has rolled 12,11,10,9,8,7,6,5,4,3,2 & 1
    // If neither, then the game is still underway
    Centennial::GAMEOUTCOME  Centennial::determineGameOutcome( ) const
    {
        GAMEOUTCOME result= GAMEOUTCOME::GAMENOTOVER;
        if(mBoard.isGameOver()==false){
        result= GAMEOUTCOME::GAMENOTOVER;
        }
        else if (mBoard.isGameOver()==true && mBoard.isHumanWinner()==false){
        result= GAMEOUTCOME::COMPUTERWONGAME;
        }
        else if (mBoard.isGameOver()==true && mBoard.isHumanWinner()==true){
            result=GAMEOUTCOME::HUMANWONGAME;
        }
        return( result );
    }
    

    // CS 31 TODO: determine if the game has ended
    // HINT: call determineGameOutcome( )
    bool Centennial::isGameOver()
   { bool result=false;
        if(mBoard.isGameOver()==true){
            result=true;
        }
        // for now, just to get it to build...
        return( result );
    }

    // trivial getter operation
    Player Centennial::getHuman() const
    {
        return( mHuman );
    }
    
    // trivial getter operation
    Player Centennial::getComputer() const
    {
        return( mComputer );
    }
    
    // trivial getter operation
    Board  Centennial::getBoard() const
    {
        return( mBoard );
    }
}
