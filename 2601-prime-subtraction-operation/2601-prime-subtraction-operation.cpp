class Solution {
public:
    bool checkPrime(int x)
    {
        for(int i=2;i<=sqrt(x);i++)
        {
            if(x%i==0)
            {
                return 0;
            }
        }
        
        return 1;
    }
    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int diff ;
            //if its first element we need to find the largest prime than nums[0]
            if(i==0)
            {
                diff = nums[0];
            }
            else
            {
                // Otherwise, we need to find the largest prime
                diff = nums[i]-nums[i-1];
            }
            
            if (diff <= 0) {
                return 0;
            }
            
            int largestPrime=0;
            //Find largest prime by sqrt(j)
            for(int j=diff-1;j>=2;j--)
            {
                if(checkPrime(j))
                {
                    largestPrime=j;
                    break;
                }
            }
            nums[i]=nums[i]-largestPrime;
            //chec
        }
        return 1;
    }
};
/*
Largest Prime Number Makes current Number Smallest makes array strictly Increasing -> Greedy

but we have to be careful: "the prime we subtract should leave the current element just slightly above the previous one."

for each element nums[i] , find the biggest prime p 
so that after subtracting ,new value of nums[i] is still greater than nums[i-1]

nums[i]-p>nums[i-1] -> p largest prime

Traverse each element nums
    look out for difference between current and previous number
        diff == 0 or diff < 0 : [curr - prev](1-3)[3,1]
            return false
        diff > 0 :[curr-prev](3-1)[1,3]
            find largest prime within this range
 
 [9,8,7]=>
 
 a prime number only has two divisors: 1 and itself
 
 To check if a number is prime
    we don’t have to test all the way up to that number, 
    we just need to check up to its square root. 
    If we don’t find any divisors up to that point, then the number is prime.

once we find largest p 

*/