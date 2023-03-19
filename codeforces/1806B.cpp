#include <iostream>
#include <queue>

using namespace std;

int zero=0;
int one=0;
int other=0;

int t, n, a;

int main() {
    ios::sync_with_stdio(0x0);
    cin.tie(0x0);
    cout.tie(0x0);

    cin >> t;
    while(t--) {
        cin >> n;
        zero = one = other = 0;
        while(n--) {
            cin >> a;
            if(a==0) zero++;
            if(a==1) one++;
            if(a > 1) other++;
        }
        if(zero <= (one+other+1)){
            cout << "0\n";
            continue;
        }
        if(other+one == 0){
            cout << "1\n";
            continue;
        }
        if(other == 0) {
            cout << "2\n";
            continue;
        }
        cout << "1\n";
    }

    return 0;
}
