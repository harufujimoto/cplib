#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B&lang=jp"
#include "../../template.cpp"
#include "../../graph/topologicalsort.cpp"

int main(){
  int n,m;cin >> n >> m;
  Graph<int> G(n);
  REP(i,m){
    int a,b;cin >> a >> b;
    G.add_edge(a,b);
  }
  TopologicalSorting<int> TS(G);
  auto ans = TS.topologicalSort();
  REP(i,n)cout << ans[i] << '\n';
}

