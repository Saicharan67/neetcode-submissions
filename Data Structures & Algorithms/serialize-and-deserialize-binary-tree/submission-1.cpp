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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string s = "";
        vector<int> v;
        deque<TreeNode*> st;
        st.push_back(root);

        while(st.size()){

            TreeNode* temp = st[0];
            st.pop_front();
            if(temp==nullptr){
                v.push_back(10001);
            }else{
            v.push_back(temp->val);
            }
            if(temp!=nullptr){
                st.push_back(temp->left);
                st.push_back(temp->right);
            }
        }
         for(int i = 0 ;i <v.size(); i++){
            if(v[i]==10001){
                s+='@';
            }else{
                s+=to_string(v[i]);
            }
            if(i!=v.size()-1){
                s+=',';
            }
        }
        cout<<s;
        return s;

    }
    deque<string> split(const string& s, char delimiter) {
        deque<string> tokens;
        string token;
        std::stringstream ss(s);
        while (std::getline(ss, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
            if(data.empty()) return nullptr;

            deque<string> tokens = split(data,',');
            if(tokens[0]=="@") return nullptr;

            TreeNode *root = new TreeNode(stoi(tokens[0]));
            tokens.pop_front();
            deque<TreeNode*> dq;
            dq.push_back(root);

           
            while(dq.size()){
                TreeNode *temp = dq.front();
                dq.pop_front();

               if (!tokens.empty()) {
                    string leftVal = tokens.front(); tokens.pop_front();
                    if (leftVal != "@") {
                        temp->left = new TreeNode(stoi(leftVal));
                        dq.push_back(temp->left);
                    }
                }

                if (!tokens.empty()) {
                    string rightVal = tokens.front(); tokens.pop_front();
                    if (rightVal != "@") {
                        temp->right = new TreeNode(stoi(rightVal));
                        dq.push_back(temp->right);
                    }
                }
            }

            return root;
    }
};
