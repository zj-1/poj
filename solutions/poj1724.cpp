// poj 1724
// 1236K 32MS G++
// constrained dijkstra or more properly, greedy bfs
#include <climits>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define INF 0x3f3f3f3f
#define MAXN 100
#define MAXR 10000

const int nMax = 105;
const int mMax = 10005;

struct node {
    int v, l, t;
    struct node *next;
};
struct node *head[MAXN];
struct node e[MAXR];

struct node2 {
    int u, l, t;
    bool operator <(const struct node2 &a) const {
        return l > a.l;
    }
};

int R, N, K, S, D, L, T;

int dijkstra()
{
    priority_queue < struct node2 >q;
    struct node *p;
    struct node2 a; a.u = 0; a.l = 0; a.t = 0;
    q.push(a);
    while (!q.empty()) {
        struct node2 c = q.top(); q.pop();
        if (c.u == N - 1) return c.l;
        p = head[c.u];
        while (p != NULL) {
            if (c.t + p->t <= K) {
                a.u = p->v; a.l = c.l + p->l; a.t = c.t + p->t;
                q.push(a);
            }
            p = p->next;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d %d", &K, &N, &R);
    memset(head, 0, sizeof(head));
    for (int i = 0; i < R; i++) {
        scanf("%d %d %d %d", &S, &D, &L, &T); S--; D--;
        e[i].v = D; e[i].l = L; e[i].t = T;
        e[i].next = head[S];
        head[S] = e + i;
    }

    printf("%d\n", dijkstra());

    return 0;
}
