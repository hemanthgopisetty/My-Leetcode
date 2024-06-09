class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int ps=0;//prefix sum
        unordered_map<int,int>hm;//remainder nd index
        hm[0]=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            ps+=nums[i];
            int r=ps%k;//remainder of cummulative sum
            if(hm.find(r)!=hm.end())//if it is in hash_map
            {
                if(i-hm[r]>1){
                    return true;
                }
            }
            else
            {
                hm[r]=i;
            }
        }
        return false ;
    }
};