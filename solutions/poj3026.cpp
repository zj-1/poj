// poj 3026
// 432K 16MS G++
// bfs + prim
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <cstdlib>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 50
#define MAXL 101

int N, M, t, cnt;
int g[MAXL][MAXL];
bool vis[MAXN][MAXN];
char data[MAXN][MAXN + 1];
int a[4] = {1, -1, 0, 0};
int b[4] = {0, 0, -1, 1};

typedef struct {
    int x, y, d;
} node;
node q[MAXL];
int head, tail;

int mdis[MAXL];
bool pvis[MAXL];

node A[MAXL];

int prim()
{
    int res = 0, mmin, tj;
    memset(pvis, false, sizeof(pvis));
    for (int i = 0; i < cnt; i++) { mdis[i] = g[0][i]; }
    pvis[0] = true;
    for (int i = 0; i < cnt - 1; i++) {
        mmin = INT_MAX; tj = -1;
        for (int j = 0; j < cnt; j++) {
            if (!pvis[j] && mmin > mdis[j]) { tj = j; mmin = mdis[j]; }
        }
        if (tj == -1) break;
        res += mmin; pvis[tj] = true;
        for (int j = 0; j < cnt; j++) {
            if (!pvis[j]) { mdis[j] = MIN(g[tj][j], mdis[j]); }
        }
    }
    return res;
}

void bfs(int n)
{
    int x, y;
    for (int i = 0; i < cnt; i++) { A[i].d = 0; }
    memset(vis, false, sizeof(vis));
    head = tail = 0;
    q[head].x = A[n].x; q[head].y = A[n].y; q[head].d = 0;
    vis[A[n].x][A[n].y] = true;
    head = (head + 1) % MAXL;
    while (head != tail) {
        for (int i = 0; i < 4; i++) {
            x = q[tail].x + a[i]; y = q[tail].y + b[i];

            // if (x >= N || x < 0 || y < 0 || y >= M) continue;
            if (vis[x][y] || data[x][y] == '#') continue;

            q[head].x = x; q[head].y = y; q[head].d = q[tail].d + 1;
            vis[x][y] = true;

            if (data[x][y] == 'A' || data[x][y] == 'S') {
                for (int j = 0; j < cnt; j++) {
                    if (A[j].x == x && A[j].y == y) {
                        A[j].d = q[head].d;
                        break;
                    }
                }
            }

            head = (head + 1) % MAXL;
        }
        tail = (tail + 1) % MAXL;
    }

    for (int i = 0; i < cnt; i++) { g[n][i] = A[i].d; }
}

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    char tmp[MAXN];
    scanf("%d", &t);
    while (t-- > 0) {
        cnt = 0;
        scanf("%d %d", &M, &N); gets(tmp);

        for (int i = 0; i < N; i++) {
            gets(data[i]);
            for (int j = 0; j < M; j++) {
                if (data[i][j] == 'A' || data[i][j] == 'S') {
                    A[cnt].x = i; A[cnt].y = j; cnt++;
                }
            }
        }

        for (int i = 0; i < cnt; i++) { bfs(i); }

        printf("%d\n", prim());
    }

    return 0;
}
