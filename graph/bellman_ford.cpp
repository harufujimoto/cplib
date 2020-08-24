#include "template.cpp"

template<class T> BellmanFord{
  vector<T> d;
  Graph<T> G;
  BellmanFord(Graph<T>& G):G(G){
    d.assign(G.n,INF);
  }
  
};
