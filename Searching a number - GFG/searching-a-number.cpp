//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    int ls(int arr[],int idx,int n,int k)
    {
        if(idx==0)
        {
            return (arr[idx]==k) ? idx+1 :-1;
        }
        return (arr[idx]== k and idx >=0) ? idx+1 : ls(arr,idx-1,n,k);
    }
	int search(int arr[], int n, int k) {
	    for(auto i=0;i<n;i++)
	    {
	        if(arr[i]==k)
	        {
	            return i+1;
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, k;
        cin >> n >> k;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.search(a, n, k);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends