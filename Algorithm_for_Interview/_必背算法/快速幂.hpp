/*
快速幂算法

例子说明：
- 求 3^20 = 9^10 = 81^5 (= 81*81^4) = 81*6561^2 = 81*43046721
- 循环次数 = `bin(20)`的位数 = `len(10100)` = 5
*/
#include "../all.h"

double quickPow(double base, int p) {
    double ret = 1.0;
    int q = abs(p);
    while (q > 0) {
        if (q & 1)          // 如果指数为奇数；一个数不断除 2 至少有一次会变成奇数，2/2 = 1
            ret *= base;    // 81^5=(1*81)*81^4
        base *= base;       // 3^20=(3*3)^(20/2)
        q >>= 1;            // 除 2
    }
    return p > 0 ? ret : 1 / ret;
}

void
solve()
{
    print(quickPow(5, 2));  // 25
}