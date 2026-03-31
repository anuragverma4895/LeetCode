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
        vector<int>ans;
        for(auto a:lists){
            while(a!=NULL){
                ans.push_back(a->val);
                a=a->next;
            }
        }
        ListNode* head= new ListNode(INT_MAX);
        ListNode* temp=head;
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            ListNode* lst=new ListNode(ans[i]);
            temp->next=lst;
            temp=temp->next;

        }
        return head->next;
    }
};