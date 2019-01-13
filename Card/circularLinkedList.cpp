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
    nodeCount = traverse();
}
circularLinkedList::circularLinkedList(circularLinkedList &existingCircularLinkedList)
{
    //clear what remains in this list before copying over terms
    clearList();
    
    //does this really copy over the list?
    //what if the list passed in by reference goes out of scope and everything is accidentally deleted?
    //should transition over to the traverse function that copy over using insertNode
    firstNode = existingCircularLinkedList.getFirstNode();
    nodeCount = existingCircularLinkedList.getNodeCount();
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
    //create new node
    listNode *node = new listNode(newPlayer);
    if(empty()) //no nodes
    {
        node->setNext(node);
        node->setPrevious(node);
        
        firstNode = node;
        nodeCount++;
        return;
    }
    if(nodeCount==1) //one node
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

//insert after and before
void circularLinkedList::insert_after(listNode *existingNode, const player &newPlayer)
{
    //create new listnode
    listNode *node = new listNode(newPlayer);
    
    //get the to be next and previous ndoes
    listNode *nextNode = existingNode->getNext();
    listNode *previousNode = existingNode;
    
    //set pointers to the correct nodes
    nextNode->setPrevious(node);
    previousNode->setNext(node);
    node->setNext(nextNode);
    node->setPrevious(previousNode);
}
void circularLinkedList::insert_before(listNode *existingNode, const player &newPlayer)
{
    insert_after(existingNode->getPrevious(),newPlayer);
}

//find
bool circularLinkedList::find(const player &existingPlayer)
{
    if(firstNode->getPlayer()==existingPlayer)
    {
        return true;
    }
    listNode *traversalPointer = firstNode->getNext();
    while(traversalPointer!=firstNode)
    {
        if(traversalPointer->getPlayer()==existingPlayer)
        {
            return true;
        }
        traversalPointer->getNext();
    }
    return false;
}
bool circularLinkedList::find(bool (*doFunction)(listNode*), player &existingPlayer)
{
    if(firstNode->getPlayer()==existingPlayer)
    {
        return doFunction(firstNode);
    }
    listNode *traversalPointer = firstNode->getNext();
    while(traversalPointer!=firstNode)
    {
        if(traversalPointer->getPlayer()==existingPlayer)
        {
            return doFunction(traversalPointer);
        }
        traversalPointer->getNext();
    }
    return false;
}

//erase
bool circularLinkedList::erase(listNode *node)
{
    if(node == nullptr)
    {
        return false;
    }
    if(node==firstNode)
    {
        if(nodeCount==1)
        {
            delete firstNode;
            firstNode = nullptr;
            nodeCount--;
            return true;
        }
        firstNode = node->getNext();
    }
    //get previous and next
    listNode *next = node->getNext();
    listNode *prev = node->getPrevious();
    
    //remove the middle node
    next->setPrevious(prev);
    prev->setNext(next);
    
    delete node;
    node = nullptr;
    nodeCount--;
    return true;
}

//this code has to be changed to use find and erase together instead of rewriting/copying over code
bool circularLinkedList::erase(player existingPlayer)
{
    if(firstNode->getPlayer()==existingPlayer)
    {
        return erase(firstNode);
    }
    listNode *traversalPointer = firstNode->getNext();
    while(traversalPointer!=firstNode)
    {
        if(traversalPointer->getPlayer()==existingPlayer)
        {
            return erase(traversalPointer);
        }
        traversalPointer->getNext();
    }
    return false;
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

void circularLinkedList::traverse(void (*doFunction)(listNode *))
{
    listNode* traversalPointer = firstNode;
    doFunction(traversalPointer);
    
    traversalPointer = traversalPointer->getNext();
    while(traversalPointer!=firstNode)
    {
        doFunction(traversalPointer);
        traversalPointer = traversalPointer->getNext();
    }
}
//this function should be used in conjunction with insert node and the constructor to assist in copying over the coonstructor.
void circularLinkedList::traverse(void (*doFunction)(circularLinkedList& other,listNode *),circularLinkedList* diffCircular)
{
    listNode* traversalPointer = firstNode;
    doFunction(*diffCircular,traversalPointer);
    
    traversalPointer = traversalPointer->getNext();
    while(traversalPointer!=firstNode)
    {
        doFunction(*diffCircular,traversalPointer);
        traversalPointer = traversalPointer->getNext();
    }
}
std::size_t circularLinkedList::traverse()
{
    if(empty())
    {
        return 0;
    }
    std::size_t var = 1;
    listNode* traversalPointer = firstNode->getNext();
    while(traversalPointer!=firstNode)
    {
        traversalPointer = traversalPointer->getNext();
        var++;
    }
    return var;
}

//print
void circularLinkedList::print()
{
    print(std::cout);
}
void circularLinkedList::print() const
{
    print(std::cout);
}
std::ostream& circularLinkedList::print(std::ostream &out)
{
    if(!empty())
    {
        listNode* traversalPointer = firstNode;
        traversalPointer->print(out);
        
        traversalPointer = traversalPointer->getNext();
        while(traversalPointer!=firstNode)
        {
            traversalPointer->print(out);
            traversalPointer = traversalPointer->getNext();
        }
    }
    else
    {
        out<<"circular linked list is empty"<<std::endl;
    }
    return out;
}
std::ostream& circularLinkedList::print(std::ostream &out) const
{
    if(!empty())
    {
        listNode* traversalPointer = firstNode;
        traversalPointer->print(out);
        
        traversalPointer = traversalPointer->getNext();
        while(traversalPointer!=firstNode)
        {
            traversalPointer->print(out);
            traversalPointer = traversalPointer->getNext();
        }
    }
    else
    {
        out<<"circular linked list is empty"<<std::endl;
    }
    return out;
}

//debug
void circularLinkedList::debug()
{
    debug(std::cout);
}
std::ostream& circularLinkedList::debug(std::ostream &out)
{
    out<<"BEGINNING DEBUG"<<std::endl;
    if(!empty())
    {
        listNode* traversalPointer = firstNode;
        traversalPointer->debug(out);
        
        traversalPointer = traversalPointer->getNext();
        while(traversalPointer!=firstNode)
        {
            traversalPointer->debug(out);
            traversalPointer = traversalPointer->getNext();
        }
    }
    else
    {
        out<<"circular linked list is empty"<<std::endl;
    }
    return out;
}

