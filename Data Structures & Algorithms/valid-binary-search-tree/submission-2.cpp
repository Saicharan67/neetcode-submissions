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


    bool recurr(TreeNode* root, int minv, int maxv){
        if(root==nullptr){
            return true;
        }

        if(root->val > minv && root->val < maxv){

            return recurr(root->left,minv,min(root->val,maxv)) && recurr(root->right,max(minv,root->val),maxv);

        }else{

            return false;
        }
      
    }
    bool isValidBST(TreeNode* root) {

        return recurr(root,INT_MIN,INT_MAX);
        
    }
};
