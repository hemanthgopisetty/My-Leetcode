class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int>s;
        
        int ans=0;
        
        for(int x:nums) s.insert(x);
        
        for(int x:nums){
            if(s.count(x-1)==0){
                int curr=1;
                while(s.count(x+1)){
                    curr++;
                    x++;
                }
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};