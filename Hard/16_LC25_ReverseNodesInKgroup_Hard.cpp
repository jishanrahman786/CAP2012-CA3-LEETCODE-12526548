
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        int count = 0;

        // Check if k nodes are available
        while (temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }

        // If less than k nodes are available
        if (count < k) {
            return head;
        }

        // Reverse k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        count = 0;

        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Connect remaining list
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};
