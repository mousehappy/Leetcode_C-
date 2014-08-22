//
//  Postorder.h
//  impala_be
//
//  Created by shwang on 8/20/14.
//  Copyright (c) 2014 shwang. All rights reserved.
//

#ifndef __impala_be__Postorder__
#define __impala_be__Postorder__

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include "DataStructs.h"

using namespace std;

class Postorder{
public:
    vector<int> postorderTraversal(TreeNode *root) {
        deque<TreeNode*> nodeStack;
        set<TreeNode*> popedNodes;
        vector<int> result;
        
        if(!root)
            return result;
        
        nodeStack.push_back(root);
        
        TreeNode* current;
        while (nodeStack.size() > 0) {
            current = nodeStack.back();
            if((!current->left || popedNodes.find(current->left) != popedNodes.end())&&(!current->right || popedNodes.find(current->right) != popedNodes.end()))
            {
                result.push_back(current->val);
                popedNodes.insert(current);
                nodeStack.pop_back();
            }
            else if(current->left && popedNodes.find(current->left) == popedNodes.end())
            {
                nodeStack.push_back(current->left);
                continue;
            }
            else if(current->right && popedNodes.find(current->right) == popedNodes.end())
            {
                nodeStack.push_back(current->right);
            }
        }
        
        return result;
    }
};

#endif /* defined(__impala_be__Postorder__) */
