#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
vector<int> pos, f;

int LCS(int n, vector<int> a, vector<int> b) {
	pos.resize(n + 1);
	f.resize(n + 2, inf);
	for (int i = 1;i <= n;++i)
		pos[b[i]] = i;
	for (int i = 1;i <= n;++i)
		a[i] = pos[a[i]];
	f[0] = 0;
	for (int i = 1;i <= n;++i) {
		*lower_bound(f.begin(), f.end(), a[i]) = a[i];
	}
	int len;
	for (len = 1;len <= n;++len) {
		if (f[len] == inf)
			break;
	}
		
	return len - 1;
}


int main() {
    int n, tmp;
    vector<int> a, b;
    scanf("%d", &n);
    a.clear();
    b.clear();
    a.push_back(-1);
    b.push_back(-1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &tmp);
        a.push_back(tmp);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &tmp);
        b.push_back(tmp);
    }
    int ans = LCS(n, a, b);
    printf("%d\n", ans);
    return 0;
}
