#include <bits\stdc++.h>
using namespace std;

int main(){
    int num = 0;
    cin >> num;
    int solve = 0;
    for (int i = 0; i < num; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b + c >= 2) solve++;
    }
    cout << solve;
    return 0;
}