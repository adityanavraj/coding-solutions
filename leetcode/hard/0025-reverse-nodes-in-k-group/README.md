# Reverse Nodes in k-Group

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

Given the `head` of a linked list, reverse the nodes of the list `k` at a time, and return  *the modified list*.

`k` is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of `k` then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

 **Example 1:** 

```
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

```

 **Example 2:** 

```
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

```

 

 **Constraints:** 

- The number of nodes in the list is n.
- 1 <= k <= n <= 5000
- 0 <= Node.val <= 1000

 

 **Follow-up:**  Can you solve the problem in `O(1)` extra memory space?

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 16.5 MB (beats 69.80%)  
**Submitted:** 2026-10-11T12:36:26.769Z  

```cpp
class Solution { public: ListNode* reverseKGroup(ListNode* head,int k){ListNode d(0,head);ListNode* gp=&d;while(true){ListNode* kth=gp;for(int i=0;i<k&&kth;i++)kth=kth->next;if(!kth)break;ListNode* next=kth->next;ListNode* prev=next;ListNode* cur=gp->next;while(cur!=next){ListNode* t=cur->next;cur->next=prev;prev=cur;cur=t;}ListNode* old=gp->next;gp->next=kth;gp=old;}return d.next;} };
```

---

[View on LeetCode](https://leetcode.com/problems/reverse-nodes-in-k-group/)