#include<bits/stdc++.h>
void convertor(unordered_map<int, list<int>> &adj,vector<vector<int>>&edges ){
    for(int i = 0 ; i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);  // as undirected;
        adj[v].push_back(u); // as undirected ;
    }
}

bool cycleDFS(unordered_map<int,list<int>>&adj,int source,int parent ,  vector<bool>&visited) {
    visited[source] = true;
    for(auto it : adj[source]){
        if(visited[it] == false){
          if   ( cycleDFS(adj, it,source,visited)){
              return true;
          }
        }
        else if(visited[it] == true and it!=parent){
            return true;
        }
    }
    return false;
}


string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int,list<int>>adj;
    vector<vector<int>>ans;
    vector<bool>visited(n+1,false);
    convertor(adj,edges);
    for(int i = 0 ;i<n;i++){
        if(visited[i] == false){
            if(cycleDFS(adj,i,-1,visited)){
                return "Yes";
            }
            
        }
    }
    return "No";
}
