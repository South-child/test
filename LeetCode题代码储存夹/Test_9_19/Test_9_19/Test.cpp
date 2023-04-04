class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast, * slow;
        fast = slow = head;

        //fast����n��
        while (n-- && fast != nullptr)
        {
            fast = fast->next;
        }
        //���絹����n������ͷ�ڵ㣬��ʱfastΪ��
        if (fast == nullptr)
        {
            head = slow->next;
            delete slow;
            return head;
        }
        //������ͬʱ�� -- ��fast�ߵ���ʱ��solw��ʱ���ǵ�����n���ڵ㣬ɾ��n�ڵ㼴��
        ListNode* prev = nullptr;//��¼slow��һ���ڵ�
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