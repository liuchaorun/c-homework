//
// Created by lcr on 2017/12/7.
//

#ifndef INC_1_GRAPH_H
#define INC_1_GRAPH_H

#include "baseHeader.h"
#include "edge.cpp"
#include "minHeap.h"
#include "minHeap.cpp"
#include "UFSet.h"
#include "../chapter three homework/my_queue.h"
#include "../chapter three homework/my_stack.h"

template<class T>
class graph {
private:
    vector<vector<T>> matrix;
    int vertexNum;
    int edgeNum;
    vector<int> mark;

    void DFSTraverse(vector<int> &m, int num);

    void BFSTraverse(vector<int> &m, int num);

public:
    explicit graph(int vertexNum);

    ~graph();

    void setVertexNum(int vertexNum);

    void setEdgeNum(int edgeNum);

    int getVertexNum();

    int getEdgeNum();

    void setEdge(edge<T> oneEdge, int flag = 0);

    void deleteOneEdge(edge<T> oneEdge, int flag = 0);

    int getOneEdgeStart(edge<T> &oneEdge);

    int getOneEdgeEnd(edge<T> &oneEdge);

    T getOneEdgeWeight(edge<T> &oneEdge);

    void DFS();

    void BFS();

    vector<edge<T>> Prim();

    vector<edge<T>> Kruskal();

    void dijkstra(int i, vector<int>& dist,vector<int>& length);

    void floyd(vector<vector<int>> &adj,vector<vector<int>> &path);

    string floydPath(vector<vector<int>> &path, int start, int end);

    string directedLoop();

    vector<edge<T>> breakCircle();
};


#endif //INC_1_GRAPH_H
