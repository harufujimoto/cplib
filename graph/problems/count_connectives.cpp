#include "../template.cpp"
/*
 * VERIFIED : 29.August.2020
 */
template<class T> struct CountConnectives
{
  Graph<T> G;
  vector<bool> used;
  vector<int> root,SizeOfMyGroup,ConnectedID;
  CountConnectives(Graph<T>& G):G(G){

  }
  void dfs(int st,int x,int id){
    used[x] = true;
    root[x] = st;
    ConnectedID[x] = id;
    SizeOfMyGroup[st]++;
    for(auto _next : G[x]){
      if(!used[_next.to]){
        dfs(st,_next.to,id);
      }
    }
  }
  int solve(){
    used.assign(G.n,false);
    ConnectedID.assign(G.n,-1);
    root.assign(G.n,-1);
    SizeOfMyGroup.assign(G.n,0);
    int res = 0;
    for (int i = 0; i < G.n; i++) {
      if (!used[i]) {
        dfs(i,i,res);
        res++;
      }
    }
    for (int i = 0; i < G.n; i++) {
      SizeOfMyGroup[i] = SizeOfMyGroup[root[i]];
    }  
    return res;
  }
};
