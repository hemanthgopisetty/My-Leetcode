class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans ;
        int n = nums.size();
    /*
        Visited or Not via marking O(n) and O(1) => TC nd SC
        
        for(int i=0;i<n;i++)
        {
            //if visited mark it as visited
            //mark it as negative number
            
            //if it's negative then we visted it already 
            //else mark it negative
            
            if(nums[abs(nums[i])-1]<0)
            {
                ans.push_back(abs(nums[i]));
            }
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1] ;
        }
        return ans ;
        
    */
    
      //Grouping all duplicates together
      //traversing each element
      //xor the curr ele with prev ele
      // if xor result is zero then we found out duplicate
      //else its' not a duplicate
    //if we found our diplicate let's move curr_idx to next idx
    //and set xor element as next_idx to skip reudant checking of a duplicate
       if(nums.empty())return ans ; 
       sort(nums.begin(),nums.end()) ;
       int s = nums[0];
       for(int curr_idx = 1 ; curr_idx < n ; curr_idx++)
       {
           if(!(s^nums[curr_idx])) //if curr is dup
           {
               ans.push_back(nums[curr_idx]) ;
               curr_idx+=1;
               
               if(curr_idx<n)s=nums[curr_idx];
               else break ;
           }
           else 
           {
               s=nums[curr_idx];
           }
       }
       return ans ;
    }
};