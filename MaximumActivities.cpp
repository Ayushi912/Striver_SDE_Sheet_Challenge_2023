#include<algorithm>
bool static cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    vector<pair<int,int>>ans;
    int n=start.size();
    for(int i=0;i<n;i++){
ans.push_back({start[i],finish[i]});
    }
    sort(ans.begin(),ans.end(),cmp);
    int c=1;
    int st=ans[0].second;
    for(int i=1;i<n;i++){
        if(ans[i].first>=st){
            c++;
            st=ans[i].second;
        }
    }
    return c;
}
