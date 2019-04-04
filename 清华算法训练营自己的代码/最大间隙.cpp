#include <bits/stdc++.h>
using namespace std;

typedef unsigned int u32;

const int N = 67108864;

u32 a[N + 1];
u32 l[N + 1], r[N + 1];

u32 nextInt(u32 x) {
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return x;
}

void initData(u32* a, int n, int k, u32 seed) {
    for (int i = 0; i < n; ++i) {
        seed = nextInt(seed);
        a[i] = seed >> (32 - k);
    }
}


u32 maxGap(int n, int k) {
	const int m = 1 << 26;
	memset(l, -1, sizeof(int)*m);
	memset(r, -1, sizeof(int)*m);

	const int _k = max(k - 26, 0);
	for (int i = 0;i < n;++i) {
		u32 bl = a[i] >> _k;
		if (l[bl] == -1 && r[bl] == -1)
			l[bl] = r[bl] = a[i];
		else if (a[i] < l[bl])
			l[bl] = a[i];
		else if (a[i] > r[bl])
			r[bl] = a[i];
	}

	u32 last = a[0];
	u32 ans = 0;
	for(int i=0;i<m;++i)
		if (l[i]!=-1) {
			if (last > l[i])
				last = l[i];
			if (l[i] - last > ans)
				ans = l[i] - last;
			last = r[i];
		}
	return ans;
}


int main() {
    int n, k;
    u32 seed;

    scanf("%d%d%u", &n, &k, &seed);
    initData(a, n, k, seed);

    u32 ans = maxGap(n, k);

    printf("%u\n", ans);
    return 0;
}
