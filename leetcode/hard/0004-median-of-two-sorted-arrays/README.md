# Median of Two Sorted Arrays

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return  **the median**  of the two sorted arrays.

The overall run time complexity should be `O(log (m+n))`.

 

 **Example 1:** 

```
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

```

 **Example 2:** 

```
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

```

 

 **Constraints:** 

- nums1.length == m
- nums2.length == n
- 0 <= m <= 1000
- 0 <= n <= 1000
- 1 <= m + n <= 2000
- -106 <= nums1[i], nums2[i] <= 106

## Solution

**Language:** C++  
**Runtime:** 4 ms (beats 18.31%)  
**Memory:** 95 MB (beats 78.80%)  
**Submitted:** 2026-10-11T12:22:52.771Z  

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size(), n = nums2.size();
        int half = (m + n + 1) / 2;
        int lo = max(0, half - n), hi = min(half, m);
        while (lo <= hi) {
            int i = lo + (hi - lo) / 2;
            int j = half - i;
            int leftA = (i == 0 ? INT_MIN : nums1[i - 1]);
            int rightA = (i == m ? INT_MAX : nums1[i]);
            int leftB = (j == 0 ? INT_MIN : nums2[j - 1]);
            int rightB = (j == n ? INT_MAX : nums2[j]);
            if (leftA <= rightB && leftB <= rightA) {
                if ((m + n) % 2) return max(leftA, leftB);
                return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
            }
            if (leftA > rightB) hi = i - 1;
            else lo = i + 1;
        }
        return 0.0;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/median-of-two-sorted-arrays/)