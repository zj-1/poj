// poj 3259
// 416K 63MS G++
// bellman-ford
#include <climits>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define INF 0x3f3f3f3f
#define MAXN 500
#define MAXM 5200

struct edge {
    int u, v, w;
};
struct edge e[MAXM];

int N, M, W, mdis[MAXN], cnt;

bool bford()
{
    bool flag;
    memset(mdis, 0x3f, sizeof(mdis));
    mdis[0] = 0;
    for (int i = 0; i < N - 1; i++) {
        flag = false;
        for (int j = 0; j < cnt; j++) {
            if (mdis[e[j].v] > mdis[e[j].u] + e[j].w) {
                flag = true;
                mdis[e[j].v] = mdis[e[j].u] + e[j].w;
            }
        }
        // not necessary to continue
        if (!flag) break;
    }

    for (int i = 0; i < cnt; i++) {
        if (mdis[e[i].v] > mdis[e[i].u] + e[i].w) return true;
    }

    return false;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    int u, v, w, F;
    scanf("%d", &F);
    while (F-- > 0) {
        cnt = 0;
        scanf("%d %d %d", &N, &M, &W);
        for (int i = 0; i < M; i++) {
            scanf("%d %d %d", &u, &v, &w);
            e[cnt].u = u - 1; e[cnt].v = v - 1; e[cnt].w = w; cnt++;
            e[cnt].u = v - 1; e[cnt].v = u - 1; e[cnt].w = w; cnt++;
        }

        for (int i = 0; i < W; i++) {
            scanf("%d %d %d", &u, &v, &w);
            e[cnt].u = u - 1; e[cnt].v = v - 1; e[cnt].w = -w; cnt++;
        }

        if (bford())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
