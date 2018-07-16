#include "all.h"
//#include "Cpp回顾/Cpp之string专题.hpp"
//#include "常用子函数/遍历子集（递归）.hpp"
//#include "动态规划/最长回文子串.hpp"
//#include "utils/位运算.hpp"
#include "深度优先搜索\部分和问题.hpp"

using namespace std;
 
int main() {

    solve();

    cout << endl;
    system("PAUSE");
    return 0;
}

//#include <iostream>
//#include <cstdio>
//#include <stack>
//#include <algorithm>
//#include <string>
//#include <sstream>
//#include <vector>
//
//using namespace std;
//
//#define MAXN 10001

//int main() {
//
//    vector<int> tmp;
//    string s;
//    getline(cin, s);
//    //while (cin >> s) {
//    int len = s.length();
//    double ans = 0;
//    if (s[0] == '-') {
//        auto pos = find(s.begin() + 1, s.end(), '-');
//        if (pos != s.end())
//            ans = stoi(string(s.begin(), pos)) - stoi(string(pos + 1, s.end()));
//    }
//    else
//    {
//        auto pos = find(s.begin(), s.end(), '-');
//        if (pos != s.end())
//            ans = stoi(string(s.begin(), pos)) - stoi(string(pos + 1, s.end()));
//    }
//    if (s[0] == '+') {
//        auto pos = find(s.begin() + 1, s.end(), '+');
//        if (pos != s.end())
//            ans = stoi(string(s.begin(), pos)) + stoi(string(pos + 1, s.end()));
//    }
//    else
//    {
//        auto pos = find(s.begin(), s.end(), '+');
//        if (pos != s.end())
//            ans = stoi(string(s.begin(), pos)) + stoi(string(pos + 1, s.end()));
//    }
//    auto pos = find(s.begin(), s.end(), '*');
//    if (pos != s.end())
//        ans = stoi(string(s.begin(), pos)) * double(stoi(string(pos + 1, s.end())));
//    pos = find(s.begin(), s.end(), '/');
//    if (pos != s.end()) {
//        auto a = stoi(string(s.begin(), pos));
//        auto b = double(stoi(string(pos + 1, s.end())));
//        if (b != 0)
//            ans = a / b;
//    }
//
//    if (ans == -0) ans = 0;
//    cout << ans;
//    cout << endl;
//    //}
//    //system("PAUSE");
//    return 0;
//}

