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


# :warning: data_structure/unionfind.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/unionfind.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 11:17:40+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct UnionFind {
#define MAX_N 2000000
	//UnionFind
	int par[MAX_N];
	int ufrank[MAX_N];
	int ufsize[MAX_N];
	UnionFind(int ufsize_of_tree) {
		for (int i = 0; i < ufsize_of_tree; i++)
		{
			par[i] = i;
			ufrank[i] = 0;
			ufsize[i] = 1;
		}
	}
	int find(int x) {
		if (par[x] == x) return x;
		else return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (ufrank[x] < ufrank[y]) {
			par[ x] = y;
			int sx = ufsize[x], sy = ufsize[y];
			ufsize[x] = ufsize[y] = sx + sy;
		}
		else {
			par[y] = x;
			if (ufrank[x] == ufrank[y]) ufrank[x]++;
			int sx = ufsize[x], sy = ufsize[y];
			ufsize[x] = ufsize[y] = sx + sy;
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data_structure/unionfind.cpp"
struct UnionFind {
#define MAX_N 2000000
	//UnionFind
	int par[MAX_N];
	int ufrank[MAX_N];
	int ufsize[MAX_N];
	UnionFind(int ufsize_of_tree) {
		for (int i = 0; i < ufsize_of_tree; i++)
		{
			par[i] = i;
			ufrank[i] = 0;
			ufsize[i] = 1;
		}
	}
	int find(int x) {
		if (par[x] == x) return x;
		else return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (ufrank[x] < ufrank[y]) {
			par[ x] = y;
			int sx = ufsize[x], sy = ufsize[y];
			ufsize[x] = ufsize[y] = sx + sy;
		}
		else {
			par[y] = x;
			if (ufrank[x] == ufrank[y]) ufrank[x]++;
			int sx = ufsize[x], sy = ufsize[y];
			ufsize[x] = ufsize[y] = sx + sy;
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

