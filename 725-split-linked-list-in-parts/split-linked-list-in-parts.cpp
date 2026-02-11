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
    int totalcount(ListNode* head){
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k,NULL);

        if(head==NULL) return ans;

        int size=totalcount(head);
        int sz=size/k;
        int extra=size%k;

        ListNode* temp=head;

        for(int j=0; j<k && temp!=NULL; j++){
            ans[j]=temp;

            int partSize=sz;
            if(extra>0){
                partSize++;
                extra--;
            }

            for(int i=1;i<partSize;i++){
                temp=temp->next;
            }

            ListNode* nextPart=temp->next;
            temp->next=NULL;
            temp=nextPart;
        }

        return ans;
    }
};
