#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> triSum;

int getAnswer(int n, vector<vector<int>> a) {
	triSum.resize(n+1);
	for (int i = 0;i <= n;++i) {
		triSum[i].resize(i + 2);
	}
	int sumTmp = 0;

	for (int i = 1;i <= n;++i) {
		for (int j = 1;j <= i;++j) {
			triSum[i][j] = a[i][j];
			triSum[i][j] = ((triSum[i][j] + triSum[i - 1][j]) > (triSum[i][j] + triSum[i - 1][j-1])) ? \
				(triSum[i][j] + triSum[i - 1][j]) : (triSum[i][j] + triSum[i - 1][j - 1]);
		}
	}

	for (int i = 1;i <= n;++i) {
		sumTmp = max(sumTmp, triSum[n][i]);
	}
	return sumTmp;
}


int main() {
    int n;
    vector<vector<int>> a;
    scanf("%d", &n);
    a.resize(n + 1);
    for (int i = 0; i <= n; ++i)
        a[i].resize(i + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            scanf("%d", &a[i][j]);
    int ans = getAnswer(n, a);
    printf("%d\n", ans);
    return 0;
}
