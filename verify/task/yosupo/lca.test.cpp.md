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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: task/yosupo/lca.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#a6a96afc30701de32dfcd524b6a3bd23">task/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/task/yosupo/lca.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-24 18:19:35+09:00


* see: <a href="https://judge.yosupo.jp/problem/lca">https://judge.yosupo.jp/problem/lca</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/graph/lca.cpp.html">graph/lca.cpp</a>
* :question: <a href="../../../library/graph/template.cpp.html">graph/template.cpp</a>
* :question: <a href="../../../library/template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../../template.cpp"
#include "../../graph/lca.cpp"
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "task/yosupo/lca.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#line 1 "template.cpp"

#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0;i < n;i++)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()

template<class T> bool chmax(T& a,T b){ if(a > b){ a = b; return true; }else return false; }
template<class T> bool chmin(T& a,T b){ if(a < b){ a = b; return true; }else return false; }
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

#line 4 "task/yosupo/lca.test.cpp"
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

