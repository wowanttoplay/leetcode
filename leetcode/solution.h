#pragma once
#include"tool.h"
struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};
class solution
{
	void PrintReverList(ListNode* pHead)
	{
		if (pHead == nullptr)
			return;
		PrintReverList(pHead->m_pNext);
		printf("%d\t", pHead->m_nKey);
	}
private:
	ListNode* root;
};

