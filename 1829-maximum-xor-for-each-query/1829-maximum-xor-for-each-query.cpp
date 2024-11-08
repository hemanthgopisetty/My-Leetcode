class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int maxXor = pow(2,maximumBit)-1;
        int xorr = nums[0];
        //Cummulative xorr
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            xorr^=nums[i];
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            ans[i]=xorr^maxXor;
            xorr^=nums[n-i-1];
        }
        return ans;
        
    }
};

/*
To find the k which will maximize k xor product(cummulative)

we xor operator evaluates to 1 when the operands differ
we can find k by inverse of first maxbits we can call that ask maxk
we can find that mask which is 2^maxBits-1 
then to get k we simply product xor max which gives k


applying this mask will provide us with the inverse of the first maximumBits of product, which is the value of k that maximizes our result.


Xor properties,dry run thinking try and error method
*/