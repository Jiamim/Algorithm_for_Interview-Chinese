/*
丑数 https://www.nowcoder.com/practice/6aa9e04fc3794f68acf8778237ba065b?tpId=13&tqId=11186&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
把只包含因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含因子7。 
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

时间限制：1秒 空间限制：32768K 热度指数：124289
本题知识点： 数组

解题思路：
    1. 使用一个 set 来保存丑数，使有序
        这样就要求每次加入的丑数必须是比 set 中最大丑数大的最小丑数
    2. 优化寻找最小丑数的过程（来自讨论区）
        其实每次我们只用比较3个数：用于乘2的最小的数、用于乘3的最小的数，用于乘5的最小的数。
        也就是比较(2*x , 3*y, 5*z) ，x>=y>=z的
        注意 x,y,z 的增加逻辑

        class Solution {
        public:
            int GetUglyNumber_Solution(int index) {
                if (index < 7)return index;
                vector<int> res(index);
                res[0] = 1;
                int t2 = 0, t3 = 0, t5 = 0, i;
                for (i = 1; i < index; ++i)
                {
                    res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
                    if (res[i] == res[t2] * 2)t2++;
                    if (res[i] == res[t3] * 3)t3++;  // 注意不能使用 if else
                    if (res[i] == res[t5] * 5)t5++;
                }
                return res[index - 1];
            }
        };

提交记录：
    1. 找最小丑数的逻辑有误
    2. 第二次暴力搜索过了
*/

#pragma once

#include "../all.h"

class Solution {
public:
    set<int> s;
    int GetUglyNumber_Solution(int index) {
        if (index < 7) return index;
        s.emplace(1);

        int m = 1; // 记录当前最大的丑数
        while (s.size() < index) {
            int mm = m * 2;  // 记录大于 m 的最小丑数
            for (auto i : s) {
                int tmp;
                tmp = i * 2;
                if (tmp > m)
                    mm = min(mm, tmp);
                tmp = i * 3;
                if (tmp > m)
                    mm = min(mm, tmp);
                tmp = i * 5;
                if (tmp > m)
                    mm = min(mm, tmp);
            }
            m = mm;
            s.emplace(mm);
        }
        return m;
    }
};

void 
solve()
{
    Solution().GetUglyNumber_Solution(10);
}
