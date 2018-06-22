/*
数组中的逆序对 https://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5?tpId=13&tqId=11188&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。
并将P对1000000007取模的结果输出。 即输出P%1000000007

输入描述:
题目保证输入的数组中没有的相同的数字

数据范围：
    对于%50的数据,size<=10^4
    对于%75的数据,size<=10^5
    对于%100的数据,size<=2*10^5
示例1
    输入
    1,2,3,4,5,6,7,0
    输出
    7

时间限制：1秒 空间限制：65536K(64MB) 热度指数：147592
本题知识点： 数组

思路描述：
    基本思路：冒泡排序（不过估计又会在和时间上卡主）
    注意空间限制和对 size 的特别说明，显然是要你平衡时间和空间的利用
    
    思路 2: 复制原数组，并对其排序，则一个数的位置提前多少，说明有多少逆序对
        （不对）
        应该是记录每个数往后移动的位数
        （不对，这跟上面是一样的）

    思路 3：用一个 map 记录 (i, min)，一旦 min 发生了变化，说明存在 i 个逆序对
        （错误，这样只计算了一部分）

    参考《剑指Offer》：归并排序的思想，具体见讨论区；
        有点难，折腾了很久，等下次完全把这题忘了再做一遍吧

提交记录：
    1. 基本思路 （果然在时间上挂了）

*/
#pragma once

#include "../all.h"

class Solution {
public:

    // 思路1：正确，但是超时
    int InversePairs_1(vector<int> data) {
        if (data.empty()) return 0;

        int ret = 0;
        int sz = data.size();
        for (int i = sz-1; i >= 1; i--) {
            int tmp = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (data[j] > data[i])
                    tmp++;
            }
            ret += tmp;
        }
        return ret;
    }

    // 思路2：错误
    int InversePairs_2(vector<int> data) {
        if (data.empty()) return 0;

        int ret = 0;
        vector<int> bac(data);
        map<int, int> m;
        sort(bac.begin(), bac.end());
        for (int i = 0; i < data.size(); i++)
        {
            m[data[i]] = i;
        }
        for (int i = 0; i < data.size(); i++)
        {   
            /*int tmp = m[bac[i]] - i;
            ret += tmp > 0 ? tmp : 0;*/
            int tmp = i - m[bac[i]];
            ret += tmp > 0 ? tmp : 0;
        }

        return ret;
    }

    // 思路 3 （错误）
    int InversePairs(vector<int> data) {
        if (data.empty()) return 0;

        int ret = 0;
        map<int, int> m;
        int n_min = data[0];  // 记录在索引 i 时的最小值
        m[0] = n_min;
        for(int i = 1; i<data.size(); i++)
        {
            n_min = min(n_min, data[i]);
            if (m[i-1] != n_min) {
                ret += i;
            }
            m[i] = n_min;
        }

        return ret;
    }
};

void solve()
{
    vector<int> data{ 364,637,341,406,747,995,234,971,571,219,993,407,416,366,315,301,601,650,418,355,460,505,360,965,516,648,727,667,465,849,455,181,486,149,588,233,144,174,557,67,746,550,474,162,268,142,463,221,882,576,604,739,288,569,256,936,275,401,497,82,935,983,583,523,697,478,147,795,380,973,958,115,773,870,259,655,446,863,735,784,3,671,433,630,425,930,64,266,235,187,284,665,874,80,45,848,38,811,267,575 };
    //vector<int> data{ 3,2,1,4,5,6,7,0 };
    int ret = Solution().InversePairs(data);  // 应该是 2519
    print(ret);
}