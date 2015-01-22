// poj 1860
// 368K 16MS G++
// bellman-ford
#include <climits>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 100
#define MAXM 100

struct edge {
    int u, v;
    double r, c;
};
struct edge e[MAXM * 2];

int N, M, S;
double m[MAXN], V;

bool bford()
{
    double tmp;
    bool flag;
    // for (int i = 0; i < N; i++) m[i] = 0.0;
    memset(m, 0, sizeof(m));
    m[S] = V;
    while (m[S] <= V) {
        flag = false;
        for (int i = 0; i < 2 * M; i++) {
            tmp = (m[e[i].u] - e[i].c) * e[i].r;
            if (m[e[i].v] < tmp ) {
                m[e[i].v] = tmp;
                flag = true;
            }
            if (m[S] > V) return true;
        }
        if (!flag) return false;
    }

    return m[S] > V;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    int u, v;
    double ruv, cuv, rvu, cvu;
    scanf("%d %d %d %lf", &N, &M, &S, &V); S--;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %lf %lf %lf %lf", &u, &v, &ruv, &cuv, &rvu, &cvu);
        e[2 * i].u = u - 1; e[2 * i].v = v - 1;
        e[2 * i].c = cuv;   e[i * 2].r = ruv;
        e[2 * i + 1].u = v - 1; e[2 * i + 1].v = u - 1;
        e[2 * i + 1].c = cvu;   e[2 * i + 1].r = rvu;
    }

    if (bford())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
