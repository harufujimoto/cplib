#include "template.cpp"
template<class T>
struct GridGraph{
  int H,W;
  Graph<T> G;
  GridGraph(int H,int W):H(H),W(W){
    G = Graph<T>((H+2)*(W+2));
  }
  int id(int x,int y){
    return x + y * W;
  }
  bool inside(int x,int y){
    return x >= 0 && x < H && y >= 0 && y < W;
  }
  void connect(int x0,int y0,int x1,int y1,T dist = 1){
    int from = id(x0,y0);
    int to = id(x1,y1);
    G.add_edge(from,to,dist);
    G.add_edge(to,from,dist);
  }
};
