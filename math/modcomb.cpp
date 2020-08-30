#include "../modint.cpp"
template<int mod = 1000000007, int maxn = 1000000>
struct modcomb {
    using mint = modint<mod>;
    vector<mint> f, finv;
    modcomb() {
        f.assign(maxn, 0);
        finv.assign(maxn, 0);
        for (int i = 0; i < maxn; i++) {
            if (!i) f[i] = (mint) 1;
            else f[i] = f[i - 1] * (mint) i;
        }
        finv[maxn - 1] = f[maxn - 1].inv();
        for (int i = maxn - 2; i >= 0; i--) {
            finv[i] = finv[i + 1] * (mint) (i + 1);
        }
    }
    mint comb(int n, int r) {
        if (n < 0 || r < 0 || n < r) return 0;
        else { return f[n] * finv[r] * finv[n - r]; }
    }
};
