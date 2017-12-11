//
// Created by lcr on 2017/12/7.
//

#include "graph.cpp"

int main(){
    graph<int> g(8);
    int num;
    cout<<"请输入边的数目:"<<endl;
    cin>>num;
    for (int i = 0; i < num; ++i) {
        cout<<"请输入一条边的起点终点和权重:(以-1结束)"<<endl;
        edge<int> a(1,1,1);
        cin>>a;
        g.setEdge(a,1);
    }
    g.BFS();
    return 0;
}