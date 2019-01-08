//
//  card.cpp
//  Card
//
//  Created by Harsha Srikara on 12/24/18.
//  Copyright © 2018 Harsha Srikara. All rights reserved.
//

#include "card.h"

//default constructor
card::card()
{
    suit  = "";
    value = 0;
    color = colorFinder("");
    name = nameFinder(0);
}
//normal constructor
card::card(std::string data, int val)
{
    suit = data;
    value = val;
    color = colorFinder(data);
    name = nameFinder(val);
}

//identifies color based on type
std::string card::colorFinder(std::string data) const
{
    if(data == "Joker")
    {
        return "TBD";
    }
    if(data ==  "spades" || data == "clubs")
    {
        return "black";
    }
    else
    {
        return "red";
    }
}

//identifies the name of the card based on its value
std::string card::nameFinder(int val) const
{
    switch (val)
    {
        case 0 : return "Joker";
        case 1 : return "Ace";
        case 2 : return "Two";
        case 3 : return "Three";
        case 4 : return "Four";
        case 5 : return "Five";
        case 6 : return "Six";
        case 7 : return "Seven";
        case 8 : return "Eight";
        case 9 : return "Nine";
        case 10: return "Ten";
        case 11: return "Jack";
        case 12: return "Queen";
        case 13: return "King";
        case 14: return "Ace";
    }
    return "invalid";
}

//getters
std::string card::getType() const
{
    return suit;
}
std::string card::getColor() const
{
    return color;
}
std::string card::getName() const
{
    return name;
}
int card::getValue() const
{
    return value;
}

//setters
void card::setSuit(std::string data)
{
    suit = data;
    color = colorFinder(data);
}
void card::setValue(int val)
{
    value = val;
    name = nameFinder(val);
}

//equality operator overloads
bool card::operator==(const card &entry) const
{
    if(suit==entry.getType() && value==entry.getValue())
    {
        return true;
    }
    return false;
}
bool card::operator!=(const card &entry) const
{
    if(suit!=entry.getType() || value!=entry.getValue())
    {
        return true;
    }
    return false;
}

//comparison operator overloads
bool card::operator>(const card &entry) const
{
    if(value > entry.getValue())
    {
        return true;
    }
    return false;
}
bool card::operator<(const card &entry) const
{
    if(value < entry.getValue())
    {
        return true;
    }
    return false;
}
bool card::operator>=(const card &entry) const
{
    if(value >= entry.getValue())
    {
        return true;
    }
    return false;
}
bool card::operator<=(const card &entry) const
{
    if(value <= entry.getValue())
    {
        return true;
    }
    return false;
}

//useful for debug purposes - will print all instance data
std::ostream& operator<<(std::ostream &out, const card &entry)
{
    out << entry.getValue() << " " << entry.getName() << " of " << entry.getType() << " " << entry.getColor() << std::endl;
    return out;
}
 
 
 
