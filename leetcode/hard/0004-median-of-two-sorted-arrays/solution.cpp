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