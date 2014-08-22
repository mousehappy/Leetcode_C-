//
//  SimplifyPath.h
//  Leetcode
//
//  Created by shwang on 8/22/14.
//  Copyright (c) 2014 shwang. All rights reserved.
//

#ifndef Leetcode_SimplifyPath_h
#define Leetcode_SimplifyPath_h
#include <string>
#include <deque>

using namespace std;

class SimplifyPath
{
public:
    string simplifyPath(string path) {
        
        deque<string> stack;
        string simplePath = "";
        int length = (int)path.length();
        if (length == 0) {
            return "";
        }
        
        int start = 0, end = 0;
        
        string folder = "";
        while (end != string::npos && start < length) {
            end = (int)path.find_first_of('/', start);
            if(start != end)
            {
                if(end != string::npos)
                    folder = path.substr(start, end-start);
                else
                    folder = path.substr(start);
                
                if(folder == "..")
                {
                    if(!stack.empty())
                        stack.pop_back();
                }
                else if(folder != ".")
                {
                    stack.push_back(folder);
                }
            }
            start = end+1;
        }
        
        if(stack.empty())
            return "/";

        while (!stack.empty()) {
            simplePath.append("/");
            simplePath.append(stack.front());
            stack.pop_front();
        }
        
        return simplePath;
    }
};

#endif
