#include <bits/stdc++.h>
class Trie {

    vector<Trie*> child;

public:

    /** Initialize your data structure here. */
    Trie() {
        child.resize(2);
    }

    /** Inserts a number into the trie. */
    void insert(int num) {
        Trie *cur = this;
        for(int bit = 30; bit >= 0; bit--)
        {
            int mask = 1 << bit;
            int isSet = (num & mask) > 0 ? 1 : 0;
            if(cur -> child[isSet] == nullptr)
                cur -> child[isSet] = new Trie();
            cur = cur -> child[isSet];
        }
    }

    /** Returns max xor in the trie. */
    int maxXor(int num, int lim) {
        Trie *cur = this;
        int ans = 0;
        for(int bit = 30; bit >= 0; bit--)
        {
            int mask = 1 << bit;
            int isSet = (num & mask) > 0 ? 1 : 0;
            if (cur->child[!isSet] != nullptr) {
              cur = cur->child[!isSet];
              ans |= mask;
            } 
			else if(cur -> child[isSet] != nullptr)
				cur = cur->child[isSet];
			else
				return -1;
        }
        return ans;
    }
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.
	Trie *trie = new Trie();
	for(int i = 0; i < queries.size(); i++)
	{
		swap(queries[i][0], queries[i][1]);
		queries[i].push_back(i);
	}
	sort(queries.begin(), queries.end());
	sort(arr.begin(), arr.end());
	int i = 0, j = 0;
	vector<int> ans(queries.size());
	while(j < queries.size())
	{
		while(i < arr.size() && arr[i] <= queries[j][0])
			trie -> insert(arr[i++]);
		ans[queries[j][2]] = trie -> maxXor(queries[j][1], queries[j][0]);
		j++;
	}
	return ans;
}
