//
//  mystack.h
//  Assign8
//
//  Created by Kaleb Fantu on 10/26/22.
//

#ifndef mystack_h
#define mystack_h

#include <stdio.h>

struct node
{
    node* next;
    int value;
    
    node(int value, node* next = nullptr)
    {
        this->value = value;
        this->next = next;
    }
};



class mystack{
  
    mystack& operator=(const mystack& x);
    node *StackTop = nullptr;
    size_t stackSize = 0;
    
    
public:
    mystack() = default;
    mystack(const mystack& x);
    ~mystack();
    size_t size()const;
    bool empty()const;
    void clear();
    const int& top()const;
    void push(int);
    void pop();
    void clone(const mystack& x);
};

#endif /* mystack_h */
