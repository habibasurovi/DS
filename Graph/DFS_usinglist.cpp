#include<bits/stdc++.h>
using namespace std;
class Graph
{

public:
    int vertices;
    vector<list<int>> adj;
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
    void DFS(int v)
    {
        stack<int> s;
        vector<bool> visited(vertices, false);
        s.push(v);
        while(s.size()>0)
        {
            v = s.top();
            s.pop();
            if(!visited[v])
            {
                cout<< v << " ";
                visited[v] = true;

                for(int x : adj[v])
                {
                    if(!visited[x])
                    {
                        s.push(x);
                    }
                }
            }

        }
    }
};

void DFS(Graph &g, int v)
{
    stack<int> s;
    vector<bool> visited(g.vertices, false);
    s.push(v);
    while(s.size()>0)
    {
        v = s.top();
        s.pop();
        if(!visited[v])
        {
            cout<< v << " ";
            visited[v] = true;

            for(int x : g.adj[v])
            {
                if(!visited[x])
                {
                    s.push(x);
                }
            }
        }

    }
}

int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,4);
    DFS(g, 0);
    cout<<endl;
    g.DFS(0);
}
