//
//  TreeSolution.h
//  impala_be
//
//  Created by shwang on 8/22/14.
//  Copyright (c) 2014 shwang. All rights reserved.
//

#ifndef impala_be_TreeSolution_h
#define impala_be_TreeSolution_h

#include "DataStructs.h"
#include <queue>

using namespace std;

class TreeSolution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root) {
            return 0;
        }
        
        int maxDepth = 0;
        queue<pair<TreeNode*, int>> nodeQueue;
        
        nodeQueue.push(make_pair(root, 1));
        
        while(!nodeQueue.empty())
        {
            pair<TreeNode*, int> p = nodeQueue.front();
            nodeQueue.pop();
            if (p.second > maxDepth) {
                maxDepth = p.second;
            }
            
            if(p.first->left)
            {
                nodeQueue.push(make_pair(p.first->left, p.second+1));
            }
            
            if(p.first->right)
            {
                nodeQueue.push(make_pair(p.first->right, p.second+1));
            }
        }
        
        return maxDepth;
    }
    
    
};

#endif
