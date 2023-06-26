int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
   // Write your code here.
   vector<vector<int>>dis(n+1,vector<int>(n+1,1e9));
   for(int i = 1 ; i<=n ;i++){
       for(int j = 1 ; j<=n ;j++){
           if(i==j)dis[i][j] = 0;
       }
   }
   for(int i = 0 ; i<edges.size();i++){
       int u = edges[i][0];
       int v = edges[i][1];
       int wt = edges[i][2];
       dis[u][v] = wt;
   }
   for(int k = 1 ; k<=n ;k++){
       for(int i = 1 ; i<=n ;i++){
           for(int j = 1;j<= n ;j++){
                if((dis[i][k]!=1e9 && dis[k][j]!=1e9))
               dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
           }
       }
   }
   return dis[src][dest];
}
