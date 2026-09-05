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

    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* newHead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }

    int countNode(ListNode* head){
        if(head==NULL) return 0;
        int ans=0;
        while(head){
            head=head->next;
            ans++;
        }
        return ans;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        int n=countNode(head);
        if(k==1) return head;
        if(n<k) return head;
        if(n==k) return reverse(head);

        ListNode* dummy=new ListNode(0);
        ListNode* prev=dummy;

        while(temp){
            int a=k;
            ListNode* prev1=temp;
            ListNode* prev2;
            while(a--){
                prev2=temp;
                temp=temp->next;
            }
            prev2->next=NULL;
            ListNode* revtemp=reverse(prev1);
            prev->next=revtemp;
            while(prev->next){
                prev=prev->next;
            }
            n-=k;
            if(n<k){
                prev->next=temp;
                break;
            }

        }
        return dummy->next;

    }
};