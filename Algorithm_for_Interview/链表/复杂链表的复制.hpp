/*
复杂链表的复制 https://www.nowcoder.com/practice/f836b2c43afc4b35ad6adc41ec941dba?tpId=13&tqId=11178&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

题目来源：剑指Offer

题目描述
输入一个复杂链表
（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

解题思路：
    （没看懂题意，以下来自讨论区）
    1、复制每个节点，如：原来是 A->B->C 变成 A->A'->B->B'->C->C'
    2、遍历链表，使：A'->random = A->random->next;
    3、拆分两个链表链表

提交记录：


*/
#pragma once

#include "../all.h"

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
        label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode * Clone(RandomListNode* pHead) {
        if (!pHead) return NULL;

        RandomListNode *cur = pHead;
        // 1. 复制每个节点，如：原来是A->B->C 变成A->A'->B->B'->C->C'
        while (cur) {
            RandomListNode *node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }

        // 2. 遍历链表，使：A'->random = A->random->next;
        cur = pHead;
        RandomListNode *tmp;
        while (cur) {
            tmp = cur->next;
            if (cur->random) {
                tmp->random = cur->random->next;
            }
            cur = cur->next->next;  // 跳过复制的节点
        }

        // 3. 拆分链表
        cur = pHead;
        RandomListNode * ret = cur->next;
        while (cur->next) {
            tmp = cur->next;
            cur->next = tmp->next;
            cur = tmp;
        }
        return ret;
    }
};

void
solve()
{

}
