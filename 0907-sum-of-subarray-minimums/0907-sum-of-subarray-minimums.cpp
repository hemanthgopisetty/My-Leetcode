#define pii pair<int,int>
class Solution {
public:
    int sumSubarrayMins(vector<int>& a) {
        int n=a.size();
        vector<int>left(n),right(n);
        // left is for the distance to previous less element
        for(auto i=0;i<n;i++)left[i]=i+1;
        // right is for the distance to next less element
        for(auto i=0;i<n;i++)right[i]=n-i;
        
        stack<pii>pstk,nstk;
        for(auto i=0;i<n;i++)
        {
            int current_element = a[i];
            
            //for prev_less
            while( !pstk.empty() and ( pstk.top().first > current_element) )pstk.pop();
            left[i]=pstk.empty() ? i+1 :i-pstk.top().second;
            pstk.push({current_element,i});
            // cout<<"Left[i] = "<<left[i]<<endl;
            
            //for next_less
            while(!nstk.empty() and (nstk.top().first > current_element))
            {
                right[nstk.top().second]=i-nstk.top().second;
                nstk.pop();
            }
            nstk.push({current_element,i});
            
        }
        
        long ans=0;
        int mod=1e9+7;
        for(auto i=0;i<n;i++)
        {
            ans=(ans+1ll*a[i]*left[i]*right[i])%mod;
        }
        return ans;
    }
};