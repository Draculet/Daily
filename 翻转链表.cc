//剑指offer24. https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/submissions/


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
    ListNode* reverseList(ListNode* head) {
        ListNode *ptr = head;
        ListNode *newhead = nullptr;
        ListNode *tmp;
        while (ptr){
            tmp = ptr->next;
            ptr->next = newhead;
            newhead = ptr;
            ptr = tmp;
        }
        return newhead;
    }
};