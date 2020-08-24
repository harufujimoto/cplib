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


# :heavy_check_mark: task/yosupo/staticrmq.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#a6a96afc30701de32dfcd524b6a3bd23">task/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/task/yosupo/staticrmq.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-24 18:51:19+09:00


* see: <a href="https://judge.yosupo.jp/problem/staticrmq">https://judge.yosupo.jp/problem/staticrmq</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data_structure/RangeMinQuery.cpp.html">data_structure/RangeMinQuery.cpp</a>
* :question: <a href="../../../library/template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "task/yosupo/staticrmq.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#line 1 "template.cpp"

#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0;i < n;i++)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()

template<class T> bool chmax(T& a,T b){ if(a > b){ a = b; return true; }else return false; }
template<class T> bool chmin(T& a,T b){ if(a < b){ a = b; return true; }else return false; }
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
#line 4 "task/yosupo/staticrmq.test.cpp"

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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

