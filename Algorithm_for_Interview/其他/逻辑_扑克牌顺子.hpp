/*
扑克牌顺子 https://www.nowcoder.com/practice/762836f4d43d43ca9deb273b3de8e1f4?tpId=13&tqId=11198&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何。为了方便起见,你可以认为大小王是0。

时间限制：1秒 空间限制：32768K 热度指数：81754

解题思路：
    先排序
    计算相邻差值，如果是顺子，那么总差值应该是 4
    如果有 1 个 0，...

提交记录：
    1. 用例 [3,0,0,0,0] 没过

*/
#pragma once

#include "../all.h"

class Solution {
public:
    bool IsContinuous(vector<int> numbers) {
        sort(numbers.begin(), numbers.end());

        int sum = 0; // 记录差值
        int n_0 = 0; // 记录 0 的数量
        for (int i = 0, j = 1; i < numbers.size() - 1 && j < numbers.size(); i++, j++)
        {
            if (numbers[i] == 0) {
                n_0++;
                continue;
            }
            sum += numbers[j] - numbers[i];
        }

        return sum == 4 || n_0 == 4;
    }
};

void
solve()
{

}