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
    int gMax = 0;
    void recurr(TreeNode* root, int maxG){
        if(root==nullptr){
            return;
        }

        if(root->val>=maxG){
            gMax+=1;
            maxG = root->val;
        }
        recurr(root->left,maxG);
        recurr(root->right,maxG);
    }
    int goodNodes(TreeNode* root) {
        recurr(root,root->val);
        return gMax;
    }
};
