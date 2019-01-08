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
    player p;
    listNode* pNext;
    listNode* pPrevious;
    bool check;
    
public:
    //constructors
    listNode();
    listNode(player&);
    listNode(player&,listNode*,listNode*);
    
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
};

#endif /* listNode_hpp */
