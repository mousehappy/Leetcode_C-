//
//  SortList.cpp
//  impala_be
//
//  Created by shwang on 8/20/14.
//  Copyright (c) 2014 shwang. All rights reserved.
//
#include "SortList.h"

ListNode* SortList::sortlist(ListNode *head)
{
    if (!head || !head->next) {
        return head;
    }
    
    int len = 1;
    int step = 1;

    ListNode* ret = head;
    ListNode* lastHead = NULL;
    ListNode* lastTail = NULL;
    ListNode *head1, *tail1, *head2, *tail2;
    ListNode *newHead, *newTail;
    
    ListNode* current = head;
    while (current->next) {
        len++;
        current = current->next;
    }
    
    for (; step < len; step*=2) {
        lastTail = NULL;
        current = ret;
        while (current) {
            head1 = tail1 = head2 = tail2 = NULL;
            head1 = current;
            tail1 = getTail(head1, step);
            if(!tail1->next)
            {
                lastTail->next = head1;
                break;
            }
            head2 = tail1->next;
            tail2 = getTail(head2, step);
            current = tail2->next;
            mergelist(head1, tail1, head2, tail2, newHead, newTail);
            if (!lastTail) {
                ret = newHead;
            }
            else{
                lastTail->next = newHead;
            }
            lastTail = newTail;
        }
    }
    
    return ret;
}


void SortList::mergelist(ListNode *head1, ListNode* tail1, ListNode* head2, ListNode* tail2, ListNode* &newhead, ListNode* &newtail)
{
    newhead = newtail = new ListNode(1);
    ListNode* lasttail = NULL;
    tail1->next = NULL;
    tail2->next = NULL;
    
    while (head1 || head2) {
        lasttail = newtail;
        
        if(!head1)
        {
            newtail=head2;
            lasttail->next=newtail;
            head2=head2->next;
        }
        else if (!head2)
        {
            newtail=head1;
            lasttail->next=newtail;
            head1=head1->next;
        }
        else if(head1->val < head2->val)
        {
            newtail=head1;
            lasttail->next=newtail;
            head1=head1->next;
        }
        else if(head1->val >= head2->val)
        {
            newtail=head2;
            lasttail->next=newtail;
            head2=head2->next;
        }
    }
    newhead = newhead->next;
}

ListNode* SortList::getTail(ListNode *head, int step)
{
    ListNode* tail = head;
    for( int i = 1; i < step; i++)
    {
        if (!tail->next) {
            break;
        }
        tail = tail->next;
    }
    return tail;
}