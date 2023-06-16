#include<stack>
#include<algorithm>
#include<cmath>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int>st;
    vector<int>v;
    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            st.push(arr[i]);
            v.push_back(-1);
        }else if(st.top()<arr[i]){
            v.push_back(st.top());
            st.push(arr[i]);
        }else{
            while( !st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                v.push_back(-1);
                st.push(arr[i]);
            }else{
                v.push_back(st.top());
                st.push(arr[i]);
            }
        }
    }
    reverse(v.begin(),v.end());
    return v;
}
//time complexity:0(n)
//space complexity:0(n) //stack space
