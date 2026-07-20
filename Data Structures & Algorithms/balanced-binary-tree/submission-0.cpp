/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    bool flag = true;
    int recurr(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        if(root->left==nullptr && root->right==nullptr){
            return 1;
        }

        int l = recurr(root->left);
        int r = recurr(root->right);

        if(abs(l-r)>1 && flag==true){
            flag = false;
        }
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        recurr(root);
        return flag;
    }
};
