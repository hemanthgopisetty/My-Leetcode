class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
         unordered_map<int,int> hm;
           for(auto i=0;i<nums.size();i++)
           {
               if(hm.count(nums[i]))
               {
                   int check=abs(hm[nums[i]]-i);
                   if(check<=k)return true;
       
               }
               hm[nums[i]]=i;
           }
        return false;
    }
};