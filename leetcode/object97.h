#pragma once
#include"tool.h"


struct _help
{
    char m_value;
    int beg = -1;
    int end = -1;
    int length = INT_MAX;
};
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s)
    {
        //1. 记录每个字母的开始位置与终止位置
        vector<pair<int, int>>position(26,make_pair(-1,-1));
        for (int i = 0; i < s.size(); ++i)
        {
            int& beg = position[s[i] - 'a'].first;
            int& end = position[s[i] - 'a'].second;
            if (beg == -1)
            {
                beg = i;
                end = i;
            }
            else
            {
                end = i;
            }
        }
        //2.统计每个字母占用长度
        vector<_help>help(26);
        for (int i = 0; i < 26; ++i)
        {
            help[i].m_value = 'a' + i;
            help[i].beg = position[i].first;
            help[i].end = position[i].second;
            if (help[i].beg != -1)
                help[i].length = position[i].second - position[i].first + 1;
        }
        sort(help.begin(), help.end(), [](_help a, _help b) {return a.length < b.length; });
        //3. 贪心开搞
        vector<string>rst;
        vector<pair<int,int>>select;
        for (int i = 0; i < help.size(); ++i)
        {
            if (help[i].length == INT_MAX)
                break;
            bool isInt = false;
            for (auto cell : select)
            {
                if ((help[i].beg < cell.second && help[i].end >= cell.second)|| (help[i].end < cell.first && help[i].beg >= cell.first))
                {
                    isInt = true;
                    break;
                }
            }
            if (!isInt)
            {
                select.push_back(make_pair(help[i].beg, help[i].end));
                rst.push_back(s.substr(help[i].beg, help[i].length));
            }
        }
        return rst;

    }
};