#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0x0);
    cin.tie(0x0);
    cout.tie(0x0);

    int t, n;
    string s;
    cin >> t;

    while(t--) {
        cin >> n;
        cin >> s;

        int nn = n-1;
        for(int i = 0; i < n-2; i++)
            if(s[i] == s[i+2]) nn--;
        cout << nn << "\n";
    }

    return 0;
}