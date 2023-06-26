#include<bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
   // Write your code here
   vector<int>adj[vertex+1];
   int m=edges.size();
   for(int i=0;i<m;i++){
       adj[edges[i].first].push_back(edges[i].second);
       adj[edges[i].second].push_back(edges[i].first);
   }
   for(int i=0;i<vertex;i++)
      sort(adj[i].begin(),adj[i].end());
   vector<int>vis(vertex+1,0);
   vector<int>bfsans;
   for(int i=0;i<vertex;i++){
       if(!vis[i]){
           queue<int>q;
           q.push(i);
           vis[i]=1;
           while(!q.empty()){
               int node=q.front();
               q.pop();
               bfsans.push_back(node);
               for(auto it:adj[node]){
                   if(!vis[it]){
                       q.push(it);
                       vis[it]=1;
                   }
               }
            }
       }
   }
   return bfsans;
}
