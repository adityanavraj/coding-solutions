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