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
