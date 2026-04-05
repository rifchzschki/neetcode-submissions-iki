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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prevNode = nullptr;
        ListNode* nextNode = nullptr;
        int i=0;
        while(curr!=nullptr){
            nextNode = curr->next;
            if(i>0){
                curr->next = prevNode;
            }else{
                curr->next = nullptr;
            }
            prevNode = curr;
            curr = nextNode;
            i++;
        }
        return prevNode;
    }
};
