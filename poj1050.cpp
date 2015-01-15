// poj 1050
// 440K 0MS G++
// two dimension subsequence with maximum sum
// numerate the range of rows, and compress it into one row, and then do it the
// same as one dimension subsequence with maximum sum.
#include <cfloat>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

int N, i, j, k, res, tmp;
int *data;
int *sum;

int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &N);
    data = (int *) malloc(N * N * sizeof(int));
    sum = (int *) malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            scanf("%d", data + i * N + j);

    res = INT_MIN;
    for (i = 0; i < N; i++) {
        memset(sum, 0, sizeof(int) * N);
        for (j = i; j < N; j++) {
            tmp = 0;
            for (k = 0; k < N; k++) {
                sum[k] += *(data + j * N + k);
                tmp = MAX(tmp + *(sum + k), *(sum + k));
                res = MAX(res, tmp);
            }
        }
    }

    printf("%d\n", res);

    free(data);
    free(sum);

    return 0;
}

