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


# :heavy_check_mark: data_structure/RangeMinQuery.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/RangeMinQuery.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-23 14:06:29+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/task/yosupo/staticrmq.test.cpp.html">task/yosupo/staticrmq.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

