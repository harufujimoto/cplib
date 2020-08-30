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


# :x: task/AOJ/GRL_1_B.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#26ab1ea50519442a89bb60aadb3416a2">task/AOJ</a>
* <a href="{{ site.github.repository_url }}/blob/master/task/AOJ/GRL_1_B.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 11:31:14+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=ja">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=ja</a>


## Depends on

* :x: <a href="../../../library/graph/bellman_ford.cpp.html">graph/bellman_ford.cpp</a>
* :question: <a href="../../../library/graph/template.cpp.html">graph/template.cpp</a>
* :question: <a href="../../../library/template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=ja"
#include "../../template.cpp"
#include "../../graph/bellman_ford.cpp"

int main(){
  lyn();
  int n,m,r;cin >> n >> m >> r;
  Graph<ll> G(n);
  REP(i,m){
    int s,t;cin >> s >> t;
    ll d;cin >> d;
    G.add_edge(s,t,d);
  }
  BellmanFord<ll> BF(G);
  BF.solve(r);
  if(BF.negative){
    cout << "NEGATIVE CYCLE" << '\n';
  }else{
    REP(i,n) cout << (BF.d[i] >= (1e10) ? "INF" : to_string(BF.d[i])) << '\n';
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "task/AOJ/GRL_1_B.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=ja"
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
#line 4 "task/AOJ/GRL_1_B.test.cpp"

int main(){
  lyn();
  int n,m,r;cin >> n >> m >> r;
  Graph<ll> G(n);
  REP(i,m){
    int s,t;cin >> s >> t;
    ll d;cin >> d;
    G.add_edge(s,t,d);
  }
  BellmanFord<ll> BF(G);
  BF.solve(r);
  if(BF.negative){
    cout << "NEGATIVE CYCLE" << '\n';
  }else{
    REP(i,n) cout << (BF.d[i] >= (1e10) ? "INF" : to_string(BF.d[i])) << '\n';
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

