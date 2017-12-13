//
// Created by lcr on 2017/12/7.
//

#include "graph.cpp"

int main(){
    int vertexNum;
    cout<<"请输入图中的顶点数目："<<endl;
    cin>>vertexNum;
    graph<int> g(vertexNum);
//    int num;
//    cout<<"请输入边的数目:"<<endl;
//    cin>>num;
//    for (int i = 0; i < num; ++i) {
//        cout<<"请输入一条边的起点终点和权重:(以-1结束)"<<endl;
//        edge<int> a(1,1,1);
//        cin>>a;
//        g.setEdge(a,0);
//    }
    edge<int> a1(0,1,6);
    g.setEdge(a1,0);
    edge<int> a2(1,4,3);
    g.setEdge(a2,0);
    edge<int> a3(4,5,6);
    g.setEdge(a3,0);
    edge<int> a4(5,3,2);
    g.setEdge(a4,0);
    edge<int> a5(3,0,5);
    g.setEdge(a5,0);
    edge<int> a6(0,2,1);
    g.setEdge(a6,0);
    edge<int> a7(1,2,5);
    g.setEdge(a7,0);
    edge<int> a8(4,2,6);
    g.setEdge(a8,0);
    edge<int> a9(5,2,4);
    g.setEdge(a9,0);
    edge<int> a10(3,2,5);
    g.setEdge(a10,0);
    g.DFS();
    g.BFS();
    vector<edge<int>> a = g.Prim();
    for (int j = 0; j < a.size(); ++j) {
        cout<<a[j];
    }
    return 0;
}