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