/*
Question - There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
           You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
           For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

If suppose [1,2],[2,3],[3,1] is given the 1->2->3->1 so we can't finish tasks as there is cyclic dependency - cycle 

If we check cycle in DFS in directed graph and if cycle is present then tasks/courses can not be scheduled
*/

bool detectcycle(int node, vector<int>adj[], vector<int>&visited, vector<int>&dfsvisited)
{
        //marking that node in both vectors as 1
        visited[node]=1;
        dfsvisited[node]=1;
        for(auto it=adj[node].begin();it!=adj[node].end();it++)
        {
            //if the node is unvisited
            if(visited[*it]==0)
            {
                //recursively call the function and check for all nodes
                if(detectcycle(*it,adj,visited,dfsvisited)==true)
                {
                    return true;
                }
            }
            //if the node was visited(visited[*it]=1) and visited in same directed traversal(dfsvisited[*it]=1)
            else if(visited[*it]==1 && dfsvisited[*it]==1)
            {
                return true;
            }
        }
        //if we did not find a cycle in this traversal then we will make that node as 0 in dfsvisited vector 
        dfsvisited[node]=0;
        return false;
}
bool isPossible(int N, vector<pair<int, int> >& prerequisites) 
{
	    int p=prerequisites.size();
	    vector<int>adj[N];
	    for(int i=0;i<p;i++)
	    {
	        int u=prerequisites[i].second;
	        int v=prerequisites[i].first;
	        adj[u].push_back(v);
      }
	    vector<int>visited(N,0);
	    vector<int>dfsvisited(N,0);
	    for(int i=0;i<N;i++)
	    {
	        //check if the node is unvisited then we will visit that node to do further checks
	        if(visited[i]==0)
	        {
	            //cycle detected so tasks can't be smoothly performed as there are unfulfilled dependencies
	            if(detectcycle(i,adj,visited,dfsvisited)==true)
	            {
	                return false;
	            }
	        }
	    }
	    return true;
}
