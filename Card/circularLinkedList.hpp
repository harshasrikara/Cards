//
//  circularLinkedList.hpp
//  Card
//
//  Created by Harsha Srikara on 1/4/19.
//  Copyright © 2019 Harsha Srikara. All rights reserved.
//

#ifndef circularLinkedList_hpp
#define circularLinkedList_hpp

#include "listNode.hpp"
#include <iostream>


class circularLinkedList
{
    private:
    listNode* firstNode;
    std::size_t nodeCount;
    
    public:
    //constructor and destructor/helper function
    circularLinkedList();
    circularLinkedList(circularLinkedList&);
    circularLinkedList(listNode*);
    ~circularLinkedList();
    void clearList();
    
    //insertion
    void insertNode(circularLinkedList&, listNode*); //used by traverse and copy constructor
    void push(const player&);
    void pop();
    
    //insert after a node
    void insert_after(listNode*,const player&);
    void insert_before(listNode*,const player&);
    
    //insert after a given player
    void insert_after(player, const player&);
    void insert_before(player, const player&);
    
    //find functions
    bool find(const player&);
    bool find(bool (*doFunction)(listNode*), player&); 
    
    //erase functions
    bool erase(listNode*); //to be used by find function
    bool erase(player);
    bool erase(std::string); //player name maybe?
    
    //count of nodes/ getters
    listNode* getFirstNode() const;
    std::size_t getNodeCount() const;
    bool empty() const; //if(nodeCount == 0);
    
    //traverse
    void traverse(void (*doFunction)(listNode*));
    void traverse(void (*doFunction)(circularLinkedList&, listNode*),circularLinkedList*);
    std::size_t traverse(); //gets size of circular linked list through traversal
    
    //debug and print
    void print();
    void print() const;
    std::ostream& print(std::ostream &out);
    std::ostream& print(std::ostream &out) const;
    
    void debug();
    std::ostream& debug(std::ostream &out);
};

#endif /* circularLinkedList_hpp */
