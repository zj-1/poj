// poj 1094
// 356K 47MS G++
// floyd
#include <climits>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 26

bool g[MAXN][MAXN];
int N, M, in[MAXN], out[MAXN], s[MAXN];

int cmp(const void *a ,const void *b)
{
    return in[*(int *)b] - in[*(int *)a];
}

bool floyd()
{
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                g[i][j] = g[i][j] || (g[i][k] && g[k][j]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (g[i][i]) { return false; }
    }

    return true;
}

bool check()
{
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (g[i][j]) {
                out[i]++; in[j]++;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (in[i] + out[i] != N - 1)
            return false;
    }
    return true;
}

void print(int k)
{
    printf("Sorted sequence determined after %d relations: ", k);

    for (int i = 0; i < N; i++) s[i] = i;
    qsort(s, N, sizeof(s[0]), cmp);

    // for (int i = 0; i < N; i++) {
    //     printf("\nin[%d]: %d\n", i, in[i]);
    //     printf("\ns[%d]: %d\n", i, s[i]);
    // }

    for (int i = 0; i < N; i++) {
        printf("%c", s[i] + 'A');
    }

    printf(".\n");
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    char u, v; //, tmp[10];
    bool f1, f2;
    int k;
    while (scanf("%d %d", &N, &M) && N != 0) {
        memset(g, false, sizeof(g));
        f1 = f2 = false;
        for (int i = 0; i < M; i++) {
            scanf("\n%c<%c", &v, &u);
            g[u - 'A'][v - 'A'] = true;

            if (f1 || f2) continue;

            if (!floyd()) {
                f1 = true; k = i + 1;
            } else if (check()){
                f2 = true; k = i + 1;
            }
        }
        if (f1)
            printf("Inconsistency found after %d relations.\n", k);
        else if (f2)
            print(k);
        else
            printf("Sorted sequence cannot be determined.\n");
    }
    return 0;
}
