//
//  inpost.cpp
//  Assign8
//
//  Created by Kaleb Fantu on 10/26/22.
//

#include "inpost.hpp"
#include "mystack.h"
#include <string>

using namespace std;

string convert(const string& infix)
{
    mystack opstack;
    string postfix = "";

    for(size_t i = 0; i < infix.length(); i++)
    {
        char token = infix[i];
        if (isalpha(token) or isdigit(token))
        {
            postfix += opstack.top();
        }
        else if(token == '(')
        {
            opstack.push(token);
        }
        else if(token == ')')
        {
            while (opstack.top() != '(')
            {
                postfix += opstack.top();
                opstack.pop();
            }
            opstack.pop();
        }
        else if(token == ' ')
        {
            int placeHolder = 0;
            placeHolder++;
        }
        else
        {
            while (opstack.empty() == false and (precedence(opstack.top()) >= precedence(token)))
            {
                postfix += opstack.top();
                opstack.pop();
            }
            opstack.push(token);
        }
    }
    while (opstack.empty() == false)
    {
        postfix += opstack.top();
        opstack.pop();
    }
    return postfix;
}
//Higher precedence is represented by a higher number
int precedence(char c)
{
    switch (c)
    {
        case '~':
            return 3;
            break;
        case '^':
            return 3;
            break;
        case '*':
            return 2;
            break;
        case '/':
            return 2;
            break;
        case '+':
            return 1;
            break;
        case '-':
            return 1;
            break;
    }
    return -1;
}
