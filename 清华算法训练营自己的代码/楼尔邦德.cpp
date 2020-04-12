//≈≈–Ú + ∂˛∑÷≤È’“
#include <bits/stdc++.h>
using namespace std;

vector<int> seq, present_query, ans;
int seq_num;

int BinarySearch(int b_lo, int b_hi, int num)
{
	int b_res = 0;
	if (b_lo >= b_hi - 1) {
		b_res = seq[b_lo];
		if (b_res < num) {
			if (b_lo + 1 < seq_num)
				b_res = seq[b_lo + 1];
			else
				b_res = -1;
		}
		return b_res;
	}
	int b_mi = (b_lo + b_hi) >> 1;
	if (seq[b_mi] == num) {
		b_res = seq[b_mi];
	}
	else if (seq[b_mi] < num) {
		b_res = BinarySearch(b_mi + 1, b_hi,num);
	}
	else {
		b_res = BinarySearch(b_lo, b_mi,num);
	}
	return b_res;

}

int partition(int p_lo, int p_hi)
{
	if (p_lo >= p_hi - 1) {
		return p_lo;
	}
	int mi = seq[p_lo];
	int lo_end = p_lo;
	for (int i = p_lo + 1;i < p_hi;++i) {
		if (seq[i] <= mi) {
			swap(seq[++lo_end], seq[i]);
		}
	}
	swap(seq[p_lo], seq[lo_end]);
	return lo_end;
}

void QuickSort(int lo, int hi)
{
	if (lo >= hi - 1) {
		return;
	}
	int pivot = partition(lo, hi);
	QuickSort(lo, pivot);
	QuickSort(pivot + 1, hi);
}


vector<int> getAnswer(int n, vector<int> a, int Q, vector<int> query) {
	seq = a;
	present_query = query;
	seq_num = n;
	if (n <= 0 || a.size() == 0) {
		for (int i = 0;i < Q;++i)
			ans.push_back(-1);
		return ans;
	}

	QuickSort(0, n);

	int searchRes = 0;
	for (int i = 0;i < Q;++i) {
		searchRes = BinarySearch(0, n, present_query[i]);
		ans.push_back(searchRes);
	}
	return ans;
}

int main() {
    int n, Q, tmp;
    vector<int> a, query;
    a.clear();
    query.clear();
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        a.push_back(tmp);
    }
    scanf("%d", &Q);
    for (int i = 0; i < Q; ++i) {
        scanf("%d", &tmp);
        query.push_back(tmp);
    }
    vector<int> ans = getAnswer(n, a, Q, query);
    for (int i = 0; i < Q; ++i)
        printf("%d\n", ans[i]);
    return 0;
}
