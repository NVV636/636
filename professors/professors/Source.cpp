#include <iostream>
using namespace std;
#define FOR(i,e) for(i=0; i<e; i++)
int main()
{
	int n, m, i, j, k, inf = 100000;
	cin >> n >> m;
	int a[n][n];
	FOR(i,n) FOR(j, n) a[i][j] = inf;
	while (m)
	{
		m--;
		cin >> i >> j >> k;
		a[i - 1][j - 1] = k;
		a[j - 1][i - 1] = k;
	}
	FOR(k,n) FOR(i,n) FOR(j,n)
		if (a[i][j] > a[i][k] + a[k][j])
			a[i][j] = a[i][k] + a[k][j];
	for (i = 0, k = 0; i < n; i++)
		FOR(j,n)
			if (i != j and a[i][j] < inf and k < a[i][j]) k = a[i][j];
	cout << k;
	return 0;
