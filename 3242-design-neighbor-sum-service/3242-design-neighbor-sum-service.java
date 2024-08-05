class neighborSum {
    int[][] grid;
    Map<Integer,Pair<Integer,Integer>> map;
    int row;
    int col;
    public neighborSum(int[][] grid) {
        this.grid=grid;
        map=new HashMap<Integer,Pair<Integer,Integer>>();
        row=grid.length;
        col=grid[0].length;
        for(int i=0;i<row*col;i++){
            map.put(grid[i/col][i%col],new Pair(i/col,i%col));
        }
    }
    
    public int adjacentSum(int value) {
        Pair<Integer,Integer> p=map.get(value);
        int currentRow=p.getKey();
        int currentCol=p.getValue();
        int sum=0;
        if(currentRow-1>=0)
            sum=sum+grid[currentRow-1][currentCol];
        if(currentCol-1>=0)
            sum=sum+grid[currentRow][currentCol-1];
        if(currentCol+1<col)
            sum=sum+grid[currentRow][currentCol+1];
        if(currentRow+1<row)
            sum=sum+grid[currentRow+1][currentCol];
        return sum;
    }
    
    public int diagonalSum(int value) {
        Pair<Integer,Integer> p=map.get(value);
        int currentRow=p.getKey();
        int currentCol=p.getValue();
        int sum=0;
        if(currentRow-1>=0){
            if(currentCol-1>=0)
                sum=sum+grid[currentRow-1][currentCol-1];
            if(currentCol+1<col)
                sum=sum+grid[currentRow-1][currentCol+1];
        }
        if(currentRow+1<row){
            if(currentCol-1>=0)
                sum=sum+grid[currentRow+1][currentCol-1];
            if(currentCol+1<col)
                sum=sum+grid[currentRow+1][currentCol+1];
        }
        return sum;
    }
}