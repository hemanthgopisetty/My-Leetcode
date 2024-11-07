class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans=0;
        for(int i=0;i<32;i++)
        {
            int count=0;
            for(auto num:candidates)
            {
                //check i'th bit and num is non zero 
                //as and operation gives if both the inputs are true then result is true
                //any of input is zero then result is zero
                if(num&(1<<i))
                {
                    count++;
                }
            }
            //each bit update max combination length
            ans = max(ans,count);
        }
        return ans ;
    }
};
/*
As question it self says we need to find a combination that is largest combination of and's greater than zero

Bute Forces is track each element in a stack or counter elements results in quadritic time

Instead of doing that checking each element lets check which all are elements shares set bit in same position which gives an answer right

Since integers are 32 bits in length, we loop from 0 to 31 to cover all possible bit positions.


The crucial factor is that all numbers in the group must share at least one '1' bit in the same position

 the size of the largest group we can form will correspond to the count of numbers that share a '1' bit in any particular position.\
 
 left shift -> move each bit i(right operand) times left of left operand
 check current elements and with mask (left shifted element) if it's a non zero 
 
 
 going bit by bit over n elements -> (32*n)
*/