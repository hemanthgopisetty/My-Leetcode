class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            int lowerr = lower_bound(nums,i+1,n-1,lower-nums[i]);
            int upperr = lower_bound(nums,i+1,n-1,upper-nums[i]+1);
            ans+=1LL*(upperr-lowerr);
        }
        return ans;
    }
private :
    long long lower_bound(vector<int>&nums,int low,int high,int x)
    {
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]>=x)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low ;
    }
};