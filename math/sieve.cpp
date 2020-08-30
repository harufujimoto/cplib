struct Sieve{
  vector<int> min_factor;
  Sieve(int n = 1000001)
  {
    min_factor.assign(n,0);
    for (int i = 2; i*i < n; ++i) {
      if (min_factor[i] < i) continue;
      for (int j = i*i; j < n; j += i)
        if (min_factor[j] == j) min_factor[j] = i;
    }
  }
  Sieve(){
    Sieve(1000000);
  }
  vector<int> factor(int n){
    vector<int> res;
    while (n > 1) {
      res.push_back(min_factor[n]);
      n /= min_factor[n];
    }
    return res;
  }
};
