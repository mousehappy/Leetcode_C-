//
//  evalRPN.h
//  impala_be
//
//  Created by shwang on 8/20/14.
//  Copyright (c) 2014 shwang. All rights reserved.
//

#ifndef __impala_be__evalRPN__
#define __impala_be__evalRPN__
#include <string>
#include <vector>

#include <iostream>

using namespace std;

class evalRPN{
public:
    int eval(vector<string> &tokens);
};

#endif /* defined(__impala_be__evalRPN__) */
