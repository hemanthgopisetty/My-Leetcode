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
    int dp[101][101]{};
    int uniquePaths(int m, int n,int i=0,int j=0) 
    {
	/*if Out of boundaries return false*/
	if(i>=m or j>=n)return 0;

	/*if valid path return true ,which send integer 1,
	so on a particular fn call in the emplict stack*/
	if(i==m-1 or j==n-1)return 1;
        
    /*if already this path computed then return that value*/
    if(dp[i][j]) return dp[i][j];   
	//our answer is computation of this expression
	       /*  down   */ /*	 right	*/ 
	return dp[i][j]=uniquePaths(m,n,i+1,j)+uniquePaths(m,n,i,j+1);

    }
};