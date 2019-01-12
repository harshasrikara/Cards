//
//  listNode.cpp
//  Card
//
//  Created by Harsha Srikara on 1/4/19.
//  Copyright © 2019 Harsha Srikara. All rights reserved.
//

#include "listNode.hpp"

//constructors
listNode::listNode()
{
    check = false;
    pNext = nullptr;
    pPrevious = nullptr;
}
listNode::listNode(const player &p1)
{
    p = p1;
    check = false;
    pNext = nullptr;
    pPrevious = nullptr;
}
listNode::listNode(const player &p1, listNode *next,listNode *previous)
{
    p = p1;
    check = false;
    pNext = next;
    pPrevious = previous;
}

//getters
listNode* listNode::getNext() const
{
    return pNext;
}
listNode* listNode::getPrevious() const
{
    return pPrevious;
}
player& listNode::getPlayer() const
{
    return p;
}
bool listNode::getCheck() const
{
    return check;
}

//setters
void listNode::setNext(listNode *next)
{
    pNext = next;
}
void listNode::setPrevious(listNode *previous)
{
    pPrevious = previous;
}
void listNode::setCheckTrue()
{
    check = true;
}
void listNode::setCheckFalse()
{
    check = false;
}
void listNode::flipCheckSign()
{
    check = !check;
}

//debug functions
void listNode::debug()
{
    debug(std::cout);
}
std::ostream& listNode::debug(std::ostream &out)
{
    out<<"Player Name - "<<p.getName()<<" current node - "<<this
    << "\npreviousNode - "<<pPrevious<<" nextNode - "<<pNext<<" \n"<<std::endl;
    return out;
}
