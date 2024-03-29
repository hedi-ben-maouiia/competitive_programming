#include<bits/stdc++.h>
#include <utility>

using namespace std;


const int N {100};

// adjacency matrix 
bool adjMatrixBool[N][N];
int adjMatrix[N][N];

vector<int> adjMatrixAll[N][N]; // Keep all edges for a given pair of nodes 
 
map<pair<int,int>, int> adjMatrixMap; // Imagine graph of 100000 node, but total number of edges is 50000


// adjacency lists 
vector< vector<int> > adjList1;              // boolean relation 
vector< vector< pair<int, int> > > adjList2; // cost relation (node, cost): Select 1 of multiple edges 

// Edges List 

struct edge 
{
    int from, to, w;
    edge(int from, int to, int w): from(from), to(to), w(w){}

    bool operator < (const edge & e) const {
        return w > e.w; // Sort with smaller weight first
    }
};

vector<edge> edgeList;



int main()
{
    int n;
    // Assume all input is Zero based. Node values[0 - n-1]
    
    /*
     * 3
     * 0 1 0
     * 1 1 0
     * 0 1 1 
     */ 
    
    cin >> n; 
    for(int i{0}; i < n;++i)
    {
        for(int j{0}; i < n;++j)
        {
            int b;
            cin >> b;
            adjMatrixBool[i][j] = b; 
        }
    }
    /*
     * 3 
     * 0 10 5 
     * 2 7 9
     * 3 2 0
     */ 
    
    cin >> n;
    for(int i{0}; i < n; ++i)
    {
        for(int j{0}; j < n;++j)
        {
            int b;
            cin >> b;
            adjMatrix[i][j] = b;
        }
    }
    // 
    int edges;
    cin >> n >> edges;
    /*
     * 3 5 
     * 0 3 10 
     * 1 5 2 
     * 3 7 -2 
     * 0 3 2 
     * 2 4 6
     */
    
    for(int i{0};i < edges;++i)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        adjMatrix[from][to] = min(adjMatrix[from][to], cost); // if directed
        
        // if undirected: add following 
        adjMatrix[to][from] = adjMatrix[from][to];
    }
    
    // Let's keep edge with min cost;

    /*
     * 3
     * 2 1 2 
     * 1 2 
     * 2 0 1 
     */
    cin >> n;
    adjList1 = vector< vector<int> > (n);
    for(int i{0}; i < n;++ i)
    {
        int cnt;
        cin >> cnt;
        for(int j{0}; j < cnt;++j)
        {
            int to;
            cin >> to;
            adjList1[i].push_back(to);
        }
    }

    /*
     * 3
     * 2 1 13   2 4
     * 1 2 9    3 -4
     * 2 0 -7   1 8
     */

    cin >> n;
    adjList2 = vector< vector< pair<int, int> > > (n);
    for(int i{0}; i < n; ++i)
    {
        int cnt;
        cin >> cnt;
        for(int j{0}; j < cnt; ++j)
        {
            int to, cost;
            cin >> to >> cost;
            adjList2[i].push_back( make_pair(to, cost));
        }
    }

    return 0;
}
