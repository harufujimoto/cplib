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
