#include "template.cpp"
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
        if(parent[k][v] < 0) parent[k+1][v] = -1;
        else parent[k+1][v] = parent[k][parent[k][v]];
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
    if(depth[u] > depth[v]) swap(u,v);
    for(int k = 0;k < MAX_LOG_V;k++){
      if((depth[v] - depth[u]) >> k & 1){
       v = parent[k][v];
      }
    }
    if(u == v)return u;
    for(int k = MAX_LOG_V - 1;k >= 0;k--){
      if(parent[k][u] != parent[k][v]){
       u = parent[k][u];
       v = parent[k][v];
      }
    }
    return parent[0][u];
  }
};

