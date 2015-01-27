// poj 3080
// 376K 0MS G++
// kmp
#include <cstdio>
#include <cstring>
#include <climits>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXW 60
#define MAXM 10

char data[MAXM][MAXW + 1], t1[MAXW + 1], t2[MAXW + 1];
int next[MAXW], N, t, res, mi;

int kmp(char *w)
{
    int k = next[0] = -1, res = INT_MAX;
    for (int i = 1; w[i] != 0; i++) {
        while (k > -1 && w[k + 1] != w[i]) { k = next[k]; }
        if (w[k + 1] == w[i]) { k++; }
        next[i] = k;
    }
    for (int p = 1; p < N; p++) {
        int m = -1;
        k = -1;
        for (int i = 0; data[p][i] != 0; i++) {
            while (k > -1 && w[k + 1] != data[p][i]) { k = next[k]; }
            if (w[k + 1] == data[p][i]) { k++; }
            m = MAX(m, k);
            if (w[k + 1] == 0) { break; }
        }
        res = MIN(res, m);
    }
    return res + 1;
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &t);
    while (t-- > 0) {
        res = 0;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%s", data[i]);
        }

        for (int i = 0; i < MAXW - 2; i++) {
            int tmp = kmp(data[0] + i);
            if (res == tmp) {
                for (int j = 0; j < res; j++) {
                    t1[j] = data[0][mi + j];
                    t2[j] = data[0][i + j];
                }
                t1[res] = t2[res] = 0;
                if (strcmp(t1, t2) > 0) { mi = i; }
            } else if (res < tmp) {
                res = tmp;
                mi = i;
            }
            res = MAX(res, tmp);
        }
        if (res < 3)
            printf("no significant commonalities\n");
        else {
            for (int j = 0; j < res; j++) {
                printf("%c", data[0][mi + j]);
            }
            printf("\n");
        }
    }
    return 0;
}
