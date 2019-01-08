//
//  cardManager.cpp
//  Card
//
//  Created by Harsha Srikara on 12/24/18.
//  Copyright © 2018 Harsha Srikara. All rights reserved.
//

#include "cardManager.h"
#include <iostream>

// constructor
cardManager::cardManager()
{
    insert(sortedDeck,"spades");
    insert(sortedDeck,"clubs");
    insert(sortedDeck,"diamonds");
    insert(sortedDeck,"hearts");
    
    //randomization process
    currentDeck = sortedDeck;
    currentDeck = randomize(currentDeck);
}
void cardManager::insert(std::vector<card *> &deck,std::string suitType)
{
    for(int i = 1; i < 14; i++)
    {
        card * newCard = new card(suitType,i);
        deck.push_back(newCard);
    }
}
//destructor
cardManager::~cardManager()
{
    destroy();
}
//deletes all the card pointers
//this code will need to eventually be brought back once the pointer issues have been resolved

void cardManager::destroy()
{
    std::cout<<"sorted deck"<<std::endl;
    deleteDeck(sortedDeck);
    std::cout<<"current deck"<<std::endl;
    deleteDeck(currentDeck);
    std::cout<<"draw deck"<<std::endl;
    deleteDeck(drawPile);
    std::cout<<"discard deck"<<std::endl;
    deleteDeck(discardPile);
    std::cout<<"all completed"<<std::endl;
}
void cardManager::deleteDeck(std::vector<card*> &deck)
{
    //this code needs to be revisited
    //error caused as a without this check it tries to delete memory that was already
    //freed or not part of the program
    //likely caused when i = 0 for a second time at the end of a loop
    //bool check = false;
    for(int i = (int)deck.size()-1; i > -1; i--)
    {/*
        if(check)
        {
            break;
        }*/
        if(deck[i]!=nullptr)
        {
            std::cout<<i<<" "<<deck[i]<<" "<<*deck[i]<<" ";
            delete deck[i];
            deck[i]=nullptr;
            std::cout<<deck[i]<<std::endl;
            deck.pop_back();
        }/*
        if(i==0)
        {
            check = true;
        }
        if(check)
        {
            break;
        }*/
    }
}

//deck modifiers
void cardManager::generateDrawPile()
{
    drawPile = randomize();
}
void cardManager::addDeck()
{
    insert(drawPile,"spades");
    insert(drawPile,"clubs");
    insert(drawPile,"diamonds");
    insert(drawPile,"hearts");
    drawPile = randomize(drawPile);
}

//getters
const std::vector<card *>& cardManager::getSortedDeck() const
{
    return sortedDeck;
}
const std::vector<card *>& cardManager::getCurrentDeck() const
{
    return currentDeck;
}
const std::vector<card *>& cardManager::getDrawPile() const
{
    return drawPile;
}
const std::vector<card *>& cardManager::getDiscardPile() const
{
    return discardPile;
}

//getCard functions
card* cardManager::drawCard()
{
    card * temp = drawPile[drawPile.size()-1];
//    drawPile[drawPile.size()-1] = nullptr;
    drawPile.pop_back();
    return temp;
}
card* cardManager::drawDiscardPile()
{
    card * temp = discardPile[discardPile.size()-1];
    discardPile[discardPile.size()-1] = nullptr;
    discardPile.pop_back();
    return temp;
}
void cardManager::addToDiscardPile(card* &newCard)
{
    discardPile.push_back(newCard);
}
card*& cardManager::getTopDiscard()
{
    return discardPile[discardPile.size()-1];
}
//randomize functions
std::vector<card *>& cardManager::randomize()
{
    unsigned seed = (int)std::chrono::system_clock::now()
    .time_since_epoch()
    .count();
    shuffle (currentDeck.begin(), currentDeck.end(), std::default_random_engine(seed));
    return currentDeck;
}
std::vector<card *>& cardManager::randomize(std::vector<card *> &deck)
{
    unsigned seed = (int)std::chrono::system_clock::now()
    .time_since_epoch()
    .count();
    shuffle (deck.begin(), deck.end(), std::default_random_engine(seed));
    return deck;
}

//calls print with cout
void cardManager::print()
{
    print(sortedDeck, std::cout);
}

//calls print on the deck
std::ostream& cardManager::print(const std::vector<card *> deck, std::ostream &out)
{
    for(int i = 0; i < deck.size(); i++)
    {
        out<<i<<" - "<<*deck[i];
    }
    return out;
}

//calls print on the deck - const version
std::ostream& cardManager::print(const std::vector<card *> deck, std::ostream &out) const
{
    for(int i = 0; i < deck.size(); i++)
    {
        out<<i<<" - "<<*deck[i];
    }
    return out;
}

//operator overload
std::ostream& operator<<(std::ostream &out, const cardManager &entry)
{
    entry.print(entry.getDrawPile(), out);
    return out;
}
