//πÈ≤¢≈≈–Ú
#include <bits/stdc++.h>
using namespace std;


long long inversion_num = 0;
vector<int> seq, seqTemp;

void MergeSort(int lo, int hi)
{
	if (lo >= hi-1) {
		return;
	}
	int mid = (lo + hi) >> 1;
	MergeSort(lo, mid); 
	MergeSort(mid, hi);
	int lo_pt = lo, hi_pt = mid;
	for (int i = lo;i < hi;++i) {
		if (lo_pt != mid && hi_pt != hi) {
			if (seq[lo_pt] <= seq[hi_pt]) {
				seqTemp[i] = seq[lo_pt];
				++lo_pt;
			}
			else {
				seqTemp[i] = seq[hi_pt];
				++hi_pt;
				inversion_num += mid - lo_pt;
			}
		}
		else if (lo_pt == mid) {
			seqTemp[i] = seq[hi_pt];
			++hi_pt;
		}
		else {
			seqTemp[i] = seq[lo_pt];
			++lo_pt;
		}

	}
	for (int i = lo;i < hi;++i) {
		seq[i] = seqTemp[i];
	}
	return;

}


long long getAnswer(int n, vector<int> a) {
	if (n <= 0 || a.size() == 0)
		return inversion_num;

	seq = a;
	seqTemp.resize(n);
	MergeSort(0, n);
	return inversion_num;
}


int main() {
    int n, tmp;
    vector<int> a;
    a.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &tmp);
        a.push_back(tmp);
    }
    long long ans = getAnswer(n, a);
    cout << ans << '\n';
    return 0;
}
