# Substring with Concatenation of All Words

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given a string `s` and an array of strings `words`. All the strings of `words` are of  **the same length**.

A  **concatenated string**  is a string that exactly contains all the strings of any permutation of `words` concatenated.

- For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.

Return an array of  *the starting indices*  of all the concatenated substrings in `s`. You can return the answer in  **any order**.

 

 **Example 1:** 

 **Input:**  s = "barfoothefoobarman", words = ["foo","bar"]

 **Output:**  [0,9]

 **Explanation:** 

The substring starting at 0 is `"barfoo"`. It is the concatenation of `["bar","foo"]` which is a permutation of `words`.
The substring starting at 9 is `"foobar"`. It is the concatenation of `["foo","bar"]` which is a permutation of `words`.

 **Example 2:** 

 **Input:**  s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]

 **Output:**  []

 **Explanation:** 

There is no concatenated substring.

 **Example 3:** 

 **Input:**  s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]

 **Output:**  [6,9,12]

 **Explanation:** 

The substring starting at 6 is `"foobarthe"`. It is the concatenation of `["foo","bar","the"]`.
The substring starting at 9 is `"barthefoo"`. It is the concatenation of `["bar","the","foo"]`.
The substring starting at 12 is `"thefoobar"`. It is the concatenation of `["the","foo","bar"]`.

 

 **Constraints:** 

- 1 <= s.length <= 104
- 1 <= words.length <= 5000
- 1 <= words[i].length <= 30
- s and words[i] consist of lowercase English letters.

## Solution

**Language:** C++  
**Runtime:** 19 ms (beats 79.22%)  
**Memory:** 23.8 MB (beats 69.57%)  
**Submitted:** 2026-10-11T12:38:54.800Z  

```cpp
class Solution { public: vector<int> findSubstring(string s,vector<string>& w){vector<int> ans;if(w.empty())return ans;int n=s.size(),m=w[0].size(),k=w.size();unordered_map<string,int> need;for(auto&x:w)++need[x];for(int off=0;off<m;++off){int l=off,cnt=0;unordered_map<string,int> have;for(int r=off;r+m<=n;r+=m){string x=s.substr(r,m);if(!need.count(x)){have.clear();cnt=0;l=r+m;continue;}++have[x];++cnt;while(have[x]>need[x]){string y=s.substr(l,m);--have[y];--cnt;l+=m;}if(cnt==k){ans.push_back(l);string y=s.substr(l,m);--have[y];--cnt;l+=m;}}}sort(ans.begin(),ans.end());return ans;} };
```

---

[View on LeetCode](https://leetcode.com/problems/substring-with-concatenation-of-all-words/)