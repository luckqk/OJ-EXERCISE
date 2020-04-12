#include <bits/stdc++.h>
using namespace std;

const int N = 50005;
int isignal[N * 2];
vector<int> myCard, hisCard;
int ans;

void getAns(vector<int> my, vector<int> his)
{
	vector<int>::iterator myPt, hisPt;
	myPt = my.begin();
	hisPt = his.begin();
	for (int i = 0;i < my.size()-1;++i) {
		if (*myPt < *hisPt) {
			++myPt;			
			++ans;
		}
		++hisPt;
	}
	if (*myPt < *hisPt)
		++ans;
}

int main()
{
	int n;
	int tmp;
	scanf("%d", &n);
	for (int i = 0;i < n;++i) {
		scanf("%d", &tmp);
		isignal[tmp] = 1;
	}
	for (int i = 1;i <= 2 * n;++i) {
		if (isignal[i] == 1)
			myCard.push_back(i);
		else
			hisCard.push_back(i);
	}

	sort(myCard.begin(), myCard.end());
	sort(hisCard.begin(), hisCard.end());

	getAns(myCard, hisCard);
	printf("%d", ans);
	return 0;
}