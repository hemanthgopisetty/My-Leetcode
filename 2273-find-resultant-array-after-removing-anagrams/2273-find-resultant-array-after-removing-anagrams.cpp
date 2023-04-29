class Solution {
public:
    //if a stored string is in the hash then delete it
    vector<string> removeAnagrams(vector<string>& words) {
        map<string,int>hm;
          //sorted,key
        int n=words.size();
        vector<string>ans;
        for(auto i=0;i<n;i++)
        {
            string temp=words[i];
            sort(temp.begin(),temp.end());
            //if that sorted word is not in the hm or if the word is there
            if(hm.find(temp)==hm.end() or hm[temp]!=i-1)
            {
                ans.push_back(words[i]);
            }
            hm[temp]=i;
        }
        return ans;
    }
};