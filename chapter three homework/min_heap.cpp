//
// Created by lcr on 2017/11/24.
//
//
//
//#include <iostream>
//
//using namespace std;
//
//template <class T>
//class max_heap{
//private:
//    T* heap_array;
//    int current_size;
//    int max_size;
//public:
//    max_heap(int size = 10);
//    max_heap(T* array,int size);
//    ~max_heap();
//    int choose_max(int i);
//    void init();
//    bool insert(T in);
//    bool delete_one(T key);
//    void print();
//};
//
//template <class T>
//max_heap<T>::max_heap(int size) {
//    heap_array = new T[size];
//    current_size = 0;
//    max_size = size;
//}
//
//template <class T>
//max_heap<T>::max_heap(T *array,int size) {
//    heap_array = array;
//    current_size = size;
//    max_size = size;
//}
//
//template <class T>
//max_heap<T>::~max_heap() {
//    delete[](heap_array);
//}
//
//template <class T>
//int max_heap<T>::choose_max(int i) {
//    int temp = 0;
//    if(2*i+2<current_size-1){
//        if(heap_array[i]<=heap_array[2*i+1]&&heap_array[2*i+1]>=heap_array[2*i+2]){
//            temp = heap_array[i];
//            heap_array[i] = heap_array[2*i+1];
//            heap_array[2*i+1] = temp;
//            return 1;
//        }
//        else if(heap_array[i]<=heap_array[2*i+2]&&heap_array[2*i+1]<=heap_array[2*i+2]){
//            temp = heap_array[i];
//            heap_array[i] = heap_array[2*i+2];
//            heap_array[2*i+2] = temp;
//            return 2;
//        }
//    }
//    else{
//        if(heap_array[2*i+1]>heap_array[i]){
//            temp = heap_array[i];
//            heap_array[i] = heap_array[2*i+1];
//            heap_array[2*i+1] = temp;
//            return 1;
//        }
//    }
//    return 0;
//}
//
//template <class T>
//void max_heap<T>::init() {
//    int j = 0;
//    for(int i = (current_size - 2)/2;i>=0;i--){
//        j = i;
//        int flag = choose_max(j);
//        while(flag){
//            if(flag == 1){
//                j = 2*j+1;
//            }
//            else{
//                j = 2*j+2;
//            }
//            if(j>(current_size - 2)/2){
//                break;
//            }
//            flag = choose_max(j);
//        }
//    }
//}
//
//template <class T>
//bool max_heap<T>::insert(T in) {
//    if(current_size == max_size){
//        T* new_array = new T[max_size*2];
//        for(int i = 0;i<max_size;++i){
//            new_array[i] = heap_array[i];
//        }
//        max_size *= 2;
//        delete[](heap_array);
//        heap_array = new_array;
//    }
//    heap_array[current_size] = in;
//    current_size++;
//    for(int i = current_size-1;(i -1)/2>=0;i = (i -1)/2){
//        if(heap_array[i]>heap_array[(i-1)/2]){
//            int temp = heap_array[i];
//            heap_array[i] = heap_array[(i-1)/2];
//            heap_array[(i-1)/2] = temp;
//        }
//        else{
//            break;
//        }
//    }
//}
//
//template <class T>
//bool max_heap<T>::delete_one(T key) {
//    int p = 0;
//    for(;p<current_size;++p){
//        if(heap_array[p] == key){
//            break;
//        }
//    }
//    int temp = heap_array[p];
//    heap_array[p] = heap_array[current_size-1];
//    heap_array[current_size-1] = temp;
//    current_size --;
//    int  j = p;
//    int flag = choose_max(j);
//    while(flag){
//        if(flag == 1){
//            j = 2*j+1;
//        }
//        else{
//            j = 2*j+2;
//        }
//        if(j>(current_size - 2)/2){
//            break;
//        }
//        flag = choose_max(j);
//    }
//    for(int i = current_size-1;(i -1)/2>=0;i = (i -1)/2){
//        if(heap_array[i]>heap_array[(i-1)/2]){
//            int temp = heap_array[i];
//            heap_array[i] = heap_array[(i-1)/2];
//            heap_array[(i-1)/2] = temp;
//        }
//        else{
//            break;
//        }
//    }
//}
//
//template <class T>
//void max_heap<T>::print() {
//    for(int i = 0;i<current_size;++i){
//        cout<<heap_array[i]<<" ";
//    }
//    cout<<endl;
//}
//
//int main(){
//    int l = 10;
//    cout<<"请输入最大堆的长度：";
//    cin>>l;
//    int* array = new int[l];
//    cout<<"请输入堆内容：";
//    for(int i = 0;i<l;++i){
//        cin>>array[i];
//    }
//    //int array[10] = {20,12,35,15,10,80,30,17,2,1};
//    max_heap<int> h(array,l);
//    h.print();
//    h.init();
//    h.print();
//    int n;
//    cin>>n;
//    h.insert(n);
//    h.print();
//    cin>>n;
//    h.delete_one(n);
//    h.print();
//    system("pause");
//    return 0;
//}

