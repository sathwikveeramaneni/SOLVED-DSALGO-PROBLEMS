 int trap(vector<int>& a) {
     int n=a.size();
        if(n==0)
            return 0;
        int i=0,j=n-1;
        int left=0,leftmax=0,c=0,right=0,rightmax=0;
        while(i<=j)
        {
            if(a[i]<=a[j])
            {
                if(leftmax<a[i])
                    leftmax=a[i];
                else
                c=c+leftmax-a[i];
                i++;
            }
            else
            {
                if(rightmax>a[j])
                    c=c+rightmax-a[j];
                else
                    rightmax=a[j];
                j--;
                    
            }
        }
        return c;
    }