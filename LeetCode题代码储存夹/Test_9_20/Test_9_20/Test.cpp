class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        //快指针走两步，慢指针走一步，如果相遇就代表有环
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (slow == fast)
                return true;
        }
        return false;
    }
};