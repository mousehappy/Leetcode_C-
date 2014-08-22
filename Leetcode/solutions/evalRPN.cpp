//
//  evalRPN.cpp
//  impala_be
//
//  Created by shwang on 8/20/14.
//  Copyright (c) 2014 shwang. All rights reserved.
//

#include "evalRPN.h"
#include <deque>
#include <queue>
#include "DataStructs.h"

int evalRPN::eval(vector<string> &tokens)
{
    deque<int> lArgs;
    
    vector<string>::iterator iter = tokens.begin();
    
    int arg1 = 0, arg2 = 0;
    for (; iter != tokens.end(); iter++) {
        
        if( *iter == "+")
        {
            arg2 = lArgs.back();
            lArgs.pop_back();
            arg1 = lArgs.back();
            lArgs.pop_back();
            lArgs.push_back(arg1 + arg2);
        }
        else if( *iter == "-" )
        {
            arg2 = lArgs.back();
            lArgs.pop_back();
            arg1 = lArgs.back();
            lArgs.pop_back();
            lArgs.push_back(arg1 - arg2);
        }
        else if ( *iter == "*" )
        {
            arg2 = lArgs.back();
            lArgs.pop_back();
            arg1 = lArgs.back();
            lArgs.pop_back();
            lArgs.push_back(arg1 * arg2);
        }
        else if( *iter == "/" )
        {
            arg2 = lArgs.back();
            lArgs.pop_back();
            arg1 = lArgs.back();
            lArgs.pop_back();
            lArgs.push_back(arg1 / arg2);
        }
        else
        {
            lArgs.push_back(atoi(iter->c_str()));
        }
    }
    
    return lArgs.back();
}