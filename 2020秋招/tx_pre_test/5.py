def longestPalindrome(s):
    if not s:
        return ""
    length = len(s)
    if length == 1 or s == s[::-1]:
        return s
    max_len, start = 1, 0
    for i in range(1, length):
        even = s[i-max_len:i+1]
        odd = s[i-max_len-1:i+1]
        if i - max_len - 1 >= 0 and odd == odd[::-1]:
            start = i - max_len - 1
            max_len += 2
            continue
        if i - max_len>= 0 and even == even[::-1]:
            start = i - max_len
            max_len += 1
            continue
    return s[start:start+max_len]

def getcnt(s, max_len):
    cnt = 0
    for i in range(len(s)-max_len+1):
        s_for = s[i:max_len+i]
        s_back = s_for[::-1]
        if s_for == s_back:
            cnt += 1
    return cnt

string = input()
N = int(input())
for i in range(N):
    a, b = map(int, input().split(" "))
    tmp = longestPalindrome(string[a-1:b])
    res = getcnt(string[a-1:b], len(tmp))
    print(res)
