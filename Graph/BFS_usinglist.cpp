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
        adj.resize(v);
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
            cout<< i << "-> ";
            for(int x : adj[i])
            {
                cout<< x<< " ";

            }
            cout<<endl;
        }
    }
    void BFS(int start)
    {
        queue<int> q;
        q.push(start);
        vector<bool> visited(vertices, false);
        while(q.size()>0)
        {
            int v = q.front();
            q.pop();
            if(!visited[v])
            {
                cout<<v << " ";
                visited[v]=true;
                for(int x : adj[v]) // searching v's neighbour
                {
                    if(!visited[x])
                    {
                        q.push(x);
                    }
                }
            }
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,5);
    g.display();
    g.BFS(4);
}
