class Solution {
public:
    int thirdMax(vector<int>& nums) {
       if(nums.size()==1) return nums[0];
        
       if(nums.size()==2) return max(nums[0],nums[1]);
        
       int f=*max_element(nums.begin(),nums.end());
       int s=INT_MIN;
       int t=s;
       
       //find wether second maximum is there or not and that is not equal 
       //to the first max
        
        //count s
        int cs=0;
       for(auto ele:nums)
       {
           if(s < ele and ele != f)
           {
               s=ele;
               cs++;
           }
       }
        
      if(cs==0) return f;
        
      //if there is second element ,check for third max
      
      int ct=0;
      for(auto ele:nums)
      {
          if((t < ele or ele==INT_MIN) and (ele!=f and ele != s) )
          {
              t=ele;
              ct++;
          }
      }
      //if third element is there then return third max else return max element
      if(ct>0) return t;
      else return f;
    }
};