#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int vertices;
    vector<list<int>> adj;
public:
    Graph(int v)
    {
        vertices = v;
        adj.resize(v); //number of lists
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void display()
    {
        for(int i = 0; i<vertices; i++)
        {
            cout << i << "->";
            for(int x : adj[i])
                //adj[0]= {3,1,2}
                // x represents value inside adj[i]
                //adj[0] or adj[i] has a list inside them
            {
                cout << x << " ";

            }
            cout<< endl;
        }
    }
};

int main()
{
    int vertices, edges;
    cout<< "Enter the number of vertices : ";
    cin>> vertices;
    Graph g(vertices);
    cout<< "Enter the number of edges : ";
    cin>>edges;
    for(int i = 0; i<edges; i++)
    {
        int u,v;
        cout<< "Add edge between : ";
        cin>>u>>v;
        g.addEdge(u,v);
    }
    g.display();
}
