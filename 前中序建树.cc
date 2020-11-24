//剑指offer 07. https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/ 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = traceback(preorder, inorder);
        return root;
    }

    TreeNode* traceback(vector<int> pre, vector<int> in){
        if (pre.size() == 0 || in.size() == 0) return nullptr;
        int rootval = pre[0];
        TreeNode *root = new TreeNode(rootval);
        vector<int> pre2, in2, pre3, in3;
        int i;
        for (i = 0; i < in.size(); i++){
            if (in[i] != rootval){
                in2.push_back(in[i]);
                pre2.push_back(pre[i + 1]);
            } 
            else break;
        }
        i++;
        for (;i < in.size(); i++){
            in3.push_back(in[i]);
            pre3.push_back(pre[i]);
        }
        root->left = traceback(pre2, in2);
        root->right = traceback(pre3, in3);
        return root;
    }
};