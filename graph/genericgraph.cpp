#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

template <typename T>
class Graph
{
public:
  unordered_map<T, list<T>> adj; // Use T instead of int

  void add(T u, T v, bool direction)
  {
    // Note: Your logic is BACKWARDS from your comment!
    // direction = 0 → you add reverse edge (makes it undirected)
    // direction = 1 → you DON'T add reverse edge (makes it directed)

    adj[u].push_back(v);
    if (direction == 0)
    { // This makes it UNDIRECTED with your logic
      adj[v].push_back(u);
    }
  }

  void print()
  {
    for (auto it : adj)
    {
      cout << it.first << " -> ";
      for (auto neighbour : it.second)
      {
        cout << neighbour << ", ";
      }
      cout << endl;
    }
  }
};

int main()
{
  // For integer graph
  Graph<int> intGraph;
  cout << "Integer Graph (using your logic: direction=0 means undirected):\n";
  intGraph.add(0, 1, 0); // undirected
  intGraph.add(1, 2, 0); // undirected
  intGraph.add(0, 2, 0); // undirected
  intGraph.print();

  // For character graph (what you wanted)
  cout << "\n\nCharacter Graph:\n";
  Graph<char> charGraph;
  charGraph.add('A', 'B', 0); // undirected
  charGraph.add('B', 'C', 0); // undirected
  charGraph.add('C', 'A', 0); // undirected
  charGraph.print();

  // For string graph
  cout << "\n\nString Graph:\n";
  Graph<string> stringGraph;
  stringGraph.add("Delhi", "Mumbai", 0);   // undirected
  stringGraph.add("Mumbai", "Chennai", 0); // undirected
  stringGraph.add("Chennai", "Delhi", 0);  // undirected
  stringGraph.print();

  // Directed example (with your logic: direction=1 means directed)
  cout << "\n\nDirected Character Graph:\n";
  Graph<char> directedGraph;
  directedGraph.add('X', 'Y', 1); // directed X→Y
  directedGraph.add('Y', 'Z', 1); // directed Y→Z
  directedGraph.add('Z', 'X', 1); // directed Z→X
  directedGraph.print();

  return 0;
}