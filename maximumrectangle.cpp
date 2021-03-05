int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        if(n==0)
            return 0;
        int m=matrix[0].size();
        int mat[n][m+1];
        memset(mat,0,sizeof(mat));
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1' && i>0)
                    mat[i][j]=mat[i-1][j]+1;
                
                if(i==0)
                    mat[i][j]=matrix[i][j]=='1'?1:0;
            }
        
        
            int ret=0;
            vector<int> index;
        for(int j=0;j<n;j++)
            {
            
                for(int i = 0; i <m+1; i++)
            {
                while(index.size() > 0 && mat[j][index.back()] >= mat[j][i])
                {
                    int h = mat[j][index.back()];
                    index.pop_back();
                    
                    int sidx = index.size() > 0 ? index.back() : -1;
                    if(h * (i-sidx-1) > ret)
                        ret = h * (i-sidx-1);
                    cout<<ret<<" ";
                }
                index.push_back(i);
                    
            }
            index.clear();
            
            }
        
        return ret;
    }
