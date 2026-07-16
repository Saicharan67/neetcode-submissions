/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    pair<ListNode*, ListNode*> reverseList(ListNode* head,int k) {

        ListNode *temp = NULL;
        ListNode *ret = head;

        while(k){

            ListNode *next = head->next;

            head->next = temp;
            temp  = head;
            head = next;
            k-=1;
        }

        return {temp,ret};
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode *first = head;
         ListNode *first1 = head;
        ListNode *prev = new ListNode(0);
        ListNode *ret = nullptr;
        int i = 0;
        while(head){
            if(i!=0 && i%k==0){
                auto retr = reverseList(first,k);
                retr.second->next = head;
                prev->next = retr.first;
                prev = first;
                first = head;
                if(ret == nullptr){
                    ret = retr.first;
                }
            }
            i++;
            head = head->next;
        }
        
         if(i!=0 && i%k==0){
               auto retr = reverseList(first,k);
                retr.second->next = head;
                prev->next = retr.first;
                prev = first;
                first = head;
                 if(ret == nullptr){
                    ret = retr.first;
                }
        }
       
        return ret==nullptr? first1: ret;
    }
};
