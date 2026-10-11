# Longest Valid Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given a string containing just the characters `'('` and `')'`, return  *the length of the longest valid (well-formed) parentheses **substring*.

 

 **Example 1:** 

```
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

```

 **Example 2:** 

```
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

```

 **Example 3:** 

```
Input: s = ""
Output: 0

```

 

 **Constraints:** 

- 0 <= s.length <= 3 * 104
- s[i] is '(', or ')'.

## Solution

**Language:** C++  
**Runtime:** 3 ms (beats 37.41%)  
**Memory:** 12.1 MB (beats 9.64%)  
**Submitted:** 2026-10-11T12:39:57.387Z  

```cpp
class Solution { public: int longestValidParentheses(string s){int ans=0;vector<int> st;st.push_back(-1);for(int i=0;i<(int)s.size();++i){if(s[i]=='(')st.push_back(i);else{st.pop_back();if(st.empty())st.push_back(i);else ans=max(ans,i-st.back());}}return ans;} };
```

---

[View on LeetCode](https://leetcode.com/problems/longest-valid-parentheses/)