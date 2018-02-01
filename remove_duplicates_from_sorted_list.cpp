// LeetCode Problem 83 Remove Duplicates from Sorted List
// Given a sorted linked list, delete all duplicates such that each element appear only once.

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode* prev = new ListNode(0);
        prev->next = head;
        ListNode* current = head;
        int prev_val = head->val-1;
        while(current!=nullptr)
        {
            if (current->val == prev_val)
            {
                prev->next = current->next;
                current = current->next;
            }
            else
            {
                prev_val = current->val;
                prev = current;
                current = current->next;
            }
        }
        
        return head;
    }
};


// Below is a later simplified version
/* class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current=head;
        while(current && current->next){
            if(current->val == current->next->val)
                current->next = current->next->next;
            else
                current = current->next;
        }
        return head;
    }
}; */
