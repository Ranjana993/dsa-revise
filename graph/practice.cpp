#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Graph
{
public:
  unordered_map<int, list<pair<int, int>>> adj;

  void add(int u, int v, int weight, bool direction)
  {
    adj[u].push_back({v, weight});
    if (direction == 0)
    {
      adj[v].push_back({u, weight});
    }
  }
  void print()
  {
    for (auto node : adj)
    {
      cout << node.first << " -> ";
      for (auto nbr : node.second)
      {
        cout << "(" << nbr.first << "," << nbr.second << ")";
      }
      cout << endl;
    }
  }

  void bfs(int src, unordered_map<int, bool> &visited)
  {
    // create queue;
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty())
    {
      int frontNode = q.front();
      q.pop();
      cout << frontNode << " ";
      for (auto nbr : adj[frontNode])
      {
        if (!visited[nbr.first])
        {
          q.push(nbr.first);
          visited[nbr.first] = true;
        }
      }
    }
  }
  void dfs(int src, unordered_map<int, bool> &visited1)
  {
    cout << src << " ";
    visited1[src] = true;

    for (auto nbr : adj[src])
    {
      if (!visited1[nbr.first])
      {
        dfs(nbr.first, visited1);
      }
    }
  }
};

int main()
{
  Graph g;
  g.add(0, 1, 5, 0);
  g.add(0, 2, 3, 0);
  g.add(0, 3, 6, 0);
  g.add(1, 2, 9, 0);
  g.print();

  cout << "Printing BFS ... " << endl;
  unordered_map<int, bool> visited;
  for (int i = 0; i < 4; i++)
  {
    if (!visited[i])
    {
      g.bfs(i, visited);
    }
  }
  cout << endl;
  cout << "Printing DFS .. " << endl;
  unordered_map<int, bool> visited1;
  for (int i = 0; i < 4; i++)
  {
    if (!visited1[i])
    {
      g.dfs(i, visited1);
    }
  }

  return 0;
}