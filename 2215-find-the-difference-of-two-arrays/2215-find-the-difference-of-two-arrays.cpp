#define all(x) x.begin(),x.end()
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> ds1(all(nums1)),ds2(all(nums2));
        vector<int>v1,v2;
        set_difference(all(ds1),all(ds2),back_inserter(v1));
        set_difference(all(ds2),all(ds1),back_inserter(v2));
        return {v1,v2};
    }
};