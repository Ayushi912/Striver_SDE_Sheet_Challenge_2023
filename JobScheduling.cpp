#include <bits/stdc++.h> 
static bool cmp(vector<int>&a, vector<int>&b){
    return a[1]>b[1];
}
int jobScheduling(vector< vector<int> > &jobs)
{
    sort(jobs.begin(), jobs.end(), cmp);
    int n=jobs.size(), pr=0;
    vector<int>m(10000,-1); //data structure to identify which deadlines were already considered.

    for(int i=0; i<n; i++){
        for(int j=jobs[i][0]; j>0; j--){
            if(m[j]==-1){ //prevents us from reconsidering the same deadline.
                m[j]=i;
                pr+=jobs[i][1];
                break;
            }
        }
    }
    return pr;
}
