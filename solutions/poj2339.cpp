// poj 2339
// 404K 469MS G++
// simulation
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
#define MAXN 100

int t, C, R, N;
char data[MAXN][MAXN + 1], data2[MAXN][MAXN + 1];
int a[4] = {1, -1, 0, 0};
int b[4] = {0, 0, 1, -1};

char pro(int x, int y)
{
    int x1, y1;
    for (int i = 0; i < 4; i++) {
        x1 = x + a[i]; y1 = y + b[i];
        if (x1 < 0 || x1 >= R || y1 < 0 || y1 >= C) continue;
        if (data[x][y] == 'S' && data[x1][y1] == 'R') return 'R';
        if (data[x][y] == 'P' && data[x1][y1] == 'S') return 'S';
        if (data[x][y] == 'R' && data[x1][y1] == 'P') return 'P';
    }
    return data[x][y];
}

void process()
{
    while (N-- > 0) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                data2[i][j] = pro(i, j);
            }
        }
        memcpy(data, data2, sizeof(char) * MAXN * (MAXN + 1));
    }

    for (int i = 0; i < R; i++) {
        printf("%s\n", data[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%d %d %d", &R, &C, &N);
        for (int i = 0; i < R; i++) {
            scanf("%s", data[i]);
            // printf("%s\n", data[i]);
        }
        process();
    }

    return 0;
}
