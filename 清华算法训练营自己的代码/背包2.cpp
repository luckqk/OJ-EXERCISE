#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int pre[N][N], post[N][N];

vector<int> getAnswer(int n, vector<int> w, vector<int> v, int q, vector<int> qV, vector<int> qx) {
	for (int i = 1;i <= n;++i) {
		for (int j = 0;j < v[i];++j)
			pre[i][j] = pre[i - 1][j];
		for (int j = v[i];j <= 5000;++j)
			pre[i][j] = max(pre[i - 1][j], pre[i - 1][j - v[i]] + w[i]);
	}

	for (int i = n;i >= 1;--i) {
		for (int j = 0;j < v[i];++j)
			post[i][j] = post[i + 1][j];
		for (int j = v[i];j <= 5000;++j)
			post[i][j] = max(post[i + 1][j], post[i + 1][j - v[i]] + w[i]);
	}

	vector<int> ans;
	for (int k = 1;k <= q;++k) {
		int x = qx[k], V = qV[k];
		int mx = 0;
		for (int i = 0;i <= V;++i)
			mx = max(mx, pre[x - 1][i] + post[x + 1][V-i]);
		ans.push_back(mx);
	}
	return ans;
}


int main() {
    int n, q;
    vector<int> v, w, qv, qx;
    v.push_back(-1);
    w.push_back(-1);
    qv.push_back(-1);
    qx.push_back(-1);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        v.push_back(a);
        w.push_back(b);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        qv.push_back(a);
        qx.push_back(b);
    }
    vector<int> ans = getAnswer(n, w, v, q, qv, qx);
    for (int i = 0; i < q; ++i)
        printf("%d\n", ans[i]);
    return 0;
}

