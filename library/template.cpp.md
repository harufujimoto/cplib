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


# :question: template.cpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-24 10:46:33+09:00




## Required by

* :warning: <a href="ITP_1_1_B.cpp.html">ITP_1_1_B.cpp</a>
* :warning: <a href="data_structure/Mo_algorithm.cpp.html">data_structure/Mo_algorithm.cpp</a>
* :warning: <a href="graph/main.cpp.html">graph/main.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../verify/ITP_1_1_B.test.cpp.html">ITP_1_1_B.test.cpp</a>
* :x: <a href="../verify/task/AOJ/DSL_2_G.test.cpp.html">task/AOJ/DSL_2_G.test.cpp</a>
* :x: <a href="../verify/task/AOJ/GRL_1_B.test.cpp.html">task/AOJ/GRL_1_B.test.cpp</a>
* :heavy_check_mark: <a href="../verify/task/AOJ/GRL_4_B.test.cpp.html">task/AOJ/GRL_4_B.test.cpp</a>
* :heavy_check_mark: <a href="../verify/task/yosupo/associative_array.test.cpp.html">task/yosupo/associative_array.test.cpp</a>
* :heavy_check_mark: <a href="../verify/task/yosupo/lca.test.cpp.html">task/yosupo/lca.test.cpp</a>
* :heavy_check_mark: <a href="../verify/task/yosupo/shortest_path.test.cpp.html">task/yosupo/shortest_path.test.cpp</a>
* :heavy_check_mark: <a href="../verify/task/yosupo/staticrmq.test.cpp.html">task/yosupo/staticrmq.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp

#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0;i < n;i++)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()

template<class T> bool chmax(T& a,T b){ if(a > b){ a = b; return true; }else return false; }
template<class T> bool chmin(T& a,T b){ if(a < b){ a = b; return true; }else return false; }

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../index.html">Back to top page</a>

