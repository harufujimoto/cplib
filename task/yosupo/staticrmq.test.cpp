#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../../template.cpp"
#include "../../data_structure/RangeMinQuery.cpp"

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,q;cin >> n >> q;
    RangeMinQuery<int> RMQ(n);
    REP(i,n){
        int x;cin >> x;
        RMQ.update(i,x);
    }
    REP(_,q){
        int l,r;cin >> l >> r;
        cout << RMQ.query(l,r) << '\n';
    }
}
