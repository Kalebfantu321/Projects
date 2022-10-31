//
//  main.cpp
//  Assign8
//
//  Created by Kaleb Fantu on 10/26/22.
//

#include <iostream>
#include "mystack.h"

mystack::mystack(const mystack& x){
    
    this->stackSize = x.stackSize;
    if(this->stackSize == 0){
        this->StackTop = nullptr;
        }
    else
        clone(x);
}

mystack& mystack::operator=(const mystack& x){
    if (this != &x) {
        clear();
        stackSize = x.stackSize;
        clone(x);
        
    }

       
    return *this;
}

size_t mystack::size()const{
    return this->stackSize;
}
mystack::~mystack(){
    clear();
}



bool mystack::empty()const
{
    if(this->stackSize == 0){
        return true;
    }
    else
        return false;
}


void mystack::clear(){
    while(!empty()){
        pop();
    }
    this->stackSize = 0;
}

const int& mystack::top()const{
    return StackTop->value;
}


void mystack::push(int value){
    node *new_node = new node(value, this->StackTop);
    StackTop = new_node;
    stackSize++;
    
    }
void mystack::pop(){
    
    node* delete_node = StackTop;
    StackTop = StackTop->next;
    delete delete_node;
    stackSize--;
    
}

void mystack::clone(const mystack &x){
    
    node* last = nullptr;
    node* ptr = x.StackTop;
    
    
    while(ptr != nullptr){
        node *new_node = new node(ptr->value);
        
        if(last == nullptr){
            StackTop = new_node;
        }
        else{
            last->next = new_node;
        }
        last = new_node;
        ptr = ptr->next;
    }
    
}
