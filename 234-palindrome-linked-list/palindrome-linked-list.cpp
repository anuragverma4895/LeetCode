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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode * prev=NULL;
        ListNode* curr=head;
        ListNode* front;
        while(curr!=NULL){
            front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        head=prev;
        return head;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *temp1=head;
        ListNode *temp2=middleNode(head);
        ListNode *temp3=reverseList(temp2);
        while(temp1!=NULL && temp3!=NULL){
            if(temp1->val!=temp3->val){
                return false;
            }
            temp1=temp1->next;
            temp3=temp3->next;
        }
        return true;

    }
};