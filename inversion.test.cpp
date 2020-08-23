#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D"
#define GLIBCXX_DEBUG
#include<bits/stdc++.h>
#include<cassert>
using namespace std;

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
	cout << inversion(a, 200020) << '\n';
	return 0;
}


