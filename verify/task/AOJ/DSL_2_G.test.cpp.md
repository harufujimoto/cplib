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


# :heavy_check_mark: task/AOJ/DSL_2_G.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#26ab1ea50519442a89bb60aadb3416a2">task/AOJ</a>
* <a href="{{ site.github.repository_url }}/blob/master/task/AOJ/DSL_2_G.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 00:44:09+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&lang=ja">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&lang=ja</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data_structure/LazySegtree.cpp.html">data_structure/LazySegtree.cpp</a>
* :heavy_check_mark: <a href="../../../library/template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "task/AOJ/DSL_2_G.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G&lang=ja"
#line 1 "template.cpp"

#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0;i < n;i++)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()

using ll = long long;

template<class T> bool chmax(T& a,T b){ if(a > b){ a = b; return true; }else return false; }
template<class T> bool chmin(T& a,T b){ if(a < b){ a = b; return true; }else return false; }
#line 1 "data_structure/LazySegtree.cpp"
template<class T> struct LazySegtree {
#define DAT_SIZE 2000000
#define MIN 0
	int n;
	vector<T> data, datb;
	LazySegtree(int _n) {
		n = 1; while (n <= _n) n *= 2;
		data.assign(DAT_SIZE, 0);
		datb.assign(DAT_SIZE, 0);
	}
	// add x to [a,b)
	void add(int a, int b, int x, int k, int l, int r) {
		if (a <= l && r <= b) { data[k] += x; }
		else if (l < b && a < r) {
			datb[k] += (min(b, r) - max(a, l)) * x;
			add(a, b, x, k * 2 + 1, l, (l + r) / 2);
			add(a, b, x, k * 2 + 2, (l + r) / 2, r);
		}
	}
	void add(int a, int b, int x) {
		add(a, b, x, 0, 0, n);
	}
	// [a,b)
	T sum(int a, int b, int k, int l, int r) {
		if (b <= l || r <= a) {
			return MIN;
		} else if (a <= l && r <= b) {
			return data[k] * (r - l) + datb[k];
		} else {
			T res = (min(b, r) - max(a, l)) * data[k];
			res += sum(a, b, k * 2 + 1, l, (l + r) / 2);
			res += sum(a, b, k * 2 + 2, (l + r) / 2, r);
			return res;
		}
	}
	T sum(int a, int b) {
		return sum(a, b, 0, 0, n);
	}
};
#line 4 "task/AOJ/DSL_2_G.test.cpp"

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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

