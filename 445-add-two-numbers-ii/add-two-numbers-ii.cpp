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
        if(head==NULL or head->next==NULL) return head;
        ListNode* newHead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=reverse(l1);
        ListNode* temp2=reverse(l2);

        int carry=0;
        ListNode* ans = new ListNode(0);
        ListNode* temp=ans;
        while(temp1 and temp2){
            int a=temp1->val+temp2->val+carry;
            ListNode* prev=new ListNode(a%10);
            temp->next=prev;
            temp=temp->next;
            carry=a/10;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1) {
            int a = temp1->val + carry;
            ListNode* prev = new ListNode(a % 10);
            temp->next = prev;
            temp = temp->next;
            carry = a / 10;
            temp1 = temp1->next;
        }
        while(temp2) {
            int a = temp2->val + carry;
            ListNode* prev = new ListNode(a % 10);
            temp->next = prev;
            temp = temp->next;

            carry = a / 10;
            temp2 = temp2->next;
        }
        if(carry) {
            temp->next = new ListNode(carry);
        }
        return reverse(ans->next);
    }
};