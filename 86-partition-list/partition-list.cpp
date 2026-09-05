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
//     ListNode* partition(ListNode* head, int x) {
//         if(head==NULL) return head;
//         ListNode* left=new ListNode(0);
//         ListNode* left1=left;
//         ListNode* right=new ListNode(0);
//         ListNode* right1=right;
//         ListNode* temp=head;
//         int count=0;
//         while(temp){
//             ListNode* tempnode=new ListNode(temp->val);
//             if(temp->val<x){
//                 left1->next=tempnode;
//                 left1=left1->next;
//             }else if(temp->val>x){
//                 right1->next=tempnode;
//                 right1=right1->next;
//             }
//             temp=temp->next;
//         }
//         ListNode* tempnodee=new ListNode(x);
//         left1->next=tempnodee;
//         right=right->next;
//         tempnodee->next=right;
//         return head=left->next;
//     }
// };


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* large = new ListNode(0);

        ListNode* s = small;
        ListNode* l = large;

        while (head) {
            if (head->val < x) {
                s->next = head;
                s = s->next;
            } else {
                l->next = head;
                l = l->next;
            }
            head = head->next;
        }

        l->next = NULL;
        s->next = large->next;

        return small->next;
    }
};