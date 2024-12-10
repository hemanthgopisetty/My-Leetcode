class Solution {
public:
    int maximumLength(string s) {
    int n=s.size();
	map<string,int>hm;	//to store the special substrings
	for(int i=0;i<n;i++)
	{
		char spl=s[i];
		string tmp;
		tmp+=spl;
		hm[tmp]++;
		for(int j=i+1;j<n;j++)
		{
			if(s[j]==spl)
			{
				tmp+=spl;
				hm[tmp]++;
			}
			else
			{
				break;
			}
		}
	}
	int maxx=-1;
	for(auto it:hm)
	{
		if(it.second>=3)
		{
			maxx=max((int)it.first.size(),maxx);
		}
	}
	return maxx;
    }
};