int numDecodings(string s) {
        if(s.size()==0)
            return 0;
        vector<int> num(s.size()+1,0);
        num[0]=1;
        if(s[0]=='0')
            num[1]=0;
        else
            num[1]=1;
        for(int i=1;i<s.size();i++)
        {
          if(s[i]>'0')
            num[i+1]+=num[i-1+1];
            if(s[i]>='0' && s[i]<='6' && i-1>=0 && s[i-1]=='2' )
                num[i+1]+=num[i-2+1];
            if(s[i]>='0' && s[i]<='9' && i-1>=0 && s[i-1]=='1')
                num[i+1]+=num[i-2+1];
        }
        return num[s.size()];
    }
