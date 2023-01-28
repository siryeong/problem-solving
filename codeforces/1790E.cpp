#include <iostream>
 
using namespace std;
 
int t, x;
 
int main() {
    scanf(" %d", &t);
    while(t--){
        scanf(" %d", &x);
        if(x % 2)
            printf("-1\n");
        else {
            if(((x + x/2) ^ (x/2)) == x)
                printf("%d %d\n", (x + x/2), (x/2));
            else
                printf("-1\n");
        }
    }
    return 0;
}