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
  bool isCyclicBFS(int src, unordered_map<int, bool> &visited)
  {
    queue<int> q;
    unordered_map<int, int> parent;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while (!q.empty())
    {
      int frontNode = q.front();
      q.pop();
      for (auto nbr : adj[frontNode])
      {
        int neighbor = nbr.first;
        if (!visited[neighbor])
        {
          visited[neighbor] = true;
          parent[neighbor] = frontNode;
          q.push(neighbor);
        }
        else
        {
          if (neighbor != parent[frontNode])
          {
            return true;
          }
        }
      }
    }
    return false;
  }

  bool isCyclicDFS(int src, int parent, unordered_map<int, bool> &visited)
  {
    visited[src] = true;
    for (auto nbr : adj)
    {
      if (!visited[nbr.first])
      {
        if (isCyclicDFS(nbr.first, src, visited))
        {
          return true;
        }
      }
      else if (nbr.first != parent)
      {
        return true;
      }
    }
    return false;
  }
  bool isCycleDFSDirectGraph(int src , unordered_map<int,bool>&visited,unordered_map<int , bool>&bfsVisited){
      visited[src] = true;
      bfsVisited[src] = true;
      for(auto nbr:adj[src]){
          if(!visited[nbr.first]){
              if(isCycleDFSDirectGraph(nbr.first , visited , bfsVisited)){
                  return true;
              }
          }
          if(visited[nbr.first] == true &&bfsVisited[nbr.first] == true ){
              return true;
          }
      }
      bfsVisited[src] = false;
      return false;
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

  // cout <<"Printing BFS ... "<<endl;
  // unordered_map<int, bool> visited;
  // for(int i = 0 ; i< 4 ;i++){
  //     if(!visited[i]){
  //         g.bfs(i ,visited );
  //     }
  // }
  // cout <<endl;
  // cout <<"Printing DFS .. "<<endl;
  // unordered_map<int, bool> visited1;
  // for(int i = 0 ; i< 4 ;i++){
  //     if(!visited1[i]){
  //         g.dfs(i ,visited1);
  //     }
  // }

  // int ans = false;
  // unordered_map<int, bool> visited;
  // for(int i = 0 ; i< 4 ;i++){
  //     if(!visited[i]){
  //         ans = g.isCyclicBFS(i ,visited);
  //         if(ans == true) break;
  //     }
  // }
  // if(ans == true){
  //     cout <<"Cycle present.";
  // }else{
  //     cout <<"Cycle is not present.";
  // }

//   int ans = false;
//   unordered_map<int, bool> visited;
//   for (auto &node : g.adj)
//   {
//     if (!visited[node.first])
//     {
//       ans = g.isCyclicDFS(node.first, -1, visited);
//       if (ans == true)
//         break;
//     }
//   }
//   if (ans == true)
//   {
//     cout << "Cycle present.";
//   }
//   else
//   {
//     cout << "Cycle is not present.";
//   }



// -------------------FOR DIRECTED GRAPH .....
Graph g;
  g.add(0, 2, 5, 1);
  g.add(2, 3, 3, 1);
  g.add(3, 4, 6, 1);
  g.add(4, 2, 9, 1);
  g.print();
  
  int ans = false;
  unordered_map<int, bool> visited;
  unordered_map<int, bool> bfsVisited;
  for (auto &node : g.adj)
  {
    if (!visited[node.first])
    {
      ans = g.isCycleDFSDirectGraph(node.first, visited ,bfsVisited);
      if (ans == true)
        break;
    }
  }
  if (ans == true)
  {
    cout << "Cycle present.";
  }
  else
  {
    cout << "Cycle is not present.";
  }
  return 0;
}