//
// Created by lcr on 2017/12/7.
//

#include "graph.h"

template<class T>
graph<T>::graph(int vertexNum):vertexNum(vertexNum) {
    edgeNum = 0;
    mark.resize((size_t) vertexNum);
    matrix.resize((size_t) vertexNum);
    for (int i = 0; i < vertexNum; i++) {
        matrix[i].resize((size_t) vertexNum);
    }
}

template<class T>
graph<T>::~graph()= default;

template<class T>
void graph<T>::setVertexNum(int vertexNum) {
    this->vertexNum = vertexNum;
}

template<class T>
void graph<T>::setEdgeNum(int edgeNum) {
    this->edgeNum = edgeNum;
}

template<class T>
int graph<T>::getVertexNum() {
    return vertexNum;
}

template<class T>
int graph<T>::getEdgeNum() {
    return edgeNum;
}

template<class T>
void graph<T>::setEdge(edge<T> oneEdge, int flag) {
    if (!flag) {
        matrix[oneEdge.getStart()][oneEdge.getEnd()] = oneEdge.getWeight();
        matrix[oneEdge.getEnd()][oneEdge.getStart()] = oneEdge.getWeight();
    } else {
        matrix[oneEdge.getStart()][oneEdge.getEnd()] = oneEdge.getWeight();
    }
}

template<class T>
int graph<T>::getOneEdgeStart(edge<T> &oneEdge) {
    return oneEdge.getStart();
}

template<class T>
int graph<T>::getOneEdgeEnd(edge<T> &oneEdge) {
    return oneEdge.getEnd();
}

template<class T>
T graph<T>::getOneEdgeWeight(edge<T> &oneEdge) {
    return oneEdge.getWeight();
}

template<class T>
void graph<T>::deleteOneEdge(edge<T> oneEdge, int flag) {
    if (!flag) {
        matrix[oneEdge.getStart()][oneEdge.getEnd()] = 0;
        matrix[oneEdge.getEnd()][oneEdge.getStart()] = 0;
    } else {
        matrix[oneEdge.getStart()][oneEdge.getEnd()] = 0;
    }
}

template<class T>
void graph<T>::DFSTraverse(vector<int> &m, int num) {
    m[num] = 1;
    cout << num << " ";
    for (int i = 0; i < vertexNum; i++) {
        if (m[i] == 0 && matrix[num][i] != 0) {
            DFSTraverse(m, i);
        }
    }
}

template<class T>
void graph<T>::DFS() {
    for (int i = 0; i < vertexNum; i++) {
        mark[i] = 0;
    }
    for (int i = 0; i < vertexNum; i++) {
        if (mark[i] == 0) {
            DFSTraverse(mark, i);
        }
    }
    cout << endl;
}

template<class T>
void graph<T>::BFSTraverse(vector<int> &m, int num) {
    queue<int> vertexQueue;
    int one;
    m[num] = 1;
    cout << num << " ";
    vertexQueue.en_queue(num);
    while (vertexQueue.get_size() != 0) {
        vertexQueue.de_queue(one);
        for (int i = 0; i < vertexNum; i++) {
            if (m[i] == 0 && matrix[one][i] != 0) {
                vertexQueue.en_queue(i);
                m[i] = 1;
                cout << i << " ";
            }
        }
    }
    cout<<endl;
}

template<class T>
void graph<T>::BFS() {
    for (int i = 0; i < vertexNum; i++) {
        mark[i] = 0;
    }
    for (int i = 0; i < vertexNum; i++) {
        if (mark[i] == 0) {
            BFSTraverse(mark, i);
        }
    }
}

template<class T>
vector<edge<T>> graph<T>::Prim() {
    for (int i = 0; i < vertexNum; i++) {
        mark[i] = 0;
    }
    vector<edge<T>> MST;
    minHeap<edge<T>> neighbor(10);
    int n = 0;
    mark[0] = 1;
    for (int j = 0; j < vertexNum - 1; ++j) {
        for (int i = 0; i < vertexNum; ++i) {
            if (matrix[n][i] != 0) {
                edge<T> one(n, i, matrix[n][i]);
                neighbor.insert(one);
            }
        }
        neighbor.init();
        n = neighbor.minOne().getEnd();
        while (mark[n] != 0) {
            neighbor.deleteMinOne();
            n = neighbor.minOne().getEnd();
        }
        mark[n] = 1;
        MST.push_back(neighbor.minOne());
        neighbor.deleteMinOne();
    }
    return MST;
}

template<class T>
vector<edge<T>> graph<T>::Kruskal() {
    for (int i = 0; i < vertexNum; i++) {
        mark[i] = 0;
    }
    vector<edge<T>> MST;
    UFSet vertexSet(vertexNum);
    minHeap<edge<T>> edgeSet(10);
    for (int j = 0; j < vertexNum; ++j) {
        for (int i = j; i < vertexNum; ++i) {
            if(matrix[j][i]!=0){
                edge<T> one(j,i,matrix[j][i]);
                edgeSet.insert(one);
            }
        }
    }
    edgeSet.init();
    for (int k = 0; k < vertexNum - 1; ++k) {
        while(vertexSet.Find(edgeSet.minOne().getStart()) == vertexSet.Find(edgeSet.minOne().getEnd())){
            edgeSet.deleteMinOne();
        }
        MST.push_back(edgeSet.minOne());
        vertexSet.Union(edgeSet.minOne().getStart(),edgeSet.minOne().getEnd());
    }
    return MST;
}

template<class T>
void graph<T>::dijkstra(int i, vector<int> &dist, vector<int> &length) {
    vector<int> front;
    int min = 0;
    for (int j = 0; j < vertexNum; ++j) {
        mark[j] = 0;
        dist.push_back(0);
        length.push_back(0);
        front.push_back(j);
    }
    mark[i] = 1;
    for (int k = 0; k < vertexNum - 1; ++k) {
        for (int j = 0; j < vertexNum; ++j) {
            if(mark[j] == 0){
                if((length[j] == 0||length[j] < length[i] + matrix[i][j])&&matrix[i][j]!=0){
                    length[j] = length[i] + matrix[i][j];
                    front[j] = i;
                }
                min = j;
            }
        }
        for (int l = 0; l < vertexNum; ++l) {
            if(mark[l] == 0 && length[l] != 0){
                if(length[l]<length[min]){
                    min = l;
                }
            }
        }
        dist[min] = i;
        i = ( min == front[min] )?min:front[min];
        mark[i] = 1;
    }
}

template<class T>
vector<edge<T>> graph<T>::floyd() {

}