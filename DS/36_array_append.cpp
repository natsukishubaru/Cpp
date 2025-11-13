#include <iostream>
using namespace std;

class ArraySorter {
    int* A1;
    int n1;
    int* A2;
    int n2;
public:
    ArraySorter(int arr1[], int size1, int arr2[], int size2) {
        n1 = size1;
        n2 = size2;
        A1 = new int[n1];
        A2 = new int[n2];
        for (int i = 0; i < n1; i++) A1[i] = arr1[i];
        for (int i = 0; i < n2; i++) A2[i] = arr2[i];
    }

    void sortA1ByA2() {
        int* temp = new int[n1];
        bool* visited = new bool[n1];
        for (int i = 0; i < n1; i++) visited[i] = false;

        int index = 0;
        for (int i = 0; i < n2; i++) {
            for (int j = 0; j < n1; j++) {
                if (A1[j] == A2[i] && !visited[j]) {
                    temp[index++] = A1[j];
                    visited[j] = true;
                }
            }
        }

        for (int i = 0; i < n1 - 1; i++) {
            for (int j = i + 1; j < n1; j++) {
                if (A1[i] > A1[j]) {
                    int t = A1[i];
                    A1[i] = A1[j];
                    A1[j] = t;
                }
            }
        }

        for (int i = 0; i < n1; i++) {
            if (!visited[i]) {
                temp[index++] = A1[i];
            }
        }

        for (int i = 0; i < n1; i++) A1[i] = temp[i];

        delete[] temp;
        delete[] visited;
    }

    void print() {
        for (int i = 0; i < n1; i++) cout << A1[i] << " ";
        cout << "\n";
    }

    ~ArraySorter() {
        delete[] A1;
        delete[] A2;
    }
};

int main() {
    int A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    int A2[] = {2, 1, 8, 3};
    int n1 = sizeof(A1) / sizeof(A1[0]);
    int n2 = sizeof(A2) / sizeof(A2[0]);

    ArraySorter sorter(A1, n1, A2, n2);

    cout << "Array A1 before sorting:\n";
    sorter.print();

    cout << "Array A2 (order reference):\n";
    for (int i = 0; i < n2; i++) cout << A2[i] << " ";
    cout << "\n";

    sorter.sortA1ByA2();

    cout << "Array A1 after sorting according to A2:\n";
    sorter.print();

    return 0;
}

