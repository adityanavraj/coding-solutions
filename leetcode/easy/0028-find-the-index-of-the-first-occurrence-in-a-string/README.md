# Find the Index of the First Occurrence in a String

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given two strings `needle` and `haystack`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.

 

 **Example 1:** 

```
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

```

 **Example 2:** 

```
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

```

 

 **Constraints:** 

- 1 <= haystack.length, needle.length <= 104
- haystack and needle consist of only lowercase English characters.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 9.4 MB (beats 14.61%)  
**Submitted:** 2026-10-11T12:37:52.457Z  

```cpp
class Solution { public: int strStr(string h,string n){int m=n.size();vector<int> lps(m);for(int i=1,len=0;i<m;){if(n[i]==n[len])lps[i++]=++len;else if(len)len=lps[len-1];else lps[i++]=0;}for(int i=0,j=0;i<(int)h.size();){if(h[i]==n[j]){++i;++j;if(j==m)return i-j;}else if(j)j=lps[j-1];else ++i;}return -1;} };
```

---

[View on LeetCode](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)