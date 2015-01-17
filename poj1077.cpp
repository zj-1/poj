// poj 1077
// 2876K 204MS G++
// bfs
#include <cstdio>
#include <cmath>
#include <cstring>

#define MAXN 363000

int fac[8] = { 1, 2, 6, 24, 120, 720, 5040, 40320 };
int x[4] = { -1, 1, 0, 0 };
int y[4] = { 0, 0, -1, 1 };

int data[9];
bool vis[MAXN];
char op[4] = { 'd', 'u', 'r', 'l' };

int head, tail;
struct node {
    int p, num, pre;
};
node q[MAXN];

// perfect hash
int hash(int num)
{
    int res = 0;
    for (int i = 0; i < 9; i++) {
        data[i] = num % 10;
        num /= 10;
    }
    for (int i = 1; i < 9; i++) {
        int cnt = 0;
        for (int j = 0; j < i; j++) {
            if (data[i] > data[j])
                cnt++;
        }
        res += cnt * fac[i - 1];
    }
    return res;
}

void prf(int n)
{
    for (int i = 0; i < 9; i++) {
        data[i] = n % 10;
        n /= 10;
    }

    printf("#####\n");
    for (int i = 0; i < 3; i++) {
        printf("%d %d %d\n", data[8 - 3 * i], data[7 - 3 * i],
               data[6 - 3 * i]);
    }
}

int opr(int n, int t)
{
    int old_pos, pos, tmp;
    for (int i = 0; i < 9; i++) {
        data[i] = n % 10;
        if (data[i] == 9)
            old_pos = i;
        n /= 10;
    }

    if (old_pos % 3 == 2 && t == 3) return 0;
    if (old_pos % 3 == 0 && t == 2) return 0;
    if (old_pos < 3 && t == 0) return 0;
    if (old_pos > 5 && t == 1) return 0;

    pos = old_pos + x[t] * 3 + y[t];
    tmp = data[old_pos];
    data[old_pos] = data[pos];
    data[pos] = tmp;

    int res = 0;
    for (int i = 8; i >= 0; i--) {
        res = res * 10 + data[i];
    }

    return res;
}

void print(int h)
{
    // prf(q[h].num);
    // printf("\nh:%d\tpre:%d\n", h, q[h].pre);
    if (h != 0) {
        print(q[h].pre);
        printf("%c", op[q[h].p]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    char c;
    int num = 0, tmp, h;
    head = tail = 0;
    memset(vis, false, sizeof(vis));
    int cnt = 0;
    while (cnt < 9) {
        scanf("%c", &c);
        if (c != 'x' && (c < '1' || c > '8'))
            continue;
        cnt++;
        if (c == 'x')
            num = num * 10 + 9;
        else
            num = num * 10 + c - '0';
    }
    // printf("%d\n", num);

    q[head].num = num;
    q[head].pre = tail;
    h = hash(num);
    vis[h] = true;
    head++;

    while (head != tail) {
        // printf("=====root====== node: %d\n", tail);
        // prf(q[tail].num);
        for (int i = 0; i < 4; i++) {
            tmp = opr(q[tail].num, i);
            if (tmp == 0) continue;
            h = hash(tmp);
            if (vis[h]) continue;

            // printf("node: %d\t\tpre: %d", head, tail);
            // prf(tmp);

            q[head].num = tmp;
            q[head].p = i;
            q[head].pre = tail;
            vis[h] = true;
            if (tmp == 123456789) {
                print(head);
                printf("\n");
                return 0;
            }
            head++;
        }
        tail++;
    }

    printf("unsolvable\n");
    return 0;
}
