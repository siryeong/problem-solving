#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0x0);
    cin.tie(0x0);
    cout.tie(0x0);

    int n;
    bool x[1000001];
    int score[1000001];
    vector<int> v;
    memset(x, 0, sizeof x);
    memset(score, 0, sizeof score);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        v.push_back(k);
        x[k] = 1;
    }

    for(int i = 1; i <= 500000; i++) {
        if (!x[i]) continue;
        for(int j = i+i; j <= 1000000; j += i ) {
            if(x[j]) {
                score[i] ++;
                score[j] --;
            }
        }
    }

    for(int k : v) {
        cout << score[k] << " ";
    } cout << "\n";

    return 0;
}
