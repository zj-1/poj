// poj 2495
// 356K 32MS G++
// simulation
// shocked by this!
#include <climits>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

int main(int argc, char const *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
#endif

	int n, a, b, c, d, i = 1;
	scanf("%d", &n);
	while (n-- > 0) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("Scenario #%d:\n", i++);
		printf("%d\n\n", (a + b + c + d) % 2);
	}

	return 0;
}
