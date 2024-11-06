class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        //Based on the given conditon 
        //we can think , like same bits can be swapped in anyway
        //so divide same bits elements as segments 
        //track min and max of that segment
        //if set bits were not same
        //then if curr element is less than the currMin
        //sorting not possible then return false
        //set bits were not same and curr element is greater than the curMin
        //update curMin , curMax,PrevMin , PrevMax
        
        int prevMax = INT_MIN;
        int currMax = nums[0];
        int currMin = nums[0];
        int setBits = countBits(nums[0]);
        
        for(int i=1;i<nums.size();i++)
        {
            if(setBits == countBits(nums[i]))
            {
                currMin = min(currMin,nums[i]);
                currMax = max(currMax,nums[i]);
            }
            else
                //new segment
            {
                if(currMin<prevMax)return false;
                    
                prevMax = currMax;
                setBits = countBits(nums[i]);
                currMin = nums[i];
                currMax = nums[i];
            }
        }
        
        return currMin>prevMax;
        
    }
    
    private:
    int countBits(int num) {
        return std::bitset<32>(num).count();
    }
};