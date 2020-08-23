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


# :warning: task/AOJ_DSL_2_A.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#478f3a4c51824ad23cb50c1c60670c0f">task</a>
* <a href="{{ site.github.repository_url }}/blob/master/task/AOJ_DSL_2_A.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-23 14:06:29+09:00




## Depends on

* :warning: <a href="../data_structure/RangeMinQuery.cpp.html">data_structure/RangeMinQuery.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "task/AOJ_DSL_2_A.cpp"
#define PROBELM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(int i = 0;i < n;i++)

#line 1 "data_structure/RangeMinQuery.cpp"
template<class T> class RangeMinQuery {
private:
	vector<T> dat;
	int n;
	T INF;
public:
	RangeMinQuery(int n_) {
		INF = numeric_limits<T>::max();
		n = 1;
		while (n < n_) n *= 2;
		dat.assign(2*n-1,INF);
	}
	void update(int k, T a) {
		k += n - 1;
		dat[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
		}
	}
	T query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l)return INF;
		if (a <= l && r <= b)return dat[k];
		else {
			T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return min(vl, vr);
		}
	}
	T query(int a, int b) {
		return query(a, b, 0, 0, n);
	}
};
#line 9 "task/AOJ_DSL_2_A.cpp"

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


```
{% endraw %}

<a href="../../index.html">Back to top page</a>

