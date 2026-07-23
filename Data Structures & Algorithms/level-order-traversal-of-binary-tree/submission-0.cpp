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
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>> res;
       vector<int> temp;
       deque<TreeNode* > dq;
       if(root==nullptr){
        return {};
       }
       if(root->left==nullptr && root->right==nullptr){
        return {{root->val}};
       }

       dq.push_back(root);

       int n = dq.size();

       while(n){

        TreeNode*  t = dq[0];
        dq.pop_front();
        n--;
        if(t->left){
            dq.push_back(t->left);
        }
        if(t->right){
            dq.push_back(t->right);
        }
        temp.push_back(t->val);
        if(n==0){
            res.push_back(temp);
            temp = {};
            n = dq.size();
        }
       }

       return res;
    }
};
