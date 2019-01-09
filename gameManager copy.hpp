//
//  gameManager.hpp
//  Card
//
//  Created by Harsha Srikara on 12/31/18.
//  Copyright © 2018 Harsha Srikara. All rights reserved.
//

#ifndef gameManager_hpp
#define gameManager_hpp

#include "cardManager.h"
#include "Player.hpp"

class gameManager
{
    private:
    
    int direction = 1; //to move through the player array in a positive direction. Can also be -1
    cardManager Deck;  //Deck of Cards
    std::vector<player> players; //needs to eventually transition to the circular linked list
    
    public:
    gameManager();
    
    void addPlayer();
    void restart(); //also called by constructor
    void endGame();
    void reverseDirection();
    void shufflePlayerOrder();
    
    void playRound(void (*playGame)(player&));
    void playRound(void (*playGame)(player&,card)); //for a variant that involves playing a card not belonging to a player
    
    //print functions
    void print();
    void print() const;
    std::ostream& print(std::ostream &out);
    std::ostream& print(std::ostream &out) const;
    
};

std::ostream& operator<<(std::ostream&,const gameManager&);

#endif /* gameManager_hpp */
