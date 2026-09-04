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
// class Solution {
// public:
//     vector<int> nextLargerNodes(ListNode* head) {
//         vector<int>ans;
//         ListNode* temp=head;
//         while(temp->next){
//             ListNode* temp1=temp->next;
//             while(temp1){
//                 if(temp->val<temp1->val){
//                     ans.push_back(temp1->val);
//                     break;
//                 }
//                 temp1=temp1->next;
//             }
//             if(temp1==NULL)
//                 ans.push_back(0);
//             temp=temp->next;
//         }
//         ans.push_back(0);
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        vector<pair<int,int>> st;

        ListNode* temp = head;
        int i = 0;

        while(temp) {
            while(!st.empty() && st.back().first < temp->val) {
                ans[st.back().second] = temp->val;
                st.pop_back();
            }

            ans.push_back(0);
            st.push_back({temp->val, i});

            temp = temp->next;
            i++;
        }

        return ans;
    }
};