// poj 3748
// 400K 0MS G++
// easy problem
// bit operation
#include <cstdio>

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    int r, x, y, s[32];
    scanf("%x,%d,%d", &r, &x, &y);

    for (int i = 0; i < 32; i++) {
        s[i] = r % 2;
        r >>= 1;
    }
    s[x] = s[y - 2] = 0;
    s[y] = s[y - 1] = 1;

    r = 0;
    for (int i = 31; i >= 0; i--) {
        r <<= 1;
        r += s[i];
    }

    printf("%x\n", r);

    return 0;
}
