//
//  card.hpp
//  Card
//
//  Created by Harsha Srikara on 12/24/18.
//  Copyright © 2018 Harsha Srikara. All rights reserved.
//

#ifndef card_h
#define card_h

#include <string>
#include <iostream>

class card
{
    //instance data
    private:
    std::string suit; //clubs, spades, diamonds, hearts
    std::string color; //red, black
    std::string name;
    int value;  //2-13    A = 1 or 14?
    
    public:
    card();
    card(std::string data, int val);
    
    //identifies the color based on the suit
    std::string colorFinder(std::string) const;
    
    //identifies the name of the card based on its value
    std::string nameFinder(int) const;
    
    //getters
    std::string getType() const;
    std::string getColor() const;
    std::string getName() const;
    int getValue() const;
    
    //setters
    void setValue(int);
    void setSuit(std::string);
    
    //operator overloads
    bool operator==(const card &entry) const;
    bool operator!=(const card &entry) const;
    bool operator<(const card &entry) const;
    bool operator<=(const card &entry) const;
    bool operator>(const card &entry) const;
    bool operator>=(const card &entry) const;
};

//useful for debug purposes - will print all instance data
std::ostream& operator<<(std::ostream &out, const card &entry);

#endif /* card_hpp */
