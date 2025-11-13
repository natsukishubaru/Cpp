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

    int countBits(int x) {
        int c = 0;
        while (x) {
            x &= (x - 1);
            c++;
        }
        return c;
    }

    void sortBySetBitCount() {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                int c1 = countBits(a[j]);
                int c2 = countBits(a[j + 1]);
                if (c1 < c2) {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
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
    int arr[] = {3, 7, 8, 9, 5};
    int n = 5;
    Array A(arr, n);

    cout << "Original array:\n";
    A.print();

    A.sortBySetBitCount();

    cout << "Sorted by decreasing count of set bits:\n";
    A.print();

    return 0;
}
