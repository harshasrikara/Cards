//
//  circularLinkedList.cpp
//  Card
//
//  Created by Harsha Srikara on 1/4/19.
//  Copyright © 2019 Harsha Srikara. All rights reserved.
//

#include "circularLinkedList.hpp"

circularLinkedList::circularLinkedList()
{
    firstNode = nullptr;
    nodeCount = 0;
}
circularLinkedList::circularLinkedList(listNode* first)
{
    firstNode = first;
    //nodeCount = traverse();
}
circularLinkedList::circularLinkedList(circularLinkedList &existingCircularLinkedList)
{
    //clear what remains in this list before copying over terms
    clearList();
    
    //does this really copy over the list?
    //what if the list passed in by reference goes out of scope and everything is accidentally deleted?
    firstNode = existingCircularLinkedList.getFirstNode();
    //nodeCount = traverse();
}
circularLinkedList::~circularLinkedList()
{
    clearList();
}
void circularLinkedList::clearList()
{
    while(!empty())
    {
        pop();
    }
}
void circularLinkedList::insertNode(circularLinkedList &other, listNode *node)
{
    other.push(node->getPlayer());
}
//push should be the only function to add 1 to nodeCount.
void circularLinkedList::push(const player &newPlayer)
{
    listNode *node = new listNode(newPlayer);
    if(empty())
    {
        node->setNext(node);
        node->setPrevious(node);
        
        firstNode = node;
        nodeCount++;
        return;
    }
    if(nodeCount==1)
    {
        node->setNext(firstNode);
        node->setPrevious(firstNode);
        firstNode->setNext(node);
        firstNode->setPrevious(node);
        
        firstNode = node;
        nodeCount++;
        return;
    }
    //seperatly identifying next and previous nodes for readability
    listNode *nextNode = firstNode;
    listNode *previousNode = firstNode->getPrevious();
    
    //setting next and previous
    node->setNext(nextNode);
    nextNode->setPrevious(node);
    node->setPrevious(previousNode);
    previousNode->setNext(node);
    
    firstNode = node;
    
    nodeCount++;
}
void circularLinkedList::pop()
{
    if(nodeCount==0)
    {
        return;
    }
    if(nodeCount==1)
    {
        delete firstNode;
        nodeCount--;
        return;
    }
    if(nodeCount==2)
    {
        firstNode = firstNode->getNext();
        delete firstNode->getNext();
        firstNode->setPrevious(firstNode);
        firstNode->setNext(firstNode);
        nodeCount--;
        return;
    }
    //get the listNode before and after the firstNode
    listNode* prev = firstNode->getPrevious();
    listNode* next = firstNode->getNext();
    
    //set next and previous terms for the nodes
    prev->setNext(next);
    next->setPrevious(prev);
    
    //delete and set nodeCount value
    delete firstNode;
    nodeCount--;
    firstNode = next; //could also be previous
}
//getters
listNode* circularLinkedList::getFirstNode() const
{
    return firstNode;
}
std::size_t circularLinkedList::getNodeCount() const
{
    return nodeCount;
}
bool circularLinkedList::empty() const
{
    if(nodeCount==0)
    {
        return true;
    }
    return false;
}

//debug
void circularLinkedList::debug()
{
    debug(std::cout);
}
std::ostream& circularLinkedList::debug(std::ostream &out)
{
    out<<"BEGINNING DEBUG"<<std::endl;
    listNode* traversalPointer = firstNode;
    traversalPointer->debug(out);
    
    traversalPointer = traversalPointer->getNext();
    while(traversalPointer!=firstNode)
    {
        traversalPointer->debug(out);
        traversalPointer = traversalPointer->getNext();
    }
    return out;
}
