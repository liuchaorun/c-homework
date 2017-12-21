////
//// Created by lcr on 2017/12/7.
////
//
//#include "graph.cpp"
//
//int main(){
////    int vertexNum;
////    cout<<"请输入图中的顶点数目："<<endl;
////    cin>>vertexNum;
////    graph<int> g(vertexNum);
////    int num;
////    cout<<"请输入边的数目:"<<endl;
////    cin>>num;
////    for (int i = 0; i < num; ++i) {
////        cout<<"请输入一条边的起点终点和权重:(以-1结束)"<<endl;
////        edge<int> a(1,1,1);
////        cin>>a;
////        g.setEdge(a,1);
////    }
//
//
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
//    cout<<"Kruskal算法结果为："<<endl;
//    vector<edge<int>> a = g.Kruskal();
//    for (int j = 0; j < a.size(); ++j) {
//        cout<<a[j];
//    }
//    cout<<"破圈法结果为："<<endl;
//    vector<edge<int>> b = g.breakCircle();
//    for (int j = 0; j < b.size(); ++j) {
//        cout<<b[j];
//    }
//
//
////    graph<int> g(6);
////    edge<int> a1(0,1,7);
////    g.setEdge(a1,1);
////    edge<int> a2(0,3,2);
////    g.setEdge(a2,1);
////    edge<int> a3(0,5,60);
////    g.setEdge(a3,1);
////    edge<int> a4(1,4,6);
////    g.setEdge(a4,1);
////    edge<int> a5(3,4,12);
////    g.setEdge(a5,1);
////    edge<int> a6(3,5,15);
////    g.setEdge(a6,1);
////    edge<int> a7(4,2,25);
////    g.setEdge(a7,1);
////    edge<int> a8(5,2,10);
////    g.setEdge(a8,1);
////    edge<int> a9(5,4,1);
////    g.setEdge(a9,1);
////    vector<int> dist,length;
////    g.dijkstra(0,dist,length);
////    string to("->");
////    for (int i = 0; i < g.getVertexNum(); ++i) {
////        string a;
////        if(i != 0){
////            int j = i;
////            do{
////                j = dist[j];
////                a.insert(0,to_string(j)+to);
////
////            }while(0 != j);
////            a += to_string(i);
////            cout<<a<<" 长度为："<<length[i]<<endl;
////        }
////    }
////    vector<vector<int>> adj;
////    vector<vector<int>> path;
////    g.floyd(adj,path);
////    cout<<"请输入起点和终点："<<endl;
////    int start,end;
////    cin>>start>>end;
////    int temp = path[start][end];
////    if(temp == start){
////        cout<<start<<"->"<<end<<" 长度为："<<adj[start][end]<<endl;
////    } else{
////        string a = g.floydPath(path,start,end);
////        cout<<a<<" 长度为："<<adj[start][end]<<endl;
////    }
////    cout<<g.directedLoop()<<endl;
////    edge<int> a10(2,1,1);
////    g.setEdge(a10,1);
////    cout<<g.directedLoop()<<endl;
//    return 0;
//}