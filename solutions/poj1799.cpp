// poj 1799
// 412K 32MS G++
// simulation
// easy problem
#include <cstdio>
#include <cmath>

#define PI 3.14159265358979323846

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    int N, n, i = 1;
    double R, ans;
    scanf("%d", &N);
    while (N-- > 0) {
        scanf("%lf %d", &R, &n);
        ans = R * sin(PI / n) / (sin(PI / n) + 1);
        printf("Scenario #%d:\n%.3f\n\n", i++, ans);
    }

    return 0;
}
