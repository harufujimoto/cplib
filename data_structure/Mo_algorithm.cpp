#include "../template.cpp"
int block;
struct Query{
  int L,R,id;
  Query(int L,int R,int id):L(L),R(R),id(id){}
};
bool compare(Query x,Query y){
  if(x.L/block != y.L/block) return x.L/block < y.L/block;
  else return x.R < y.R;
}
template<class T> struct Answer{
  T val;
  Answer(T val):val(val){}
  Answer():val(0){}
  Answer& operator += (const T& anot)
  {
    val += anot;
    return *this;
  }
  Answer operator -= (const T& anot)
  {
    val -= anot;
    return *this;
  }
  Answer operator = (T& anot){
    Answer res(*this);
    res.val = anot;
    return *this = res;
  }
};
template<class T>
ostream& operator << (ostream& os,const Answer<T>& a){return os << a.val;}

template<class T>
vector<T> queryResults(vector<T>& a,int n,vector<Query>& q,int m)
{
  block = (int) sqrt(n);
  sort(q.begin(),q.end(),compare);
  int currL = 0,currR = 0;
  Answer<T> currAns = 0;
  vector<T> res(m); 
  for (int i = 0; i < m; i++) {
    int L = q[i].L,R = q[i].R;
    while(currL < L){
      currAns -= a[currL];
      debug2(currAns,a[currL]);
      currL++;
    }
    while(currL > L){
      currAns += a[currL - 1];
      currL--;
    }
    while(currR <= R){
      currAns += a[currR];
      currR++;
    }
    while(currR > R + 1){
      currAns -= a[currR - 1];
      currR--;
    }
    //cout << L << ' ' << R << ' ' << currAns.val << '\n';
    res[q[i].id] = currAns.val;
  }
  return res;
}


int main(int argc, char const* argv[])
{
  lyn();
  int n,q;cin >> n >> q;
  vector<Query> query(q);
  REP(i,n){
    int l,r;cin >> l >> r;
    l--,r--;
    query[i] = Query(l,r,i);
  }
  return 0;
}
