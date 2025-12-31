#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

class Graph
{
public:
  unordered_map<int, list<pair<int, int>>> adj;

  void add(int u, int v, int weight, bool direction)
  {
    // if the direction 0 it means it is directed
    // if the direction is 1 it means it is undirected.
    adj[u].push_back({v, weight});
    if (direction == 0)
    {
      adj[v].push_back({u, weight});
    }
  }
  void print()
  {
    for (auto it : adj)
    {
      cout << it.first << " -> ";
      for (auto neighbour : it.second)
      {
        cout << "(" << neighbour.first << "," << neighbour.second << ")";
      }
      cout << endl;
    }
  }
};

int main()
{
  Graph g;
  cout << "\n\nDirected Graph Example:\n";
  g.add(0, 1, 4, 0);
  g.add(1, 2, 6, 0);
  g.add(0, 2, 8, 0);
  g.print();
  cout << "\n\nUnDirected Graph Example:\n";
  g.add(0, 1, 8, 1);
  g.add(1, 2, 7, 1);
  g.add(0, 2, 5, 1);
  g.print();
  return 0;
}