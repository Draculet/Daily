//leetcode 2.  https://leetcode-cn.com/problems/add-two-numbers/submissions/

//两数逆序链表相加

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = l1, *head2 = l1;
        int num = 0, up = 0;
        while (l1 && l2){
            num = (l1->val + l2->val + up) % 10;
            up = (l1->val + l2->val + up) / 10;
            head->val = num;
            if (l1->next && l2->next)
                head = head->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1) head->next = l1;
        else if (l2) head->next = l2;

        while (head->next){
            num = (head->next->val + up) % 10;
            up = (head->next->val + up) / 10;
            head->next->val = num;
            head = head->next;
        }
        if (up != 0){
            head->next = new ListNode(up);
        }
        return head2;
    }
};