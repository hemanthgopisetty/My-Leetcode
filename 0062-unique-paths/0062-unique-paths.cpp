class Solution {
public:
    /*
    Dynamic Programming ~cache steps
    starting point (0,0) need to reach the end point(n,n) of grid mxn
    Moves -> right or down
    Constraints ~1<=m,n<=100
    
    ButeForce :-Try all the pos
    We will get time limit exceeded
    y ? Calculating a path again in one of the fn call
    To optimize it we will remember that
    we will use the dp 
    int dp[101][101]
    */
    int uniquePaths(int m, int n,int i=0,int j=0) 
    {
        
	// /*if Out of boundaries return false*/
	//if(i>=m or j>=n)return 0;

	// /*if valid path return true ,which send integer 1,
	//so on a particular fn call in the emplict stack*/
	//if(i==m-1 or j==n-1)return 1;
        
   // /*if already this path computed then return that value*/
    //if(dp[i][j]) return dp[i][j]   
	//our answer is computation of this expression
	      //                      down    	            right	
	//return dp[i][j]=uniquePaths(m,n,i+1,j)+uniquePaths(m,n,i,j+1);
    
        
        //for tabulation we declare a vector 
        //becuase we iterate each path once we need to calculate the ways to reach that cell
        //if there is a cell means we include it to the count 
        //Bottum up start with base case
        //1 step is need to reach the 0,j
        //and 1 step is reached to reach the i,0
        vector<vector<int>> dp(m,vector<int>(n,1));
        for(auto i=1;i<m;i++)
        {
            for(auto j=1;j<n;j++){
             //dp[currentright][currentdown]=dp[previousright][currentdown]+dp[currentright][previousdown]
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};