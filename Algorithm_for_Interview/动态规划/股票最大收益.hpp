#pragma once

#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

#define MAXN 10001

int _main() {

    vector<int> tmp;
    string s;
    getline(cin, s);
    auto it = s.begin();
    while (it != s.end()) {
        auto to = find(it, s.end(), ' ');
        string t = string(it, to);
        if (t[t.length() - 1] == 'Y')
            tmp.push_back(stoi(string(t.begin(), t.end() - 1)));
        else
            tmp.push_back(7 * stoi(string(t.begin(), t.end() - 1)));
        if (to != s.end())
            it = to + 1;
        else
            break;
    }

    //for (auto i : tmp)
    //    cout << i << ' ';
    int maxP = 0;;
    for (int i = 0; i < tmp.size() - 1; i++) {
        int p = tmp[i + 1] - tmp[i];
        if (p > 0)
            maxP += p;

    }
    cout << maxP;

    //system("PAUSE");
    return 0;
}