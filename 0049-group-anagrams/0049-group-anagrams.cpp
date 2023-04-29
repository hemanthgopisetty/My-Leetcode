class Solution {
      private :
     string sorted(string str){
        
        int freq[26] = {0};        
        for(auto ch : str){
            freq[ch - 'a']++;
        }
        //freq[e,a,t]=1,1,1
        string sortedStr;                
        for(int itr = 0; itr < 26; itr++){
            //Creating a new string on every iteration
            //n,) in vector
            sortedStr += string(freq[itr], 'a' + itr);           
        }
        cout<<sortedStr.size()<<endl;;
        return sortedStr;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      //we have to find anagrams First
      //we have to group them

      //For group same string 
      //If suppose one anagram belongs to one group y
      //if suppose we found a string that is belonging to the group y
      //we have push this string to that grp y
      //to do so we use unorderd_map<string,vector<string>> jm;
      //We have to sort for each iteration
      //to know which group this anagram belongs to
      //We had done grouping the all anagrams which are belonging to the same group
      //We have to make result
      //For this we have to traverse hash_map
      //This Approach takes O(nlogn)

      //Since the string contains only alphabets lower
      //which is a constant
      //We can use this to reduce time complexity
      //By couting the frequenceis
      //As we know they are only 26 so time complexity will be O(n.m.26);
      
      unordered_map<string,vector<string>> hm;
      for(auto it:strs)
      {
          string temp=it;
          it=sorted(it);
         hm[it].push_back(temp);
      }
       vector<vector<string>> res;        
        for(auto values : hm){
            res.push_back(values.second);
        }
      return res;
    }
};