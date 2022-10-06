/*

*/

void dfs(Node *node, Node *copygraph, vector<Node*>&visited)
{
        //add the node in visited vector
        visited[copygraph->val]=copygraph;
        for(auto x:node->neighbors)
        {
            //if the adjacent/neighbor nodes are not visited
            if(visited[x->val]==NULL)
            {
                Node* newnode=new Node(x->val);
                //push that node into neighbors of the copygraph reference
                (copygraph->neighbors).push_back(newnode);
                //recursively call function for other nodes
                dfs(x,newnode,visited);
            }
            //if the adjacent/neighbor nodes are visited
            else
            {
                //push that node into neighbors of the copygraph reference 
                //for undirected graph 1--3 we need to add both 1--3 & 3--1 into copygraph too
                (copygraph->neighbors).push_back(visited[x->val]);
            }
        }
}
Node* cloneGraph(Node* node) 
{
        if(node==NULL)
        {
            return NULL;
        }
        vector<Node*>visited(1000,NULL);
        //create graph copy with given node value
        Node *copygraph=new Node(node->val);
        //call dfs to clone the entire graph 
        dfs(node,copygraph,visited);
        return copygraph;
}
