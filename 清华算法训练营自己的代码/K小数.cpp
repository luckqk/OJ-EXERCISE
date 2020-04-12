#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>

template<typename T>
inline void swap(T& a, T& b)
{
	T t = a;
	a = b;
	b = t;
}

template<typename T>
T* partition(T *l, T *r)
{
	swap<T>(*l, *(l + rand() % (r - l + 1)));
	T pivot = *l;
	while (l < r) {
		while ((l < r) && pivot <= *r)
			--r;
		*l = *r;
		while ((l < r) && *l <= pivot)
			++l;
		*r = *l;
	}
	*l = pivot;
	return l;
}


template<typename T>
T find(T *l, T *r, int k)
{
	T res = 0;
	if (r - l < 1)
		return res = *l;
	T *mi = partition(l, r - 1);
	if (k == mi - l + 1) {
		return res = *mi;
	}
	else if (k < mi - l + 1) {
		res = find(l, mi, k);
	}
	else {
		res = find(mi + 1, r, k - (mi-l+1));
	}
	return res;
}

#define maxn 30000000

int a[maxn + 10];

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int p, q, M;
	scanf("%d%d%d%d", a, &p, &q, &M);

	for (int i = 1; i < n; i++)
		a[i] = ((long long)p * a[i - 1] + q) % M;

	printf("%d\n", find(a, a + n, k));
	return 0;
}