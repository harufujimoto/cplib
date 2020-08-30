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


# :warning: graph/bellman_ford.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/bellman_ford.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 11:19:34+09:00




## Depends on

* :heavy_check_mark: <a href="template.cpp.html">graph/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
#line 2 "graph/bellman_ford.cpp"
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

