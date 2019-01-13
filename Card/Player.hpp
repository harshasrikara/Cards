//
//  Player.hpp
//  Card
//
//  Created by Harsha Srikara on 12/25/18.
//  Copyright © 2018 Harsha Srikara. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <string>
#include <vector>
#include <iostream>

#include "card.h"

class player
{
    //instance data
    private:
    std::string name;
    std::string gameName;
    std::vector<card *> hand;
    int score;
    
    public:
    //constructor
    player();
    player(const player &otherPlayer);
    player(std::string);
    player(std::string, std::vector<card *>);
    
    //assignment operator overload
    //const player& operator=(const player& other);
    
    //destructor
    ~player();        //could cause some serious pointer issues. Probably best to leave it to cardManager
                      //could be unnessecary if cardManager class deals with all pointers.
    void emptyHand(); //deletes the card pointers in hand (to be implemented)
    
    
    //getters
    int getScore() const;
    int getHandSize() const;
    std::string getName() const;
    std::string getGameName() const;
    std::vector<card *> getHand() const;
    
    //setters
    void setName(std::string);
    void setGameName(std::string);
    void createNewHand(std::vector<card *>);
    
    //modifiers
    void addCard(card*&); //gets reference from the draw pile
    bool removeCard(card*);
    bool find(card*);
    bool find(bool (*playCard)(card*),card*);
    void sort();
    
    std::ostream& print(std::ostream &out);
    std::ostream& print(std::ostream &out) const;
    
    //comparison operator overload
    bool operator==(const player &entry) const;
    bool operator!=(const player &entry) const;
    
};

std::ostream& operator<<(std::ostream &out, const player &entry);

#endif /* Player_hpp */
