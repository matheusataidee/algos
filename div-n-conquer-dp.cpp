#include <bits/stdc++.h>

using namespace std;

#define MAXK 880
#define MAXN 4040

typedef long long ll;

ll acc_cost[MAXN][MAXN];
ll C[MAXN][MAXN];
ll dp[MAXK][MAXN];

ll calc_cost(int l, int r) {
	if (l >= r) return 0;
	if (C[l][r] != -1) return C[l][r];
	C[l][r] = calc_cost(l, r - 1) + acc_cost[r][r];
	if (l) C[l][r] -= acc_cost[r][l-1];
	return C[l][r];
}

void compute(int p, int l, int r, int optl, int optr) {
	if (l > r) return;
	int mid = (l + r) / 2;
	pair<ll, int> best = {0x7fffffff, -1};
	for (int i = optl; i <= min(mid, optr); i++) {
		best = min(best, {dp[p - 1][i] + calc_cost(i + 1, mid), i});
	}
	dp[p][mid] = best.first;
	compute(p, l, mid - 1, optl, best.second);
	compute(p, mid + 1, r, best.second, optr);
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	memset(C, -1, sizeof(C));
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char ch;
			while (ch = getchar(), (ch < '0' || ch > '9'))
				;
			acc_cost[i][j] = ch - '0';
			if (j) acc_cost[i][j] += acc_cost[i][j-1];
		}
	}
	for (int i = 0; i < n; i++) dp[1][i] = calc_cost(0, i);
	for (int i = 2; i <= k; i++) {
		compute(i, 0, n - 1, 0, n - 1);
	}
	printf("%lld\n", dp[k][n - 1]);
	
	return 0;
}
