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


# :warning: data_structure/LazySegtree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/LazySegtree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 00:39:20+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

