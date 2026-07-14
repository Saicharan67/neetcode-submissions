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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        

        int carry = 0;
        ListNode *head = l1;
        while(l1->next && l2->next){
            int temp = (l1->val + l2->val+carry)%10;
            carry = (l1->val + l2->val+carry)/10;
            l1->val = temp;
            l1= l1->next;
            l2 = l2->next;
        }
        int temp = (l1->val + l2->val+carry)%10;
        cout<<temp;
        carry = (l1->val + l2->val+carry)/10;
        l1->val = temp;
      
        if(l2->next){
            l1->next = l2->next;
           
        }
        
        
        
        
           
        ListNode *prev =  l1;
         l1= l1->next;
        while(l1){
                int temp = (l1->val +carry)%10;
                carry = (l1->val +carry)/10;
                l1->val = temp;
                prev = l1;
                l1 = l1->next;
        }
      
        if(carry!=0){
            ListNode *temp = new ListNode();
            temp->val = carry;
            prev->next = temp;
            cout<<prev->val;
        }
          
        

        return head;
    }
};
