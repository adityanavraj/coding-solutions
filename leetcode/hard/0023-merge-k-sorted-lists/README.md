# Merge k Sorted Lists

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

 *Merge all the linked-lists into one sorted linked-list and return it.* 

 

 **Example 1:** 

```
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6

```

 **Example 2:** 

```
Input: lists = []
Output: []

```

 **Example 3:** 

```
Input: lists = [[]]
Output: []

```

 

 **Constraints:** 

- k == lists.length
- 0 <= k <= 104
- 0 <= lists[i].length <= 500
- -104 <= lists[i][j] <= 104
- lists[i] is sorted in ascending order.
- The sum of lists[i].length will not exceed 104.

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 18.9 MB (beats 23.44%)  
**Submitted:** 2026-10-11T12:35:29.983Z  

```cpp
class Solution { ListNode* merge(ListNode* a,ListNode* b){ListNode d;ListNode*t=&d;while(a&&b){if(a->val<b->val){t->next=a;a=a->next;}else{t->next=b;b=b->next;}t=t->next;}t->next=a?a:b;return d.next;} ListNode* sortLists(vector<ListNode*>&v,int l,int r){if(l==r)return v[l];int m=l+(r-l)/2;return merge(sortLists(v,l,m),sortLists(v,m+1,r));} public: ListNode* mergeKLists(vector<ListNode*>& lists){if(lists.empty())return nullptr;return sortLists(lists,0,lists.size()-1);} };
```

---

[View on LeetCode](https://leetcode.com/problems/merge-k-sorted-lists/)