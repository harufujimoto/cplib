#line 1 "lca.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#line 1 "/home/parallels/kyopro/cplib/template.cpp"

#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0;i < n;i++)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()

template<class T> bool chmax(T& a,T b){ if(a > b){ a = b; return true; }else return false; }
template<class T> bool chmin(T& a,T b){ if(a < b){ a = b; return true; }else return false; }
#line 1 "/home/parallels/kyopro/cplib/graph/template.cpp"
template<class T> struct Edge{
  int from,to; T cost;
  Edge(int from,int to,T cost):from(from),to(to),cost(cost){}
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
#line 2 "/home/parallels/kyopro/cplib/graph/lca.cpp"
template<class T> struct LCA{
#define MAX_LOG_V 50
  Graph<T> G;
  int root;
  vector<vector<int>> parent;
  vector<int> depth;
  LCA(Graph<T>& G,int root):G(G){
    parent.assign(MAX_LOG_V,vector<int>(G.n+1,0));
    depth.assign(G.n+1,0);
    // initialize parent[0] and depth
    dfs(root,-1,0);
    // initialize parent
    for(int k = 0;k + 1 < MAX_LOG_V;k++){
      for(int v = 0;v < G.n;v++){
        //if(parent[k][v] < 0) parent[k+1][v] = -1;
        //else parent[k+1][v] = parent[k][parent[k][v]];
        if(parent.at(k).at(v) < 0) parent.at(k+1).at(v) = -1;
        else parent.at(k+1).at(v) = parent.at(k).at(parent.at(k).at(v));
      }
    }
  }
  void dfs(int v,int p,int d){
    parent[0][v] = p;
    depth[v] = d;
    for(int i = 0;i < G[v].size();i++){
      if(G[v][i].to != p) dfs(G[v][i].to , v , d + 1);
    }
  }
  // get lca(u,v)
  int lca(int u,int v){
    if(depth.at(u) > depth.at(v)) swap(u,v);
    //if(depth[u] > depth[v]) swap(u,v);
    for(int k = 0;k < MAX_LOG_V;k++){
      //if((depth[v] - depth[u]) >> k & 1){
      //  v = parent[k][v];
      //}
      if((depth.at(v) - depth.at(u)) >> k & 1){
        v = parent.at(k).at(v);
      }
    }
    if(u == v)return u;
    for(int k = MAX_LOG_V - 1;k >= 0;k--){
      //if(parent[k][u] != parent[k][v]){
      //  u = parent[k][u];
      //  v = parent[k][v];
      //}
      if(parent.at(k).at(u) != parent.at(k).at(v)){
        u = parent.at(k).at(u);
        v = parent.at(k).at(v);
      }
    }
    //return parent[0][u];
    return parent.at(0).at(u);
  }
};
#line 4 "lca.test.cpp"
int main(void){
  int n,q;cin >> n >> q;
  Graph<int> g(n);
  REP(i,n - 1){
    int p;cin >> p;
    g.add_edge(p,i+1);
  }
  LCA<int> sol(g,0);
  REP(_,q){
    int u,v;cin >> u >> v;
    cout << sol.lca(u,v) << '\n';
  }
}
