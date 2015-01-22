// poj 1511
// 44420K 1891MS G++
// SPFA
// double direction SSSP
#include <climits>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 1000000

struct edge { int v; int w; struct edge * next; };
struct edge e1[MAXN], e2[MAXN];
struct edge *p1[MAXN];
struct edge *p2[MAXN];

int q[MAXN], head, tail;

int t, P, Q, u, v, w, cnt;
long long mdis[MAXN], tmp;
bool vis[MAXN];

long long spfa(bool f)
{
    struct edge *ep;
    head = tail = 0;
    q[head] = 0; head = (head + 1) % MAXN;
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < P; i++) mdis[i] = LLONG_MAX;
    mdis[0] = 0;
    vis[0] = true;
    while (head != tail) {
        if (f)
            ep = p1[q[tail]];
        else
            ep = p2[q[tail]];
        while (ep != NULL) {
            tmp = mdis[q[tail]] + ep->w;
            if (tmp < mdis[ep->v]) {
                mdis[ep->v] = tmp;
                if (!vis[ep->v]) {
                    vis[ep->v] = true;
                    q[head] = ep->v; head = (head + 1) % MAXN;
                }
            }
            ep = ep->next;
        }
        vis[q[tail]] = false;
        tail = (tail + 1) % MAXN;
    }

    long long res = 0;
    for (int i = 0; i < P; i++) res += mdis[i];
    return res;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%d %d", &P, &Q);
        for (int i = 0; i < P; i++) { p1[i] = p2[i] = NULL; }
        for (int i = 0; i < Q; i++) {
            scanf("%d %d %d", &u, &v, &w);
            u--, v--;
            e1[i].next = p1[u]; e1[i].v = v; e1[i].w = w; p1[u] = e1 + i;
            e2[i].next = p2[v]; e2[i].v = u; e2[i].w = w; p2[v] = e2 + i;
        }

        printf("%I64d\n", spfa(true) + spfa(false));
    }
    return 0;
}
