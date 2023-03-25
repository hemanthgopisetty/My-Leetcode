class Solution {
public:
/*
The idea here is to use a hash map (unordered_map in C++, dictionary in Python) to store the prefix sum's and the number of occurrences of that prefix sum
The idea here is to use a hash map (unordered_map in C++, dictionary in Python) to store the prefix sum and the number of occurrences of the prefix sum
If the prefix sum (the cumulative sum minus k) exists in the map, it means that there is a subarray with sum k between the indices where the prefix sum was first encountered and the current index
We can then update the result by adding the number of occurrences of the prefix sum to it.
*/
    int subarraySum(vector<int>& nums, int k) {
        //Our answer
      int ans=0;
      // Map to store the prefix sum and
      // the number of occurrences of the prefix sum
      unordered_map<int,int>hm;
      // Cumulative sum
      int sum=0;
      //Add the starting prefix sum (default value of 0) at -1 to the map
      hm[0]=1;
      // Iterate through the array
      for(auto i=0;i<nums.size();i++)
      {
          //Sum up to current index - Cummulative Sum
          sum+=nums[i];
         /*
         If the prefix sum (sum - k) exists in the map,
            it means that there is a subarray with 
            sum k between the indices
            where prefix sum (sum - k) was first 
            encountered and the current index
         */
         if(hm.count(sum-k))
         {
             // Add the number of occurrences of prefix sum (sum - k)
             // to the result
             ans+=hm[sum-k];
         }
        // Increment the number of occurrences of the current 
        //prefix sum by 1
         hm[sum]++;
      }
      return ans;
    }
};