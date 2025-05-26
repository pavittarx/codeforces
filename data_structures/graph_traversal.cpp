#include <iostream>
#include <list>  // For adjacency list
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Graph {
 public:
  int V;           // Number of vertices
  list<int> *adj;  // Pointer to an array containing adjacency lists

  Graph(int V);

  void addEdge(int v, int w);
  void DFS(int startVertex);
  void BFS(int startVertex);
};

Graph::Graph(int V) {
  this->V = V;
  // dynamically allocate an array of lists
  // Each list represent neighbors of vertex i
  adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) { adj[v].push_back(w); }

void Graph::DFS(int startVertex) {
  vector<bool> visited(V, false);
  stack<int> st;

  st.push(startVertex);

  while (!st.empty()) {
    int i = st.top();
    st.pop();

    cout << "[DFS]: Visiting: " << i << endl;

    visited[i] = true;
    auto itr = adj[i];
    for (auto vertex : itr) {
      if (!visited[vertex]) {
        st.push(vertex);
      }
    }
  }
}

// TODO: to be implemented
void Graph::BFS(int startVertex) {
  vector<int> visited(V, false);
  queue<int> q;

  q.push(startVertex);

  while (!q.empty()) {
    int front = q.front();
    q.pop();
    visited[front] = true;
    auto itr = adj[front];

    cout<<"Visited: "<<front<<endl;
    
    for(auto vertex: itr){
      if(!visited[vertex]){
        q.push(vertex);
      }
      
    }

  }
}

int main() {
  // Create a graph with 6 vertices
  Graph g(6);

  // Add edges to the graph.  The graph is directed.
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(2, 4);
  g.addEdge(3, 5);
  g.addEdge(4, 5);
  g.addEdge(5, 0);  // added an edge to create a cycle.

  // Perform DFS starting fṇrom vertex 0
  g.BFS(0);

  // Perform BFS starting from vertex 0
  // g.BFS(0);

  return 0;
}
