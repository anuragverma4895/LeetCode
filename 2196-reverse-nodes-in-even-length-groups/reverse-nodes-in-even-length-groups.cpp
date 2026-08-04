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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        ListNode*prev=dummy;

        ListNode* temp=head;
        int n=countNode(head);
        int a=1;
        while(temp!=NULL){
            if(a%2!=0){
                int b=a;
                while(b-- and temp->next){
                    prev->next=temp;
                    prev=prev->next;
                    temp=temp->next;
                    prev->next=NULL;
                }
                n-=a;
                a++;
                if(n<=a) break;
            }else{
                int b = a;
                ListNode* prev2=temp;
                ListNode* temp2 = NULL;
                while (b-- and temp->next) {
                    temp2=temp;
                    temp = temp->next;
                }
                temp2->next = NULL;
                ListNode* revtemp = reverse(prev2);
                prev->next = revtemp;

                while (prev->next) {
                    prev = prev->next;
                }
                n -= a;
                a++;
                if(n<=a) break;
            }
        }
        if (n % 2 == 0) {
            ListNode* revtemp = reverse(temp);
            prev->next = revtemp;
        } else {
            prev->next = temp;
        }
        return dummy->next;
    }
};