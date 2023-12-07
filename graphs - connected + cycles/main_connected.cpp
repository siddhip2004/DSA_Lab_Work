#include <iostream>
#include <vector>

using namespace std;

void createList(vector<int> adjList[], int e)
{
    cout << "Enter the edges between the nodes:" << endl;
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[v].push_back(u);
        adjList[u].push_back(v);
    }
}

void display(vector<int> adj[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> ";

        for (auto x : adj[i])
        {
            cout << x << " ";
        }

        cout << endl;
    }
}

void dfs_visit(vector<int> adj[], int a, vector<bool> &visited)
{
    visited[a] = true;

    for (auto x : adj[a])
    {
        if (!visited[x])
        {
            dfs_visit(adj, x, visited);
        }
    }
}

void dfs_check(vector<int> adj[], int n)
{
    vector<bool> visited(n + 1, false);
    int counter = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            counter++;
            dfs_visit(adj, i, visited);
        }
    }

    if (counter == 1)
    {
        cout << "It is a connected graph" << endl;
    }
    else
    {
        cout << "Not a connected graph" << endl;
    }
}

int main()
{
    int n, e;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> e;

    vector<int> adjList[n + 1];

    createList(adjList, e);
    display(adjList, n);

    dfs_check(adjList, n);
    
    return 0;
}
