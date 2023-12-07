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


bool isCycleUtil(vector<int> adj[], int v, vector<bool> &visited, int parent)
{
    visited[v] = true;

    for (auto i : adj[v])
    {
        if (!visited[i])
        {
            if (isCycleUtil(adj, i, visited, v))
                return true;
        }
        else if (i != parent)
        {
            // If the adjacent node is visited and not the parent of the current node,
            // then a cycle exists.
            return true;
        }
    }

    return false;
}

bool isCycle(vector<int> adj[], int n)
{
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (isCycleUtil(adj, i, visited, -1))
                return true;
        }
    }

    return false;
}

int main()
{
    int n, e;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> e;

    vector<int> adjList[n + 1];

    createList(adjList, e);
    display(adjList, n);

    if (isCycle(adjList, n))
    {
        cout << "Cycle exists in the graph." << endl;
    }
    else
    {
        cout << "No cycle in the graph." << endl;
    }
    return 0;
}
