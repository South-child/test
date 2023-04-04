class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* guardHead = new ListNode(0);//定义一个哨兵位的头节点
        guardHead->next = head;

        ListNode* cur = guardHead;

        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode* tmp1 = cur->next;
            ListNode* tmp2 = cur->next->next->next;

            //交换
            cur->next = cur->next->next;
            cur->next->next = tmp1;

            cur->next->next->next = tmp2;

            cur = cur->next->next;
        }
        head = guardHead->next;
        delete guardHead;
        return head;
    }
};