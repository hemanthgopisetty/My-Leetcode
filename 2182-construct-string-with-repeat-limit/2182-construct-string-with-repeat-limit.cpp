class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n=s.size();
        //Put characters in HashMap and store there frequeinces
        unordered_map<char,int>hm;
        for(int i=0;i<n;i++)
        {
           hm[s[i]]++;
        }
        //Put characters only mean (unique) in maxHeap(max top always)
        priority_queue<char>pq;
        for(auto& [ch,cnt]:hm)
        {
            pq.push(ch);
        }
        //Now build the answer by using hashmap and priority_queue
        string ans;
        while(!pq.empty())
        {
            char ch=pq.top();
            pq.pop();
            int cnt=hm[ch];
            
            int use=min(cnt,repeatLimit);
            ans.append(use,ch);
            
            hm[ch]-=use;
            
            if(hm[ch]>0 and !pq.empty())
            {
                char nxtch = pq.top();
                pq.pop();
                ans.push_back(nxtch);
                
                hm[nxtch]--;
                if(hm[nxtch]>0)
                {
                    pq.push(nxtch);
                }
                pq.push(ch);
            }
        }
        return ans ;
    }
};