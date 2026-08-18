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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                temp->next = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                temp->next = new ListNode(list2->val);
                list2 = list2->next;
            }

            temp = temp->next;
        }

        if(list1 != NULL) temp->next = list1;
        if(list2 != NULL) temp->next = list2;

        return dummy->next;
    }

    ListNode* divide(vector<ListNode*>& lists , int st , int end){
        if(st == end){
            return lists[st];
        }

        int mid = st +(end-st)/2;

        ListNode* list1 = divide(lists , st , mid);
        ListNode* list2 = divide(lists , mid+1 , end);

        return merge(list1 , list2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return 0;
        }

        return divide(lists , 0 , lists.size()-1);
    }
};