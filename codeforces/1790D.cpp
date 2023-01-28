#include <iostream>
#include <map>
 
using namespace std;
 
 
int t, n, x;
map<int, int> m;
 
int main() {
    scanf(" %d", &t);
    while(t--){
        m.clear();
        scanf(" %d", &n);
        while(n--){
            scanf(" %d", &x);
            if(m.find(x) == m.end())
                m[x] = 0;
            if(m.find(x+1) == m.end())
                m[x+1] = 0;
 
            m[x]++;
            m[x+1]--;
        }
 
        int ans = 0;
        for(auto d : m) {
            if(d.second > 0)
                ans += d.second;
        }
        printf("%d\n", ans);
    }
 
    return 0;
}