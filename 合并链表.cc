//剑指offer25 https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2) return l2;
        if (l2 == nullptr && l1) return l1;
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        ListNode *head, *ptr;
        if (l1->val < l2->val){
            head = ptr = l1;
            l1 = l1->next;
        }
        else {
            head = ptr = l2;
            l2 = l2->next;
        }
        while (l1 && l2){
            if (l1->val < l2->val){
                ptr->next = l1;
                l1 = l1->next;
            } else {
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }
        if (l1) ptr->next = l1;
        else ptr->next = l2;
        return head;
    }
};