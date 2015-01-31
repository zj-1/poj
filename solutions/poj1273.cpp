// poj 1273
// 508K 0MS G++
// network flow
#include <cstdio>
#include <cstring>
#include <climits>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 200

int N, M, g[MAXN][MAXN], pre[MAXN], q[MAXN], head, tail;
bool vis[MAXN];

bool bfs()
{
    memset(vis, false, sizeof(vis));
    head = tail = 0;
    q[head] = 0; head = (head + 1) % MAXN;
    vis[0] = true;
    while (head != tail) {
        for (int i = 0; i <= M; i++) {
            if (g[q[tail]][i] > 0 && !vis[i]) {
                q[head] = i; head = (head + 1) % MAXN;
                vis[i] = true;
                pre[i] = q[tail];
                if (i == M) return true;
            }
        }
        tail = (tail + 1) % MAXN;
    }
    return false;
}

int min_path_aug()
{
    int res = 0, flow, tmp;
    while (bfs()) {
        flow = INT_MAX;
        tmp = M;
        while (tmp != 0) {
            flow = MIN(flow, g[pre[tmp]][tmp]);
            tmp = pre[tmp];
        }
        tmp = M;
        while (tmp != 0) {
            g[pre[tmp]][tmp] -= flow;
            g[tmp][pre[tmp]] += flow;
            tmp = pre[tmp];
        }
        res += flow;
    }
    return res;
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    int u, v, w;
    while (scanf("%d %d", &N, &M) != EOF) {
        M--; memset(g, 0, sizeof(g));
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &u, &v, &w);
            g[u - 1][v - 1] += w;
        }
        printf("%d\n", min_path_aug());
    }

    return 0;
}
