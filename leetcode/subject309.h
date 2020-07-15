#pragma once
#include "tool.h"

enum class TransStatus
{
	no = 0,	//未持有
	buy = 1,	//持有
	sell = 2		//冻结状态
};

class subject309
{
public:
	int maxProfit(vector<int>& prices)
	{
		profitMap[TransStatus::buy] = map<int, int>();
		profitMap[TransStatus::no] = map<int, int>();
		profitMap[TransStatus::sell] = map<int, int>();
		return _maxProfit(prices, TransStatus::no, 0);
	}

private:
	int _maxProfit(const vector<int>& prices, TransStatus status, int curPrice)
	{
		if (prices.size() == 0)
			return 0;

		int maxProfit = 0;

		if (profitMap[status].count(prices.size()) != 0)
		{
			return profitMap[status][prices.size()];
		}

		vector<int>nextVec(prices.begin() + 1, prices.end());
		if (status == TransStatus::sell)
		{
			maxProfit =  _maxProfit(nextVec, TransStatus::no, 0);
		}
		else if (status == TransStatus::no)
		{
			maxProfit = max(
				_maxProfit(nextVec, TransStatus::buy, prices.front()),  //买入
				_maxProfit(nextVec, TransStatus::no, 0)  //未持有
			);
		}
		else if (status == TransStatus::buy)
		{
			maxProfit = max(
				prices.front() - curPrice + _maxProfit(nextVec, TransStatus::sell, 0),	//卖出
				0 + _maxProfit(nextVec, TransStatus::buy, curPrice)	//持有
			);
		}
		else
		{
			cout << "error status" << endl;
		}
		
		if (profitMap[status].count(prices.size()) == 0)
		{
			profitMap[status][prices.size()] = maxProfit;
		}
		return maxProfit;
	}

	map<TransStatus, map<int, int>>profitMap;
};

