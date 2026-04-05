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
    bool hasCycle(ListNode* head) {
        if(head==nullptr) return false;
        ListNode* first = head, *second = first->next;

        int it = 0;
        while(first->next && second->next){
            if(it%2){
                first = first->next;
            }else{
                int tmp=2;
                while(tmp-- && second->next){
                    second = second->next;
                    if(first == second) return true;
                }
            }
            it++;
            if(first == second && second!=head) return true;
        }
        return false;
    }
};


// 1 2 3 4 5 6
//     |