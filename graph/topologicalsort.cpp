#include "template.cpp"
template<class T> struct TopologicalSorting{
    Graph<T> G;
    TopologicalSorting(Graph<T>& G):G(G){}
    void topologicalSortUtil(int v,vector<bool>& visited,stack<int>& Stack);
    vector<int> topologicalSort();
};
template<class T>
void TopologicalSorting<T>::topologicalSortUtil(int v, vector<bool> &visited, stack<int> &Stack) {
    visited[v] = true;
    for(int i = 0;i < G[v].size();i++){
        int _to = G[v][i].to;
        if(!visited[_to]) topologicalSortUtil(_to,visited,Stack);
    }
    Stack.push(v);
}
template<class T>
vector<int> TopologicalSorting<T>::topologicalSort() {
    stack<int> Stack;
    vector<int> res;
    vector<bool> visited(G.n,false);
    for(int i = 0;i < G.n;i++){
        if(!visited[i]) topologicalSortUtil(i,visited,Stack);
    }
    while(Stack.size()){
        res.push_back(Stack.top());
        Stack.pop();
    }
    return res;
}

