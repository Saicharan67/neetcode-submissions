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
    int glb_max = 0;
    int temp(TreeNode* root){
        
        if(root==nullptr){
            return -1;
        }
        if((root->left==nullptr && root->right==nullptr)){
            return 0;
        }

        int l = 1+temp(root->left);
        int r = 1+temp(root->right);
       
        glb_max = max(glb_max , (l+r));

        return max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {

        temp(root);

        return glb_max;
    }
};
