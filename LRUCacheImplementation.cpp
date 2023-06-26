#include <bits/stdc++.h>
using namespace std;
class LRUCache
{
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>> :: iterator> mp;
    int cap;
public:
    LRUCache(int capacity)
    {
        // Write your code here
        cap = capacity;
    }

    int get(int key)
    {
        // Write your code here
        if(mp.find(key) == mp.end())
            return -1;
        int val = (*mp[key]).second;
        put(key, val);
        return val;
    }

    void put(int key, int value)
    {
        // Write your code here
        if(mp.find(key) != mp.end())
        {
            auto it = mp[key];
            cache.erase(it);
            cache.push_back({key, value});
            mp[key] = --cache.end();
            return;
        }
        if(mp.size() == cap)
        {
            int k = cache.front().first;
            cache.pop_front();
            mp.erase(k);
        }
        cache.push_back({key, value});
        mp[key] = --cache.end();
    }
};
