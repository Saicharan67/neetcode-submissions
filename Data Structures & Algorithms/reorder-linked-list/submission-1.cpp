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
    void reorderList(ListNode* head) {

            ListNode *fast = head;
            ListNode *slow = head;

            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
            }

            ListNode *second = slow->next;
            ListNode *prev = slow->next = nullptr;

            while(second!=nullptr){

                ListNode *tmp = second->next;
                second->next = prev;
                prev = second;
                second = tmp;
            }

            ListNode *first = head;
            second = prev;
            ListNode *n1 = first;
            ListNode *n2 = second;
            int i = 0;
            while(second){

                    if(i%2==0){
                        n1 = first->next;
                        first->next = n2;
                        first = n1;

                    }else{
                        n2 = second->next;
                        second->next = n1;
                        second = n2;
                    }
                    i++;
                      
            }

            

        
    }
};
