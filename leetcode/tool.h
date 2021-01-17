#pragma once
//所有的头文件和一些基本的通用函数
#include<vector>
#include <string>
#include<memory>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
using namespace std;

template<typename T>
void PrintVec(const vector<T>& vec)
{
	ostream_iterator<T> out(cout, ", ");
	copy(vec.begin(), vec.end(), out);
	cout << endl;
}

template<typename _KEY, typename _VALUE>
void PrintMap(const map<_KEY, _VALUE>& target)
{
	for (auto& cell : target)
	{
		cout << "key: " << cell.first << "\tvalue: " << cell.second << endl;
	}
}
