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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    
        int fx = preorder[0];
        int idx = 0;
        for(int i = 0; i<inorder.size(); i++){
            if(inorder[i]==fx){
                idx = i;
                break;
            }
        }
        int n = inorder.size();
        TreeNode *root = new TreeNode(inorder[idx]);
        if(idx>0){
            std::vector<int> first_k(preorder.begin()+1, preorder.begin() + idx+1);
            std::vector<int> second_k(inorder.begin(), inorder.begin() + idx);
            root->left = buildTree(first_k,second_k);
        }
        if(idx+1<n){
            std::vector<int> first_k(preorder.begin()+idx+1, preorder.end());
            std::vector<int> second_k(inorder.begin()+idx+1, inorder.end());
            root->right = buildTree(first_k,second_k);
        }

        return root;
    }
};
