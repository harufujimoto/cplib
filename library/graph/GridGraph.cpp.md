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


# :warning: graph/GridGraph.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/GridGraph.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 11:19:34+09:00




## Depends on

* :heavy_check_mark: <a href="template.cpp.html">graph/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "template.cpp"
template<class T>
struct GridGraph{
  int H,W;
  Graph<T> G;
  GridGraph(int H,int W):H(H),W(W){
    G = Graph<T>((H+2)*(W+2));
  }
  int id(int x,int y){
    return x + y * W;
  }
  bool inside(int x,int y){
    return x >= 0 && x < H && y >= 0 && y < W;
  }
  void connect(int x0,int y0,int x1,int y1,T dist = 1){
    int from = id(x0,y0);
    int to = id(x1,y1);
    G.add_edge(from,to,dist);
    G.add_edge(to,from,dist);
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
#line 2 "graph/GridGraph.cpp"
template<class T>
struct GridGraph{
  int H,W;
  Graph<T> G;
  GridGraph(int H,int W):H(H),W(W){
    G = Graph<T>((H+2)*(W+2));
  }
  int id(int x,int y){
    return x + y * W;
  }
  bool inside(int x,int y){
    return x >= 0 && x < H && y >= 0 && y < W;
  }
  void connect(int x0,int y0,int x1,int y1,T dist = 1){
    int from = id(x0,y0);
    int to = id(x1,y1);
    G.add_edge(from,to,dist);
    G.add_edge(to,from,dist);
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

