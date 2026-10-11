# 3Sum Closest

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given an integer array `nums` of length `n` and an integer `target`.

Find three integers at  **distinct indices**  in `nums` such that the sum is  **closest**  to `target`.

Return the sum of the three integers.

You may assume that each input would have  **exactly**  one solution.

 

 **Example 1:** 

```
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

```

 **Example 2:** 

```
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

```

 

 **Constraints:** 

- 3 <= nums.length <= 500
- -1000 <= nums[i] <= 1000
- -104 <= target <= 104

## Solution

**Language:** C++  
**Runtime:** 4 ms (beats 95.33%)  
**Memory:** 14 MB (beats 86.16%)  
**Submitted:** 2026-10-11T12:32:14.863Z  

```cpp
class Solution { public: int threeSumClosest(vector<int>& a,int t) { sort(a.begin(),a.end()); int best=a[0]+a[1]+a[2]; for(int i=0;i<(int)a.size()-2;++i){int l=i+1,r=a.size()-1;while(l<r){int s=a[i]+a[l]+a[r];if(abs(s-t)<abs(best-t))best=s;if(s<t)++l;else if(s>t)--r;else return s;}}return best;} };
```

---

[View on LeetCode](https://leetcode.com/problems/3sum-closest/)