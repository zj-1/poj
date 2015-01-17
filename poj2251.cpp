// poj 2251
// 856K 16MS G++
// bfs
// easy problem
#include <cstdio>
#include <cmath>
#include <cstring>

#define MAXN 30

int x[6] = {1, -1, 0, 0, 0, 0};
int y[6] = {0, 0, 1, -1, 0, 0};
int z[6] = {0, 0, 0, 0, 1, -1};

char data[MAXN][MAXN][MAXN + 1];
bool vis[MAXN][MAXN][MAXN];
int head, tail;
struct node {
    int l, r, c, cnt;
};
struct node q[MAXN * MAXN * MAXN];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int L, R, C;
    struct node S;
    bool flag;

    while (scanf("%d %d %d", &L, &R, &C) && L != 0) {
        memset(vis, false, sizeof(vis));
        head = tail = 0;
        flag = false;
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < R; j++) {
                scanf("%s", data[i][j]);
                if (strlen(data[i][j]) == 0)
                    scanf("%s", data[i][j]);
                for (int k = 0; k < C; k++) {
                    if (data[i][j][k] == 'S') { S.l = i; S.r = j; S.c = k; }
                }
            }
        }
        q[head].l = S.l; q[head].r = S.r; q[head].c = S.c;
        vis[S.l][S.r][S.c] = true;
        q[head].cnt = 0;
        head++;

        while (head != tail && !flag) {
            for (int i = 0; i < 6; i++) {
                int tl = q[tail].l + x[i];
                int tr = q[tail].r + y[i];
                int tc = q[tail].c + z[i];
                if (tl < 0 || tl >= L || tr < 0 || tr >= R || tc < 0 || tc >= C)
                    continue;
                if (vis[tl][tr][tc]) continue;
                if (data[tl][tr][tc] == '#') continue;
                if (data[tl][tr][tc] == 'E') { flag = true; break; }
                q[head].l = tl; q[head].r = tr; q[head].c = tc;
                q[head].cnt = q[tail].cnt + 1;
                vis[tl][tr][tc] = true;
                head++;
            }
            tail++;
        }

        if (flag) {
            printf("Escaped in %d minute(s).\n", q[tail - 1].cnt + 1);
        } else {
            printf("Trapped!\n");
        }
    }

    return 0;
}
