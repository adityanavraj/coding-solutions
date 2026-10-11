# Longest Palindromic Substring

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string `s`, return  *the longest*   *palindromic*   *substring*  in `s`.

 

 **Example 1:** 

```
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

```

 **Example 2:** 

```
Input: s = "cbbd"
Output: "bb"

```

 

 **Constraints:** 

- 1 <= s.length <= 1000
- s consist of only digits and English letters.

## Solution

**Language:** C++  
**Runtime:** 9 ms (beats 62.58%)  
**Memory:** 9.5 MB (beats 57.16%)  
**Submitted:** 2026-10-11T12:23:53.574Z  

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), start = 0, best = 0;
        for (int center = 0; center < n; ++center) {
            for (int d = 0; d <= 1; ++d) {
                int l = center, r = center + d;
                while (l >= 0 && r < n && s[l] == s[r]) {
                    if (r - l + 1 > best) { start = l; best = r - l + 1; }
                    --l; ++r;
                }
            }
        }
        return s.substr(start, best);
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/longest-palindromic-substring/)