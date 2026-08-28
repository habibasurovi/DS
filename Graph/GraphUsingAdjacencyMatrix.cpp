#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int vertices;
    int adj[100][100];
public:
    Graph(int v)
    {
        vertices = v;
    }
    void addEdge(int u, int v)
    {
        adj[u][v]=1;
        adj[v][u]=1;
    }
    void display()
    {
        cout<< "   ";
        for(int i = 0; i<vertices; i++)
        {
            cout << i << " ";
        }
        cout<<endl<<endl;
        for(int i = 0; i<vertices; i++)
        {
            cout << i << "  ";
            for(int j = 0; j<vertices; j++)
            {
                cout<< adj[i][j] << " ";
            }
            cout<< endl;
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.display();
}
