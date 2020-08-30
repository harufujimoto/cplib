struct UnionFind {
#define MAX_N 2000000
	//UnionFind
	int par[MAX_N];
	int ufrank[MAX_N];
	int ufsize[MAX_N];
	UnionFind(int ufsize_of_tree) {
		for (int i = 0; i < ufsize_of_tree; i++)
		{
			par[i] = i;
			ufrank[i] = 0;
			ufsize[i] = 1;
		}
	}
	int find(int x) {
		if (par[x] == x) return x;
		else return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (ufrank[x] < ufrank[y]) {
			par[ x] = y;
			int sx = ufsize[x], sy = ufsize[y];
			ufsize[x] = ufsize[y] = sx + sy;
		}
		else {
			par[y] = x;
			if (ufrank[x] == ufrank[y]) ufrank[x]++;
			int sx = ufsize[x], sy = ufsize[y];
			ufsize[x] = ufsize[y] = sx + sy;
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};
