#include "template.cpp"
template<class T> struct BellmanFord{
#define INF 1LL << 55
  int V;
  vector<T> d;
  Graph<T> G;
  BellmanFord(Graph<T>& G):G(G){
    d.resize(G.n);
    V = G.n;
  }
  bool negative = false;
  void solve(int s){
    d.assign(G.n,INF);
    d[s] = 0;
    for(int i = 0;i <= V;i++){
      for(int j = 0;j < G.n;j++){
        for(int k = 0;k < G[j].size();k++){
          int u = j;
          int v = G[j][k].to;
          if(d[u] != INF && d[v] > d[u] + G[j][k].cost){
            if(i == V){
              negative = true;
              return;
            }
            d[v] = d[u] + G[j][k].cost;
          }
        }
      }
    }
  }
};
