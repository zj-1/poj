// poj 1751
// 2604K 110MS G++
// prim MST
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 750

int N, M;

int dis[MAXN][MAXN];

struct pair {
    int x, y;
};
struct pair t[MAXN];

struct pair s[MAXN];
int top;

struct node {
    int dis, start, end;
};
struct node mdis[MAXN];

int find()
{
    int m = INT_MAX, k = -1;
    for (int i = 0; i < N; i++) {
        if (m > mdis[i].dis) {
            k = i;
            m = mdis[i].dis;
        }
    }
    return k;
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    int x, y;
    top = 0;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &(t[i].x), &(t[i].y));
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j)
                dis[i][j] = dis[j][i] = INT_MAX;
            else
                dis[i][j] = dis[j][i] = (t[i].x - t[j].x) * (t[i].x - t[j].x)
                    + (t[i].y - t[j].y) * (t[i].y - t[j].y);
        }
    }

    scanf("%d", &M);
    while (M-- > 0) {
        scanf("%d %d", &x, &y); x--, y--;
        dis[x][y] = dis[y][x] = -1;
    }

    for (int i = 0; i < N; i++) {
        mdis[i].start = 0;
        mdis[i].end = i;
        mdis[i].dis = dis[0][i];
    }
    mdis[0].dis = INT_MAX;

    int tmp = find();
    while (tmp != -1) {
        if (mdis[tmp].dis != -1) {
            s[top].x = mdis[tmp].start;
            s[top].y = mdis[tmp].end;
            top++;
        }
        mdis[tmp].dis = INT_MAX;

        for (int i = 0; i < N; i++) {
            if (mdis[i].dis == INT_MAX) continue;
            if (mdis[i].dis > dis[tmp][i]) {
                mdis[i].start = tmp;
                mdis[i].end = i;
                mdis[i].dis = dis[tmp][i];
            }
        }

        tmp = find();
    }

    for (int i = 0; i < top; i++) {
        printf("%d %d\n", s[i].x + 1, s[i].y + 1);
    }

    return 0;
}
