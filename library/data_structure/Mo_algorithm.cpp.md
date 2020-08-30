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


# :warning: data_structure/Mo_algorithm.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c8f6850ec2ec3fb32f203c1f4e3c2fd2">data_structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data_structure/Mo_algorithm.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-30 11:17:40+09:00




## Depends on

* :heavy_check_mark: <a href="../template.cpp.html">template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../template.cpp"
int block;
struct Query{
  int L,R,id;
  Query(int L,int R,int id):L(L),R(R),id(id){}
};
bool compare(Query x,Query y){
  if(x.L/block != y.L/block) return x.L/block < y.L/block;
  else return x.R < y.R;
}
template<class T> struct Answer{
  T val;
  Answer(T val):val(val){}
  Answer():val(0){}
  Answer& operator += (const T& anot)
  {
    val += anot;
    return *this;
  }
  Answer operator -= (const T& anot)
  {
    val -= anot;
    return *this;
  }
  Answer operator = (T& anot){
    Answer res(*this);
    res.val = anot;
    return *this = res;
  }
};
template<class T>
ostream& operator << (ostream& os,const Answer<T>& a){return os << a.val;}

template<class T>
vector<T> queryResults(vector<T>& a,int n,vector<Query>& q,int m)
{
  block = (int) sqrt(n);
  sort(q.begin(),q.end(),compare);
  int currL = 0,currR = 0;
  Answer<T> currAns = 0;
  vector<T> res(m); 
  for (int i = 0; i < m; i++) {
    int L = q[i].L,R = q[i].R;
    while(currL < L){
      currAns -= a[currL];
      debug2(currAns,a[currL]);
      currL++;
    }
    while(currL > L){
      currAns += a[currL - 1];
      currL--;
    }
    while(currR <= R){
      currAns += a[currR];
      currR++;
    }
    while(currR > R + 1){
      currAns -= a[currR - 1];
      currR--;
    }
    //cout << L << ' ' << R << ' ' << currAns.val << '\n';
    res[q[i].id] = currAns.val;
  }
  return res;
}


int main(int argc, char const* argv[])
{
  lyn();
  int n,q;cin >> n >> q;
  vector<Query> query(q);
  REP(i,n){
    int l,r;cin >> l >> r;
    l--,r--;
    query[i] = Query(l,r,i);
  }
  return 0;
}

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
#line 2 "data_structure/Mo_algorithm.cpp"
int block;
struct Query{
  int L,R,id;
  Query(int L,int R,int id):L(L),R(R),id(id){}
};
bool compare(Query x,Query y){
  if(x.L/block != y.L/block) return x.L/block < y.L/block;
  else return x.R < y.R;
}
template<class T> struct Answer{
  T val;
  Answer(T val):val(val){}
  Answer():val(0){}
  Answer& operator += (const T& anot)
  {
    val += anot;
    return *this;
  }
  Answer operator -= (const T& anot)
  {
    val -= anot;
    return *this;
  }
  Answer operator = (T& anot){
    Answer res(*this);
    res.val = anot;
    return *this = res;
  }
};
template<class T>
ostream& operator << (ostream& os,const Answer<T>& a){return os << a.val;}

template<class T>
vector<T> queryResults(vector<T>& a,int n,vector<Query>& q,int m)
{
  block = (int) sqrt(n);
  sort(q.begin(),q.end(),compare);
  int currL = 0,currR = 0;
  Answer<T> currAns = 0;
  vector<T> res(m); 
  for (int i = 0; i < m; i++) {
    int L = q[i].L,R = q[i].R;
    while(currL < L){
      currAns -= a[currL];
      debug2(currAns,a[currL]);
      currL++;
    }
    while(currL > L){
      currAns += a[currL - 1];
      currL--;
    }
    while(currR <= R){
      currAns += a[currR];
      currR++;
    }
    while(currR > R + 1){
      currAns -= a[currR - 1];
      currR--;
    }
    //cout << L << ' ' << R << ' ' << currAns.val << '\n';
    res[q[i].id] = currAns.val;
  }
  return res;
}


int main(int argc, char const* argv[])
{
  lyn();
  int n,q;cin >> n >> q;
  vector<Query> query(q);
  REP(i,n){
    int l,r;cin >> l >> r;
    l--,r--;
    query[i] = Query(l,r,i);
  }
  return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

