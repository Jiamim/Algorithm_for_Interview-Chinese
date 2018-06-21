#pragma once
#pragma once

#include <iostream>
#include <string>
#include <sstream>

// ÈÝÆ÷
#include <vector>
#include <deque>
#include <stack>
#include <bitset>
#include <queue>
#include <map>
#include <set>
#include <list>

#include <functional>
#include <climits>
#include <algorithm>

using namespace std;

template<class T>
void
print(T t) {
    cout << t << endl;
}

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};