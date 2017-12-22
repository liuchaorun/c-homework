//
// Created by lcr on 17-12-21.
//

#include <iostream>
#include <random>
#define N 10

using namespace std;

template <class T>
void insertSort(T* array, int n){
    for (int i = 1; i < n; ++i) {
        int temp = array[i];
        int j = i -1;
        while(j >= 0 && array[j] > temp){
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

template <class T>
void binaryInsertSort(T* array, int n){
    for (int i = 1; i < n; ++i) {
        int left = 0, right = i - 1, mid = 0, temp = array[i];
        while(left <= right){
            mid = (left + right)/2;
            if(array[mid] > array[i]){
                right = mid - 1;
            } else{
                left = mid + 1;
            }
        }
        for (int j = i - 1; j >= left; --j) {
            array[j + 1] = array[j];
        }
        array[left] = temp;
    }
}

template <class T>
void bubbleSort(T* array, int n){
    for (int i = 0; i < n; ++i) {
        int flag = 0;
        for (int j = 1; j < n - i; ++j) {
            if(array[j] < array[j - 1]){
                T temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
                flag = 1;
            }
        }
        if(!flag){
            return;
        }
    }
}

template <class T>
int partition(T* array, int left, int right){
    int temp = array[left];
    while(left < right){
        while(left < right && array[right] > temp){
            right--;
        }
        array[left] = array[right];
        while(left < right && array[left] < temp){
            left++;
        }
        array[right] = array[left];
    }
    array[left] = temp;
    return right;
}

template <class T>
void quickSort(T* array, int left, int right){
    if(left < right){
        int mid = partition(array,left,right);
        quickSort(array,left,mid - 1);
        quickSort(array,mid + 1,right);
    }
}

template <class T>
void selectionSort(T* array, int n){
    for (int i = 0; i < n; ++i) {
        int min = i;
        for (int j = i; j < n; ++j) {
            if(array[j] < array[min]){
                min = j;
            }
        }
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

template <class T>
void merge(T* array,int left, int mid, int right){
    int leftLength = mid - left + 1, rightLength = right - mid;
    T* leftArray = new T[leftLength];
    T* rightArray = new T[rightLength];
    for (int i = 0; i < leftLength; ++i) {
        leftArray[i] = array[left + i];
    }
    for (int j = 0; j < rightLength; ++j) {
        rightArray[j] = array[mid + j + 1];
    }
    int i = 0, j = 0;
    while(i < leftLength || j < rightLength){
        if(i < leftLength && j < rightLength){
            if(leftArray[i] < rightArray[j]){
                array[left + i + j] = leftArray[i];
                i++;
            } else{
                array[left + i + j] = rightArray[j];
                j++;
            }
        } else if(i < leftLength && j >= rightLength){
            while(i < leftLength){
                array[left + i + j] = leftArray[i];
                i++;
            }
        } else{
            while(j < rightLength){
                array[left + i + j] = rightArray[j];
                j++;
            }
        }
    }
    delete[] leftArray;
    delete[] rightArray;
}

template <class T>
void mergeSort(T* array, int left, int right){
    if(left < right){
        int mid = (left + right)/2;
        mergeSort(array,left,mid);
        mergeSort(array,mid + 1,right);
        merge(array,left,mid,right);
    }
}

int main(){
    random_device rd;
    int *array = new int[N];
    cout<<"直接插入排序："<<endl;
    for (int i = 0; i < N; ++i) {
        array[i] = rd()%10000;
    }
    for (int j = 0; j < N; ++j) {
        cout<<array[j]<<" ";
    };
    cout<<endl;
    insertSort(array,N);
    for (int j = 0; j < N; ++j) {
        cout<<array[j]<<" ";
    }
    cout<<endl;
    cout<<"折半插入排序："<<endl;
    for (int i = 0; i < N; ++i) {
        array[i] = rd()%10000;
    }
    for (int j = 0; j < N; ++j) {
        cout<<array[j]<<" ";
    };
    cout<<endl;
    binaryInsertSort(array,N);
    for (int j = 0; j < N; ++j) {
        cout<<array[j]<<" ";
    }
    cout<<endl;
    cout<<"冒泡排序："<<endl;
    for (int i = 0; i < N; ++i) {
        array[i] = rd()%10000;
    }
    for (int j = 0; j < N; ++j) {
        cout<<array[j]<<" ";
    };
    cout<<endl;
    bubbleSort(array,N);
    for (int j = 0; j < N; ++j) {
        cout<<array[j]<<" ";
    }
    cout<<endl;
    cout<<"快速排序："<<endl;
    for (int i = 0; i < N; ++i) {
        array[i] = rd()%10000;
    }
    for (int j = 0; j < N; ++j) {
        cout<<array[j]<<" ";
    };
    cout<<endl;
    quickSort(array,0,N - 1);
    for (int j = 0; j < N; ++j) {
        cout<<array[j]<<" ";
    }
    cout<<endl;
    cout<<"简单选择排序："<<endl;
    for (int i = 0; i < N; ++i) {
        array[i] = rd()%10000;
    }
    for (int j = 0; j < N; ++j) {
        cout<<array[j]<<" ";
    };
    cout<<endl;
    selectionSort(array,N);
    for (int j = 0; j < N; ++j) {
        cout<<array[j]<<" ";
    }
    cout<<endl;
    cout<<"归并排序："<<endl;
    for (int i = 0; i < N; ++i) {
        array[i] = rd()%10000;
    }
    for (int j = 0; j < N; ++j) {
        cout<<array[j]<<" ";
    };
    cout<<endl;
    mergeSort(array,0,N - 1);
    for (int j = 0; j < N; ++j) {
        cout<<array[j]<<" ";
    }
    cout<<endl;
}