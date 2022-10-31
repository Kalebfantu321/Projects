//
//  main.cpp
//  Assign8
//
//  Created by Kaleb Fantu on 10/26/22.
//

//*
// @return Returns 0 upon successful completion.
//********************************************************************

#include <iostream>
#include <iomanip>
#include "inpost.hpp"
#include "eval.hpp"




int main()
{
   string infix;
   string postfix;

   while (getline(cin, infix))
   {
       cout << "  infix: " << infix << endl;
       postfix = convert(infix);
       cout << "postfix: " << postfix << endl;
       int result = evaluate(postfix);
       cout << "  value: " << result << endl << endl;
   }

   return 0;
}
