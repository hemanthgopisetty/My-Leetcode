bool fun(int i,int j)
{
    return i>j;
}
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        return is_sorted(nums.begin(),nums.end()) or is_sorted(nums.begin(),nums.end(),fun);
    }
};