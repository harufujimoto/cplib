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
<script type="text/javascript" src="../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../assets/css/copy-button.css" />


# :x: inversion.test.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/inversion.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-23 13:47:09+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D">https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D</a>


## Depends on

* :x: <a href="../library/data_structure/fenwick_tree.cpp.html">data_structure/fenwick_tree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/*
	author : Haruki Fujimoto
 */
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D"
#define GLIBCXX_DEBUG
#include<bits/stdc++.h>
#include<cassert>
using namespace std;
#include "data_structure/fenwick_tree.cpp"
template<class T> vector<T> compress(vector<T>& a) {
	vector<T> b = a;
	vector<T> res(a.size());
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	for (int i = 0; i < a.size(); i++)res[i] = 1 + (lower_bound(b.begin(), b.end(), a[i]) - b.begin());
	return res;
}
template<class T> long long inversion(vector<T> a, int maxn) {
	BIT<T> B(maxn, a.size());
	T res = 0;
	for (int i = 0; i < a.size(); i++) {
		res += i - B.sum(a[i]);
		B.add(a[i], 1);
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int n; cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++)cin >> a[i];
	a = compress(a);
	assert(*max_element(a.begin(),a.end()) <= 200020);
	cout << inversion(a, 200020) - 1<< '\n';
	return 0;
}



```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "inversion.test.cpp"
/*
	author : Haruki Fujimoto
 */
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D"
#define GLIBCXX_DEBUG
#include<bits/stdc++.h>
#line 8 "inversion.test.cpp"
using namespace std;
#line 1 "data_structure/fenwick_tree.cpp"
// BIT
template<class T> class BIT {
private:
	int n;
	vector<T> dat;//[1,n]
public:
	BIT(int maxn, int _n) {
		dat.assign(maxn + 1, 0);
		n = _n;
	}
	T sum(int i) {
		T res = 0;
		while (i > 0) {
			res += dat[i];
			i -= i & -i;
		}
		return res;
	}
	void add(int i, T x) {
		while (i <= n) {
			dat[i] += x;
			i += i & -i;
		}
	}
};

#line 10 "inversion.test.cpp"
template<class T> vector<T> compress(vector<T>& a) {
	vector<T> b = a;
	vector<T> res(a.size());
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	for (int i = 0; i < a.size(); i++)res[i] = 1 + (lower_bound(b.begin(), b.end(), a[i]) - b.begin());
	return res;
}
template<class T> long long inversion(vector<T> a, int maxn) {
	BIT<T> B(maxn, a.size());
	T res = 0;
	for (int i = 0; i < a.size(); i++) {
		res += i - B.sum(a[i]);
		B.add(a[i], 1);
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int n; cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++)cin >> a[i];
	a = compress(a);
	assert(*max_element(a.begin(),a.end()) <= 200020);
	cout << inversion(a, 200020) - 1<< '\n';
	return 0;
}



```
{% endraw %}

<a href="../index.html">Back to top page</a>

