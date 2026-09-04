// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* reverse(ListNode* head){
//         if(head==NULL or head->next==NULL) return head;
//         ListNode* newHead=reverse(head->next);
//         head->next->next=head;
//         head->next=NULL;
//         return newHead;
//     }
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//         if(head==NULL or head->next==NULL or left==right) return head;
//         ListNode* l=NULL;
//         ListNode* r=NULL;
//         ListNode* prev1=NULL;
//         ListNode* prev2=NULL;
//         ListNode* temp=head;
//         for(int i=1;i<=right;i++){
//             if(i==left) l=temp;
//             if(i==right) r=temp;
//             if(l==NULL){
//                 prev1=temp;
//             }
//             temp=temp->next;
//         }
//         if(r->next){
//             prev2=r->next;
//         }
//         r->next=NULL;
//         reverse(l);
//         if(prev1)
//             prev1->next=r;
//         l->next=prev2;
//         if(prev1==NULL){
//             head=r;
//         }
//         return head;
//     }
// };

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;

        ListNode* dummy=new ListNode(0);
        dummy->next = head;

        ListNode* prev =dummy;

        for(int i = 1; i < left; i++)
            prev = prev->next;

        ListNode* curr = prev->next;

        for(int i = 0; i < right - left; i++){
            ListNode* temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }
        return dummy->next;
    }
};