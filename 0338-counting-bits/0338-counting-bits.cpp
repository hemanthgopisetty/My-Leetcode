class Solution {
public:
/*
    For every i (0<=i<=n)  there is relation ship with it's number
    
*/
    vector<int> countBits(int n) {
        vector<int> a;
        for(auto i=0;i<=n;i++)
        {
            a.push_back(__builtin_popcount(i)) ;  
        }
        return a;
    }
};