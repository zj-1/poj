// poj 2136
// 384K 16MS G++
// simulation
#include <cstdio>
#include <cstdlib>
#include <cstring>

char str[73];
int num[26];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    int i, j;
    for (i = 0; i < 4; i++) {
        memset(str, 0, 73);
        gets(str);
        for (j = 0; j < 72; j++) {
            if ((str[j] >= 'A') && (str[j] <= 'Z'))
                num[str[j] - 'A']++;
        }
    }

    int m = 0;
    for (i = 0; i < 26; i++) {
        if (num[i] > m)
            m = num[i];
    }

    int t, k;
    int f;
    for (i = m; i > 0; i--) {
        f = 0;
        for (j = 0; j < 26; j++) {
            /* if(num[j] == 0) continue; */
            k = 0;
            for (t = j; t < 26; t++) {
                if (num[t] >= i) { k = 1; break; }
            }
            if (k == 0) continue;
            if (f == 0) {
                if (num[j] >= i) printf("*");
                else printf(" ");
            } else {
                if (num[j] >= i) printf(" *");
                else printf("  ");
            }
            f = 1;
        }
        printf("\n");
    }

    f = 0;
    for (i = 0; i < 26; i++) {
        /* if (num[i] == 0) continue; */
        if (f == 0) printf("%c", 'A' + i);
        else printf(" %c", 'A' + i);
        f = 1;
    }
    printf("\n");

    return 0;
}
