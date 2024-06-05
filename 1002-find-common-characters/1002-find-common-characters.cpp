class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> minC(26,INT_MAX);
        for(auto it:words){
            
            vector<int>freq(26,0);
            
            for(char jt:it){
                
                freq[jt-'a']++;
            }
            
            for(int i=0;i<26;i++){
                
                minC[i]=min(minC[i],freq[i]);
            }
        }
        
        vector<string> ans ;
        
        for(int i=0;i<26;i++){
            
               while(minC[i]>0){
                   
                   ans.push_back(string(1, i + 'a'));
                   minC[i]--;
                   
               }
        }
        return ans;
    }
};