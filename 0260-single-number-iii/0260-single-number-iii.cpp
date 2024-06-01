class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // In given array , there are elements that appears twice
        // and two elements that appears one
        // find two elements that appears once
        
        // O(n^2)TC , O(1)SC -> Bute Force -> Nested Loop
        
        // O(n)TC , O(n)SC -> Optimised -> Single Pass using HashMap
        
        // Given Follow up was this 
        // O(n)TC , O(1)
        
        
        // we need to something with this elements appears twice 
        // two elements appears single
        int xor2no = 0;
        for (int num : nums) {
            xor2no ^= num;
        }

        unsigned int lowestBit = xor2no & -(unsigned int)xor2no;

        vector<int> result(2, 0);
        for (int num : nums) {
            if ((lowestBit & num) == 0) {
                result[0] ^= num;
            } else {
                result[1] ^= num;
            }
        }

        return result;
    }
};
    