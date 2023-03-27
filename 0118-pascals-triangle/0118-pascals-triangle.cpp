class Solution {
public:
    //we need to return the matrix 
    //matrix having elements with increasing size
    //Base case first element and last element in the row is always 1
    //Every row has dynamic size

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>dp;
        for(auto i=0;i<numRows;i++)
        {
            vector<int>row(i+1,1);
            for(auto j=1;j<i;j++)
            {
                row[j]=dp[i-1][j]+dp[i-1][j-1];
            }
            dp.push_back(row);
        }
        return dp;
    }
};