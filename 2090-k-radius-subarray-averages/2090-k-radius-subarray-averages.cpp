class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        //Sliding Window
        int n=nums.size();
        int windowSize=2*k+1;
        vector<int>ans(n,-1);
        if(n<windowSize)
        {
            return ans;
        }
        long long windowSum=0;
        for(auto i=0;i<n;i++)
        {
            windowSum+=nums[i];//Right side pointer
            
            if(i-windowSize>=0)
            {
                windowSum-=nums[i-windowSize];//Left side window Pointer
            }
            if(i>=windowSize-1)
            {
                ans[i-k]=windowSum/windowSize;
            }
        }
        return ans;
    }
};