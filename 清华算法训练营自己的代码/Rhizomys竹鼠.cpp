#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int MO = 911814;
typedef pair<int, int> pii;

vector<pii> graph[N];
priority_queue<pii, vector<pii>, greater<pii>> pq;
bool flag[N];
int mind[N];
int pathNum[N];

void getAnswer(int n, int m, vector<int> U, vector<int>V, vector<int>C) {
	while (!pq.empty())
		pq.pop();
	for (int i = 1;i <= n;++i) {
		graph[i].clear();
	}	
	memset(mind, 127, sizeof(mind));
	memset(flag, 0, sizeof(flag));
	memset(pathNum, 0, sizeof(pathNum));

	for (int i = 0;i < m;++i) {
		graph[U[i]].push_back(make_pair(V[i], C[i]));
		graph[V[i]].push_back(make_pair(U[i], C[i]));
	}

	mind[1] = 0;
	pq.push(make_pair(mind[1], 1));
	
	pathNum[1] = 1;
	while (pq.size()!= 0) {
		int u = pq.top().second;
		pq.pop();
		if (!flag[u]) {
			flag[u] = 1;
			for (vector<pii>::iterator it = graph[u].begin();it != graph[u].end();++it) {
				int v = it->first, c = it->second;
				if (c + mind[u] > mind[v])
					continue;
				else if (c + mind[u] == mind[v]) {
					pathNum[v] = (pathNum[v] + pathNum[u]) % MO;
				}	
				else {
					pathNum[v] = pathNum[u] % MO;
					mind[v] = mind[u] + c;
					pq.push(make_pair(mind[v], v));
				}
			}
		}
	}

	for (int i = 1;i <= n;++i) {
		printf("%d\n", pathNum[i]);
	}
}


int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> U, V, C;
    for (int i = 0; i < m; ++i) {
    	int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        U.push_back(u);
        V.push_back(v);
        C.push_back(c);
    }
    getAnswer(n, m, U, V, C);
    return 0;
}
