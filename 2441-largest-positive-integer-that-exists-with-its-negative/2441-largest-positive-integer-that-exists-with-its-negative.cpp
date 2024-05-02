class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int l=0,r=nums.size()-1;
//         sort(nums.begin(),nums.end());
        
//         while(l<r)
//         {
//             if(nums[l]+nums[r]==0)
//             {
//                 return nums[r];
//             }
//             else if(nums[l]+nums[r]<0)
//             {
//                 l++;
//             }
//             else r--;
//         }
        
//         return -1; -> O(nlogn)[sorting] ,o(n)[two pointer]
        
         // store negative numbers , track postive max
        
        unordered_set<int> hs ;
        for(int it :nums)
        {
            if(it<0)hs.insert(it);
        }
        int ans =-1;
        for(auto it:nums)
        {
            if(it>ans and hs.count(-it))ans=it;
        }
        return ans ;
    }
};