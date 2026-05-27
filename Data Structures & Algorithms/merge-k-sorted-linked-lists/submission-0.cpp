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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode(0);
        ListNode* curr = res;

        while(!lists.empty()){
            pair<ListNode*, int> minNode = {lists[0], 0};
            for(int i=1;i<lists.size();i++){
                if(lists[i]->val<minNode.first->val){
                    minNode = {lists[i],i};
                }
            }
            if(minNode.first->next){
                lists[minNode.second] = minNode.first->next;
            }else{
                lists.erase(lists.begin()+minNode.second);
            }
            curr->next = minNode.first;
            curr = curr->next;
        }
        return res->next;
    }
};
