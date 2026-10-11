# Generate Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given `n` pairs of parentheses, write a function to  *generate all combinations of well-formed parentheses*.

 

 **Example 1:** 

```
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

```

 **Example 2:** 

```
Input: n = 1
Output: ["()"]

```

 

 **Constraints:** 

- 1 <= n <= 8

## Solution

**Language:** C++  
**Runtime:** 2 ms (beats 78.06%)  
**Memory:** 13 MB (beats 88.83%)  
**Submitted:** 2026-10-11T12:35:00.739Z  

```cpp
class Solution { public: vector<string> generateParenthesis(int n){vector<string> r;string s;auto dfs=[&](auto&& self,int o,int c)->void{if((int)s.size()==2*n){r.push_back(s);return;}if(o<n){s.push_back('(');self(self,o+1,c);s.pop_back();}if(c<o){s.push_back(')');self(self,o,c+1);s.pop_back();}};dfs(dfs,0,0);return r;} };
```

---

[View on LeetCode](https://leetcode.com/problems/generate-parentheses/)