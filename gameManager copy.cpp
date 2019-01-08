//
//  gameManager.cpp
//  Card
//
//  Created by Harsha Srikara on 12/31/18.
//  Copyright © 2018 Harsha Srikara. All rights reserved.
//

#include "gameManager.hpp"

gameManager::gameManager()
{
    restart();
}

void gameManager::restart()
{
    //end the previous game and initialize all values to default
    endGame();
    
    //game intro
    std::cout<<"welcome to the game"<<std::endl;
    
    //getNumber of Players
    std::cout<<"How many players will be joining us?"<<std::endl;
    int numberOfPlayers;
    std::cin>>numberOfPlayers;
    
    //add Players
    for(int i = 0;i<numberOfPlayers;i++)
    {
        addPlayer();
    }
}

void gameManager::addPlayer()
{
    std::string playerName;
    //    std::string playerGameName;
    std::cin>>playerName;//>>playerGameName;
    player newPlayer(playerName);
    //   newPlayer.setGameName(playerGameName);
    players.push_back(newPlayer);
}

//empty the vector and reinitialize all variable
void gameManager::endGame()
{
    while(players.size()!=0)
    {
        players.pop_back();
    }
    direction = 1;
}
void gameManager::shufflePlayerOrder()
{
    unsigned seed = (int)std::chrono::system_clock::now()
    .time_since_epoch()
    .count();
    shuffle (players.begin(), players.end(), std::default_random_engine(seed));
}

void gameManager::playRound(void (*playGame)(player &))
{
    std::cout<<"Enter Y/N"<<std::endl;
    std::string str;
    std::cin>>str;
    while(str=="Y")
    {
        std::cout<<"Enter Y/N"<<std::endl;
        std::cin>>str;
    }
}

//flips direction from 1 to -1 or the other way
void gameManager::reverseDirection()
{
    direction*=-1;
}

void gameManager::print()
{
    print(std::cout);
}
void gameManager::print() const
{
    print(std::cout);
}
std::ostream& gameManager::print(std::ostream &out)
{
    out<<"/nDraw Pile"<<std::endl;
    Deck.print(Deck.getDrawPile(), out);
    out<<"/nDiscard Pile"<<std::endl;
    Deck.print(Deck.getDiscardPile(),out);
    
    for(int i = 0; i<players.size();i++)
    {
        out<<players[i]<<std::endl;
    }
    return out;
}
std::ostream& gameManager::print(std::ostream &out) const
{
    out<<"/nDraw Pile"<<std::endl;
    Deck.print(Deck.getDrawPile(), out);
    out<<"/nDiscard Pile"<<std::endl;
    Deck.print(Deck.getDiscardPile(),out);
    
    for(int i = 0; i<players.size();i++)
    {
        out<<players[i]<<std::endl;
    }
    return out;
}

std::ostream& operator<<(std::ostream &out, const gameManager &game)
{
    return game.print(out);
}
