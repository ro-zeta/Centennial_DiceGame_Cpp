//
//  Player.cpp
//  Centennial
//
//  Created by Howard Stahl on 1/27/17.
//  Copyright © 2017 Howard Stahl. All rights reserved.
//

#include "Player.h"
#include <iostream>
#include "Die.h"
#include "Board.h"
#include "Centennial.h"

namespace cs31
{
    // set up three six sided dies
    // indicate that none of the spots 1-12 have yet been tossed
    Player::Player() : mDie1( 6 ), mDie2( 6 ), mDie3( 6 ), hasRolled1(false), hasRolled2(false), hasRolled3(false), hasRolled4(false), hasRolled5(false), hasRolled6(false), hasRolled7(false), hasRolled8(false), hasRolled9(false), hasRolled10(false), hasRolled11(false), hasRolled12(false)
    {
    }
    
    // CS 31 TODO: cheat by accepting a particular set of dies for this player to use
    void Player::roll( Die d1, Die d2, Die d3 )
    {
    // assign each of the arguments to the Player's member variables to enable cheating...
        int dVal1=d1.getValue(); int dVal2=d2.getValue(); int dVal3=d3.getValue();
       mDie1.setValue(dVal1);  mDie2.setValue(dVal2);  mDie3.setValue(dVal3);
    }

    // CS 31 TODO: randomly roll each of the player's three dies
    void Player::roll( )
    {
        // randomly roll each of the three Die member variables--3
        mDie1.roll();  mDie2.roll();  mDie3.roll();
//        mDie1=mDie1.getValue(); // MOST LIKELY INCORRECT
//        mDie2=mDie2.getValue();  //DOESN'T ASSIGN VALUE IN WHATSPOTISNEEDED
//        mDie3=mDie3.getValue();
    }
    
    // CS 31 TODO: based on what has been tossed previously, determine the spot that is needed next
    // returning 1 means, in order to progress in the game at this point, the Player
    //             needs to toss a one
    // returning 2 means, in order to progress in the game at this point, the Player
    //             needs to toss a two
    // etc...
    int  Player::whatSpotIsNeededNext() {
        //  updates the hasRolled1-12 bool vars  //get the dice values rolled
//        int whatRolled1; int whatRolled2; int whatRolled3;
//        whatRolled1=mDie1.getValue();
//        whatRolled2=mDie2.getValue();
//        whatRolled3=mDie3.getValue();
//           std::cout<< whatRolled2<<std::endl;
//        // check what other possibilites are to advance aka sums
//             int sumFirstSecond=whatRolled1+whatRolled2;
//             int sumSecondThird=whatRolled2+whatRolled3;
//             int sumFirstThird=whatRolled1+whatRolled3;
//             int sumAll=whatRolled1+whatRolled2+whatRolled3;
        bool HasRolledArray[12]={hasRolled1, hasRolled2, hasRolled3, hasRolled4, hasRolled5, hasRolled6, hasRolled7, hasRolled8, hasRolled9, hasRolled10, hasRolled11, hasRolled12};
        int nextSpot=1;
//        if ((whatRolled1==1 ||whatRolled2==1||whatRolled3==1) && hasRolled1==true){
             for(int l=0; l<12; l++){
                       if (HasRolledArray[l]==false){
                            int j=l+1;
                           nextSpot=j;
                           break;
                       }
    }
//            nextSpot=2; }
//        if ((whatRolled1==2 ||whatRolled2==2||whatRolled3==2|| sumFirstSecond==2|| sumSecondThird==2|| sumFirstThird==2 || sumAll==2) && hasRolled2==true){
//               nextSpot=3; }
//        if ((whatRolled1==3 ||whatRolled2==3||whatRolled3==3|| sumFirstSecond==3|| sumSecondThird==3|| sumFirstThird==3 || sumAll==3)&&  hasRolled3==true ){
//                           nextSpot=4;}
//        if ((whatRolled1==4 ||whatRolled2==4||whatRolled3==4|| sumFirstSecond==4|| sumSecondThird==4|| sumFirstThird==4 || sumAll==4)&& hasRolled4==true){
//                            nextSpot=5;}
//        if ((whatRolled1==5 ||whatRolled2==5||whatRolled3==5|| sumFirstSecond==5|| sumSecondThird==5|| sumFirstThird==5 || sumAll==5)&& hasRolled5==true){
//                            nextSpot=6;}
//        if ((whatRolled1==6 ||whatRolled2==6||whatRolled3==6|| sumFirstSecond==6|| sumSecondThird==6|| sumFirstThird==6 || sumAll==6)&& hasRolled6==true){
//                            nextSpot=7;}
//        if ((sumFirstSecond==7||sumSecondThird==7||sumFirstThird==7||sumAll==7)&& hasRolled7==true){
//                            nextSpot=8; }
//        if ((sumFirstSecond==8||sumSecondThird==8||sumFirstThird==8||sumAll==8)&& hasRolled8==true){
//                            nextSpot=9;}
//        if ((sumFirstSecond==9||sumSecondThird==9||sumFirstThird==9||sumAll==9)&& hasRolled9==true){
//                            nextSpot=10;}
//        if ((sumFirstSecond==10||sumSecondThird==10||sumFirstThird==10||sumAll==10)&& hasRolled10==true){
//                            nextSpot=11;}
//        if ((sumFirstSecond==11||sumSecondThird==11||sumFirstThird==11||sumAll==11) && hasRolled11==true){ nextSpot=12; }
//        if ((sumFirstSecond==12|| sumSecondThird==12|| sumFirstThird==12 || sumAll==12) && hasRolled12==true){
//                            nextSpot=0;}  //CAN I LEAVE IT 0?
        return( nextSpot);
    }
    
