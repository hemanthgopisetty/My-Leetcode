class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans(n-k+1,0);
        for(int i=0;i<=n-k;i++)
        {
            bool pass = true ;
            for(int j=i;j<i+k-1;j++)
            {
                if(nums[j+1]!=nums[j]+1)
                {
                    pass=false;
                    break;
                }
            }
            
            if(pass)
            {
                ans[i]=nums[i+k-1];
            }
            else
            {
                ans[i]=-1;
            }
        }
        return ans ;
    }
};

/*

Power of array defines as -> Maximum element if all of it's elements are sorted and consecutive
consecutive means current+1 value

1 2 3 4 3 2 5 -> []
k = 3
n=9
n-k
1 2 3 max -> 3
2 3 4 max -> 4
3 4 3 -1 not consecutive
4 3 2 -1 not sorted
3 2 5 -1 not consecutive


1 2 3 4 5 6 7 8 9 k=2
2 3 4 5 6 7 8 9 -> Every sub array of size k is sorted and consecutive

9 8 7 6 5 4 3 2 1 k=2
-1 -1 -1 -1 -1 -1 -1 

1 3 4 5 6 8 10 k=3
1 3 4 -1
3 4 5  5
4 5 6  6
5 6 8  -1
6 8 10 -1


first we need to choose sub array of size k (i(o to n),j(i to i+k))
then we need to check consecutive and sorted prooperty

j -> (i to i+k)
j=i+1
consecutive -> (nums[i-1]+1==nums[i])
sorted -> (nums[i]>nums[i-1])
*/