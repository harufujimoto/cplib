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
