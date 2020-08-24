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


# :warning: task/yosupo/out.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#a6a96afc30701de32dfcd524b6a3bd23">task/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/task/yosupo/out.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-24 19:09:50+09:00


* see: <a href="https://judge.yosupo.jp/problem/shortest_path">https://judge.yosupo.jp/problem/shortest_path</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#line 1 "shortest_path.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
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
#line 2 "/home/parallels/kyopro/cplib/graph/dijkstra.cpp"

template<class T> struct Dijkstra{
  #define INF (1LL << 55)
  using P = pair<T,int>;
  Graph<T> G;
  vector<T> d;
  vector<int> prev;
  Dijkstra(Graph<T>& G):G(G){}
  void solve(int s){
    d.assign(G.n,INF);
    prev.assign(G.n,-1);
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
          prev[e.to] = v;
          que.push(P(d[e.to] , e.to));
        }
      }
    }
  }
  bool reachable(int t){
    return d[t] != INF;
  }
  vector<int> get_path(int t){
    vector<int> path;
    for(;t != -1;t = prev[t]){ path.push_back(t); }
    reverse(path.begin(),path.end());
    return path;
  }
  T& operator[](int i){return d[i];}
};
#line 4 "shortest_path.test.cpp"

int main(){

  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,m,s,t;cin >> n >> m >> s >> t;
  Graph<long long> G(n);
  REP(i,m){
    int a,b;cin >> a >> b;
    long long c;cin >> c;
    G.add_edge(a,b,c);
  }
  Dijkstra<long long> sol(G);
  sol.solve(s);
  if(!sol.reachable(t)){
    cout << -1 << '\n';
  }else{
    vector<int> path = sol.get_path(t);
    cout << sol[t] << ' ' << path.size() - 1 << '\n';
    REP(i,path.size() - 1){
      cout << path[i] << ' ' << path[i+1] << '\n';
    }
  }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "task/yosupo/out.cpp"
#line 1 "shortest_path.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
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
#line 2 "/home/parallels/kyopro/cplib/graph/dijkstra.cpp"

template<class T> struct Dijkstra{
  #define INF (1LL << 55)
  using P = pair<T,int>;
  Graph<T> G;
  vector<T> d;
  vector<int> prev;
  Dijkstra(Graph<T>& G):G(G){}
  void solve(int s){
    d.assign(G.n,INF);
    prev.assign(G.n,-1);
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
          prev[e.to] = v;
          que.push(P(d[e.to] , e.to));
        }
      }
    }
  }
  bool reachable(int t){
    return d[t] != INF;
  }
  vector<int> get_path(int t){
    vector<int> path;
    for(;t != -1;t = prev[t]){ path.push_back(t); }
    reverse(path.begin(),path.end());
    return path;
  }
  T& operator[](int i){return d[i];}
};
#line 4 "shortest_path.test.cpp"

int main(){

  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,m,s,t;cin >> n >> m >> s >> t;
  Graph<long long> G(n);
  REP(i,m){
    int a,b;cin >> a >> b;
    long long c;cin >> c;
    G.add_edge(a,b,c);
  }
  Dijkstra<long long> sol(G);
  sol.solve(s);
  if(!sol.reachable(t)){
    cout << -1 << '\n';
  }else{
    vector<int> path = sol.get_path(t);
    cout << sol[t] << ' ' << path.size() - 1 << '\n';
    REP(i,path.size() - 1){
      cout << path[i] << ' ' << path[i+1] << '\n';
    }
  }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

