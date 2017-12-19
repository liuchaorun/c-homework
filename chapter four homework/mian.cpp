//
// Created by lcr on 2017/12/7.
//

#include "graph.cpp"

int main(){
//    int vertexNum;
//    cout<<"请输入图中的顶点数目："<<endl;
//    cin>>vertexNum;
//    graph<int> g(vertexNum);
//    int num;
//    cout<<"请输入边的数目:"<<endl;
//    cin>>num;
//    for (int i = 0; i < num; ++i) {
//        cout<<"请输入一条边的起点终点和权重:(以-1结束)"<<endl;
//        edge<int> a(1,1,1);
//        cin>>a;
//        g.setEdge(a,0);
//    }
    graph<int> g(6);
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
    g.breakCircle();
//    vector<edge<int>> a = g.Kruskal();
//    for (int j = 0; j < a.size(); ++j) {
//        cout<<a[j];
//    }
//    graph<int> g(6);
//    edge<int> a1(0,2,10);
//    g.setEdge(a1,1);
//    edge<int> a2(0,4,30);
//    g.setEdge(a2,1);
//    edge<int> a3(1,2,5);
//    g.setEdge(a3,1);
//    edge<int> a4(2,3,50);
//    g.setEdge(a4,1);
//    edge<int> a5(3,5,10);
//    g.setEdge(a5,1);
//    edge<int> a6(4,3,20);
//    g.setEdge(a6,1);
//    edge<int> a7(4,5,60);
//    g.setEdge(a7,1);
//    edge<int> a8(0,5,100);
//    g.setEdge(a8,1);
//    edge<int> a9(0,1,12);
//    g.setEdge(a9,1);
//    vector<int> dist,length;
//    g.dijkstra(0,dist,length);
//    string to("->");
//    for (int i = 0; i < g.getVertexNum(); ++i) {
//        string a;
//        if(i != 0){
//            int j = i;
//            do{
//                j = dist[j];
//                a.insert(0,to_string(j)+to);
//
//            }while(0 != j);
//            a += to_string(i);
//            cout<<a<<" 长度为："<<length[i]<<endl;
//        }
//    }
//    graph<int> g(3);
//    edge<int> a1(0,1,5);
//    g.setEdge(a1,1);
//    edge<int> a2(1,0,2);
//    g.setEdge(a2,1);
//    edge<int> a3(0,2,10);
//    g.setEdge(a3,1);
//    edge<int> a4(2,0,9);
//    g.setEdge(a4,1);
//    edge<int> a5(1,2,13);
//    g.setEdge(a5,1);
//    edge<int> a6(2,1,6);
//    g.setEdge(a6,1);
//    graph<int> g(11);
//    edge<int> a1(0,1,2);
//    g.setEdge(a1,0);
//    edge<int> a2(0,2,8);
//    g.setEdge(a2,0);
//    edge<int> a3(0,3,1);
//    g.setEdge(a3,0);
//    edge<int> a4(1,2,6);
//    g.setEdge(a4,0);
//    edge<int> a5(2,3,7);
//    g.setEdge(a5,0);
//    edge<int> a6(1,4,1);
//    g.setEdge(a6,0);
//    edge<int> a7(2,4,5);
//    g.setEdge(a7,0);
//    edge<int> a8(2,5,1);
//    g.setEdge(a8,0);
//    edge<int> a9(2,6,2);
//    g.setEdge(a9,0);
//    edge<int> a10(3,6,9);
//    g.setEdge(a10,0);
//    edge<int> a11(4,5,3);
//    g.setEdge(a11,0);
//    edge<int> a12(5,6,1);
//    g.setEdge(a12,0);
//    edge<int> a13(4,7,2);
//    g.setEdge(a13,0);
//    edge<int> a14(4,8,9);
//    g.setEdge(a14,0);
//    edge<int> a15(5,8,6);
//    g.setEdge(a15,0);
//    edge<int> a16(6,8,3);
//    g.setEdge(a16,0);
//    edge<int> a17(6,9,1);
//    g.setEdge(a17,0);
//    edge<int> a18(7,8,7);
//    g.setEdge(a18,0);
//    edge<int> a19(8,9,1);
//    g.setEdge(a19,0);
//    edge<int> a20(7,10,9);
//    g.setEdge(a20,0);
//    edge<int> a21(8,10,2);
//    g.setEdge(a21,0);
//    edge<int> a22(9,10,4);
//    g.setEdge(a22,0);
//    vector<vector<int>> adj;
//    vector<vector<int>> path;
//    g.floyd(adj,path);
//    cout<<"请输入起点和终点："<<endl;
//    int start,end;
//    cin>>start>>end;
//    int temp = path[start][end];
//    if(temp == start){
//        cout<<start<<"->"<<end<<" 长度为："<<adj[start][end]<<endl;
//    } else{
//        string a = g.floydPath(path,start,end);
//        cout<<a<<" 长度为："<<adj[start][end]<<endl;
//    }
//    graph<int> g(4);
//    edge<int> a1(0,1,1);
//    g.setEdge(a1,1);
//    edge<int> a2(0,2,1);
//    g.setEdge(a2,1);
//    edge<int> a3(1,3,1);
//    g.setEdge(a3,1);
//    edge<int> a4(3,2,1);
//    g.setEdge(a4,1);
//    edge<int> a5(2,1,1);
//    g.setEdge(a5,1);
//    cout<<g.directedLoop()<<endl;
    return 0;
}