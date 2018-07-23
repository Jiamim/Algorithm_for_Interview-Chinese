"""
字符串构造

问题描述：
    一个长串由一个字串循环构成，即 s[i]=t[i%n]，比如 "abcabc" 由 "abc" 构成

    注意："abcabcab" 也是由 "abc" 构成的，答题时没注意这个又只过了一部分

    *建议使用 Python 解决字符串相关问题，下面也只贴 Python 代码
"""

s = input()

n = len(s)
for i in range(1, n + 1) :
    base = s[:i]
    if base * (n // i) + base[:n % i] == s:
        print(base)
        break
