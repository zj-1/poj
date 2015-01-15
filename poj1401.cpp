// poj 1401
// 400K 344MS G++
// counting trailing zeros
#include <cstdio>

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int t, n, res;
    scanf("%d", &t);

    while (t-- > 0) {
        res = 0;
        scanf("%d", &n);
        while (n >= 5) { res += n / 5; n /= 5; }
        printf("%d\n", res);
    }

    return 0;
}
