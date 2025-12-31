#include <iostream>
#include<vector>
using namespace std;

int main() {
  int nodes ;
  cout <<"Enter the number of nodes : " ;
  cin >>nodes;
  int edges;
  cout <<"Enter the total number of edges : " ;
  cin >>edges;
  vector<vector<int> >adj(nodes , vector<int>(nodes , 0));



  for(int i = 0 ; i < edges ; i++){
    int u , v;
    cin >> u >> v ;
    adj[u][v] = 1;
  }

  cout << "\nAdjacency Matrix:\n";
    cout << "   ";
    for(int j = 0; j < nodes; j++) {
        cout << j << " ";
    }
    cout << endl;
    
    for(int i = 0; i < nodes; i++) {
        cout << i << ": ";
        for(int j = 0; j < nodes; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
  return 0;
}