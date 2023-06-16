#include<queue>
void bfs(int** arr,int n,int m,int i,int j,vector<vector<int>>&vis){
   queue<pair<int,int>>q;
   q.push({i,j});
   vis[i][j]=1;
   while(!q.empty()){
      int row=q.front().first;
      int col=q.front().second;
      q.pop();
      for(int ip=-1;ip<=1;ip++){
         for(int jp=-1;jp<=1;jp++){
            int nr=row+ip;
            int nc=col+jp;
            if(nr>=0 && nr<n && nc>=0 && nc<m&&!vis[nr][nc]&& arr[nr][nc]==1){
               vis[nr][nc]=1;
             q.push({nr,nc});
            }
         }
      }
   }
}

int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
   vector<vector<int>>vis(n,vector<int>(m,0));
   int c=0;
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         if( !vis[i][j] &&arr[i][j]==1){
            c++;
            bfs(arr,n,m,i,j,vis);
         }
      }
   }
   return c;
}
