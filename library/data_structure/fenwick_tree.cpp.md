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


# :heavy_check_mark: data_structure/fenwick_tree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/fenwick_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-23 13:30:28+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/inversion.test.cpp.html">inversion.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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


```
{% endraw %}

<a href="../../index.html">Back to top page</a>

