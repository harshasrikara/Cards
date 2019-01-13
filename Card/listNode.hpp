//
//  listNode.hpp
//  Card
//
//  Created by Harsha Srikara on 1/4/19.
//  Copyright © 2019 Harsha Srikara. All rights reserved.
//

#ifndef listNode_hpp
#define listNode_hpp

#include "Player.hpp"

class circularLinkedList;

class listNode
{
    friend class circularLinkedList;
    
private:
    mutable player p;
    listNode* pNext;
    listNode* pPrevious;
    bool check;
    
public:
    //constructors
    listNode();
    listNode(const player&);
    listNode(const player&,listNode*,listNode*);
    
    //getters
    listNode* getNext() const;
    listNode* getPrevious() const;
    player& getPlayer() const;
    bool getCheck() const;
    
    //setters -- player cannot be modified. To change, the listnode must be removed/recreated.
    void setNext(listNode*);
    void setPrevious(listNode*);
    void setCheckTrue();
    void setCheckFalse();
    void flipCheckSign();
    
    std::ostream& print(std::ostream &out);
    std::ostream& print(std::ostream &out) const;
    
    //debug - gets the pointers for next and previous
    void debug();
    std::ostream& debug(std::ostream &out);
};

#endif /* listNode_hpp */
