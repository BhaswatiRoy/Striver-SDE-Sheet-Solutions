/*
We will maintain a color vector which will initially has -1 representing no color. Then we will keep on coloring nodes in the opposite color of the parent node
Everytime in call, there is a check that if the node's adjacent nodes are colored then do they have different colors than it if not then not a bipartite graph

1. DFS
2. BFS

TC - O(n), SC - O(n)

*/

bool checkbipartitedfs(int sourcenode, vector<vector<int>>&graph, vector<int>&color)
{
        if(color[sourcenode]==-1)
        {
            color[sourcenode]=0;
        }
        for(auto it:graph[sourcenode])
        {
            if(color[it]==-1)
            {
                color[it]=!color[sourcenode];
                if(checkbipartitedfs(it,graph,color)==false)
                {
                    return false;
                }
            }
            else if(color[it]==color[sourcenode])
            {
                return false;
            }
        }
        return true;
}
bool isBipartite(vector<vector<int>>& graph) 
{
        int v=graph.size();
        vector<int>color(v,-1);
        for(int i=0;i<v;i++)
        {
            if(color[i]==-1)
            {
                if(checkbipartitedfs(i,graph,color)==false)
                {
                    return false;
                }
            }
        }
        return true;
}
