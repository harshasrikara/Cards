//
//  main.cpp
//  Card
//
//  Created by Harsha Srikara on 12/23/18.
//  Copyright © 2018 Harsha Srikara. All rights reserved.
//

#include <iostream>
#include "card.h"
#include "cardManager.h"
#include "Player.hpp"

int main() {
    // insert code here...
    
    /*
    card Cone("hearts",6);
    card Ctwo("spades",12);
    std::cout<< Cone;
    std::cout<< Ctwo;
    
    if(Cone == Ctwo)
    {
        std::cout << "they match" << std::endl;
    }
    else
    {
        std::cout << "they dont match" << std::endl;
    }
     */
    
    
    cardManager Deck;
    Deck.generateDrawPile();
    return 0;
}
