#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0x0);
    cin.tie(0x0);
    cout.tie(0x0);

    int t, n;
    long long s;
    cin >> t;

    while(t--) {
        priority_queue<int> pq;
        long long sum = 0;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> s;
            if(s > 0ll) pq.push(s);
            else {
                if(!pq.empty()){
                    sum += pq.top();
                    pq.pop();
                }
            }
        }

        cout << sum << "\n";
    }

    return 0;
}