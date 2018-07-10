/*
406. 根据身高重建队列 - LeetCode (中国) https://leetcode-cn.com/problems/queue-reconstruction-by-height/description/

问题描述：
    假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。

    注意：
        总人数少于1100人。

    示例
        输入:
            [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

        输出:
            [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

思路：
    贪心算法

    每次找出剩余部分最高的，并按 k 值插入到新的数组
    > [Easy concept with Python/C++/Java Solution](https://leetcode.com/problems/queue-reconstruction-by-height/discuss/89345/Easy-concept-with-PythonC++Java-Solution) - LeetCode 讨论区
    
    （不要问是如何抽象到这个数学模型的，唯一的方法就是熟能生巧）
*/
#pragma once

#include "../all.h"

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        auto cmp = [](const pair<int, int> &p1, const pair<int, int> &p2) {
            return p1.first > p2.first  // 先降序
                || (p1.first == p2.first && p1.second < p2.second);  // 再升序
        };
        sort(people.begin(), people.end(), cmp);

        vector<pair<int, int>> ret;
        for (auto p : people)
            ret.insert(ret.begin() + p.second, p);

        return ret;
    }
};

void
solve()
{

}
