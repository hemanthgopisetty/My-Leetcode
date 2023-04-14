class Solution {
public:
    //nums.lenght==200 max of 200 elements 
    //definetly bute force will work 
    //what about if size is >10^4
    int countKDifference(vector<int>& nums, int k) {
        int ans=0;
        map<int,int>m;
        for(auto i=0;i<nums.size();i++)
        {
            if(m.count(nums[i]-k)){
                ans+=m[nums[i]-k];
            }
            
            if(m.count(nums[i]+k)){
                ans+=m[nums[i]+k];
            }
            
            m[nums[i]]++;
        }
        return ans;
    }
};