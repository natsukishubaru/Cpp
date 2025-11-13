#include <iostream>
using namespace std;

bool canMakeEqual(int A[], int N) {
    int oddSum = 0, evenSum = 0;
    for (int i = 0; i < N; i++) {
        if ((i + 1) % 2 == 1) oddSum += A[i];
        else evenSum += A[i];
    }
    if (oddSum == evenSum) return true;

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            int tempOdd = oddSum, tempEven = evenSum;
            for (int k = i; k <= j; k++) {
                if ((k + 1) % 2 == 1) tempOdd -= 2 * A[k];
                else tempEven -= 2 * A[k];
            }
            if (tempOdd == tempEven) return true;
        }
    }
    return false;
}

int main() {
    int N;
    cout << "Enter number of elements:\n";
    cin >> N;
    int* A = new int[N];
    cout << "Enter " << N << " elements:\n";
    for (int i = 0; i < N; i++) cin >> A[i];

    if (canMakeEqual(A, N)) cout << "YES\n";
    else cout << "NO\n";

    delete[] A;
    return 0;
}
