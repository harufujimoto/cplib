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


