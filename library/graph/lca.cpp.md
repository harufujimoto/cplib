---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: graph/lca.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/lca.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-24 18:19:35+09:00




## Depends on

* :question: <a href="template.cpp.html">graph/template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/task/yosupo/lca.test.cpp.html">task/yosupo/lca.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/template.cpp"
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
#line 2 "graph/lca.cpp"
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


```
{% endraw %}

<a href="../../index.html">Back to top page</a>

