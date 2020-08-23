#define PROBELM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(int i = 0;i < n;i++)

#include "../data_structure/RangeMinQuery.cpp"

int main() {

	int n, q; cin >> n >> q;
	RangeMinQuery<ll> S(n);

	ll inf = (1LL << 31) - 1;
	REP(i, n) S.update(i, inf);

	REP(_, q) {
		ll c, x, y; cin >> c >> x >> y;
		if (c == 0) {
			S.update(x, y);
		} else {
			cout << S.query(x, y + 1) << '\n';
		}
	}
}

