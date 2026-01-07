#include <bits\stdc++.h>
using namespace std;

bool is_sorted(vector<int> &arr){
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i + 1] < arr[i]) return false;
    }
    return true;
}

int main(){
    int num = 0;
    cin >> num;
    for (int i = 0; i < num; i++) {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        if (n > 1 && k == 1 && !is_sorted(arr)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";

        }
    }
    return 0;
}