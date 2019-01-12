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
#include "gameManager.hpp"
#include "circularLinkedList.hpp"

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
    
    //gameManager game;
    
    player p1("apple");
    player p2("grape");
    player p3("berry");
    player p4("orange");
    
    circularLinkedList circ;
    
    circ.push(p1);
    circ.push(p2);
    circ.push(p3);
    circ.push(p4);
    
    circ.debug();
    
    std::cout<<"everything works just fine"<<std::endl;
    return 0;
}
