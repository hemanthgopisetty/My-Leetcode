class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())return false;
        string temp =s+s;
        return temp.find(goal)<temp.length();
    }
};
/*
    idea is to concate two strings 
    if we right shift the current string character by character until the end
    we will get main string
    abcde+abcde = abcdeabcde
    for ex :-
    shift until e then we get abcde
    
    if we can concate two string we can find that easily
    TC O(n)  SC O(n)
*/

/*

    kmp algorithm allows us to search for substrings in linear time by preprocessing the pattern 
    Usually Finding Substring takes in a string Takes O(n^2) time
    kmp algo do that in linear time
    
    
*/