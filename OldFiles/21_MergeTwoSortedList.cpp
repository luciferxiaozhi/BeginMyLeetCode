/*
********************************
Create by Shepherd Chang. 
Contents from leetcode.com
********************************
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.

Example:
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode preHead(0), *p = &preHead;
        while(l1 && l2)
        {
            if(l2->val <= l1->val) {p->next = new ListNode(l2->val); l2 = l2->next;}
            else {p->next = new ListNode(l1->val); l1 = l1->next;}
            p = p->next;
        }
        while(l1)
        {
            p->next = new ListNode(l1->val); 
            l1 = l1->next;
            p = p-> next;
        }
        while(l2)
        {
            p->next = new ListNode(l2->val); 
            l2 = l2->next;
            p = p-> next;
        }
        return preHead.next;
    }
};