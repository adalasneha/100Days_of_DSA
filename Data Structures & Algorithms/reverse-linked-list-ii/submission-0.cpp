class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        for (int i = 1; i < left; i++)
            prev = prev->next;

        ListNode* curr = prev->next;
        ListNode* prevNode = nullptr;

        for (int i = left; i <= right; i++) {
            ListNode* nextNode = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = nextNode;
        }

        ListNode* tail = prev->next;
        tail->next = curr;
        prev->next = prevNode;

        return dummy->next;
    }
};