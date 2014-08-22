//
//  main.cpp
//  Leetcode
//
//  Created by shwang on 8/22/14.
//  Copyright (c) 2014 shwang. All rights reserved.
//

#include <iostream>
#include "solutions/SimplifyPath.h"

using namespace std;

int main(int argc, const char * argv[])
{

    // insert code here...
    SimplifyPath simplePath;
    
    cout<<simplePath.simplifyPath("")<<endl;
    cout<<simplePath.simplifyPath("/")<<endl;
    cout<<simplePath.simplifyPath("/..")<<endl;
    cout<<simplePath.simplifyPath("/a/./b/../../c/")<<endl;
    cout<<simplePath.simplifyPath("/home/")<<endl;
    
    return 0;
}

