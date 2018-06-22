/*
二分查找模板

注意点：
    - 是否存在重复元素

模板 1 - binary_search
    - 没有重复元素时，目标值若存在，则返回索引；若不存在，返回 -1
    - 存在重复元素时，目标值若存在，则返回最小索引；若不存在，返回 -1

模板 2 - lower_bound
    - 返回大于、等于目标值的最小索引（第一个大于、等于目标值的索引）

模板 3 - upper_bound
    - 返回大于目标值的最小索引（第一个大于目标值的索引）
    
注意点：
    - 
    
*/
#pragma once

#include "../all.h"

class Solution {
public:
    int binary_search(vector<int>& nums, int v) {
        if (nums.size() < 1) return - 1;

        int lo = -1, hi = nums.size();

        while (hi - lo > 1) {                       // 退出循环时有：lo + 1 == hi
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < v)
                lo = mid;
            else
                hi = mid;
        }

        return nums[lo + 1] == v ? lo + 1 : -1;
    }

    int lower_bound(vector<int>& nums, int v) {
        if (nums.size() < 1) return -1;

        int lo = -1, hi = nums.size();

        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < v)
                lo = mid;
            else
                hi = mid;
        }

        return lo + 1; // 相比 binary_search，只有返回值不同
        // lo + 1 == hi ——根据循环条件，退出循环时，必有 `lo + 1 == hi`
        // 为什么返回 `lo+1`，而不是 `hi`？（实际上没有区别）
        //   模板开始时将 (lo, hi) 看做是一个开区间，最后退出循环时会成为 (lo, hi]，且 lo+1 == hi
        //   为了统一始终将 (lo, hi) 看做开区间，所以最后返回 lo+1
    }

    int upper_bound(vector<int>& nums, int v) {
        if (nums.size() < 1) return -1;

        int lo = -1, hi = nums.size();

        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] <= v) // 相比 lower_bound，唯一不同点：`<` -> `<=`
                lo = mid;
            else
                hi = mid;
        }

        return lo + 1;
    }
};

void
solve()
{
    vector<int> v{ 1,2,2,3,4,6,6,6,8,9 };
    cout << v.size() << endl;

    auto ret = Solution().binary_search(v, 7);
    cout << ret << endl;

    ret = Solution().lower_bound(v, 6);
    cout << ret << endl; // 5

    ret = Solution().lower_bound(v, 7);
    cout << ret << endl; // 8

    ret = Solution().upper_bound(v, 6);
    cout << ret << endl; // 8

    ret = Solution().upper_bound(v, 7);
    cout << ret << endl; // 8
}