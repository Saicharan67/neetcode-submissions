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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

       
        ListNode dummy(0);
        ListNode *temp = &dummy;

        while(list1 && list2){

            if(list1->val>list2->val){
                temp->next = list2;
                list2 = list2->next;
            }else{
                temp->next = list1;
                list1 = list1->next;
            }
            
            temp = temp->next;
        }

        if(list1){
            temp->next = list1;
        }
        if(list2){
            temp->next = list2;
        }
        
        return dummy.next;
    }

    // Recursive merge sort
    ListNode* mergeSort(std::vector<ListNode *>& arr, int left, int right) {
        if (left >= right) return arr[left]; // Base case
        int mid = left + (right - left) / 2; // Avoid overflow
        ListNode *l1 =  mergeSort(arr, left, mid); // Sort halves
        ListNode *l2 = mergeSort(arr, mid + 1, right);
        return mergeTwoLists(l1,l2); // Merge
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size()==0) return nullptr;

        return mergeSort(lists, 0, lists.size() - 1); //
        
    }
};
