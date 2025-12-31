#include <iostream>
#include<unordered_map>
#include<vector>
#include<limits.h>
#include<list>
#include<stack>
using namespace std;


class Graph{
    public:
    unordered_map<int , list<pair<int , int >>> adj;
    
    void add(int u , int v , int weight , bool direction){
        adj[u].push_back({v,weight});
        if(direction == 1){
            adj[v].push_back({u,weight});
        }
    }
    
    void print(){
        for(auto node:adj){
            cout <<node.first <<" => ";
            for(auto nbr : node.second){
                cout <<"(" <<nbr.first<<", " <<nbr.second<<")";
            }
            cout <<endl;
        }
    }
    
    void topoSort(int src , unordered_map<int,bool>&visited , stack<int>&ans){
        visited[src] = true;
        for(auto nbr:adj[src]){
            if(!visited[nbr.first]){
                topoSort(nbr.first , visited , ans);
            }
        }
        ans.push(src);
    }
    
    void shortestPathDFS(int dest, stack<int>& st, int n) {
        vector<int> dist(n, INT_MAX);
        int src = 0;  // Assuming source is always 0
        
        dist[src] = 0;
        
        // You need to find src in stack first
        stack<int> temp;
        while (!st.empty()) {
            temp.push(st.top());
            st.pop();
        }
    
        // Now temp has reverse order, but let's process properly
        // Reset the stack
        while (!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }
        
        // Process in topological order
        while (!st.empty()) {
            int currNode = st.top();
            st.pop();
            
            if (dist[currNode] != INT_MAX) {
                for (auto nbr : adj[currNode]) {
                    if (dist[currNode] + nbr.second < dist[nbr.first]) {
                        dist[nbr.first] = dist[currNode] + nbr.second;
                    }
                }
            }
        }
    
        // Print distance to destination
        if (dist[dest] == INT_MAX)
            cout << "No path from source to destination " << dest << endl;
        else
            cout << "Shortest distance to " << dest << " is: " << dist[dest] << endl;
        
        // Or print all distances
        cout << "\nAll distances:\n";
        for (int i = 0; i < n; i++) {
            cout << i << " -> " << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << endl;
        }
    }
};



int main() {
    Graph g;
    g.add(0,1 , 5, 0);
    g.add(0,2 , 3, 0);
    g.add(2,1 , 2, 0);
    g.add(1, 3, 3, 0);
    g.add(2,3 , 5, 0);
    g.print();
    cout <<endl<<endl;
     unordered_map<int,bool>visited;
     stack<int>ans;
     g.topoSort(0,visited,ans);
     
    //  while(!ans.empty()){
    //      cout<<ans.top()<<" ";
    //     ans.pop();
    //  }
     g.shortestPathDFS(3 ,ans , 5 );

    return 0;
}