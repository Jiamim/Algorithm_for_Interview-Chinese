/*
二分查找最优解的模板：
    在一定精度下，求满足条件 C 的最大/小解 x

注意点：
    - 初始化上下界：
        求最大值时，将下界 lo 初始化为一个特殊的可行解；上界初始化为一个不满足条件的解
        求最小值时，反之
    - 一般这种最优解问题会提供精度要求，需要在返回时处理
        - 最大值用“下取整” floor(ret * 1000) / 1000 ——三位精度，floor: 地板
        - 最小值用“上取整” ceil(ret * 1000) / 1000  ——三位精度，ceil:  天花板

*/
#pragma once

#include "../all.h"

/*例 1：
求大于 目标值 v(>0) 的最小值，精确到 3 位小数
*/
double min_bigger(double v) {
    // 初始化上下界
    double lo = v - EPSILON, hi = INF;

    for (size_t i = 0; i < 100; i++) {          // 100 次循环已经能达到相当的精度
        double mid = lo + (hi - lo) / 2.0;
        if (mid <= v)
            lo = mid;
        else
            hi = mid;
    }

    // 因为 hi 在解空间中（hi 必大于 v），所以返回 hi
    return ceil(hi * 1000) / 1000; // 三位精度
}


/*例 2：POJ No.1064
    有 N 条绳子，长度分别为 Li。如果从它们中切割出 K 条长度相同的绳子，求这 K 条绳子的最大长度。答案保留 2 位小数。
*/
class Solution {
public:
    double max_length(vector<double> ls, int k) {
        double lo = 0, hi = INF;

        for (size_t i = 0; i < 100; i++) {
            double mid = lo + (hi - lo) / 2;

            if (C(ls, mid, k))
                lo = mid;
            else
                hi = mid;
        }

        // 因为 lo 在解空间中，所以返回 lo
        return floor(lo * 100) / 100;
    }
private:
    bool C(vector<double> ls, double mid, double k) {
        int n = 0;
        for (size_t i = 0; i < ls.size(); i++) {
            n += ls[i] / mid;
        }

        return n >= k; 
        // n >= k 说明还有加大的空间，所以当 C 返回 true 时，lo = mid
    }
};

void
solve()
{
    auto ret = min_bigger(3.14);
    print(ret);

    vector<double> ls{ 8.02, 7.43, 4.57, 5.39 };
    int k = 11;
    ret = Solution().max_length(ls, k);
    print(ret);
}