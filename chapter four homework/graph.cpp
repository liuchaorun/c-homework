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
    cout << endl;
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
            if (matrix[j][i] != 0) {
                edge<T> one(j, i, matrix[j][i]);
                edgeSet.insert(one);
            }
        }
    }
    edgeSet.init();
    for (int k = 0; k < vertexNum - 1; ++k) {
        while (vertexSet.Find(edgeSet.minOne().getStart()) == vertexSet.Find(edgeSet.minOne().getEnd())) {
            edgeSet.deleteMinOne();
        }
        MST.push_back(edgeSet.minOne());
        vertexSet.Union(edgeSet.minOne().getStart(), edgeSet.minOne().getEnd());
    }
    return MST;
}

template<class T>
void graph<T>::dijkstra(int i, vector<int> &dist, vector<int> &length) {
    int min = 0;
    for (int j = 0; j < vertexNum; ++j) {
        mark[j] = 0;
        dist.push_back(0);
        length.push_back(0);

    }
    mark[i] = 1;
    for (int k = 0; k < vertexNum - 1; ++k) {
        for (int j = 0; j < vertexNum; ++j) {
            if (mark[j] == 0) {
                if ((length[j] == 0 || length[j] > length[i] + matrix[i][j]) && matrix[i][j] != 0) {
                    length[j] = length[i] + matrix[i][j];
                    dist[j] = i;
                }
            }
        }
        for (int m = 0; m < vertexNum; ++m) {
            if(mark[m] == 0&&length[m]){
                min = m;
                break;
            }
        }
        for (int l = 0; l < vertexNum; ++l) {
            if (mark[l] == 0 && length[l] != 0) {
                if (length[l] < length[min]) {
                    min = l;
                }
            }
        }
        i = min;
        mark[i] = 1;
    }
}

template<class T>
void graph<T>::floyd(vector<vector<int>> &adj, vector<vector<int>> &path) {
    adj.resize((size_t) vertexNum);
    path.resize((size_t) vertexNum);
    for (int i = 0; i < vertexNum; i++) {
        adj[i].resize((size_t) vertexNum);
        path[i].resize((size_t) vertexNum);
    }
    for (int j = 0; j < vertexNum; ++j) {
        for (int i = 0; i < vertexNum; ++i) {
            if (i == j) {
                adj[j][i] = 0;
                path[j][i] = j;
            } else {
                path[j][i] = j;
                adj[j][i] = matrix[j][i];
            }
        }
    }
    for (int k = 0; k < vertexNum; ++k) {
        for (int i = 0; i < vertexNum; ++i) {
            for (int j = 0; j < vertexNum; ++j) {
                if (i != k && j != k && i != j) {
                    if (((adj[i][j] > adj[i][k] + adj[k][j]) || (adj[i][j] == 0))&& adj[i][k] != 0 && adj[k][j] != 0) {
                        adj[i][j] = adj[i][k] + adj[k][j];
                        path[i][j] = k;
                    }
                }
            }
        }
    }
}

template<class T>
string graph<T>::floydPath(vector<vector<int>> &path, int start, int end) {
    int temp = path[start][end];
    if (start == temp) {
        return to_string(start) + "->" + to_string(end);
    } else {
        return floydPath(path, start, temp) +
               floydPath(path, temp, end).substr(1, floydPath(path, temp, end).size() - 1);
    }
}

template<class T>
string graph<T>::directedLoop() {
    vector<vector<int>> matrixTemp = matrix;
    for (int i = 0; i < vertexNum; i++) {
        mark[i] = 0;
    }
    vector<int> p;
    p.resize((size_t) vertexNum);
    for (int i = 0; i < vertexNum; ++i) {
        int n = 0;
        for (int j = 0; j < vertexNum; ++j) {
            if (matrixTemp[j][i] != 0) {
                n++;
            }
        }
        p[i] = n;
    }
    for (int k = 0; k < vertexNum; ++k) {
        int i = 0, flag = 0;
        for (i = 0; i < vertexNum; ++i) {
            if (mark[i] == 0 && p[i] == 0) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            flag = 0;
            mark[i] = 1;
            for (int j = 0; j < vertexNum; ++j) {
                matrixTemp[i][j] = 0;
            }
            for (int l = 0; l < vertexNum; ++l) {
                int n = 0;
                for (int j = 0; j < vertexNum; ++j) {
                    if (matrixTemp[j][l] != 0) {
                        n++;
                    }
                }
                p[l] = n;
            }
        }
    }
    int m = 0,i = 0,flag = 0;
    for (m = 0; m < vertexNum; ++m) {
        for (i = 0; i < vertexNum; ++i) {
            if(matrixTemp[m][i] != 0){
                flag = 1;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    if(flag){
        int start = m;
        string a(to_string(m) + "->" + to_string(i));
        while(start != i){
            m = i;
            for (int j = 0; j < vertexNum; ++j) {
                if(matrixTemp[m][j]){
                    i = j;
                    a += "->" + to_string(j);
                    break;
                }
            }
        }
        return a;
    }
    else{
        return string("不存在回路！");
    }
}

template <class T>
vector<edge<T>> graph<T>::breakCircle() {
    vector<edge<T>> MST;
    vector<edge<T>> edgeArray;
    vector<vector<int>> m = matrix;
    vector<int> vertexClass(vertexNum,0);
    stack<int> vertexStack;
    stack<int> rest;
    for (int i = 0; i < vertexNum; ++i) {
        edgeArray.erase(edgeArray.begin(),edgeArray.end());
        vertexStack.clear();
        rest.clear();
        for (int j = 0; j < vertexNum; ++j) {
            mark[j] = 0;
            vertexClass[j] = 0;
        }
        int flag = 0;
        vertexStack.push(i);
        mark[i] = 1;
        while(!vertexStack.is_empty()){
            int j, c;
            vertexStack.pop(j);
            rest.Top(c);
            if(vertexClass[j] == c || rest.get_size() == 0){
                rest.push(j);
            }
            else{
                while(vertexClass[j] != c&&!rest.is_empty()){
                    rest.pop(c);
                    rest.Top(c);
                }
                rest.push(j);
            }
            mark[j] = 1;
            for (int k = vertexNum - 1; k >= 0; --k) {
                if(m[j][k]&&k!=j){
                    if(mark[k]==0){
                        vertexStack.push(k);
                        vertexClass[k] = j;
                    }
                    else{
                        if(k==i&&!vertexStack.is_empty()&&rest.get_size()>2){
                            flag = 1;
                            break;
                        }
                    }
                }
            }
            if(flag){
                break;
            }
        }
        if(flag){
            int j = i,k = i;
            while(!rest.is_empty()){
                rest.pop(j);
                edgeArray.push_back(edge<T>(j,k,m[j][k]));
                k = j;
            }
            sort(edgeArray.begin(),edgeArray.end());
            m[edgeArray[edgeArray.size()-1].getStart()][edgeArray[edgeArray.size()-1].getEnd()] = 0;
            m[edgeArray[edgeArray.size()-1].getEnd()][edgeArray[edgeArray.size()-1].getStart()] = 0;
            i--;
        }
    }
    for (int l = 0; l < vertexNum; ++l) {
        for (int i = l; i < vertexNum; ++i) {
            if(m[l][i]){
                MST.push_back(edge<T>(l,i,m[l][i]));
            }
        }
    }
    return MST;
}
