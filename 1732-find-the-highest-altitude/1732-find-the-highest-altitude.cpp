class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>a(n+1,0);
        for(auto i=1;i<n+1;i++)
        {
            a[i]=a[i-1]+gain[i-1];
        }
        for(auto it:a)
        {
            cout<<it<<" ";
        }
        return *max_element(begin(a),end(a));
    }
};