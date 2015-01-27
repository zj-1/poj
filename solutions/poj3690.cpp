// poj 3690
// 9188K 1922MS G++
// kmp
#include <cstdio>
#include <cstring>

#define MAXN 1000
#define MAXW 50

int N, M, T, P, Q;
bool data[MAXN][MAXN];
int next[MAXW];
long long w[MAXW], t[MAXN][MAXN];
char c[MAXN + 1];

bool kmp(int x)
{
    int k = next[0] = -1;
    for (int i = 1; i < P; i++) {
        while (k > -1 && w[k + 1] != w[i]) { k = next[k]; }
        if (w[k + 1] == w[i]) { k++; }
        next[i] = k;
    }

    k = -1;
    for (int i = 0; i < N; i++) {
        while (k > -1 && w[k + 1] != t[x][i]) { k = next[k]; }
        if (w[k + 1] == t[x][i]) { k++; }
        if (k == P - 1) { return true; }
    }

    return false;
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int cnt, n = 0;
    while (scanf("%d %d %d %d %d", &N, &M, &T, &P, &Q) && N != 0) {
        memset(data, false, sizeof(data));
        memset(t, 0, sizeof(t));
        cnt = 0;
        for (int i = 0; i < N; i++) {
            scanf("%s", c);
            // scanf("%s", &(data[i][0]));
            // printf("%s\n", c);
            for (int j = 0; j < M; j++) {
                data[i][j] = (c[j] == '*');
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = M - Q; j >= 0; j--) {
                if (j == M - Q) {
                    for (int k = 0; k < Q; k++) {
                        t[j][i] = (t[j][i] << 1) + (data[i][j + k] ? 1 : 0);
                    }
                } else {
                    t[j][i] = (t[j + 1][i] >> 1)
                        + (((long long)(data[i][j] ? 1 : 0)) << (Q - 1));
                }
            }
        }

        while (T-- > 0) {
            memset(w, 0, sizeof(w));
            for (int i = 0; i < P; i++) {
                scanf("%s", c);
                // printf("%s\n", c);
                for (int j = 0; j < Q; j++) {
                    w[i] = (w[i] << 1) + (c[j] == '*' ? 1 : 0);
                }
            }

            for (int i = 0; i < M - Q + 1; i++) {
                if (kmp(i)) { cnt++; break; }
            }
        }

        printf("Case %d: %d\n", ++n, cnt);
    }

    return 0;
}
