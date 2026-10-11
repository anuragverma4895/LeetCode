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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }
        if (list1 != NULL) {
            temp->next = list1;
        }
        if (list2 != NULL) {
            temp->next = list2;
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }
        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;
            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* list1 = lists[i];
                ListNode* list2 = NULL;

                if (i + 1 < lists.size()) {
                    list2 = lists[i + 1];
                }
                ListNode* merged = mergeTwoLists(list1, list2);
                mergedLists.push_back(merged);
            }
            lists = mergedLists;
        }
        return lists[0];
    }
};
