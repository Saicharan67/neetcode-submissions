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
    int gMax = -10001;
    int recurr(TreeNode *root){
        if(root==nullptr){
            return 0;
        }

        int l = recurr(root->left);
        int r = recurr(root->right);

        gMax = max(gMax,root->val+l);
        gMax = max(root->val+r+l,gMax);
        gMax = max(gMax,root->val+r);
        gMax = max(gMax,root->val);
        int temp = max(root->val+l,root->val+r);
        return max(root->val,temp);


    }
    int maxPathSum(TreeNode* root) {
        recurr(root);
        return gMax;
    }
};
