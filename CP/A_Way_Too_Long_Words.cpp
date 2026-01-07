#include <bits\stdc++.h>
using namespace std;

int main(){
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.size() <= 10) cout << s;
        else {
            string s2;
            s2 += s[0];
            s2 += to_string(s.size() - 2);
            s2 += s.back();
            cout << s2;
        } 
        cout << '\n';
    }
    return 0;
}