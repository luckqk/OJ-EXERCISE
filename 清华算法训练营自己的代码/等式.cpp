//并查集、路径压缩
#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
int Father[N], Book[N*2];
struct node {
	int a, b, e;
}numnode[1000001];

int find(int x)
{
	if (Father[x] != x) {
		Father[x] = find(Father[x]);
	}
	return Father[x];
}

bool cmp(node a, node b) {
	return a.e > b.e;
}

string getAnswer(int n, int m, vector<int> A, vector<int> B, vector<int> E) {
	int num = -1;
	for (int i = 0;i < m;++i) {
		Book[num++] = A[i];
		Book[num++] = B[i];
	}
	sort(Book, Book + num);
	int offset = unique(Book, Book + num) - Book;
	for (int i = 0;i < m;++i) {
		numnode[i].a = lower_bound(Book, Book + offset, A[i]) - Book + 1;
		numnode[i].b = lower_bound(Book, Book + offset, B[i]) - Book + 1;
		numnode[i].e = E[i];
	}
	sort(numnode, numnode + m, cmp);

	for (int i = 1;i <= offset+1;++i)
	{
		Father[i] = i;
	}

	for (int i = 0;i < m;++i) {
		int setA = find(numnode[i].a);
		int setB = find(numnode[i].b);
		if (numnode[i].e == 0) {
			if (setA == setB) {
				return "No";
			}
		}
		else {
			if (numnode[i].e == 1) {
				Father[setA] = setB;
			}
		}
	}
	return "Yes";
}



int main() {
    int T;
    for (scanf("%d", &T); T--; ) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<int> A, B, E;
        for (int i = 0; i < m; ++i) {
            int a, b, e;
            scanf("%d%d%d", &a, &b, &e);
            A.push_back(a);
            B.push_back(b);
            E.push_back(e);
        }
        printf("%s\n", getAnswer(n, m, A, B, E).c_str());
    }
    return 0;
}
