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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        while (second) {
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }

        ListNode* first = head;
        ListNode* secondHalf = prev;

        while (secondHalf) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = secondHalf->next;

            first->next = secondHalf;
            secondHalf->next = tmp1;

            first = tmp1;
            secondHalf = tmp2;
        }
    }
};

