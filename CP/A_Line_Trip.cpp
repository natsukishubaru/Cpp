#include <bits\stdc++.h>
using namespace std;

int main(){
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        int n, x;
        cin >> n >> x;
        
        int max = 0;
        int prev = 0;
        int curr;

        for (int k = 0; k < n; k++) {
            cin >> curr; 
            if (curr - prev > max) max = curr - prev;
            
            prev = curr;
        }
        
        if (2 * (x - curr) > max) max = 2 * (x - curr);
        
        cout << max << '\n';
    } 
    return 0;
}