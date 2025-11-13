#include <iostream>
using namespace std;

class SearchArray {
    int* a;
    int n;
public:
    SearchArray(int arr[], int size) {
        n = size;
        a = new int[n];
        for (int i = 0; i < n; i++) a[i] = arr[i];
    }

    int linearSearch(int key) {
        for (int i = 0; i < n; i++)
            if (a[i] == key) return i;
        return -1;
    }

    int binarySearch(int key) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (a[mid] == key) return mid;
            else if (a[mid] < key) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }

    void sortArray() {
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (a[i] > a[j]) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
    }

    void print() {
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << "\n";
    }

    ~SearchArray() {
        delete[] a;
    }
};

int main() {
    int n;
    cout << "Enter size of array:\n";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    SearchArray s(arr, n);
    int key;
    cout << "Enter element to search:\n";
    cin >> key;

    int pos = s.linearSearch(key);
    if (pos != -1) cout << "Linear Search: Element found at position " << pos << "\n";
    else cout << "Linear Search: Element not found\n";

    s.sortArray();
    cout << "Array after sorting (for Binary Search):\n";
    s.print();

    pos = s.binarySearch(key);
    if (pos != -1) cout << "Binary Search: Element found at position " << pos << "\n";
    else cout << "Binary Search: Element not found\n";

    delete[] arr;
    return 0;
}
