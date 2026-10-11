# Zigzag Conversion

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

```
P   A   H   N
A P L S I I G
Y   I   R

```

And then read line by line: `"PAHNAPLSIIGYIR"`

Write the code that will take a string and make this conversion given a number of rows:

```
string convert(string s, int numRows);

```

 

 **Example 1:** 

```
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

```

 **Example 2:** 

```
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

```

 **Example 3:** 

```
Input: s = "A", numRows = 1
Output: "A"

```

 

 **Constraints:** 

- 1 <= s.length <= 1000
- s consists of English letters (lower-case and upper-case), ',' and '.'.
- 1 <= numRows <= 1000

## Solution

**Language:** C++  
**Runtime:** 4 ms (beats 61.59%)  
**Memory:** 13.9 MB (beats 70.93%)  
**Submitted:** 2026-10-11T12:24:37.740Z  

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= static_cast<int>(s.size())) return s;
        vector<string> rows(min(numRows, static_cast<int>(s.size())));
        int row = 0, direction = 1;
        for (char c : s) {
            rows[row].push_back(c);
            if (row == 0) direction = 1;
            else if (row == numRows - 1) direction = -1;
            row += direction;
        }
        string result;
        for (const string& part : rows) result += part;
        return result;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/zigzag-conversion/)