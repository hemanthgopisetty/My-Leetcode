class Solution {
public:
    //Bute Force to Optimal ~Lc journey
    //Bute Force generetae substring from each i and each i to n-1
    //check weteher it's nice substring or not
    //if yes then return the result
    
    //optimal way is using Divide and Conquer
    bool f(string s,int i,int j)
    {
        unordered_map<char,bool>hm;
        for(auto x=i;x<=j;x++)
        {
            hm[s[x]]=true;//insert in the map and mark it is as a true
        }
        while(i<=j)
        {
            if(s[i]<97)//small letter
            {
                //it's upper case is in the map or not // if no then return false
                if(hm[s[i]+32]==false)
                {
                    return false;
                }
            }
            else
            {
                if(hm[s[i]-32]==false)
                {
                    return false;
                }
            }
            i++;
        }
        return true ;
    }
    string longestNiceSubstring(string s) {
        string result ;
        int maxm=INT_MIN;
        for(auto i=0;i<s.size();i++)
        {
            for(auto j=i;j<s.size();j++)
            {
                if(f(s,i,j))
                {
                    if(j-i+1>maxm)
                    {
                        maxm=j-i+1;
                        result=s.substr(i,j-i+1);
                    }
                }
            }
        }
        return result;
    }
};