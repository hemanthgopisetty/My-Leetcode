class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n=words.size();
        unordered_map<string,int>hm;
        int ans=0;
        for(auto i=0;i<n;i++)
        {
            string curr=words[i];
            reverse(begin(curr),end(curr));
            if(hm[curr]>0)
            {
                ans++;
            }
            else
            {
                hm[words[i]]++;
            }
        }
        return ans;
    }
};