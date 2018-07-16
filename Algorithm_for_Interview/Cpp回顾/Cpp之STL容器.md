**RoadMap**
---
<!-- TOC -->

- [新特性](#新特性)
  - [emplace 系列函数](#emplace-系列函数)
- [vector 向量/数组 (`#include <vecetor>`)](#vector-向量数组-include-vecetor)
  - [其他操作](#其他操作)
- [list 链表 (`#include <list>`)](#list-链表-include-list)
- [deque 双端队列 (`#include <deque>`)](#deque-双端队列-include-deque)
- [queue 队列 / stack 栈 (`#include <queue>/<stack>`)](#queue-队列--stack-栈-include-queuestack)
- [堆/优先队列 priority_queue](#堆优先队列-priority_queue)
- [set/multiset 集合 (`#include <set>`)](#setmultiset-集合-include-set)
- [map/multimap 字典 (`#include <map>`)](#mapmultimap-字典-include-map)

<!-- /TOC -->

## 新特性

### emplace 系列函数
C++11 新特性，可以直接传入参数构造对象（见下面的例子说明），不需要拷贝或者移动内存，相比 push 系列拥有更好的性能；

除 array 外（array 不可变），所有标准容器都添加了相关函数，如 emplace、emplace_front、emplace_back、、emplace_hint（set/map） 等。

面试手写代码时可以用，平时网上 OJ 一般没有那么细的性能要求
```C++
// 假设 Date 类型接收 3 个参数来构造对象
vector<Date> vd;
// 一般的 push 或 insert 需要这么作
vd.push_back(Date("2018", "4", "1"));
// 而 emplace 使用不定参数，可以这么写
vd.emplace("2018", "4", "1");
```

## vector 向量/数组 (`#include <vecetor>`)
下面详细列出 vector 所有常用过的接口（不是全部）；其他容器大同小异，就不全列出来了

- 初始化
    ```C++
    vector<int> v1;  // {}
    vector<int> v2 = { 1,2,3,4 };
    vector<int> v3(3, 10);  // {10,10,10}
    vector<int> v4(v2.begin() + 1, v2.end());  // {2,3,4}
    vector<int> v5(v3);  // {2,3,4}
    ```
- 遍历
    ```C++
    for (auto it = v5.begin(); it != v5.end(); it++)
        cout << *it << ' ';
    for (auto i = 0; i < v3.size(); i++)
        cout << v3[i] << ' ';
    for (auto i : v4)
        cout << i << ' ';
    ```
- 逆序遍历
    ```C++
    for (auto it = v5.rbegin(); it != v5.rend(); it++)
        cout << *it << ' ';
    ```
- 容器长度
    ```C++
    v2.size();  // len(v2)
    ```
- 获取第一个元素，最后一个元素
    ```C++
    v2.front() = 1;  // v2[0] = 1
    v2.back() -= v2.front();  // v2[-1] -= v2[0]
    // 注意：这两个函数的返回的是元素的引用，可以直接对其修改
    ```
- 判断为空
    ```C++
    v1.empty();  // len(v1) == 0
    ```
- 尾插/弹出
    ```C++
    v1.push_back(3);  // v1.append(3)
    v1.push_back(2);  // v1.append(2)
    v1.push_back(1);  // v1.append(1)
    
    // last_val = v1.pop()
    last_val = v1.back();
    v1.pop_back();  // return void
    ```
- 插入
    ```C++
    v1.insert(v1.begin() + 1, 0);  // v1.insert(1, 0)
    v1.insert(v1.begin() + 1, v2.begin(), v2.end());  
    // 这个挺厉害，好像 Python 都没有直接插入另一个数组的方法，
    // 只能 `v1 = v1[:1] + v2 + v1[1:]`
    ```
- 合并
    ```C++
    v1.insert(v1.end(), v2.begin(), v2.end())  // v1 += v2
    ```
- 删除
    ```C++
    v1.erase(v1.begin() + 1);  // del v1[1]
    // erase() 有一个返回值，指向被删除元素下一个

    // 删除区间
    v1.erase(v1.begin() + 1, v1.begin() + 3);  // del v1[1:3]
    ```
- 清空
    ```C++
    v1.clear()
    ```

### 其他操作
- 判断是否存在
    ```C++
    // 使用 find() 不需要引入头文件
    // 注意: lower_bound() 要求容器有序，这里不适用
    auto it = find(v2.begin(), v2.end(), val);
    if(it != v2.end()) {  // if val in v2:
        //
    }
    ```
- 排序
```C++
// 降序
sort(v2.begin(), v2.end(), greater<int>());
// 升序
sort(v2.begin(), v2.end());

// 二级排序
typedef pair<int, int> ii;
vector<ii> vp{ {1,1}, {1,2}, {2,2}, {2,3}, {3,3} };

sort(vp.begin(), vp.end(), [](const ii &l, const ii &r) {
    return l.first != r.first ? l.first < r.first : l.second > r.second;
});
// 这里反而 C++ 比 Python 要简单些
// 因为 Python3 中移除了 cmp 参数，所以需要排序两次才能达到要求
// l.sort(key=lambda x: x[1], reverse=True)  # 要先排第二级
// l.sort(key=lambda x: x[0])
// 也可以使用 functools.cmp_to_key()，但我没有成功
```
- 交换 swap
    ```C++
    // vector.swap(v) 交换的是两个容器中的内容，而不是元素交换
    vector<int> v1;  // {}
    vector<int> v2 = { 1,2,3,4 };

    v1.swap(v2);  // v1: {1,2,3,4} 

    // 交换两个元素
    swap(v2[1, v2[2]])
    // 这个 swap() 是内置函数，不清楚具体在哪个头文件
    ```


## list 链表 (`#include <list>`)

list 的接口与 vector 基本相同，多了 push_front/pop_front

此外不能随机存取（想一下链表和数组的区别）；而 Python 中的 list 其实是数组。

- 头插
```C++
list<int> l1 = { 1,2,3 };

l1.push_front(0);  // { 0,1,2,3 }

auto front_val = l1.front();  // 0
l1.pop_front();  // { 1,2,3 }
```

## deque 双端队列 (`#include <deque>`)

把它当作支持 push_front/pop_front 的 vector 即可。
```C++
deque<int> d1 = { 1,2,3 };

d1.push_front(0);  // {0,1,2,3}

auto front_val = d1.front();  // 0
d1.pop_front();  // {1,2,3}
```

deque 是 queue/stack 的底层容器


## queue 队列 / stack 栈 (`#include <queue>/<stack>`)

这两个的内部容器都是 ~~list~~ deque，相当于对接口做了限制的 deque；实际中完全可以使用 deque 代替

- queue 开放的接口
    - empty
    - size
    - front
    - back
    - push (push_back)
    - pop (**pop_front**)
- stack 开放的接口
    - empty
    - size
    - top (back)
    - push (push_back)
    - pop (**pop_back**)

```C++
deque<int> d1 = { 1,2,3 };

// queue
queue<int> q1(d1);

list<int> l = { 1,2,3,4,5 };
queue<int, list<int>> q2(l);

queue<int> q3 = { 1,2,3 };  // error
queue<int, vector<int>> q4;  // warning

// stack
stack<int> s1(d1);
s1.push(4);
auto top_val = s1.top();  // 4
s1.pop();  // {1,2,3}
```

> 注意: 它们都不能使用**初始化列表**，也不支持 range 构造；只要是支持对应接口的都可以作为它们的底层容器，比如 vector 不能做 queue 的容器，因为它不支持 pop_front（虽然不会报错）；但它可以做 stack 的容器

## 堆/优先队列 priority_queue
priority_queue 被定义在 `<queue>` 中，但它的底层容器默认是 vector，而不是 deque

- priority_queue 支持的接口
    - empty
    - size
    - top (front)
    - push (push_back)
    - pop (push_back)

默认构建的是最大堆/大顶堆
```C++
vector<int> v1 = { 1,2,3 };
priority_queue<int> p1(v1.begin(), v1.end());
p1.top();  // 3 
```

构建最小堆
```C++
#include <functional>  // greater

int arr[] = { 1,2,3 };
priority_queue<int, vector<int>, greater<int>> p2(arr, arr + 3);
p2.top();  // 1
```

> 记: **小于** -> 大顶堆；**大于** -> 小顶堆

自定义优先级（效果同 greater）
```C++
// 大于 -> 小顶堆
struct cmp {
    bool operator () (int l, int r) {
        return l > r;
    }
};

int arr[] = { 1,2,3 };
priority_queue<int, vector<int>, cmp> p2(arr, arr + 3);
p2.top();  // 1
```

更复杂点的例子
```C++
struct node {
    int v1;
    int v2;
};

// 小于 -> 大顶堆
struct cmp2 {
    bool operator () (node l, node r) {
        return l.v1 != r.v1 ? l.v1 < r.v1 : l.v2 < r.v2;
    }
};

node arr2[] = { {1, 1}, {2, 2}, {2, 4}, {2, 3}, {1, 2} };
priority_queue<node, vector<node>, cmp2> p3(arr2, arr2 + 5);
p3.pop();  // {2, 4}
p3.pop();  // {2, 3}
p3.pop();  // {2, 2}
p3.pop();  // {1, 2}
p3.pop();  // {1, 1}
```

> priority_queue 也不支持初始化列表，甚至还不支持 `priority_queue<int> p1(v1);`，但又可以使用 range 构造（区别于 queue 和 stack）；这就是 C++ 最讨厌的地方，**不统一**（我不认为存在技术上的问题）

> C++ 还提供了 make_heap 方法（不是类）用于对**数组类**容器中的元素重排，但是不推荐使用


## set/multiset 集合 (`#include <set>`)
set 不支持重复元素，multiset (多重集)支持重复元素

内部实现是**红黑树**（平衡二叉搜索树），插入的同时也在排序（默认使用 less 比较器，即升序）

set 的查找效率高于 vector/deque/list 等容器

- 初始化
    ```C+++
    set<int> s1;
    set<int> s2{ 3,1,2 };
    
    vector<int> v { 3,2,1,5,4 };
    set<int> s3(v.begin(), v.end());
    ```

- 遍历：默认遍历方式是**中序遍历**
    ```C++
    for (auto i : s3)
        cout << i << ' ';
        
    // 逆序
    for (auto it = s3.rbegin(); it != s3.rend(); it++)
        cout << *it << ' ';  // {5,4,3,2,1}
    ```

- 插入/删除
    ```C++
    s2.insert(4);  // {1,2,3,4}
    s2.erase(3);  // {1,2,4}
    ```

- 查找

    set/multiset 支持三种查找方式: find, lower_bound, upper_bound；因为 set 是有序的，所以这三种方法其实都是二分查找
    
    > lower_bound 找目标下界（包含）；upper_bound 找目标上界（不包含）；find 内部调用的就是 lower_bound

    > 注意: C++ 中的查找并不是返回 bool 值，而是返回一个指向目标的**迭代器指针**；如果没有找到，则指向 end() 指针。

    ```C++
    // set
    auto it = s2.find(4);
    if (it != s2.end()) {
        //
    }

    // multiset
    multiset<int> ms1{ 1,2,2,2,3,4 };
    auto itp1 = ms1.find(2);  // No.2 （迭代器指针是从 1 开始计数的）
    auto itp2 = ms1.lower_bound(2);  // No.2
    cout << (itp1 == itp2) << endl;  // True

    auto itp3 = ms1.upper_bound(2);  // No.5
    cout << *itp3 << endl;  // 3
    ```


## map/multimap 字典 (`#include <map>`)
底层也是红黑树，内部实现相当于一个 `set<pair<key, value>>`

- 初始化 + 遍历
    ```C++
    map<int, int> m1{ { 1,2 },{ 2,3 },{ 3,4 } };
    map<int, int> m2(m1.begin(), m1.end());
    map<int, int> m3(m2);

    for (auto& i : m3)
        cout << i.first << ": " << i.second << endl;
    ```
- 插入/更新
    ```C++
    m3[1] = 3;  // 更新
    m3[4] = 5;  // 插入
    
    pair<map<int, int>::iterator, bool> ret;
    ret = m3.insert(pair<int, int>(1, 4));
    if (ret.second == false)
        cout << "exist" << endl;

    // hint 插入
    auto it = m3.begin();
    it = m3.insert(it, pair<int, int>(6, 7));  
    // 使用 hint 不一定能提高效率
    // 很多编译器在实现时，只有当 hint 恰好是最终位置是才会使用 hint，否则直接忽略它 
    // 一般的使用场景是顺序插入一系列有序的数时，用返回值作为 hint 
    // ref: http://en.cppreference.com/w/cpp/container/set/emplace_hint

    ret = m3.emplace(5, 6);  // 插入
    ret = m3.emplace(1, 4);  // 未更新
    it = m3.emplace_hint(it, 8, 9);  // hint 插入
    // emplace 内部调用的是 insert
    ```
- 删除
    ```C+++
    m3.erase(3);  // 删除 by key
    auto it = m3.find(7);  // 删除 by iterator
    if (it != m3.end())
        m3.erase(it);
    ```
- 查找
    跟 set 类似，略