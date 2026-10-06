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
        vector<int> ans;
        for(auto l:lists){
            while(l!=nullptr){
                ans.push_back(l->val);
                l=l->next;
            }
        }

        sort(ans.begin(),ans.end());

        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        for(auto& i:ans){
            curr->next=new ListNode(i);
            curr=curr->next;
        }

        return dummy->next;
    }
};