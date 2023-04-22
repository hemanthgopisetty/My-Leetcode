class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> hm;
        for(auto i=0;i<arr.size();i++)
        {
            hm[arr[i]]++;
        }
        unordered_set<int> hs;
        for(auto it:hm)
        {
            hs.insert(it.second);
        }
        return hs.size()==hm.size();
    }
};