// poj 3278
// 720K 32MS G++
// bfs
// easy problem
#include <cstdio>
#include <cmath>
#include <cstring>

#define MAXN 100001
#define MAXQ 30000

bool vis[MAXN];
int head, tail;
int cnt[MAXQ], q[MAXQ];

void opr(int x)
{
    if (x >=0 && x <= MAXN && ! vis[x]) {
        vis[x] = true;
        q[head] = x;
        cnt[head] = cnt[tail] + 1;
        head = (head + 1) % MAXQ;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int N, K, tmp;
    scanf("%d %d", &N, &K);
    if (N == K) {
        printf("0\n");
        return 0;
    }
    head = tail = 0;
    memset(vis, false, sizeof(vis));

    q[head] = N;
    vis[N] = true;
    cnt[head] = 0;
    head = (head + 1) % MAXQ;

    while (head != tail) {

        tmp = q[tail] + 1;
        if (tmp == K) break; else opr(tmp);

        tmp = q[tail] - 1;
        if (tmp == K) break; else opr(tmp);

        tmp = q[tail] * 2;
        if (tmp == K) break; else opr(tmp);

        tail = (tail + 1) % MAXQ;
    }

    printf("%d\n", cnt[tail] + 1);
    return 0;
}
