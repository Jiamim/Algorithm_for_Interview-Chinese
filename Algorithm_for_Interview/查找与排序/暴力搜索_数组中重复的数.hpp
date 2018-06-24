/*
数组中重复的数字 https://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8?tpId=13&tqId=11203&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 
数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。
请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。

时间限制：1秒 空间限制：32768K 热度指数：98747
本题知识点： 数组

解题思路：
    排序 - 时间
    顺序查找 - 空间
    
提交记录：
    1. 忘记返回值；

*/
#pragma once

#include "../all.h"

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if (length <= 0) return false;

        *duplication = -1;
        set<int> s;
        for (int i = 0; i < length; i++)
        {
            if (s.count(numbers[i]) > 0) {
                *duplication = numbers[i];
                break;
            } 
            s.emplace(numbers[i]);
        }

        if (*duplication == -1) return false;
        return true;
    }
};
