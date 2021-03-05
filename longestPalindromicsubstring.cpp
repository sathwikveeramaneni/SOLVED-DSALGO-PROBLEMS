 string longestPalindrome(string s) {
       int n=s.size();
        int k;
        string b;
        int l=0;
        int start=0;
        int a[n][n];
        memset(a,0,n*n*sizeof(int));
        for(int i=0;i<n;i++)
        {
            a[i][i]=1;
            l=1;
            start=i;
        }
        
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
            a[i][i+1]=1;
                    l=2;
                    start=i;
            }
        }
        for(int i=3;i<=n;i++)
        {
            for(int j=0;j<n-i+1;j++)
            {
                k=j+i-1;
                if(s[j]==s[k] && a[j+1][k-1]==1)
                {
                    a[j][k]=1;
                    if(i>l)
                    {
                        start=j;
                        l=i;
                    }
                }
            }
        }
        
        for(int i=start;i<start+l;i++)
            b=b+s[i]; 
        
        return b;
    }