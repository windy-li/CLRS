#include "clrs.h"
#include "part6_graph_algorithms/digraph.h"
#include "part6_graph_algorithms/vertex.h"

class Solution {
 public:
  Solution() : count_(0), stack_(std::stack<Vertex*>()), result_digraph_(nullptr) {}

  std::vector<std::list<Vertex*>> components() { return components_; }

  void StronglyConnectedComponents(Digraph* digraph) {
    //    for (int i = 0; i < digraph->V; i++) {
    //      digraph->vertices[i]->visited = false;
    //    }
    for (Vertex* v : digraph->vertices) {
      v->visited = false;
    }
    //    for (int i = 0; i < digraph->V; i++) {
    //      Vertex* u = digraph->vertices[i];
    //      if (!u->visited) {
    //        DFS(digraph, u, false);
    //      }
    //    }
    for (Vertex* v : digraph->vertices) {
      if (!v->visited) {
        DFS(digraph, v, false);
      }
    }

    Digraph* t_digraph = digraph->Transpose();
    //    for (int i = 0; i < digraph->V; i++) {
    //      t_digraph->vertices[i]->visited = false;
    //    }
    for (Vertex* v : t_digraph->vertices) {
      v->visited = false;
    }
    while (!stack_.empty()) {
      Vertex* top = stack_.top();
      stack_.pop();
      Vertex* u = t_digraph->vertices[top->id];
      if (!u->visited) {
        DFS(t_digraph, u, true);
        count_++;
      }
    }

    components_ = std::vector<std::list<Vertex*>>(count_, std::list<Vertex*>());
    //    for (int i = 0; i < count_; i++) {
    //      components_[i] = std::list<Vertex*>();
    //    }

    //    for (int i = 0; i < digraph->V; i++) {
    //      Vertex* u = t_digraph->vertices[i];
    //      components_[u->component_id].push_back(u);
    //    }
    for (Vertex* v : t_digraph->vertices) {
      components_[v->component_id].push_back(v);
    }

    result_digraph_ = t_digraph;
  }

  bool Connected(int u_id, int v_id) {
    Vertex* u = result_digraph_->vertices[u_id];
    Vertex* v = result_digraph_->vertices[v_id];
    return u->component_id == v->component_id;
  }

 private:
  std::vector<std::list<Vertex*>> components_;
  int count_;
  std::stack<Vertex*> stack_;
  Digraph* result_digraph_;

  void DFS(Digraph* digraph, Vertex* u, bool is_t) {
    u->visited = true;
    for (Edge* e : digraph->adj[u->id]) {
      Vertex* v = digraph->vertices[e->Other(u->id)];
      if (!v->visited) {
        DFS(digraph, v, is_t);
      }
    }
    if (is_t) {
      u->component_id = count_;
    } else {
      stack_.push(u);
    }
  }
};

void Test() {
  std::vector<std::string> labels = {"a", "b", "c", "d", "e", "f", "g", "h"};
  Digraph digraph(8, labels);
  digraph.AddEdge(0, 1);
  digraph.AddEdge(1, 2);
  digraph.AddEdge(1, 4);
  digraph.AddEdge(2, 3);
  digraph.AddEdge(3, 2);
  digraph.AddEdge(3, 7);
  digraph.AddEdge(4, 0);
  digraph.AddEdge(4, 5);
  digraph.AddEdge(5, 6);
  digraph.AddEdge(6, 5);
  digraph.AddEdge(6, 7);
  digraph.AddEdge(7, 7);

  std::cout << Digraph::ToString(&digraph) << std::endl;

  Solution solution;
  solution.StronglyConnectedComponents(&digraph);

  std::vector<std::list<Vertex*>> components = solution.components();
  size_t count = components.size();
  std::cout << count << " components" << std::endl;

  for (std::list<Vertex*>& vertices : components) {
    for (Vertex* v : vertices) {
      std::cout << Vertex::ToString(v) + " ";
    }
    std::cout << std::endl;
  }

  std::cout << solution.Connected(0, 4) << std::endl;
  std::cout << solution.Connected(1, 7) << std::endl;
}

int main() { Test(); }

/*
a: b
b: c e
c: d
d: c h
e: a f
f: g
g: f h
h: h

4 components
a b e
f g
c d
h
1
0
 */
