#pragma once

#include "./all.h"

void
solve()
{
    vector<int> v{ 1,2,2,3,4,6,6,6,8,9 };
    cout << v.size() << endl;

    auto ret = upper_bound(v.begin(), v.end(), 7);
    
    if(ret != v.end())
        print(*ret);
}