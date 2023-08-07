class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowsize=matrix.size();
        int columnsize=matrix[0].size();
        vector<bool>row(rowsize,false),column(columnsize,false);
        
        for(int i=0;i<rowsize;i++)
        {
           for(int j=0;j<columnsize;j++)
            {
                if(matrix[i][j]==0)
                {
                    row[i]=column[j]=true;
                }
            }
        }
        
        for(int i=0;i<rowsize;i++)
        {
            if(row[i]==true)
            {
                for(int j=0;j<columnsize;j++)
                {
                    matrix[i][j]=0;
                }
            }
        }
        
        for(int i=0;i<columnsize;i++)
        {
            if(column[i]==true)
            {
                for(int j=0;j<rowsize;j++)
                {
                    matrix[j][i]=0;
                }
            }
        }
    }
};