void merge(ListNode*& ahead,ListNode*& bhead)
{
	ListNode* chead = new ListNode;
	ListNode* pc = chead;
	ListNode* pa = ahead->next;
	ListNode* pb = bhead->next;
	//插入所有元素
	while(pa != NULL)
	{
		ListNode* newnode = new ListNode(pa->data);
		pc->next = newnode;
		pc = newnode;
		pa= pa->next;
	}
	while(pb != NULL)
	{
		int flag = 1;
		for(ListNode* cur = chead; cur->next != NULL; cur=cur->next)
		{
			if(cur->next->data == pb->data)
			{
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			ListNode* newnode = new ListNode(pb->data);
			pc->next = newnode;
			pc = newnode;
			pb = pb->next;
		}
	}
	
}