    // CS 31 TODO: this operation is called to indicate that the argument has been rolled
    //             in conjunction with the operation whatSpotIsNeededNext( ), adjust member
    //       variables correctly so that play can progress in the game
    // passing 1 means that a one was just tossed
    // passing 2 means that a two was just tossed
    // etc...
    void Player::rolled( int spot ) {
//        gets values rolled, updates possible spots
        if (spot==1 ){hasRolled1=true; }
        if (spot==2 && hasRolled1==true ){hasRolled2=true;}
        if (spot==3 && hasRolled1==true && hasRolled2==true){hasRolled3=true;}
        if (spot==4 && hasRolled1==true && hasRolled2==true&& hasRolled3==true){hasRolled4=true; }
        if (spot==5 && hasRolled1==true && hasRolled2==true&& hasRolled3==true&& hasRolled4==true){hasRolled5=true;}
        if (spot==6 &&hasRolled1==true && hasRolled2==true&& hasRolled3==true&& hasRolled4==true&& hasRolled5==true){hasRolled6=true;}
        if (spot==7 &&hasRolled1==true && hasRolled2==true&& hasRolled3==true&& hasRolled4==true&& hasRolled5==true&& hasRolled6==true){hasRolled7=true; }
        if (spot==8 &&hasRolled1==true && hasRolled2==true&& hasRolled3==true&& hasRolled4==true&& hasRolled5==true&& hasRolled6==true&& hasRolled7==true){hasRolled8=true; }
        if (spot==9 &&hasRolled1==true && hasRolled2==true&& hasRolled3==true&& hasRolled4==true&& hasRolled5==true&& hasRolled6==true&& hasRolled7==true&& hasRolled8==true){hasRolled9=true;}
        if (spot==10 &&hasRolled1==true && hasRolled2==true&& hasRolled3==true&& hasRolled4==true&& hasRolled5==true&& hasRolled6==true && hasRolled7==true&& hasRolled8==true && hasRolled9==true ){hasRolled10=true;}
        if (spot==11 &&hasRolled1==true && hasRolled2==true&& hasRolled3==true&& hasRolled4==true&& hasRolled5==true&& hasRolled6==true && hasRolled7==true&& hasRolled8==true && hasRolled9==true && hasRolled10==true){hasRolled11=true;}
        if (spot==12 &&hasRolled1==true && hasRolled2==true&& hasRolled3==true&& hasRolled4==true&& hasRolled5==true&& hasRolled6==true && hasRolled7==true&& hasRolled8==true && hasRolled9==true && hasRolled10==true && hasRolled11==true){hasRolled12=true;}
              //!!!CAN I LEAVE IT AS 0??
    }
    
    // trivial getter operation
    Die Player::getDie1() const
    {return( mDie1 );}
    
    // trivial getter operation
    Die Player::getDie2( ) const
    {return( mDie2 ); }
    
    // trivial getter operation
    Die Player::getDie3( ) const
    {return( mDie3 ); }

    // trivial getter operation
    bool Player::hasRolledOne() const
    {
        return( hasRolled1 );
    }

    // trivial getter operation
    bool Player::hasRolledTwo() const
    {
        return( hasRolled2 );
    }

    // trivial getter operation
    bool Player::hasRolledThree() const
    {
        return( hasRolled3 );
    }

    // trivial getter operation
    bool Player::hasRolledFour() const
    {
        return( hasRolled4 );
    }

    // trivial getter operation
    bool Player::hasRolledFive() const
    {
        return( hasRolled5 );
    }

    // trivial getter operation
    bool Player::hasRolledSix() const
    {
        return( hasRolled6 );
    }

    // trivial getter operation
    bool Player::hasRolledSeven() const
    {
        return( hasRolled7 );
    }

    // trivial getter operation
    bool Player::hasRolledEight() const
    {
        return( hasRolled8 );
    }

    // trivial getter operation
    bool Player::hasRolledNine() const
    {
        return( hasRolled9 );
    }

    // trivial getter operation
    bool Player::hasRolledTen() const
    {
        return( hasRolled10 );
    }

    // trivial getter operation
    bool Player::hasRolledEleven() const
    {
        return( hasRolled11 );
    }

    // trivial getter operation
    bool Player::hasRolledTwelve() const
    {
        return( hasRolled12 );
    }
    
    // used solely for testing purposes to see the value of each die
    // if we are using random rolls, we won't know what was tossed
    //         unless we use this operation
    std::string Player::whatWasRolled()
    {
        using namespace std;
        std::string s = "";
        s += "Die1: ";
        s += std::to_string( mDie1.getValue() );
        s += " Die2: ";
        s += std::to_string( mDie2.getValue() );
        s += " Die3: ";
        s += std::to_string( mDie3.getValue() );
        s += "\n";
     
        return( s );
    }
    
    

}
