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
