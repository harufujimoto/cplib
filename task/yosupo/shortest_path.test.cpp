#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "../../template.cpp"
#include "../../graph/dijkstra.cpp"

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
