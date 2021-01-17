// leetcode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include "tool.h"

map<int,int> GetDup(vector<int> vec) 
{
	map<int, int>result;
	for (int i = 0; i < vec.size(); ++i) 
	{
		int cur = vec[i];
		if (cur == i) 
		{
			continue;
		}
		else 
		{
			if (vec[cur] != cur)
			{
				swap(vec[cur], vec[i]);
			}
			else
			{
				result[cur] += 1;
			}
		}
	}

	return result;
}

int main() 
{
	vector<int>vec{ 1,1,2,3,4,5,2,3,1,6,9 };
	auto rst = GetDup(vec);
	PrintMap(rst);
}


