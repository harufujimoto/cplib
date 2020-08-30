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


# :warning: graph/problems/count_connectives.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#e9972f8ef95f0cca0371213ec9c6bd5f">graph/problems</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/problems/count_connectives.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 11:19:34+09:00




## Depends on

* :question: <a href="../template.cpp.html">graph/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"
/*
 * VERIFIED : 29.August.2020
 */
template<class T> struct CountConnectives
{
  Graph<T> G;
  vector<bool> used;
  vector<int> root,SizeOfMyGroup,ConnectedID;
  CountConnectives(Graph<T>& G):G(G){

  }
  void dfs(int st,int x,int id){
    used[x] = true;
    root[x] = st;
    ConnectedID[x] = id;
    SizeOfMyGroup[st]++;
    for(auto _next : G[x]){
      if(!used[_next.to]){
        dfs(st,_next.to,id);
      }
    }
  }
  int solve(){
    used.assign(G.n,false);
    ConnectedID.assign(G.n,-1);
    root.assign(G.n,-1);
    SizeOfMyGroup.assign(G.n,0);
    int res = 0;
    for (int i = 0; i < G.n; i++) {
      if (!used[i]) {
        dfs(i,i,res);
        res++;
      }
    }
    for (int i = 0; i < G.n; i++) {
      SizeOfMyGroup[i] = SizeOfMyGroup[root[i]];
    }  
    return res;
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
#line 2 "graph/problems/count_connectives.cpp"
/*
 * VERIFIED : 29.August.2020
 */
template<class T> struct CountConnectives
{
  Graph<T> G;
  vector<bool> used;
  vector<int> root,SizeOfMyGroup,ConnectedID;
  CountConnectives(Graph<T>& G):G(G){

  }
  void dfs(int st,int x,int id){
    used[x] = true;
    root[x] = st;
    ConnectedID[x] = id;
    SizeOfMyGroup[st]++;
    for(auto _next : G[x]){
      if(!used[_next.to]){
        dfs(st,_next.to,id);
      }
    }
  }
  int solve(){
    used.assign(G.n,false);
    ConnectedID.assign(G.n,-1);
    root.assign(G.n,-1);
    SizeOfMyGroup.assign(G.n,0);
    int res = 0;
    for (int i = 0; i < G.n; i++) {
      if (!used[i]) {
        dfs(i,i,res);
        res++;
      }
    }
    for (int i = 0; i < G.n; i++) {
      SizeOfMyGroup[i] = SizeOfMyGroup[root[i]];
    }  
    return res;
  }
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

