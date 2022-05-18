#include <bits/stdc++.h>
using namespace std;
class Graph
{
    vector<int> *adj;
    int v;
    int edges;

public:
    Graph()
    {
        int vertices;
        cout << "Please enter the number of vertices do you want in your graph\n";
        cin >> vertices;
        this->v = vertices;
        adj = new vector<int>[v];
    }
    void add_edge();
    void show_graph();
    void bfs(int s);
    void dfs_rec(bool visited[], int s);
    void dfs(int s);
    bool dfs_cyc();
    bool dfs_cyc_rec(bool visited[], int s, int parent);
    void count_dfs_rec(bool visited[], int s);
    void count_dfs();
};
void Graph::add_edge()
{
    cout << "Enter the number of edges you want in your graph\n";
    cin >> edges;
    cout << "Enter the u,v for undirected graph\n";
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void Graph::show_graph()
{
    cout << "The graph is :-\n";
    for (int i = 0; i < v; i++)
    {
        cout << i << "-> ";
        for (auto j : adj[i])
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}
void Graph::bfs(int s)
{
    cout << "The bfs transversal of graph is\n";
    bool visited[v] = {false};
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (auto i : adj[u])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
void Graph::dfs_rec(bool visited[], int s)
{
    visited[s] = true;
    cout << s << " ";
    for (auto i : adj[s])
    {
        if (!visited[i])
        {
            dfs_rec(visited, i);
        }
    }
}

void Graph::dfs(int s)
{
    cout << "The dfs transversal of graph is\n";
    bool visited[v] = {false};
    dfs_rec(visited, s);
}
void Graph::count_dfs_rec(bool visited[], int s)
{
    visited[s] = true;
    for (auto u : adj[s])
    {
        if (!visited[u])
        {
            count_dfs_rec(visited, u);
        }
    }
}

void Graph::count_dfs()
{
    bool visited[v] = {false};
    int count = 0;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            count_dfs_rec(visited, i);
            count++;
        }
    }
    if (count > 1)
    {
        cout << "The graph is disconnected\n";
        cout << "The garph has " << count << " component\n";
    }
    else
    {
        cout << "The graph is connected\n";
    }
}

int main()
{
    bool flag = true;
    Graph g;
    while (flag)
    {
        cout << "---------MENU---------\n";
        cout << "1.Add edges in graph\n";
        cout << "2.Display graph\n";
        cout << "3.Dfs Transversal\n";
        cout << "4.Bfs Transversal\n";
        cout << "5.Cheking connected component in graph\n";
        cout << "6.Exit\n";
        cout << "Enter the correct choice number\n";
        int ch;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            g.add_edge();
            break;
        }
        case 2:
        {
            g.show_graph();
            break;
        }
        case 3:
        {
            int k;
            cout << "Enter the starting vertice\n";
            cin >> k;
            g.dfs(k);
            cout << "\n";
            break;
        }
        case 4:
        {
            int k;
            cout << "Enter the starting vertice\n";
            cin >> k;
            g.bfs(k);
            cout << "\n";
            break;
        }
        case 5:
        {
            g.count_dfs();
            break;
        }
        case 6:
        {
            flag = false;
            break;
        }
        default:
        {
            cout << "Wrong choice enetered \n";
            break;
        }
        }
    }
    return 0;
}
