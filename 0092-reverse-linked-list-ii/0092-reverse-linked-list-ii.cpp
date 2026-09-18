class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (head == nullptr || left == right)
            return head;

        // Dummy node helps when left = 1
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Move prev to the node just before left
        ListNode* prev = dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // curr is the first node that needs reversing
        ListNode* curr = prev->next;

        // Reverse nodes one by one
        for (int i = 0; i < right - left; i++) {

            ListNode* temp = curr->next;

            curr->next = temp->next;

            temp->next = prev->next;

            prev->next = temp;
        }

        return dummy->next;
    }
};