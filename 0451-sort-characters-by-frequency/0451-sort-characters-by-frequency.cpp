class Solution {
public:
    string frequencySort(string s) {
        //Find Frequencies
        //Sort based on the Frequcneis
        //Sort 
        
        int n = s.size();
        unordered_map<char,int> hm ;
        
        for(int i=0;i<n;i++)
        {
            hm[s[i]]++;
        }
        
        vector<pair<int,char>> arr ;
        
        for(auto& [c,f] : hm)
        {
            arr.push_back({f,c});
        }
        
        sort(arr.begin(),arr.end(),[](const auto &a,const auto &b){
            return a.first>b.first ;
        });
        
        string ans ;
        for(auto& [f,c]:arr)
        {
            ans.append(f,c);
        }
        
        return ans ;
    }
    
};