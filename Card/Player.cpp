//
//  Player.cpp
//  Card
//
//  Created by Harsha Srikara on 12/25/18.
//  Copyright © 2018 Harsha Srikara. All rights reserved.
//

#include "Player.hpp"

//constructors
player::player()
{
    score = 0;
}
player::player(std::string newName)
{
    name = newName;
    score = 0;
}
player::player(std::string newName, std::vector<card *> newHand)
{
    name = newName;
    hand = newHand;
    score = 0;
}

player::player(const player &otherPlayer)
{
    name = otherPlayer.getName();
    hand = otherPlayer.getHand();
    score = otherPlayer.getScore();
}

//assignment operator overload
//needs to be written unless its not needed

//destructor
player::~player()
{
//    emptyHand();
}

void player::emptyHand()
{
    for(int i = 0; i < hand.size(); i++)
    {
        delete hand[i];
        hand[i] = nullptr;
    }
}


//getters
int player::getScore() const
{
    return score;
}
int player::getHandSize() const
{
    return (int)hand.size();
}
std::string player::getName() const
{
    return name;
}
std::string player::getGameName() const
{
    return gameName;
}
std::vector<card *> player::getHand() const
{
    return hand;
}

//setters
void player::setName(std::string data)
{
    name = data;
}
void player::setGameName(std::string data)
{
    gameName = data;
}
void player::createNewHand(std::vector<card *> newHand)
{
    hand = newHand;
}

//modifiers
void player::addCard(card* &newCard)
{
    hand.push_back(newCard);
}
bool player::removeCard(card* currentCard)
{
    if(find(currentCard))
    {
        for(int i = 0; i<hand.size(); i++)
        {
            if(*hand[i]==*currentCard) //is this correct? or should I compare pointers. probably correct to see if taget matches up
            {
                hand.erase(hand.begin()+i);
                return true;
            }
        }
    }
    return false;
}
bool player::find(card* currentCard)
{
    for(int i = 0; i<hand.size(); i++)
    {
        if(*hand[i]==*currentCard) //is this correct? or should I compare pointers. probably correct to see if taget matches up
        {
            return true;
        }
    }
    return false;
}
//I need to get this function to do the erase part as well as anything else required. Needs to be coded.
bool player::find(bool (*playCard)(card*), card* currentCard)
{
    for(int i = 0; i<hand.size(); i++)
    {
        if(hand[i]==currentCard)
        {
            return playCard(hand[i]);
        }
    }
    return false;
}

std::ostream& player::print(std::ostream &out)
{
    for( int i = 0; i < hand.size(); i++)
    {
        out<<i<<" - "<<*hand[i];
    }
    return out;
}

std::ostream& player::print(std::ostream &out) const
{
    for( int i = 0; i < hand.size(); i++)
    {
        out<<i<<" - "<<*hand[i];
    }
    return out;
}

std::ostream& operator<<(std::ostream &out, const player &entry)
{
    out<<entry.getName()<<std::endl;
    return entry.print(out);
}
