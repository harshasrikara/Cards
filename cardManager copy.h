//
//  cardManager.hpp
//  Card
//
//  Created by Harsha Srikara on 12/24/18.
//  Copyright © 2018 Harsha Srikara. All rights reserved.
//

#ifndef cardManager_h
#define cardManager_h

#include <iostream>
#include "card.h"
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <cstdlib>
//#inclde <stack>

class cardManager
{
    //instance data
    private:
    //currently not used anywhere. Possible use cases present
    enum suits {spades,clubs,diamonds,hearts};
    
    std::vector<card *> sortedDeck;  //permanent and unchanging once class has been initialized
    std::vector<card *> currentDeck; //can be shuffled and modified. However, it will always be the entire deck
    
    std::vector<card *> drawPile;    //will load the current deck at the beginning of a game
    std::vector<card *> discardPile; //will be empty unless added to.
    
    //private functions. Only to be called by the destructor.
    //DO NOT CALL THESE FUNCTIONS - WILL CAUSE MEMORY ERRORS
    void destroy(); //called by destructor
    void deleteDeck(std::vector<card*> &deck);  //called by destroy
    
    public:
    //constructor
    cardManager();
    void insert(std::vector<card *> &deck,std::string); //constructor uses this to insert efficiently
    
    //destructor
     ~cardManager();
    
    //deck modifiers
    void generateDrawPile();
    void addDeck();
    
    //getters
    const std::vector<card *>& getSortedDeck() const;
    const std::vector<card *>& getCurrentDeck() const;
    const std::vector<card *>& getDrawPile() const;
    const std::vector<card *>& getDiscardPile() const;
    
    
    
    //getSingleCard
    card* drawCard();
    void addToDiscardPile(card*&);
    card* drawDiscardPile();       //will also remove card from discard pile
    card*& getTopDiscard();   //will only return the top card in the discard pile
    
    //shuffle the existing deck or get a new random deck
    std::vector<card *>& randomize();
    std::vector<card *>& randomize(std::vector<card *> &deck);

    //print functions
    void print();
    std::ostream& print(const std::vector<card *>, std::ostream &out);
    std::ostream& print(const std::vector<card *>, std::ostream &out) const;
    
    //debug
    void debug(std::ostream &out);
};

std::ostream& operator<<(std::ostream &out, const cardManager &entry);

#endif /* cardManager_h */
