class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int t = 0;
        ListNode* guard = new ListNode;
        ListNode* cur = guard;
        while(l1 || l2)
        {
            int a = 0,b = 0;
            if(l1)
            {
                a = l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                b = l2->val;
                l2 = l2->next;
            }
            t = a + b + t;
            cur->next = new ListNode(t%10);
            t /= 10;
            cur = cur->next;
        }
        if(t) cur->next = new ListNode(t);
        return guard->next;
    }
};