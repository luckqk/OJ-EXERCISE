#include <bits/stdc++.h>
using namespace std;

int ans, allOne;

void dfs(int pos, int left, int right)
{
	if (pos == allOne) {
		++ans;
		return;
	}
	for (int t = allOne & (~(pos | left | right));t;) {
		int p = t & -t;
		dfs(pos | p, (left | p) << 1, (right | p) >> 1);
		t ^= p;
	}
}

int getAnswer(int n) {
	ans = 0;
	allOne = (1 << n) - 1;
	dfs(0, 0, 0);
	return ans;
}

int main() {
    int n;
	cin >> n;
	cout << getAnswer(n) << endl;
	return 0;
}
