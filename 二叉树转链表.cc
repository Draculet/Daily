//剑指offer36.  https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;
        Node *head = nullptr;
        Node *pre = nullptr;
        Node *cur = nullptr;
        Node *tail = nullptr;

        stack<Node *> s;
        Node *ptr = root;
        while (ptr || !s.empty()){
            while (ptr){
                s.push(ptr);
                ptr = ptr->left;
            }
            Node *cur = s.top();
            tail = cur; //tail尾部在中序遍历最后
            s.pop();
            if (head == nullptr){
                head = cur;
                pre = cur;
            }
            else {
                cur->left = pre;
                pre->right = cur;
                pre = cur;
            }

            ptr = cur->right;
        }
        /*
        ptr = head;
        while (ptr->right){
            ptr = ptr->right;
        }
        Node * tail = ptr;
        tail->right = head;
        head->left = tail;
        */
       
        //头尾相连
        tail->right = head;
        head->left = tail;
        return head;
    }
};