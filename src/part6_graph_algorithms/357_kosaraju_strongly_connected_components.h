#ifndef CLRS_SRC_PART6_GRAPH_ALGORITHMS_357_KOSARAJU_STRONGLY_CONNECTED_COMPONENTS_H_
#define CLRS_SRC_PART6_GRAPH_ALGORITHMS_357_KOSARAJU_STRONGLY_CONNECTED_COMPONENTS_H_

#include "clrs.h"
#include "part6_graph_algorithms/digraph.h"
#include "part6_graph_algorithms/vertex.h"

class Solution {
 public:
  Solution() : count_(0), stack_(std::stack<Vertex*>()), result_digraph_(nullptr) {}

  std::vector<std::list<Vertex*>> components() { return components_; }

  void StronglyConnectedComponents(Digraph* digraph) {
    for (Vertex* v : digraph->vertices) {
      v->visited = false;
    }
    for (Vertex* v : digraph->vertices) {
      if (!v->visited) {
        DFS(digraph, v, false);
      }
    }
    Digraph* t_digraph = digraph->Transpose();
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

  void DFS(Digraph* digraph, Vertex* u, bool is_transpose) {
    u->visited = true;
    for (Edge* e : digraph->adj[u->id]) {
      Vertex* v = digraph->vertices[e->Other(u->id)];
      if (!v->visited) {
        DFS(digraph, v, is_transpose);
      }
    }
    if (is_transpose) {
      u->component_id = count_;
    } else {
      stack_.push(u);
    }
  }
};

#endif  // CLRS_SRC_PART6_GRAPH_ALGORITHMS_357_KOSARAJU_STRONGLY_CONNECTED_COMPONENTS_H_
