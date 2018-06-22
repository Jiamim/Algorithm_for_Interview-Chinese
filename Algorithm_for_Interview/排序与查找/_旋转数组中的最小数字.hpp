/*
旋转数组的最小数字 https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=13&tqId=11159&tPage=1&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

题目来源：剑指Offer

题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

时间限制：3秒 空间限制：32768K 热度指数：283825
本题知识点： 查找

解题思路：
    “非递减”说明元素可能重复
    注意 {3,4,5,1,2,3} 的情况，此时只要 lo++ 或 hi-- 即可

提交记录：
    
*/
#pragma once

#include "../all.h"

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty()) {
            return 0;
        }

        int lo = 0;
        int hi = rotateArray.size() - 1;

        // 完全旋转，或者说没有旋转
        if (rotateArray[lo] < rotateArray[hi])
            return rotateArray[lo];

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (rotateArray[mid] > rotateArray[hi])
                lo = mid + 1;
            else if (rotateArray[mid] < rotateArray[hi])
                hi = mid;
            else
                hi--;  // 防止这种情况 {3,4,5,1,2,3}
        }
        
        return rotateArray[lo];
    }
};

void solve() {
    vector<int> v{ 3,4,5,1,2,3 };
    int ret = Solution().minNumberInRotateArray(v);
    print(ret);
}
