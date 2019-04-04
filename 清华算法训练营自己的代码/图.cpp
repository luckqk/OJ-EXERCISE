#include <bits/stdc++.h>
using namespace std;


const int N = 10005;

int n, m, in[N];
vector<int> e[N];

bool getAnswer() {
	int x = 0;
	for (int i = 1;i <= n;++i)
		if (in[i] == 0) {
			if (x != 0)
				return 0;
			x = i;
		}

	for (int _ = 1;_ <= n;++_) {
		int z = 0;
		for (int i = 0;i < (int)e[x].size();++i) {
			int y = e[x][i];
			if (--in[y] == 0) {
				if (z != 0)
					return 0;
				z = y;
			}
		}
		x = z;
	}
	return 1;
}

int main() {
    int T;
    for (scanf("%d", &T); T--; ) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            in[i] = 0;
            e[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            e[x].push_back(y);
            ++in[y];
        }
        printf("%d\n", getAnswer());
    }
    return 0;
}

