//
//  eval.cpp
//  Assign8
//
//  Created by Kaleb Fantu on 10/26/22.
//

#include "eval.hpp"
#include "inpost.hpp"
#include "mystack.h"
#include <string>
#include <iostream>


mystack eval_stack;

int evaluate(const string& postfix){
    for(size_t i =0; i < postfix.length(); i++){
        char token = postfix[i];
        if(isdigit(token)){
            eval_stack.push(token);
        }
    
        else if(isalpha(token)){
            eval_stack.push(token - 'a');
        }
        else if(token == '~'){
           int tild = eval_stack.top();
            eval_stack.pop();
            tild *= -1;
            eval_stack.push(tild);
        }
        
        else if(token == '+'){
            int rightop = eval_stack.top();
            eval_stack.pop();
            
            int leftOp = eval_stack.top();
            eval_stack.pop();
            
            eval_stack.push(rightop + leftOp);
        }
        else if(token == '-'){
            int right_op = eval_stack.top();
            eval_stack.pop();
            
            int leftop = eval_stack.top();
            eval_stack.pop();
            
            eval_stack.push(leftop - right_op);
        }
        else if(token == '*'){
            int right_op = eval_stack.top();
            eval_stack.pop();
            
            int left_op = eval_stack.top();
            eval_stack.pop();
            
            eval_stack.push(right_op * left_op);
        }
        else if(token == '/'){
            int right = eval_stack.top();
            eval_stack.pop();
            
            int left = eval_stack.top();
            eval_stack.pop();
            
            eval_stack.push(left / right);
        }
        else if(token == '^'){
            int right = eval_stack.top();
            eval_stack.pop();
            
            int left = eval_stack.top();
            eval_stack.pop();
            
            int exp = right;
            int result = 1;
            
            while(exp > 0 ){
                result *= left;
                exp--;
            }
            eval_stack.push(result);

        }
            
    }
    return eval_stack.top();

}
