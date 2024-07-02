void merge(ListNode*& ahead,ListNode*& bhead)
{
    ListNode* chead = new ListNode;
    ListNode* pa = ahead->next;
    ListNode* pb = bhead->next;
    ListNode* pc = chead;
    while(pa != NULL && pb != NULL)
    {
        //判断集合A元素和集合B元素大小关系，谁小就添加谁
        if(pa->data > pb->data)
        {
            ListNode* newnode = new ListNode(pb->data);
            pc->next = newnode;
            pc = newnode;
            pb= pb->next;
        }
        else if(pa->data < pb->data)
        {
            ListNode* newnode = new ListNode(pa->data);
            pc->next = newnode;
            pc = newnode;
            pa = pa->next;
        }
        //如果相等 则添加该数值，并将两个指针都后移
        else
        {
            ListNode* newnode = new ListNode(pa->data);
            pc->next = newnode;
            pc = newnode;
            pa = pa->next;
            pb = pb->next;
        }
    }
    while(pa != NULL)
    {
        ListNode* newnode = new ListNode(pa->data);
        pc->next = newnode;
        pc = newnode;
        pa = pa->next;
    }
    while(pb != NULL)
    {
        ListNode* newnode = new ListNode(pb->data);
        pc->next = newnode;
        pc = newnode;
        pb = pb->next;
    }
}