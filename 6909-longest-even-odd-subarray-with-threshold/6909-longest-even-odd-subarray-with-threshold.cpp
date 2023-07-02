class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n=nums.size();
        int l=0;
        int ans=0;
        int x=threshold;
        vector<int>&a=nums;
        while(l<n)
        {
            if(a[l]>x or a[l]%2)
            {
                l++;
                continue;
            }
            
            int r=l;
            while( (r<n-1) and (a[r]%2 != a[r+1]%2) and a[r+1]<=x)r++;
            
            ans=max(ans,r-l+1);
            l=r+1;
        }
        return ans;
    }
};