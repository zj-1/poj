// poj 2503
// 2508K 657MS G++
// string
#include <climits>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define MAXN 100000
#define MAXL 11

struct word {
    char a[MAXL], b[MAXL];
};
struct word w[MAXN], tmp;

int N;
int cmp(const void * a, const void * b)
{
    return strcmp(((struct word *)a)->b, ((struct word *)b)->b);
}

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    char s[30]; struct word *p; N = 0;
    while(gets(s) && s[0] != '\0') {
        sscanf(s,"%s %s", w[N].a, w[N].b);
        N++;
    }
    qsort(w, N, sizeof(struct word), cmp);

    while (gets(tmp.b) && tmp.b[0] != '\0') {
        p = (struct word *) bsearch(&tmp, w, N, sizeof(struct word), cmp);
        if (p != NULL)
            printf("%s\n", p->a);
        else
            printf("eh\n");
    }
    return 0;
}
