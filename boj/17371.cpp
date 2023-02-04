#include <iostream>
#include <math.h>
#include <map>

int n;
double x[1000], y[1000];
double hx, hy;

double getAvg(double hx, double hy) {
    double max_dist = 0.0;
    double min_dist = 1000000000.0;
    for(int i = 0; i < n; i++) {
        double dist = sqrt(
                pow(hx - x[i], 2)
                + pow(hy - y[i], 2));
        max_dist = std::max(dist, max_dist);
        min_dist = std::min(dist, min_dist);
    }
    return (max_dist + min_dist) / 2.0;
}

int main() {
    scanf(" %d", &n);
    for(int i = 0; i < n; i++)
        scanf(" %lf %lf", x+i, y+i);

    double dist = 1000000000.0;
    for(int i = 0; i < n; i++) {
        double tmp = getAvg(x[i], y[i]);
        if(dist > tmp){
            dist = tmp;
            hx = x[i];
            hy = y[i];
        }
    }
    printf("%lf %lf\n", hx, hy);
    return 0;
}
