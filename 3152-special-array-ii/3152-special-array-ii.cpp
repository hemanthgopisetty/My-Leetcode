class Solution {
private:
    bool binarySearch(int start, int end, vector<int>& violatingIndices) {
        int left = 0, right = violatingIndices.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (violatingIndices[mid] < start) {
                left = mid + 1;
            } else if (violatingIndices[mid] > end) {
                right = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }

public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        if (nums.empty()) return vector<bool>(queries.size(), true);
        if (queries.empty()) return {};

        int n = nums.size();
        vector<int> violatingIndices;
        for (int i = 1; i < n; i++) {
            if (nums[i] % 2 == nums[i - 1] % 2) {
                violatingIndices.push_back(i);
            }
        }

        int q = queries.size();
        vector<bool> ans(q);
        for (int i = 0; i < q; i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            ans[i] = !binarySearch(start + 1, end, violatingIndices);
        }

        return ans;
    }
};
