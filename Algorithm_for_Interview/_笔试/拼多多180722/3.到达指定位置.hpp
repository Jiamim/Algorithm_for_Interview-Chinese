/*
到达指定位置
> Leetcode 754. 到达终点数字 https://leetcode-cn.com/problems/reach-a-number/description/

思路：
    > 一道乐视网的面试题，求解答？ - 知乎 https://www.zhihu.com/question/50790221/answer/125213696
*/
#pragma once

#include <cstdio>
#include <cmath>

int minStep(int x) {
    if (x == 0) return 0;
    if (x<0) x = -x;
    int n = sqrt(2 * x);    // 这里相当于选了一个下界， n=1 开始也能过

    while ((n + 1)*n / 2 - x & 1 || (n + 1)*n / 2 < x)
        ++n;
    return n;
}

void
solve()
{
    int x;
    while (scanf("%d", &x))
        printf("%d\n", minStep(x));
}