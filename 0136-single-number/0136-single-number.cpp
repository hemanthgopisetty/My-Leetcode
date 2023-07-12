class Solution {
public:
    //every element appears twice except for one
    //find the single one
    
    //we could use map here to find the frequencies
    //and return an element that appers the exactly once
    //this would take N time complexity and N space Complexity
    
    //we need to think like when we access an element
    //we should get identified by no of times we had visited this
    //In this way we will get Linear time and space complexity.
    
    //what to do then ??
    //Bit manipulation :)
    
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(auto it:nums)ans^=it;
        return ans;
    }
};