#include <sstream> 
#include<bits/stdc++.h>
string reverseString(string str)
{
    // Write your code here.
    vector<string>res;
    string ans, word;
    stringstream ss(str); 
    while(ss >> word)    
        res.push_back(word);

    reverse(res.begin(),res.end());
    for(string &word : res)
        ans += word + " ";
    return ans;
}
