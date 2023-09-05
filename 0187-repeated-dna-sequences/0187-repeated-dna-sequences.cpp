class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        //For every 10 character string  we need to store there result in the hashmap
        //traverse the hashmap , mantain a ans variable if it's more than the ans then 
        //modify that .
        
        
        //buteforce 
        //for every i traverse 10 letter character string from i
        //mantain a answer varaible 
        
        
        //storing the string in the hashmap would give us memory limit excced
        hash<string> hfn;//for indexing 
        unordered_map<size_t,int> hm ;
        vector<string>ans ;
        int n = s.size();
        for(int i=0;i<n-9;i++)//traverse upto last but 9 digits
        {
            string temp = s.substr(i,10);
            if(hm[hfn(temp)]++ == 1)
            {
                ans.push_back(temp);
            }
        }
        return ans ;
    }
};