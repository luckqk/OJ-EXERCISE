//¹þÏ£±í
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Mod = 1000003;
vector<ll> table[Mod];

int Hash(ll x)
{
	return x % Mod;
}


bool check(int op, ll x) {
	int h = Hash(x);
	vector<ll>::iterator ptr = table[h].end();
	for (vector<ll>::iterator it = table[h].begin();it != table[h].end();++it) {
		if (*it == x) {
			ptr = it;
			break;
		}
	}
	if (op == 1) {
		if (ptr == table[h].end()) {
			table[h].push_back(x);
			return 1;
		}
		return 0;
	}
	else {
		if (ptr != table[h].end()) {
			*ptr = table[h].back();
			table[h].erase(ptr);
			return 1;
		}
		return 0;
	}
}



int main() {
    int Q, op;
    ll x;
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d%lld", &op, &x);
        puts(check(op, x) ? "Succeeded" : "Failed");
    }
    return 0;
}
