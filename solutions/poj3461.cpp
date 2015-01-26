// poj 3461
// 1400K 110MS G++
// kmp
#include <cstdio>
#include <cstring>

#define MAXW 10000
#define MAXT 1000000

char w[MAXW + 1], t[MAXT + 1];
int next[MAXW + 1];

int kmp()
{
    int k = next[0] = -1, res = 0;
    for (int i = 1; w[i] != 0; i++) {
        while (k > -1 && w[k + 1] != w[i]) { k = next[k]; }
        if (w[k + 1] == w[i]) { k++; }
        next[i] = k;
    }
    for (int i = 0; i < 10; i++) { printf("%d: %d\n", i, next[i]); }
    k = -1;
    for (int i = 0; t[i] != 0; i++) {
        while (k > -1 && w[k + 1] != t[i]) { k = next[k]; }
        if (w[k + 1] == t[i]) { k++; }
        if (w[k + 1] == 0) { res++; k = next[k]; }
    }

    return res;
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    while (n-- > 0) {
        scanf("%s", w); scanf("%s", t);
        printf("%d\n", kmp());
    }

    return 0;
}
