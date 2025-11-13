#include <iostream>
using namespace std;

class Array {
    int* a;
    int n;
public:
    Array(int arr[], int size) {
        n = size;
        a = new int[n];
        for (int i = 0; i < n; i++) a[i] = arr[i];
    }

    void selectionSort() {
        for (int i = 0; i < n - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < n; j++)
                if (a[j] < a[minIdx]) minIdx = j;
            swap(a[i], a[minIdx]);
        }
    }

    void bubbleSort() {
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
    }

    void insertionSort() {
        for (int i = 1; i < n; i++) {
            int key = a[i], j = i - 1;
            while (j >= 0 && a[j] > key) {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = key;
        }
    }

    void merge(int l, int m, int r) {
        int n1 = m - l + 1, n2 = r - m;
        int* L = new int[n1];
        int* R = new int[n2];
        for (int i = 0; i < n1; i++) L[i] = a[l + i];
        for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
        while (i < n1) a[k++] = L[i++];
        while (j < n2) a[k++] = R[j++];
        delete[] L;
        delete[] R;
    }

    void mergeSort(int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort(l, m);
            mergeSort(m + 1, r);
            merge(l, m, r);
        }
    }

    int partition(int low, int high) {
        int pivot = a[high], i = low - 1;
        for (int j = low; j < high; j++)
            if (a[j] < pivot) swap(a[++i], a[j]);
        swap(a[i + 1], a[high]);
        return i + 1;
    }

    void quickSort(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);
            quickSort(low, pi - 1);
            quickSort(pi + 1, high);
        }
    }

    void heapify(int n, int i) {
        int largest = i, l = 2 * i + 1, r = 2 * i + 2;
        if (l < n && a[l] > a[largest]) largest = l;
        if (r < n && a[r] > a[largest]) largest = r;
        if (largest != i) {
            swap(a[i], a[largest]);
            heapify(n, largest);
        }
    }

    void heapSort() {
        for (int i = n / 2 - 1; i >= 0; i--) heapify(n, i);
        for (int i = n - 1; i > 0; i--) {
            swap(a[0], a[i]);
            heapify(i, 0);
        }
    }

    void print() {
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << "\n";
    }

    ~Array() {
        delete[] a;
    }
};

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;
    Array A(arr, n);

    cout << "Original array:\n";
    A.print();

    Array B(arr, n);
    B.selectionSort();
    cout << "\nAfter Selection Sort:\n";
    B.print();

    Array C(arr, n);
    C.bubbleSort();
    cout << "\nAfter Bubble Sort:\n";
    C.print();

    Array D(arr, n);
    D.insertionSort();
    cout << "\nAfter Insertion Sort:\n";
    D.print();

    Array E(arr, n);
    E.mergeSort(0, n - 1);
    cout << "\nAfter Merge Sort:\n";
    E.print();

    Array F(arr, n);
    F.quickSort(0, n - 1);
    cout << "\nAfter Quick Sort:\n";
    F.print();

    Array G(arr, n);
    G.heapSort();
    cout << "\nAfter Heap Sort:\n";
    G.print();

    return 0;
}
