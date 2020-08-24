#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include "../../template.cpp"

int main(void){

    cin.tie(0);
    ios::sync_with_stdio(false);
    int q;cin >> q;
    map<int64_t ,int64_t > M;
    REP(i,q){
        int64_t c;cin >> c;
        if(c == 0){
            int64_t k,v;cin >> k >> v;
            M[k] = v;
        }else{
            int64_t k;cin >> k;
            cout << M[k] << '\n';
        }
    }
}

