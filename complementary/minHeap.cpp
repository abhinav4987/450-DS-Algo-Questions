#include<iostream>
#include<vector>
using namespace std;

class MinHeap {
    public :
        int heap_size;
        int *arr;
        int capacity;

        MinHeap(int capacity);
        void MinHeapify(int);
        int parent(int i) { return (i - 2) / 2; }
        int left(int i) { return (2 * i + 1); }
        int right(int i) { return (2 * i + 2); }
        int extractMin();
        int getMin() { return arr[0]; }
        void deleteKey(int i);
        void insertKey(int k);
};

MinHeap::MinHeap(int cap) {
    this->heap_size = 0;
    this->capacity = cap;
    this->arr = new int[cap];
}

void MinHeap::insertKey(int k) {
    if(this->heap_size >= this->capacity) {
        cout << "OVERFLOW OF HEAP";
    }else {
        heap_size++;
        int i = heap_size - 1;

        arr[i] = k;

        while(i != 0 && arr[this->parent(i)] > arr[i]){
            swap(arr[i], arr[this->parent(i)]);
            i = parent(i);
        }
    }

}

int main() {

}
