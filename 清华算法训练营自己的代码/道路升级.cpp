//最小支撑树，Kruskal 算法，其中还包含并查集、路径压缩等知识
#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
vector<int> roadChosen;
int Father[N];

int Find(int son)
{
	if (Father[son] != son) {
		Father[son] = Find(Father[son]);
	}
	return Father[son];
}

vector<int> getAnswer(int n, int m, vector<int> U, vector<int> V) {
	int U_sontmp, V_sontmp;
	stack<int> roadSave;
	for (int i = 1;i <= n;++i) {
		Father[i] = i;
	}

	for (int p = m - 1;p >= 0;--p)
	{
		U_sontmp = Find(U[p]);
		V_sontmp = Find(V[p]);
		if (U_sontmp == V_sontmp) {
			continue;
		}
		else if (U_sontmp != V_sontmp) {
			Father[U_sontmp] = V_sontmp;
			roadSave.push(p + 1);
			if (roadSave.size() == n - 1) {
				break;
			}
		}
	}
	for (int q = 0;q < n-1;++q) {
		roadChosen.push_back(roadSave.top());
		roadSave.pop();
	}
	return roadChosen;
}



int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> U, V;
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        U.push_back(u);
        V.push_back(v);
    }
    vector<int> ans = getAnswer(n, m, U, V);
    printf("%d\n", int(ans.size()));
    for (int i = 0; i < int(ans.size()); ++i)
        printf("%d\n", ans[i]);
    return 0;
}
