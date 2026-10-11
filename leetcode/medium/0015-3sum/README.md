# 3Sum

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an integer array nums, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`.

Notice that the solution set must not contain duplicate triplets.

 

 **Example 1:** 

```
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

```

 **Example 2:** 

```
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

```

 **Example 3:** 

```
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

```

 

 **Constraints:** 

- 3 <= nums.length <= 3000
- -105 <= nums[i] <= 105

## Solution

**Language:** C++  
**Runtime:** 44 ms (beats 73.04%)  
**Memory:** 29.2 MB (beats 27.03%)  
**Submitted:** 2026-10-11T12:31:46.935Z  

```cpp
class Solution { public: vector<vector<int>> threeSum(vector<int>& a) { sort(a.begin(),a.end()); vector<vector<int>> r; int n=a.size(); for(int i=0;i<n-2;++i){ if(i&&a[i]==a[i-1])continue; int l=i+1,h=n-1; while(l<h){ long long s=(long long)a[i]+a[l]+a[h]; if(s<0)++l; else if(s>0)--h; else {r.push_back({a[i],a[l],a[h]}); int x=a[l],y=a[h]; while(l<h&&a[l]==x)++l; while(l<h&&a[h]==y)--h;} } } return r; } };
```

---

[View on LeetCode](https://leetcode.com/problems/3sum/)