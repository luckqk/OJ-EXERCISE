#include <bits/stdc++.h>
using namespace std;


const int N = 100005;
struct treenode {
	int val;
	int l;
	int r;
} Tree[N];
int cnt, root;
vector<int> ans;

int insertTree(const int v, int r)
{
	if (r == 0) {
		cnt = cnt + 1;
		r = cnt;
		Tree[r].val = v;
		Tree[r].l = 0;
		Tree[r].r = 0;
		return r;
	}
	if (v < Tree[r].val) {
		Tree[r].l = insertTree(v, Tree[r].l);
	}
	else if (Tree[r].val <= v) {
		Tree[r].r = insertTree(v, Tree[r].r);
	}
	return r;
}



vector<int> getAnswer(int n, vector<int> sequence) {

	cnt = root = 0;
	for (int i = 0;i < n;++i) {
		root = insertTree(sequence[i], root);
	}
	return ans;
}



int main() {
    int n;
    scanf("%d", &n);
    vector<int> sequence;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        sequence.push_back(x);
    }
    vector<int> ans = getAnswer(n, sequence);
    for (int i = 0; i < n; ++i)
        printf("%d%c", ans[i], " \n"[i == n - 1]);
    for (int i = 0; i < n; ++i)
        printf("%d%c", ans[n + i], " \n"[i == n - 1]);
    return 0;
}
