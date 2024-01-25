#include<bits/stdc++.h>

using namespace std;

int n, e;
vector< vector<int> > adj;
vector<bool> visited;
vector<int> topsport;
vector<int> start, finish;


void dfs(int node)
{
    visited[node] = true;

    for(int i{0}; i < (int)(adj[node].size()); ++i)
    {
        int child = adj[node][i];
        if(!visited[child]) // To avoid cyclic behavior
            dfs(child); 
    }

    //topsport.push_back(node); // DAG // Other INdegree / Outdegree
}


int ConnectedComponents(int n)
{
    int cnt = 0;
    for(int i{0}; i < n; ++i)
    {
        if(!visited[i]) // Then no one reach this isolated node yet and its neighbors.
        {
            dfs(i);
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    cin >> n >> e;


    return 0;
}
