int maxProfit(vector<int>& prices) {
        int k=INT_MAX;
        int n=0;
        for(int i=0;i<prices.size();i++)
        {
            k=min(k,prices[i]);
            n=max(n,prices[i]-k);
        }
        return n;
    }
