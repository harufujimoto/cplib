#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A"
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(int i = 0;i < n;i++)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define debug(arr) cout << #arr << " = " << arr << '\n'
#define debug2(a,b) cout << "[" << #a << "," << #b << "] = " << "[" << a << "," << b << "]" << '\n'

template<class T> bool chmin(T& a, T b) { if (b < a) {a = b; return true;} else return false;}
template<class T> bool chmax(T& a, T b) { if (b > a) {a = b; return true;} else return false;}
template<class T> T max_element(T[], int);
template<class T> T min_element(T[], int);
template<class T> pair<T, int> lower_bound(T arr[], int n, T val);
template<class T> pair<T, int> upper_bound(T arr[], int n, T val);
template<class T> int get_range_cnt(vector<T>& a, T lb, T ub);
template<class T> vector<pair<T, int> > runlength(vector<T> arr);
vector<pair<char, int> > runlength(string s);
template<class T> ostream &operator << (ostream&, const vector<T>&);
template<class T> ostream &operator << (ostream&, const vector<vector<T> >&);
template<class S, class T> ostream &operator << (ostream& out, const pair<S, T>& p);
template<class T> istream &operator >> (istream&, vector<T>&);

#include "graph/dijkstra.cpp"

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  //cout << fixed << setprecision(20);
  //int t;cin >> t; REP(_,t) main2();

  int n, m, r; cin >> n >> m >> r;
  Graph<ll> G(n);
  for (int i = 0; i < m; i++) {
    int s, t, d; cin >> s >> t >> d;
    G.add_edge(s,t,d);
  }
  Dijkstra<ll> D(G);
  D.solve(r);
  REP(i,n){
    if(D[i] == (1LL << 55)){
      cout << "INF" << '\n'; 
    }else{
      cout << D[i] << '\n';
    }
  } 
  return 0;
}


/////////////////////////////////////////////////////////////////////////////////
// for debug & input
template<class T> ostream &operator << (ostream& out, const vector<T>& arr) {
  cout << "{"; for (int i = 0; i < arr.size(); i++)cout << (!i ? "" : ", ") << arr[i]; cout << "}";
  return out;
}
template<class T> ostream &operator << (ostream& out, const vector<vector<T> >& arr) {
  cout << "{\n"; for (auto& vec : arr)cout << "  " << vec << ",\n"; cout << "}";
  return out;
}
template<class S, class T> ostream &operator << (ostream& out, const pair<S, T>& p) {
  cout << "{" << p.first << "," << p.second << "}";
  return out;
}
template<class T> istream &operator >> (istream& in, vector<T>& arr) {
  for (auto& i : arr)cin >> i; return in;
}

// for arrays.
template<class T> T max_element(T arr[], int n) {
  T res = numeric_limits<T>::min(); for (int i = 0; i < n; i++) res = max(res , arr[i]); return res;
}
template<class T> T min_element(T arr[], int n) {
  T res = numeric_limits<T>::max(); for (int i = 0; i < n; i++) res = min(res , arr[i]); return res;
}
template<class T> pair<T, int> lower_bound(T arr[], int n, T val) {
  int l = 0, r = n;
  while (r - l) { int mid = (r + l) / 2; if (arr[mid] >= val) r = mid; else l = mid; }
  return make_pair(arr[r] , r);
}
template<class T> pair<T, int> upper_bound(T arr[], int n, T val) {
  int l = 0, r = n;
  while (r - l) { int mid = (r + l) / 2; if (arr[mid] > val) r = mid; else l = mid; }
  return make_pair(arr[r] , r);
}
// [lb,ub)??????????????????????????????
// last checked : 2020.5.8
template<class T> int get_range_cnt(vector<T>& a, T lb, T ub) {
  int n = a.size();
  int r = n - (int)(a.end() - (lower_bound(a.begin(), a.end(), ub)));
  int l = n - (int)(a.end() - (lower_bound(a.begin(), a.end(), lb)));
  return r - l;
}
template<class T> vector<pair<T, int> > runlength(vector<T> arr) {
  vector<pair<T, int> > res; int n = arr.size(); T tmp = arr[0]; int cont = 1;
  for (int i = 1; i < n; i++) {
    if (arr[i] != tmp) { res.push_back(make_pair(tmp, cont)); tmp = arr[i], cont = 1; } else cont++;
  }
  res.push_back(make_pair(tmp, cont));
  return res;
}
vector<pair<char, int> > runlength(string s) {
  vector<char> arr(s.size()); for (int i = 0; i < s.size(); i++)arr[i] = s[i];
  return runlength(arr);
}


