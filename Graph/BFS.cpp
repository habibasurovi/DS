#include<bits/stdc++.h>
using namespace std;

int vertices;
int graph[100][100];
vector<bool> visited(100,false);

void addEdge(int v, int w)
{
    graph[w][v]=1;
    graph[v][w]=1;
}

void display()
{
    for(int i = 0; i<vertices; i++)
    {
        for(int j= 0; j<vertices; j++)
        {
            cout<< graph[i][j]<< " ";
        }
        cout<< endl;
    }
}
void BFS(int v)
{
    queue<int> q;
    q.push(v);
    while(q.size()>0)
    {
        int v = q.front();
        q.pop();
        if(!visited[v])
        {
            cout << v << " ";
            visited[v] = true;

            for(int w = 0; w<vertices; w++)
            {
                if(graph[v][w] == 1 && !visited[w])
                {
                    q.push(w);
                }
            }
        }
    }

}
int main()
{
    vertices = 6;
    addEdge(0,1);
    addEdge(1,2);
    addEdge(1,3);
    addEdge(2,4);
    addEdge(3,5);
    display();
    BFS(4);
}
