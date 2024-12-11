class Solution {
    bool isValid(string&s,int k)
{
	int n=s.size();
	vector<int>freq(26,0);
    vector<int>count(26,0);
	int l=0,r=0;
	while(r<n)
	{
        freq[s[r]-'a']++;
		if(r-l+1==k)
		{
			if(freq[s[r]-'a']==k)
            {
                count[s[r]-'a']++;
            }
            if(count[s[r]-'a']>=3)
            {
                return true;
            }
            freq[s[l]-'a']--;
			l++;
		}
		r++;
	}
	return false;
}
public:
    int maximumLength(string s) {
	int n=s.size();
	int l=1,h=n-2;
	int ans=-1;
	while(l<=h)
	{
		int m=l+(h-l)/2;
		if(isValid(s,m))
		{
			ans=m;
			l=m+1;
		}
		else
		{
			h=m-1;
		}
	}
	return ans;
    }
};