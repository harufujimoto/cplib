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


# :x: graph/dijkstra.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-23 17:07:18+09:00




## Depends on

* :x: <a href="template.cpp.html">graph/template.cpp</a>


## Required by

* :warning: <a href="../GRL_1_A.cpp.html">GRL_1_A.cpp</a>


## Verified with

* :x: <a href="../../verify/task/AOJ/GRL_1_A.test.cpp.html">task/AOJ/GRL_1_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include<bits/stdc++.h>
using namespace std;

#include "template.cpp"

template<class T> struct Dijkstra{
  #define INF (1LL << 55)
  using P = pair<T,int>;
  Graph<T> G;
  vector<T> d;
  Dijkstra(Graph<T>& G):G(G){}
  void solve(int s){
    d.assign(G.n,INF);
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
          que.push(P(d[e.to] , e.to));
        }
      }
    }
  }
  T& operator[](int i){return d[i];}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/dijkstra.cpp"
#include<bits/stdc++.h>
using namespace std;

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
#line 5 "graph/dijkstra.cpp"

template<class T> struct Dijkstra{
  #define INF (1LL << 55)
  using P = pair<T,int>;
  Graph<T> G;
  vector<T> d;
  Dijkstra(Graph<T>& G):G(G){}
  void solve(int s){
    d.assign(G.n,INF);
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
          que.push(P(d[e.to] , e.to));
        }
      }
    }
  }
  T& operator[](int i){return d[i];}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

