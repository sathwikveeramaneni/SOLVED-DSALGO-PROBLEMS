int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        int a[m][n];
        memset(a,0,m*n*sizeof(int));
        if(obstacleGrid[0][0]==1)
            return 0;
        if(obstacleGrid[m-1][n-1]==1)
            return 0;
        a[0][0]=1;
       
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(obstacleGrid[i][j]==0)
                {
                if(i-1>=0)
                a[i][j]=a[i-1][j]+a[i][j];
                
                if(j-1>=0)
                    a[i][j]=a[i][j]+a[i][j-1];
                }
            }
        }
        
        return a[m-1][n-1];
    }
