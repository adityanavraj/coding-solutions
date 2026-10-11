class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size(), sign = 1;
        while (i < n && s[i] == ' ') ++i;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            ++i;
        }
        long long value = 0;
        long long limit = (sign == 1 ? INT_MAX : -(long long)INT_MIN);
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            if (value > (limit - digit) / 10) return sign == 1 ? INT_MAX : INT_MIN;
            value = value * 10 + digit;
            ++i;
        }
        return static_cast<int>(sign * value);
    }
};