/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       ListNode* first = head;
       ListNode* second = head;
       ListNode* prev = head;
       while(n--) 
        {
            first = first->next;
        }
        if(!first) return head->next;
       while(first){
            first = first->next;
            prev = second;
            second = second->next;
        }
        prev->next = second->next;
        return head;
    }
};