//template <class T>
//class min_heap{
//private:
//    T* heap_array;
//    int current_size;
//    int max_size;
//public:
//    min_heap(int size = 10);
//    min_heap(T* array,int size);
//    ~min_heap();
//    int choose_max(int i);
//    void init();
//    bool insert(T in);
//    bool delete_one(T key);
//    void print();
//};
//
//template <class T>
//min_heap<T>::min_heap(int size) {
//    heap_array = new T[size];
//    current_size = 0;
//    max_size = size;
//}
//
//template <class T>
//min_heap<T>::min_heap(T *array,int size) {
//    heap_array = array;
//    current_size = size;
//    max_size = size;
//}
//
//template <class T>
//min_heap<T>::~min_heap() {
//    delete[](heap_array);
//}
//
//template <class T>
//int min_heap<T>::choose_max(int i) {
//    int temp = 0;
//    if(2*i+2<current_size-1){
//        if(heap_array[i]>=heap_array[2*i+1]&&heap_array[2*i+1]<=heap_array[2*i+2]){
//            temp = heap_array[i];
//            heap_array[i] = heap_array[2*i+1];
//            heap_array[2*i+1] = temp;
//            return 1;
//        }
//        else if(heap_array[i]>=heap_array[2*i+2]&&heap_array[2*i+1]>=heap_array[2*i+2]){
//            temp = heap_array[i];
//            heap_array[i] = heap_array[2*i+2];
//            heap_array[2*i+2] = temp;
//            return 2;
//        }
//    }
//    else{
//        if(heap_array[2*i+1]<heap_array[i]){
//            temp = heap_array[i];
//            heap_array[i] = heap_array[2*i+1];
//            heap_array[2*i+1] = temp;
//            return 1;
//        }
//    }
//    return 0;
//}
//
//template <class T>
//void min_heap<T>::init() {
//    int j = 0;
//    for(int i = (current_size - 2)/2;i>=0;i--){
//        j = i;
//        int flag = choose_max(j);
//        while(flag){
//            if(flag == 1){
//                j = 2*j+1;
//            }
//            else{
//                j = 2*j+2;
//            }
//            if(j>(current_size - 2)/2){
//                break;
//            }
//            flag = choose_max(j);
//        }
//    }
//}
//
//template <class T>
//bool min_heap<T>::insert(T in) {
//    if(current_size == max_size){
//        T* new_array = new T[max_size*2];
//        for(int i = 0;i<max_size;++i){
//            new_array[i] = heap_array[i];
//        }
//        max_size *= 2;
//        delete[](heap_array);
//        heap_array = new_array;
//    }
//    heap_array[current_size] = in;
//    current_size++;
//    for(int i = current_size-1;(i -1)/2>=0;i = (i -1)/2){
//        if(heap_array[i]<heap_array[(i-1)/2]){
//            int temp = heap_array[i];
//            heap_array[i] = heap_array[(i-1)/2];
//            heap_array[(i-1)/2] = temp;
//        }
//        else{
//            break;
//        }
//    }
//}
//
//template <class T>
//bool min_heap<T>::delete_one(T key) {
//    int p = 0;
//    for(;p<current_size;++p){
//        if(heap_array[p] == key){
//            break;
//        }
//    }
//    int temp = heap_array[p];
//    heap_array[p] = heap_array[current_size-1];
//    heap_array[current_size-1] = temp;
//    current_size --;
//    int  j = p;
//    int flag = choose_max(j);
//    while(flag){
//        if(flag == 1){
//            j = 2*j+1;
//        }
//        else{
//            j = 2*j+2;
//        }
//        if(j>(current_size - 2)/2){
//            break;
//        }
//        flag = choose_max(j);
//    }
//    for(int i = current_size-1;(i -1)/2>=0;i = (i -1)/2){
//        if(heap_array[i]<heap_array[(i-1)/2]){
//            int temp = heap_array[i];
//            heap_array[i] = heap_array[(i-1)/2];
//            heap_array[(i-1)/2] = temp;
//        }
//        else{
//            break;
//        }
//    }
//}
//
//template <class T>
//void min_heap<T>::print() {
//    cout<<"堆为："<<endl;
//    for(int i = 0;i<current_size;++i){
//        cout<<heap_array[i]<<endl;
//    }
//}
//
//int main(){
//    int l = 10;
//    cout<<"请输入最小堆的长度：";
//    cin>>l;
//    int* array = new int[l];
//    cout<<"请输入堆内容：";
//    for(int i = 0;i<l;++i){
//        cin>>array[i];
//    }
//    //int array[10] = {20,12,35,15,10,80,30,17,2,1};
//    min_heap<int> h(array,l);
//    h.print();
//    h.init();
//    h.print();
//    int n;
//    cin>>n;
//    h.insert(n);
//    h.print();
//    cin>>n;
//    h.delete_one(n);
//    h.print();
//    return 0;
//}
//#include <stdio.h>
//
//const int MAXN = 50005; /*结点数目上线*/
//int pa[MAXN];    /*p[x]表示x的父节点*/
//int rank[MAXN];    /*rank[x]是x的高度的一个上界*/
//int n, ans;
//
//void make_set(int x)
//{/*创建一个单元集*/
//    pa[x] = x;
//    rank[x] = 0;
//}
//
//int find_set(int x)
//{/*带路径压缩的查找*/
//    if(x != pa[x])
//        pa[x] = find_set(pa[x]);
//    return pa[x];
//}
//
///*按秩合并x，y所在的集合*/
//void union_set(int x, int y)
//{
//    x = find_set(x);
//    y = find_set(y);
//    if(x == y)return ;
//    ans--;    //统计
//    if(rank[x] > rank[y])/*让rank比较高的作为父结点*/
//    {
//        pa[y] = x;
//    }
//    else
//    {
//        pa[x] = y;
//        if(rank[x] == rank[y])
//            rank[y]++;
//    }
//}
////answer to 2524
//int main()
//{
//    int m, i, j = 1, x, y;
//    while(scanf("%d%d", &n, &m))
//    {
//        if(n == m && m == 0) break;
//        for(i = 1; i <= n; i++)
//            make_set(i);
//        ans = n;
//        for(i = 0; i < m; i++)
//        {
//            scanf("%d%d", &x, &y);
//            union_set(x, y);
//        }
//        printf("Case %d: %d\n", j, ans);
//        j++;
//    }
//    return 0;
//}
//#include <stdio.h>
//int n,m;
//#define N 105
//struct People{
//    int header;
//    int num;
//};
//People a[N];
//void My_swap(int & a,int & b){
//    a ^= b;     b ^= a;     a ^= b;
//}
//void Init(){
//    for(int i = 0; i < n;i++){
//        a[i].header = i;
//        a[i].num = 1;
//    }
//}
//int getheader(int t){
//    if(a[t].header == t){
//        return t;
//    }
//    else{
//        return a[t].header = getheader(a[t].header);
//    }
//}
//void merge(int u,int v){
//    int t1,t2;
//    t1 = getheader(u);
//    t2 = getheader(v);
//    if(t1 > t2){
//        My_swap(t1,t2);
//    }
//    if(t1 != t2){
//        a[t2].header = t1;
//        a[t1].num += a[t2].num;
//    }
//}
//int main(){
//    int x,y;
//        scanf("%d %d",&n,&m);
//        Init();
//        for(int i = 0; i < m; i++){
//            scanf("%d %d",&x,&y);
//            merge(x,y);
//        }
//        int max_sum = 0;
//        for(int i = 0; i < n; i++){
//            max_sum = max_sum > a[i].num ? max_sum : a[i].num;
//        }
//        printf("%d",max_sum);
//    return 0;
//}