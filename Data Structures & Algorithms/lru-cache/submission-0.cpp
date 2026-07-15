
struct ListNode {
    int key;
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode() : key(0), val(0), next(nullptr), prev(nullptr) {}
    ListNode(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
};
class LRUCache {
public:
    ListNode *head = new ListNode(0,0);
    ListNode *tail = new ListNode(0,0);
    unordered_map<int,ListNode*> mp;
    int size = 0;
    int curr_size = 0;
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void moveToTail(ListNode* node) {
        // detach
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // attach before tail
        ListNode* tail_prev = tail->prev;
        tail_prev->next = node;
        node->prev = tail_prev;
        node->next = tail;
        tail->prev = node;
    }
    int get(int key) {
        if(mp.count(key)==0){
            return -1;
        }
        ListNode *temp = mp[key];
        moveToTail(temp);
        return temp->val;
    }
    
    void put(int key, int value) {
       
         if(mp.count(key)){
       // update existing
            ListNode* node = mp[key];
            node->val = value;
            moveToTail(node);
            return;
        }
     
         if(curr_size==size){
            ListNode *del = head->next;
            head->next = del->next;
            del->next->prev = head;
           
            mp.erase(del->key);
            delete(del);
            curr_size -= 1;
        }
         if(curr_size==size){
            ListNode *del = head->next;
            head->next = del->next;
            del->next->prev = head;
           
            mp.erase(del->key);
            delete(del);
            curr_size -= 1;
        }
         ListNode* node = new ListNode(key, value);
        ListNode* tail_prev = tail->prev;
        tail_prev->next = node;
        node->prev = tail_prev;
        node->next = tail;
        tail->prev = node;
        mp[key] = node;
        curr_size++;
    }
};
