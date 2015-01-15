// poj 1007
// 408K 32MS G++
// easy problem
#include <cstdio>
#include <cstdlib>

int len, num;

struct str {
    char dna[51];
    int disorder;
} s[101];

void count(struct str *a)
{
    int i, j;
    a->disorder = 0;
    for (i = 0; i < len; i++) {
        for (j = i + 1; j < len; j++) {
            if (a->dna[i] > a->dna[j]) {
                a->disorder++;
            }
        }
    }

    return;
}

int cmp(const void *a, const void *b)
{
    return ((struct str *) a)->disorder >
        ((struct str *) b)->disorder ? 1 : -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    scanf("%d %d", &len, &num);
    int i;
    for (i = 0; i < num; i++) {
        scanf("%s", s[i].dna);
        count(s + i);
    }

    qsort(s, num, sizeof(s[0]), cmp);

    for (i = 0; i < num; i++) {
        printf("%s\n", s[i].dna);
    }

    return 0;
}
