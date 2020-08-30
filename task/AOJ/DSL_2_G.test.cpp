#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&lang=ja"
#include "../../template.cpp"
#include "../../data_structure/LazySegtree.cpp"

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,q;cin >> n >> q;
  LazySegtree<ll> DS(n);
  REP(_,q){
    int c;cin >> c;
    if(c == 0){
      int s,t;
      ll x;cin >> s >> t >> x;
      s--,t--;
      DS.add(s,t+1,x);
    }else{
      int s,t;cin >> s >> t;
      s--,t--;
      cout << DS.sum(s,t+1) << '\n';
    }
  }
}
