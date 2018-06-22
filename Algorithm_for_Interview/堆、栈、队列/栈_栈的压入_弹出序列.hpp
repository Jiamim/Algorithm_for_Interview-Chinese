/*
栈的压入、弹出序列 https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

题目来源：剑指Offer

题目描述
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

时间限制：1秒 空间限制：32768K 热度指数：161504
本题知识点： 栈

解题思路：
    1. 比较 pushV 的逆序 与 popV 是否相等，不等，则删除 popV 的第一个元素，与 pushV 中的该元素，接着比较
        如果最后两个依然不符，则不是（栈溢出）
    2. （摘自讨论区）借用一个辅助的栈，遍历压栈顺序，先讲第一个放入栈中，这里是 1，
        然后判断栈顶元素是不是出栈顺序的第一个元素，这里是4，很显然1≠4，所以我们继续压栈，
        直到相等以后开始出栈，出栈一个元素，则将出栈顺序向后移动一位，
        直到不相等，这样循环等压栈顺序遍历完成，
        如果辅助栈还不为空，说明弹出序列不是该栈的弹出顺序。

提交记录：
*/
#pragma once

#include "../all.h"

class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        /*vector<int> tmp(pushV.rbegin(), pushV.rend());

        if (pushV.size() == 2) {
            return is_vec_same(tmp, popV);
        }

        if (!is_vec_same(tmp, popV)) {
            int top = popV[0];
            popV.erase(popV.begin());
            auto it = find(pushV.begin(), pushV.end(), top);
            pushV.erase(it);
            return IsPopOrder(pushV, popV);
        }
        else
            return true;*/

        if (pushV.empty()) return false;

        stack<int> tmp;
        int j = 0;
        for (int i = 0; i < pushV.size(); i++) {
            tmp.push(pushV[i]);

            while (!tmp.empty() && tmp.top() == popV[j]) {
                tmp.pop();
                j++;
            }
        }

        return tmp.empty();
    }

    bool is_vec_same(vector<int> v1, vector<int> v2) {
        for (int i = 0; i < v1.size(); i++)
            if (v1[i] != v2[i])
                return false;
        return true;
    }
};
