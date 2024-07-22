class Solution {
public:
    string losingPlayer(int x, int y) {
        int cnt = 0 ;
        while(x>0 and y>3)
        {
            x--;
            y-=4;
            cnt++;
        }
         return cnt % 2 ? "Alice" : "Bob";
    }
};