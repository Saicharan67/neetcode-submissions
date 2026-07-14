/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        unordered_map<Node*,Node*> mp;

        Node *tmp = head;

        while(tmp){

            Node *new_val = new Node(tmp->val);
            mp[tmp] = new_val;
            tmp = tmp->next;
        }

        tmp = head;

        while(tmp){

            Node *copy = mp[tmp];
            copy->next = mp[tmp->next];
            copy->random = mp[tmp->random];
            tmp = tmp->next;
        }

        return mp[head];
      



        
    }
};
