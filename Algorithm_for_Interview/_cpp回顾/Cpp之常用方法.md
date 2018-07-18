---
title: C++ 快速回忆之常用标准库函数
date: 2018-04-04 20:50:52
tags: [面试, C++]
description: “常用”的标准依然是 Python
---

## 判断元素在不在容器中
常用容器: vector, set, map

### vector
```C++
int x = 3;
vector<int> nums{ 1,2,3,4,5 };

auto it = find(nums.begin(), nums.end(), x);
if (it != nums.end()) {
    //
}
```

### set/map
```C++
auto it = s2.find(2);
if (it != s2.end()) {
    // 找到
}

auto ii = s2.count(2);
if (ii == 1) {
    // 找到
}
```


## 排序

### 基本排序
默认升序
```C++
vector<int> n1{ 2, 233, 211 };
sort(n1.begin(), n1.end());  // {2, 211, 233}

// set/map 在插入的同时也在排序
set<int> s1{ 2, 233, 211 };
```

### 自定义排序函数 cmp()
C++ 提供了三种定义方式

1. 返回值是 bool 的普通函数
2. 仿函数
3. lambda 表达式（匿名函数）

> 以上所有函数的形参都应该是 `const T &` 类型

```C++
vector<int> ns{ 2, 233, 211 };

// 1. 普通函数
// （注意，如果定义在类中，需要加 static 关键字）
bool
cmp(const int &l, const int &r)
{
    string ll = to_string(l) + to_string(r);
    string rr = to_string(r) + to_string(l);
    return ll < rr;
}
sort(ns.begin(), ns.end(), cmp);  // {211,2,233}

// 2. 仿函数
struct Cmp
{
    bool operator () (const int &l, const int &r) 
    {
        string ll = to_string(l) + to_string(r);
        string rr = to_string(r) + to_string(l);
        return ll < rr;
    }
};
sort(ns.begin(), ns.end(), Cmp());  // {211,2,233}
// 注意调用方式与 1. 不同

// 3. lambda 表达式
sort(ns.begin(), ns.end(), [](const int &l, const int &r){
    string ll = to_string(l) + to_string(r);
    string rr = to_string(r) + to_string(l);
    return ll < rr;
});
```

### 为 set/map 指定排序函数
这时 cmp() 使用方法又与在 sort() 中不同了（麻烦啊）
```C++
// 不用加括号了
set<int, Cmp> s2{ 2, 233, 211 };

// 应该能传普通函数进去，没找到方法
```


## string/char* 相关
C++ 很麻烦的一点是，很多时候 string 和 char* 不能通用

### string 与 char* 的转换

> CSDN/[c++中char *与string之间的相互转换及原理](https://blog.csdn.net/wangqing_12345/article/details/51867247)

### string 与 int 的转换
```C++
// string to int
char c1[] = "123";
string s1{ c1 };
int i1;

i1 = atoi(c1);  // char*
// i = atoi(s1);  // err

// `#include <string>`, C++11
i1 = stoi(c1);  // char*
i1 = stoi(s1);  // string
```

```C++
// int to string
char c2[12];
string s2;
int i2 = 321;

// `#include <cstdio>`
sprintf(c2, "%d", i2);  // char*
// itoa(i1, c1, 10);  // char*
// 非标准函数，经测试 LeetCode 上不能使用

// `#include <string>`, C++11
s2 = to_string(i2);  // string
```

### `len(str)`
```C++
// len(str)
char c3[] = "12345";
string s3{ c3 };
int i3;

i3 = strlen(c3);  // char*
//i3 = strlen(s3);  // err

i3 = s3.length();  // string
```

### 字符串拼接
```C++
// string 的比较简单
string s4{ "1" };
string s5{ "2" };
s4 = s4 + s5;  // 最慢
s4 += s5;  // 比 + 快
s4.append(s5);  // 与 += 相当，稍快

stringstream ss;
ss << s4 << s5;  // 最快，注意使用场景
string s_tmp = ss.str();

// char*
char c4[64]{ "1" };  // 目标源必须足够大
char c5[]{ "2" };
strcat(c4, c5);  // 拼到 c4
// 注意这里 c4 大小不能为空，且要够大

char c_tmp[64];
sprintf(c_tmp, "%s%s", c4, c5);
```

### 替换
Python 中是这样的
```Python
"1 2 3".replace(' ', '__')  # '1__2__3'
```
C++ 虽然也提供了 replace 方法，但逻辑不一样：它需要你提供被替换字符串的**首位置和待替换子串的长度**，然后替换，且只**替换一次**
```C++
string s6{ "1 2 3" };
int pos = s6.find(' ');

while (pos != string::npos) {  // npos == -1
    s6.replace(pos, strlen(" "), "__");
    pos = s6.find(' ', pos + strlen("__"));
}
```
特别的，如果是对 char* 替换，那么考察重点往往不是替换本身，而是 char* 作为数组，内部元素的移动（要求不使用额外空间）；而且替换的套路也类似，先统计待替换子串的数量，算出替换后的总长度，**利用双指针从后往前替换**，还有别忘了手动加上 '\0'

一道典型的问题[牛客/替换空格](https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&tqId=11155&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=1)
```C++
void replaceSpace(char *str, int length) {
    if (str == NULL || length < 0)
        return;

    int l_old = strlen(str);
    int n_space = count(str, str + l_old, ' ');  // 常规做法是写个循环
    int l_new = l_old + n_space * 2;
    str[l_new] = '\0';  // 手动加 '\0'

    int p_old = l_old-1;
    int p_new = l_new-1;
    while (p_old >= 0) {
        if (str[p_old] != ' ') {
            str[p_new--] = str[p_old--];
        }
        else {
            p_old--;
            str[p_new--] = '0';
            str[p_new--] = '2';
            str[p_new--] = '%';
        }
    }
```


## 未完


