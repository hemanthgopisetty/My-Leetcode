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
        //until heap is empty
        while(!pq.empty())
        {
            //Take top element
            char ch=pq.top();
            //Pop the element
            pq.pop();
            //Take Freq from hashmap
            int cnt=hm[ch];
            
            //use limited Charaters from the map
            int use=min(cnt,repeatLimit);
            ans.append(use,ch);
            
            hm[ch]-=use;
            
            //if top element still left after using limited character take next top element
            if(hm[ch]>0 and !pq.empty())
            {
                //take next top element
                char nxtch = pq.top();
                pq.pop();
                //push back to the ans
                ans.push_back(nxtch);
                hm[nxtch]--;
                
                //check wether it's still there if yes push the second top character
                if(hm[nxtch]>0)
                {
                    pq.push(nxtch);
                }
                //as we know still first top are there we need to push it
                pq.push(ch);
            }
        }
        return ans ;
    }
};