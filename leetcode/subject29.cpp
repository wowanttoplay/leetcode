#include "subject29.h"

int subject29::divide(int dividend, int divisor)
{
	int result = 0;//����ĵ�����
	long long a = dividend, b = divisor;
	bool isNagetive_one = a < 0 ? true : false;
	bool isNagetive_sec = b < 0 ? true : false;
	a = abs(a);
	b = abs(b);
	auto tb = b;
	long count = 1;
	//�������������������������INT_MIN�Ļ���û����ȷ�Ľ��
	if (a > INT_MAX && b == 1)
		return isNagetive_one == isNagetive_sec ? INT_MAX : INT_MIN;
	while (a >= tb || tb > b)
	{
		if (a >= tb)
		{
			a -= tb;
			result += count;
			tb += tb;
			count += count;
		}
		else
		{
			tb = b;
			count = 1;
		}
		
	}
	return isNagetive_one == isNagetive_sec ? result : -result;
}
