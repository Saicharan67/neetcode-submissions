/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }

        if(mp.count(node)>0){
            return node;
        }

        Node *cl_new = new Node(node->val);

        mp[node] = cl_new;

        for(auto nei:node->neighbors){

            cloneGraph(nei);
        }
        vector<Node*> cl_nei;
        for(auto nei:node->neighbors){

            cl_nei.push_back(mp[nei]);

        }

        cl_new->neighbors = cl_nei;

        return cl_new;
       
    }
};
