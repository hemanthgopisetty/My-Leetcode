class Solution {
public:
    int minimumSum(int n, int k) {
        //k-avoiding array => if there does not exist any pair of distinct elements
        //that sum to k
        
        //return the minimum sum of k-avoidng array of lenght n
        
        //n=2 k=4
        //1,3 2,2 makes the sum right
        //i,k-i are the pairs 
        //if i have in the array then k-i should not be in the array
        
        unordered_set<int>hs;
        
        int limit=0,start=1,sum=0;
        
        while(limit<n)
        {
            int diff = k-start ;
            
            if(hs.find(diff) == hs.end())
            {
                hs.insert(start);
                sum+=start;
                start++;
                limit++;
            }
            else
            {
                start++;
            }
        }
        return sum ;
    }
};