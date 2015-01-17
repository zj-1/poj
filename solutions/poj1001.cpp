// poj 1001
// 400K 16MS G++
// simulation
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 150
char str[10];
int n, dot;
int res[MAX], a[MAX], b[MAX];
int len, lena, lenb;

void mul()
{
    int i, j;

    memset(res, 0, sizeof(res));

    for (i = 0; i < lena; i++) {
        for (j = 0; j < lenb; j++) {
            res[i + j] += a[i] * b[j];
            if (res[i + j] > 9) {
                res[i + j + 1] += res[i + j] / 10;
                res[i + j] %= 10;
            }
        }
    }

    if (res[lena + lenb] > 9) {
        res[lena + lenb + 1] += res[lena + lenb] / 10;
        res[lena + lenb] %= 10;
    }

    lena = lena + lenb;

    for (i = 0; i < lena; i++) a[i] = res[i];
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    int i, j, big, small;
    while (scanf("%s %d", str, &n) != EOF) {
        for (i = 5, j = 0; i >= 0; i--) {
            if (str[i] != '.') {
                a[j] = b[j] = str[i] - '0';
                j++;
            } else dot = 5 - i;
        }

        lena = lenb = 5;
        dot = dot * n - 1;

        for (i = 1; i < n; i++) mul();

        small = 0;
        while (a[small] == 0) small++;
        big = lena - 1;
        while (a[big] == 0) big--;

        if (big < dot) big = dot;
        if (small > dot) small = dot + 1;

        while (big >= small) {
            if (big == dot) printf(".");
            printf("%d", a[big]);
            big--;
        }
        printf("\n");
    }
    return 0;
}
