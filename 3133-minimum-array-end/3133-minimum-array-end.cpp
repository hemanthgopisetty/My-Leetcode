class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans=x;
        while(--n)
        {
            ans = (ans+1) | x ;
        }
        return ans;
    }
};

/*

We need to find integers array of size n where every integer is greater than it's previos one
in such a way and operation of all elements is x and return the minimum possible value of that array

To ensure and of all operation is X
we need to start with x(so bits in x make sure and of all upcoming int will give desired)
We all so make sure that every element in ans array follows strictly increasing
To make sure and x , we need to persists it's bits so that it gives x when we do cummulative of all 

So starting from x , increment it by 1 make sures x will be the and of all
in such way easy to find minimum too and and result x
we increment and or with x make sures persists bits

*/