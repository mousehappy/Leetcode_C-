//
//  SortList.h
//  impala_be
//
//  Created by shwang on 8/20/14.
//  Copyright (c) 2014 shwang. All rights reserved.
//

#ifndef __impala_be__SortList__
#define __impala_be__SortList__

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class SortList{
public:
    ListNode* sortlist(ListNode *head);
    void mergelist(ListNode *head1, ListNode* tail1, ListNode* head2, ListNode* tail2, ListNode* &newhead, ListNode* &newtail);
    ListNode* getTail(ListNode *head, int step);
};

#endif /* defined(__impala_be__SortList__) */
