 int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> e(n);
        vector<vector<int>> v(n+1,vector<int>(n+1));
       for(int i=0;i<flights.size();++i)
        {    
            e[flights[i][0]].push_back(flights[i][1]);
            v[flights[i][0]][flights[i][1]] = flights[i][2];
        }
        vector<int> visited(n+1,0);
        int fare=INT_MAX;
        int totalcost=0;
        flight(e,v,src,dst,K,fare,totalcost,visited);
        if(fare==INT_MAX)
            return -1;
        return fare;
    }
    
    void flight(vector<vector<int>> &adj,vector<vector<int>> &cost,int src,int dst,int k,int &fare,int totalcost,vector<int> visited)
    {
        if(k<-1)
            return ;
        
        if(src==dst)
        {
            fare=min(fare,totalcost);
            return ;
        }
        
        visited[src]=1;
        for(int i=0;i<adj[src].size();i++)
        {
             if(!visited[adj[src][i]] && (totalcost+cost[src][adj[src][i]] <= fare))
                flight(adj,cost,adj[src][i],dst,k-1,fare,totalcost+cost[src][adj[src][i]],visited);
        }
        visited[src]=0;
    }
