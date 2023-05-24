//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<vector<int>> memo;

    bool dfs(vector<int>& arr, int sum, int idx) {
        if (sum == 0) {
            return true;
        }

        if (idx <= 0) {
            return false;
        }

        if (memo[idx][sum] != -1) {
            return memo[idx][sum];
        }

        if (arr[idx - 1] > sum) {
            return memo[idx][sum] = dfs(arr, sum, idx - 1);
        }

        return memo[idx][sum] = dfs(arr, sum, idx - 1) || dfs(arr, sum - arr[idx - 1], idx - 1);
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        memo.resize(n + 1, vector<int>(sum + 1, -1));
        return dfs(arr, sum, n);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends