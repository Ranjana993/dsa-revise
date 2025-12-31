#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
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
  void topoSort(int src, unordered_map<int, bool> &visited, stack<int> &st)
  {
    visited[src] = true;
    for (auto nbr : adj[src])
    {
      if (!visited[nbr.first])
      {
        topoSort(nbr.first, visited, st);
      }
    }
    st.push(src);
  }
};

int main()
{
  //   Graph g;
  //   g.add(0, 2, 5, 0);
  //   g.add(2, 3, 3, 0);
  //   g.add(3, 4, 6, 0);
  //   g.add(4, 6, 9, 0);
  //   g.print();

  // -------------------FOR DIRECTED GRAPH .....
  Graph h;
  h.add(0, 2, 5, 1);
  h.add(2, 3, 3, 1);
  h.add(3, 4, 6, 1);
  h.add(4, 8, 9, 1);
  h.print();
  unordered_map<int, bool> visited;
  stack<int> st;
  for (auto it : h.adj)
  {
    if (!visited[it.first])
    {
      h.topoSort(it.first, visited, st);
    }
  }
  while (!st.empty())
  {
    cout << st.top() << " ";
    st.pop();
  }

  return 0;
}