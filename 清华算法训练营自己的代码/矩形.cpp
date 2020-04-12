#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1005;
const ll mo1 = 1e9 + 7;
const ll mo2 = 1e9 + 9;
const ll pw = 233;


ll h1[2][N][N], h2[2][N][N], bb[2][N][N];

int a[N][N], b[N][N], n, m, p, q;


vector<pair<int, int>> getAnswer() {
	ll p1 = 1, p2 = 1;
	for (int i = 1;i <= q;++i) {
		p1 = p1 * pw%mo1;
		p2 = p2 * pw%mo2;
	}
	p1 = (mo1 - p1) % mo1;
	p2 = (mo2 - p2) % mo2;

	for (int i = 1;i <= n;++i) {
		ll t1 = 0, t2 = 0;
		for (int j = 1;j <= m;++j) {
			if (j < q) {
				t1 = (t1*pw + a[i][j]) % mo1;
				t2 = (t2*pw + a[i][j]) % mo2;
			}
			else {
				t1 = h1[0][i][j] = (t1*pw + a[i][j] + p1 * a[i][j - q]) % mo1;
				t2 = h2[0][i][j] = (t2*pw + a[i][j] + p2 * a[i][j - q]) % mo2;
			}
		}
	}

	p1 = 1, p2 = 1;
	for (int i = 1;i <= p;++i) {
		p1 = p1 * pw%mo1;
		p2 = p2 * pw%mo2;
	}
	p1 = (mo1 - p1) % mo1;
	p2 = (mo2 - p2) % mo2;

	for (int j = 1;j <= m;++j) {
		ll t1 = 0, t2 = 0;
		for (int i = 1;i <= n;++i) {
			if (i < p) {
				t1 = (t1*pw + h1[0][i][j]) % mo1;
				t2 = (t2*pw + h2[0][i][j]) % mo2;
			}
			else {
				t1 = h1[1][i][j] = (t1*pw + h1[0][i][j] + p1 * h1[0][i - p][j]) % mo1;
				t2 = h2[1][i][j] = (t2*pw + h2[0][i][j] + p2 * h2[0][i - p][j]) % mo2;
			}
		}
	}

	for(int i=1;i<=p;++i)
		for (int j = 1;j <= q;++j) {
			bb[0][i][j] = (bb[0][i][j - 1] * pw + b[i][j]) % mo1;
			bb[1][i][j] = (bb[1][i][j - 1] * pw + b[i][j]) % mo2;
		}

	p1 = p2 = 0;
	for (int i = 1;i <= p;++i) {
		p1 = (p1*pw + bb[0][i][q]) % mo1;
		p2 = (p2*pw + bb[1][i][q]) % mo2;
	}

	vector<pii> ans;
	for (int i = p;i <= n;++i)
		for (int j = q;j <= m;++j)
			if (h1[1][i][j] == p1 && h2[1][i][j] == p2)
				ans.push_back(pii(i - p + 1, j - q + 1));

	return ans;
} 



int main() {
    scanf("%d%d%d%d", &n, &m, &p, &q);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= p; ++i)
        for (int j = 1; j <= q; ++j)
            scanf("%d", &b[i][j]);
    vector<pair<int, int>> ans = getAnswer();
    for (int i = 0; i < int(ans.size()); ++i)
        printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}
