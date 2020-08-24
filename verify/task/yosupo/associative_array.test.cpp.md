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


# :heavy_check_mark: task/yosupo/associative_array.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#a6a96afc30701de32dfcd524b6a3bd23">task/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/task/yosupo/associative_array.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 00:44:09+09:00


* see: <a href="https://judge.yosupo.jp/problem/associative_array">https://judge.yosupo.jp/problem/associative_array</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include "../../template.cpp"

int main(void){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int q;cin >> q;
    map<int64_t ,int64_t > M;
    REP(i,q){
        int64_t c;cin >> c;
        if(c == 0){
            int64_t k,v;cin >> k >> v;
            M[k] = v;
        }else{
            int64_t k;cin >> k;
            cout << M[k] << '\n';
        }
    }
}


```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "task/yosupo/associative_array.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
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
#line 3 "task/yosupo/associative_array.test.cpp"

int main(void){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int q;cin >> q;
    map<int64_t ,int64_t > M;
    REP(i,q){
        int64_t c;cin >> c;
        if(c == 0){
            int64_t k,v;cin >> k >> v;
            M[k] = v;
        }else{
            int64_t k;cin >> k;
            cout << M[k] << '\n';
        }
    }
}


```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

