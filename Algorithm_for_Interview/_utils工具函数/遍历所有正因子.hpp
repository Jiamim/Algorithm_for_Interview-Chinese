/*
遍历所有正因子并不是什么复杂的操作；
但这里想强调的是，它也没有更高级的技巧。

时间复杂度 O(√n)

注意点：
    1. 找到了小因子，另一个大因子可以直接求出，所以遍历的上限应该是 √n
    2. 循环条件 `i <= √n` 可以写作 `i*i <= n`
    3. 如果 n 正好是算术平方，此时 小因子 == 大因子

*/
#pragma once

#include "../all.h"

class Solution {
public:
    void getAllPositiveDivisor(int num, vector<vector<int>>& ret) {
        for (int i = 1; i*i <= num; i++) {
            if (num % i == 0) {
                ret.emplace_back(i);
                if (num / i != i)
                    ret.emplace_back(num / i);
            }
        }
    }
};

void
solve()
{

}
