template<class T> struct Edge{
  int from,to,id; T cost;
  Edge(int from,int to,T cost):from(from),to(to),cost(cost){}
  Edge(int from,int to,int id,T cost):from(from),to(to),id(id),cost(cost){}
  Edge(){}
};
template<class T> struct Graph{
  int n;
  vector<vector<Edge<T>>> g;
  Graph(int n):n(n){
    g.resize(n);
  }
  void add_edge(int from,int to){
    g[from].emplace_back(from,to,1);
  }
  void add_edge(int from,int to,T cost){
    g[from].emplace_back(from,to,cost);
  }
  vector<Edge<T>>& operator[](int i){ return g[i]; }
};
