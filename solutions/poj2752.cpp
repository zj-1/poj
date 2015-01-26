// poj 2752
// 6360K 485MS G++
// kmp
#include <cstdio>
#include <cstring>

#define MAXW 400000

char w[MAXW + 1];
int next[MAXW + 1];

void print(int n)
{
    if (next[n] != -1) {
        print(next[n]);
        printf("%d ", next[n] + 1);
    }
}

void kmp()
{
    int len = strlen(w);

    int k = next[0] = -1;
    for (int i = 1; i < len; i++) {
        while (k > -1 && w[k + 1] != w[i]) { k = next[k]; }
        if (w[k + 1] == w[i]) { k++; }
        next[i] = k;
    }

    // for (int i = 0; i < len; i++) { printf("%d: %d\n", i, next[i]); }

    print(len - 1);
    printf("%d\n", len);
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    while (scanf("%s", w) != EOF) { kmp(); }

    return 0;
}
