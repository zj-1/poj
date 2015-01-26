// poj 2406
// 5268K 125MS G++
// kmp
#include <cstdio>
#include <cstring>

#define MAXW 1000000

char w[MAXW + 1];
int next[MAXW + 1];

int kmp()
{
    int len = strlen(w);

    int k = next[0] = -1;
    for (int i = 1; i < len; i++) {
        while (k > -1 && w[k + 1] != w[i]) { k = next[k]; }
        if (w[k + 1] == w[i]) { k++; }
        next[i] = k;
    }

    k = len - 1 - next[len - 1];

    if (len % k == 0)
        return len / k;
    else
        return 1;
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    while (scanf("%s", w) && w[0] != '.') {
        printf("%d\n", kmp());
    }

    return 0;
}
