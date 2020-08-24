#include "template.cpp"

template<class T> struct Dijkstra{
  #define INF (1LL << 55)
  using P = pair<T,int>;
  Graph<T> G;
  vector<T> d;
  vector<int> prev;
  Dijkstra(Graph<T>& G):G(G){}
  void solve(int s){
    d.assign(G.n,INF);
    prev.assign(G.n,-1);
    d[s] = 0;
    priority_queue<P,vector<P>,greater<P> > que;
    que.push(P(0,s));
    while(que.size()){
      P p = que.top();que.pop();
      int v = p.second;
      if(d[v] < p.first) continue;
      for(int i = 0;i < G[v].size();i++){
        Edge<T>& e = G[v][i];
        if(d[e.to] > d[v] + e.cost){
          d[e.to] = d[v] + e.cost;
          prev[e.to] = v;
          que.push(P(d[e.to] , e.to));
        }
      }
    }
  }
  bool reachable(int t){
    return d[t] != INF;
  }
  vector<int> get_path(int t){
    vector<int> path;
    for(;t != -1;t = prev[t]){ path.push_back(t); }
    reverse(path.begin(),path.end());
    return path;
  }
  T& operator[](int i){return d[i];}
};
