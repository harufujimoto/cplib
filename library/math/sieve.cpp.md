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


# :warning: math/sieve.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/sieve.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 11:35:54+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
struct Sieve{
  vector<int> min_factor;
  Sieve(int n = 1000001)
  {
    min_factor.assign(n,0);
    for (int i = 2; i*i < n; ++i) {
      if (min_factor[i] < i) continue;
      for (int j = i*i; j < n; j += i)
        if (min_factor[j] == j) min_factor[j] = i;
    }
  }
  Sieve(){
    Sieve(1000000);
  }
  vector<int> factor(int n){
    vector<int> res;
    while (n > 1) {
      res.push_back(min_factor[n]);
      n /= min_factor[n];
    }
    return res;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/sieve.cpp"
struct Sieve{
  vector<int> min_factor;
  Sieve(int n = 1000001)
  {
    min_factor.assign(n,0);
    for (int i = 2; i*i < n; ++i) {
      if (min_factor[i] < i) continue;
      for (int j = i*i; j < n; j += i)
        if (min_factor[j] == j) min_factor[j] = i;
    }
  }
  Sieve(){
    Sieve(1000000);
  }
  vector<int> factor(int n){
    vector<int> res;
    while (n > 1) {
      res.push_back(min_factor[n]);
      n /= min_factor[n];
    }
    return res;
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

