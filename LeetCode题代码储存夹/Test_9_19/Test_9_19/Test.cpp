class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast, * slow;
        fast = slow = head;

        //fast先走n步
        while (n-- && fast != nullptr)
        {
            fast = fast->next;
        }
        //假如倒数第n个，是头节点，此时fast为空
        if (fast == nullptr)
        {
            head = slow->next;
            delete slow;
            return head;
        }
        //否则在同时走 -- 当fast走到空时，solw此时就是倒数第n个节点，删除n节点即可
        ListNode* prev = nullptr;//记录slow上一个节点
        while (fast)
        {
            prev = slow;
            fast = fast->next;
            slow = slow->next;
        }
        prev->next = slow->next;
        delete slow;
        return head;
    }
};