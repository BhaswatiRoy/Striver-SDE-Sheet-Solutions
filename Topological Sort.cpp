/*
1. DFS -
   DFS we recursively reach to adjacent nodes and print them first then come to current node.
   But in Topological Sort we store the current node 1st in stack then move to adjacent nodes. Thus we push the node whose dfs call is completed into the stack
   
2. BFS -
   In BFS we don't need an indegree vector. But in Topological Sort by BFS we need to maintain an indegree vector.
   We will check nodes and reduce the indegree of adjacent nodes by 1 to finally make as 0.
   Also everytime we get a node with indegree of 0 we will push it to queue and later print accordingly.
   
TC - O(n), SC - O(n)
*/

void findtoposort(int sourcenode, vector<int>&visited,vector<int>adj[],stack<int>&st)
{
	    visited[sourcenode]=1;
	    for(auto it=adj[sourcenode].begin();it!=adj[sourcenode].end();it++)
	    {
	        if(visited[*it]==0)
	        {
	            findtoposort(*it,visited,adj,st);
	        }
	    }
	    st.push(sourcenode);
}
vector<int> topoSort(int V, vector<int> adj[]) 
{
	    stack<int>st;
	    vector<int>visited(V+1,0);
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==0)
	        {
	            findtoposort(i,visited,adj,st);
	        }
	    }
	    vector<int>topo;
	    while(!st.empty())
	    {
	        topo.push_back(st.top());
	        st.pop();
	    }
	    return topo;
}
