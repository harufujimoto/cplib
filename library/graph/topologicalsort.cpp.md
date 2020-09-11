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


# :heavy_check_mark: graph/topologicalsort.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/topologicalsort.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 16:27:44+09:00




## Depends on

* :question: <a href="template.cpp.html">graph/template.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/task/AOJ/GRL_4_B.test.cpp.html">task/AOJ/GRL_4_B.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "template.cpp"
template<class T> struct TopologicalSorting{
    Graph<T> G;
    TopologicalSorting(Graph<T>& G):G(G){}
    void topologicalSortUtil(int v,vector<bool>& visited,stack<int>& Stack);
    vector<int> topologicalSort();
};
template<class T>
void TopologicalSorting<T>::topologicalSortUtil(int v, vector<bool> &visited, stack<int> &Stack) {
    visited[v] = true;
    for(int i = 0;i < G[v].size();i++){
        int _to = G[v][i].to;
        if(!visited[_to]) topologicalSortUtil(_to,visited,Stack);
    }
    Stack.push(v);
}
template<class T>
vector<int> TopologicalSorting<T>::topologicalSort() {
    stack<int> Stack;
    vector<int> res;
    vector<bool> visited(G.n,false);
    for(int i = 0;i < G.n;i++){
        if(!visited[i]) topologicalSortUtil(i,visited,Stack);
    }
    while(Stack.size()){
        res.push_back(Stack.top());
        Stack.pop();
    }
    return res;
}


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/template.cpp"
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
#line 2 "graph/topologicalsort.cpp"
template<class T> struct TopologicalSorting{
    Graph<T> G;
    TopologicalSorting(Graph<T>& G):G(G){}
    void topologicalSortUtil(int v,vector<bool>& visited,stack<int>& Stack);
    vector<int> topologicalSort();
};
template<class T>
void TopologicalSorting<T>::topologicalSortUtil(int v, vector<bool> &visited, stack<int> &Stack) {
    visited[v] = true;
    for(int i = 0;i < G[v].size();i++){
        int _to = G[v][i].to;
        if(!visited[_to]) topologicalSortUtil(_to,visited,Stack);
    }
    Stack.push(v);
}
template<class T>
vector<int> TopologicalSorting<T>::topologicalSort() {
    stack<int> Stack;
    vector<int> res;
    vector<bool> visited(G.n,false);
    for(int i = 0;i < G.n;i++){
        if(!visited[i]) topologicalSortUtil(i,visited,Stack);
    }
    while(Stack.size()){
        res.push_back(Stack.top());
        Stack.pop();
    }
    return res;
}


```
{% endraw %}

<a href="../../index.html">Back to top page</a>

