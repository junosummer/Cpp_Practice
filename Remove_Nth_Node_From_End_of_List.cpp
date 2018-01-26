/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //Given a linked list, remove the nth node from the end of list and return its head.
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newp = new ListNode(0);
        newp->next = head;
        ListNode* current = newp;
        ListNode* target = newp;
        for (int i = 0; i < n+1; i++)
        {
            current = current->next;
        }
        while(current != nullptr)
        {
            current = current->next;
            target = target->next;
        }
        target->next = (target->next)->next;
        
        return newp->next;
    }
};
