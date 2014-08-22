//
//  DataStructs.h
//  impala_be
//
//  Created by shwang on 8/22/14.
//  Copyright (c) 2014 shwang. All rights reserved.
//

#ifndef impala_be_DataStructs_h
#define impala_be_DataStructs_h

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };


#endif
