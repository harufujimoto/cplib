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

