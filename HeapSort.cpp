#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

vector<int> result;

void Heapify(vector<int>& heap, int pos) {
    if ((pos == 0) || (pos>=heap.size())) {
        return;
    }
    
    if (pos % 2 == 1) {
        if (heap[pos] > heap[(pos - 1) / 2]) {
            swap(heap[pos], heap[(pos - 1) / 2]);
            if ((pos * 2 + 2) < heap.size()) {
                if ((heap[pos * 2 + 2] > heap[pos]) || (heap[pos * 2 + 1] > heap[pos])) {
                    Heapify(heap, pos * 2 + 2);
                }
            }
            else if ((pos * 2 + 1) < heap.size()) {
                if (heap[pos * 2 + 1] > heap[pos]) {
                    Heapify(heap, pos * 2 + 1);
                }
            }
        }
    }
    else {
        if (heap[pos] > heap[(pos - 2) / 2]) {
            swap(heap[pos], heap[(pos - 2) / 2]);
            if ((pos * 2 + 2) < heap.size()) {
                if (heap[pos * 2 + 2] > heap[pos]) {
                    Heapify(heap, pos * 2 + 2);
                }
            }
            if ((pos * 2 + 1) < heap.size()) {
                if (heap[pos * 2 + 1] > heap[pos]) {
                    Heapify(heap, pos * 2 + 1);
                }
            }
        }
    }
    Heapify(heap, pos - 1);
}

void rebuild(vector<int>& heap, int pos) {
    if (((pos*2 + 1) >= heap.size()) && ((pos * 2 + 2) >= heap.size())) {
        return;
    }
    if (pos * 2 + 2 == heap.size()) {
        if (heap[pos] < heap[pos * 2 + 1]) {
            swap(heap[pos], heap[pos * 2 + 1]);
        }
        return;
    }
    if ((heap[pos] >= heap[pos * 2 + 1]) && (heap[pos] >= heap[pos * 2 + 2])) {
        return;
    }
    else {
        if (heap[pos * 2 + 2] > heap[pos * 2 + 1]) {
            swap(heap[pos], heap[pos * 2 + 2]);
            rebuild(heap, pos * 2 + 2);
        }
        else {
            swap(heap[pos], heap[pos * 2 + 1]);
            rebuild(heap, pos * 2 + 1);
        }
    }
}

void HeapSort(vector<int>& heap) {
    if (heap.size() == 0) {
        return;
    }
    result.push_back(heap[0]);
    swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    //Heapify(heap, heap.size()-1);
    rebuild(heap, 0);
    HeapSort(heap);
}

int main() {
    unsigned int start = clock();
	vector<int> heap = { 1, 10, -29, 0, 14, -32, 100, -32, 0 };
	Heapify(heap, heap.size() - 1);
    HeapSort(heap);
    reverse(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    unsigned int end = clock();

    cout << "Time: " << end - start << endl;

	return 0;
}