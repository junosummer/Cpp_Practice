// Leetcode Problem 24 Swap Nodes in pairs
/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr)
            return head;
        ListNode* current = new ListNode(0);
        ListNode* ret = new ListNode(0);
        current->next = head;
        ret->next = current;
        while (current->next != nullptr && current->next->next!=nullptr)
        {
            ListNode* temp = current->next;
            current->next = current -> next->next;
            temp->next = temp->next->next;
            current->next->next = temp;
            cout<<current->next->val<<endl;
            current = temp;
        }
        return ret->next->next;
    }
};
