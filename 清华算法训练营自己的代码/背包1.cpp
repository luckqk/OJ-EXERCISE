//0-1背包与完全背包
#include <bits/stdc++.h>
using namespace std;


const int N = 5005;
int Value[N];


int getAnswer(int n, int V, vector<int> t, vector<int> w, vector<int> v) {
	for (int i = 0;i < n;++i) {
		if (t[i] == 0) {
			for (int m = V;m >= v[i];--m) {
				Value[m] = max(Value[m],Value[m - v[i]] + w[i] );
			}
		}
		else {
			for (int m = v[i];m <= V;++m) {
				Value[m] = max(Value[m], Value[m - v[i]] + w[i]);
			}
		}
	}
	return Value[V];

}


int main() {
    int n, V;
    scanf("%d%d", &n, &V);
    vector<int> T, W, _V;
    for (int i = 0; i < n; ++i) {
        int t, w, v;
        scanf("%d%d%d", &t, &w, &v);
        T.push_back(t);
        W.push_back(w);
        _V.push_back(v);
    }
    printf("%d\n", getAnswer(n, V, T, W, _V));
    return 0;
}
