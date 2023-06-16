#include <bits/stdc++.h> 

bool static cmp( pair<int,pair<int,int>>a,pair<int,pair<int,int>>b){
 
  if(a.second.first==b.second.first){
      return a.second.second<b.second.second;
  }else {
       return a.second.first<b.second.first;
  }
   
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n=start.size();
    vector<int>v;
    vector<pair<int,pair<int,int>>>ans; //{start,{end,i+1}};
    for(int i=0;i<n;i++){
        ans.push_back({start[i],{end[i],i+1}});
    }
    sort(ans.begin(),ans.end(),cmp);
    int st=ans[0].second.first;
    v.push_back(ans[0].second.second);
    for(int i=1;i<n;i++){
        if(st<ans[i].first){
            v.push_back(ans[i].second.second);
            st=ans[i].second.first;
        }
    }
    return v;
}
