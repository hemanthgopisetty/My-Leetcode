class Solution {
public:
    string minWindow(string s, string t) {
        string result;
    
        if(s.empty() or t.empty()) return result ;
        
        unordered_map<char,int>thm;
        unordered_map<char,int>shm;
        
        for(auto it:t)thm[it]++;
        
        int minl = INT_MAX;
        
        int counter =0;
        
        for(int slow=0,fast=0;fast<s.size();fast++)
        {
            char c = s[fast];
            
            //if it's there
            if(thm.find(c)!=thm.end())
            {
                shm[c]++;
                
                if(shm[c]<=thm[c])counter++;
            }
            
            //if we got one window 
            if(counter>=t.size())
            {
                //then move the slow pointer if it's t char or t's freq is greater than the s'freq
                while(thm.find(s[slow]) == thm.end() or shm[s[slow]]>thm[s[slow]])
                {
                    cout<<s[slow]<<endl;
                    shm[s[slow]]--;
                    slow++;
                }
                //calcualte the length
                if(fast-slow+1<minl)
                {
                    minl=fast-slow+1;
                    result = s.substr(slow,minl);
                }
                
                //mo
                cout<<slow<<"  sdfsdf"<<endl;
                shm[s[slow]]--;
                slow++;
                counter--;
            }
        }
        return result ;
    }
};