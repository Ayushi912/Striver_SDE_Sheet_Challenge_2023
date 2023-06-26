/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/

#include <bits/stdc++.h>
graphNode *cloneGraph(graphNode *node){
    if(node==nullptr)    return nullptr;
    unordered_map<graphNode*, graphNode*> cloneOf;
    stack<graphNode*> st;
    st.push(node);
    while(!st.empty()){
        graphNode *orgNode = st.top();
        if(!cloneOf[orgNode])    cloneOf[orgNode] = new graphNode(orgNode->data);
        
        vector<graphNode*> cloneOfNeighbours;
        for(graphNode *neighbour: orgNode->neighbours)
            if(cloneOf[neighbour])    cloneOfNeighbours.push_back(cloneOf[neighbour]);
            else    st.push(neighbour);
        
        if(cloneOfNeighbours.size() == orgNode->neighbours.size()){
            cloneOf[orgNode]->neighbours = cloneOfNeighbours;
            st.pop();
        }
    }
    return cloneOf[node];
}
